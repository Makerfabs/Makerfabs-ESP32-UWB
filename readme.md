# Makerfabs ESP32 UWB & Display

```c++
/*
Version:		V4.0
Author:			Vincent
Create Date:	2021/11/6
Note:

	2021/12/9 	V2.0:Add a Indoor Positioning demo.
	2022/6/29 	V2.1:Add DW3000 library.
	2022/8/1  	V3.0:Provides a library available for high-power versions. Move DW3000 to other 		  					     repositories.
	2022/9/6	V3.1:Added changes to the high-power version.
	2022/10/26 	V4.0:Add new version with SSD1306
*/
```
![](md_pic/main.jpg)


[toc]

# Makerfabs

[Makerfabs home page](https://www.makerfabs.com/)

[Makerfabs Wiki](https://makerfabs.com/wiki/index.php?title=Main_Page)

# Makerfabs ESP32 UWB Serials
## Intruduce



ESP32 UWB : [esp32-uwb-ultra-wideband](https://www.makerfabs.com/esp32-uwb-ultra-wideband.html) 

ESP32 UWB Pro : [esp32-uwb-high-power](https://www.makerfabs.com/esp32-uwb-high-power-120m.html)

ESP32 UWB Pro with Display : []()

Wiki Link : [ESP32_UWB](https://www.makerfabs.com/wiki/index.php?title=ESP32_UWB) 



Makerfabs ESP32 UWB contains an ESP32 and a DW1000 chip.

The DW1000 is a single-chip wireless transceiver based on ultra-wideband technology. The chip enables you to develop cost-effective RTLS solutions that can pinpoint indoor and outdoor positioning to within 10 cm.

The chip provides a new approach to real-time location and indoor location systems, location-based services, wireless sensor networks and the Internet of Things by providing accurate location awareness and communication.






## Feature

- Integrated ESP32 2.4G WiFi and Bluetooth.
- DW1000 UWB module.
- UWB - X1 - Max module. (Pro and Pro with Display version)
- SSD1306 OLED screen. (Pro with Display version))


### Front:

![front](md_pic/front.jpg)

### Back:
![back](md_pic/back.jpg)

### Long Range Version UWB-X1-Pro

![long](md_pic/long.jpg)




# Example

## Compiler Options

**If you have any questions，such as how to install the development board, how to download the code, how to install the library. Please refer to :[Makerfabs_FAQ](https://github.com/Makerfabs/Makerfabs_FAQ)**

- Install board : ESP32 .
- Install zip library : DW1000.zip
- Install library : Adafruit_SSD1306
- Upload code, select board "ESP32 DEV"



## Firmware

### uwb_tag

*For ESP32 UWB and ESP32 UWB Pro*

Distance to the receiving end of the test. You need an anchor point to receive data.

### uwb_tag_display

*For ESP32 Pro with display*

Distance to the receiving end of the test. You need an anchor point to receive data.

## Example List

### Anchor

*For ESP32 UWB and ESP32 UWB Pro*

Distance test anchor point.

### Anchor_1306

*For ESP32 Pro with display*

Distance test anchor point.





### Indoor positioning

*For ESP32 UWB and ESP32 UWB Pro*

Three UWB modules were used for indoor plane positioning. Data is transmitted through UDP protocol and graphically displayed in Python. 

![](md_pic/pos.jpg)

The law of cosines is used to calculate tag coordinates.

```python
def tag_pos(a, b, c):
    # p = (a + b + c) / 2.0
    # s = cmath.sqrt(p * (p - a) * (p - b) * (p - c))
    # y = 2.0 * s / c
    # x = cmath.sqrt(b * b - y * y)
    cos_a = (b * b + c*c - a * a) / (2 * b * c)
    x = b * cos_a
    y = b * cmath.sqrt(1 - cos_a * cos_a)

    return round(x.real, 1), round(y.real, 1)
```





## Pin Define

### ESP32 UWB and ESP32 UWB Pro

```c++
#define SPI_SCK 18
#define SPI_MISO 19
#define SPI_MOSI 23

#define DW_CS 4
#define PIN_RST 27
#define PIN_IRQ 34
```

### ESP32 Pro with display

```c++
#define SPI_SCK 18
#define SPI_MISO 19
#define SPI_MOSI 23

#define UWB_SS 21   // spi select pin
#define UWB_RST 27  // reset pin
#define UWB_IRQ 34  // irq pin

#define I2C_SDA 4	//I2C screen ssd1306
#define I2C_SCL 5
```

