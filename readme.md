# Makerfabs ESP32 UWB

```c++
/*
Version:		V1.0
Author:			Vincent
Create Date:	2021/11/6
Note:
	
*/
```
![](md_pic/main.jpg)


[toc]

# Makerfabs

[Makerfabs home page](https://www.makerfabs.com/)

[Makerfabs Wiki](https://makerfabs.com/wiki/index.php?title=Main_Page)

# Makerfabs ESP32 UWB
## Intruduce

Product Link ：[esp32-uwb-ultra-wideband](https://www.makerfabs.com/esp32-uwb-ultra-wideband.html) 

Wiki Link : [ESP32_UWB](https://www.makerfabs.com/wiki/index.php?title=ESP32_UWB) 

Makerfabs ESP32 UWB contains an ESP32 and a DW1000 chip.

The DW1000 is a single-chip wireless transceiver based on ultra-wideband technology. The chip enables you to develop cost-effective RTLS solutions that can pinpoint indoor and outdoor positioning to within 10 cm.

The chip provides a new approach to real-time location and indoor location systems, location-based services, wireless sensor networks and the Internet of Things by providing accurate location awareness and communication.




## Feature

- Integrated ESP32 2.4G WiFi and Bluetooth.
- DW1000 UWB module.


### Front:

![front](md_pic/front.jpg)

### Back:
![back](md_pic/back.jpg)


# Example

## Equipment list


- At least two ESP32 UWB


## Compiler Options

**If you have any questions，such as how to install the development board, how to download the code, how to install the library. Please refer to :[Makerfabs_FAQ](https://github.com/Makerfabs/Makerfabs_FAQ)**

- Install board : ESP32 .
- Install library : arduino-dw1000
- Change code in DW1000.cpp

```c++
void DW1000Class::begin(uint8_t irq, uint8_t rst) {
	// generous initial init/wake-up-idle delay
	delay(5);
	// Configure the IRQ pin as INPUT. Required for correct interrupt setting for ESP8266
    	pinMode(irq, INPUT);
	// start SPI
	SPI.begin();

// Change By VINCENT
// #ifndef ESP8266
// 	SPI.usingInterrupt(digitalPinToInterrupt(irq)); // not every board support this, e.g. ESP8266
// #endif

	// pin and basic member setup
	_rst        = rst;
	_irq        = irq;
	_deviceMode = IDLE_MODE;
	// attach interrupt
	//attachInterrupt(_irq, DW1000Class::handleInterrupt, CHANGE); // todo interrupt for ESP8266
	// TODO throw error if pin is not a interrupt pin
	attachInterrupt(digitalPinToInterrupt(_irq), DW1000Class::handleInterrupt, RISING); // todo interrupt for ESP8266
}
```

Comment out these code, or a compilation error will occur.

```c++
// #ifndef ESP8266
// 	SPI.usingInterrupt(digitalPinToInterrupt(irq)); // not every board support this, e.g. ESP8266
// #endif
```

- Upload code, select board "ESP32 DEV"


## Example List

### Anchor

Distance test anchor point.

### Tag

Distance to the receiving end of the test. You need an anchor point to receive data.

### Tag_1306

There is an SSD1306 screen receiver, and a data structure for storing multiple anchor points is implemented. (The screen can display a maximum of two anchors, you can modify the font size to show more anchors). You need an anchor point to receive data.


## Code Explain

- Define Pins

```c++
#define SPI_SCK 18
#define SPI_MISO 19
#define SPI_MOSI 23
#define DW_CS 4

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4;   // spi select pin
```

