/*

For ESP32 UWB Pro with display

*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <DW1000Ranging.h>
#include <WiFi.h>
#include "link.h"

#define TAG_ADDR "7D:00:22:EA:82:60:3B:9B"

#define SPI_SCK 18
#define SPI_MISO 19
#define SPI_MOSI 23

#define UWB_RST 27 // reset pin
#define UWB_IRQ 34 // irq pin
#define UWB_SS 21  // spi select pin

#define I2C_SDA 4
#define I2C_SCL 5

const char *ssid = "YOUR SSID";
const char *password = "YOUR PASSWORD";
const char *host = "YOUR PC LOCAL IP";
WiFiClient client;

struct MyLink *uwb_data;
int index_num = 0;
long runtime = 0;
String all_json = "";

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
    Serial.begin(115200);

    Wire.begin(I2C_SDA, I2C_SCL);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }
    display.clearDisplay();

    logoshow();

    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);

    // UWB init
    DW1000Ranging.initCommunication(UWB_RST, UWB_SS, UWB_IRQ); // Reset, CS, IRQ pin
    DW1000Ranging.attachNewRange(newRange);
    DW1000Ranging.attachNewDevice(newDevice);
    DW1000Ranging.attachInactiveDevice(inactiveDevice);
    DW1000Ranging.startAsTag(TAG_ADDR, DW1000.MODE_LONGDATA_RANGE_LOWPOWER);

    WiFi.mode(WIFI_STA);
    WiFi.setSleep(false);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected");
    Serial.print("IP Address:");
    Serial.println(WiFi.localIP());

    if (client.connect(host, 80))
    {
        Serial.println("Success");
        client.print(String("GET /") + " HTTP/1.1\r\n" +
                     "Host: " + host + "\r\n" +
                     "Connection: close\r\n" +
                     "\r\n");
    }

    uwb_data = init_link();
}

void loop()
{
    DW1000Ranging.loop();
    if ((millis() - runtime) > 1000)
    {
        display_uwb(uwb_data);

        make_link_json(uwb_data, &all_json);
        send_udp(&all_json);
        runtime = millis();
    }
}

// UWB function
void newRange()
{
    char c[30];

    Serial.print("from: ");
    Serial.print(DW1000Ranging.getDistantDevice()->getShortAddress(), HEX);
    Serial.print("\t Range: ");
    Serial.print(DW1000Ranging.getDistantDevice()->getRange());
    Serial.print(" m");
    Serial.print("\t RX power: ");
    Serial.print(DW1000Ranging.getDistantDevice()->getRXPower());
    Serial.println(" dBm");
    fresh_link(uwb_data, DW1000Ranging.getDistantDevice()->getShortAddress(), DW1000Ranging.getDistantDevice()->getRange(), DW1000Ranging.getDistantDevice()->getRXPower());
}

void newDevice(DW1000Device *device)
{
    Serial.print("ranging init; 1 device added ! -> ");
    Serial.print(" short:");
    Serial.println(device->getShortAddress(), HEX);

    add_link(uwb_data, device->getShortAddress());
}

void inactiveDevice(DW1000Device *device)
{
    Serial.print("delete inactive device: ");
    Serial.println(device->getShortAddress(), HEX);

    delete_link(uwb_data, device->getShortAddress());
}

void send_udp(String *msg_json)
{
    if (client.connected())
    {
        client.print(*msg_json);
        Serial.println("UDP send");
    }
}

// LCD display
void logoshow(void)
{
    display.clearDisplay();

    display.setTextSize(2);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.setCursor(0, 0);             // Start at top-left corner
    display.println(F("Makerfabs"));

    display.setTextSize(1);
    display.setCursor(0, 20); // Start at top-left corner
    display.println(F("DW1000 DEMO"));
    display.display();
    delay(2000);
}

void display_uwb(struct MyLink *p)
{
    struct MyLink *temp = p;
    int row = 0;

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);

    if (temp->next == NULL)
    {
        display.setTextSize(2);
        display.setCursor(0, 0);
        display.println("No Anchor");
        display.display();
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
        char c[30];

        sprintf(c, "%.1fm %x", temp->range[0], temp->anchor_addr);
        display.setTextSize(2);
        display.setCursor(0, row++ * 32); // Start at top-left corner
        display.println(c);

        sprintf(c, "%.2f dbm", temp->dbm);
        display.setTextSize(2);
        display.println(c);

        if (row >= 2)
        {
            break;
        }
    }
    delay(100);
    display.display();
    return;
}
