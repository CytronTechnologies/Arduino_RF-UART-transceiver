# Arduino_RF-UART-transceiver-  
Arduino sample sketches for 433MHz and 434MHz RF(UART) Transceiver Module with LM35.

## Tutorial:  
For detail explanation on how to setup the project you can visit our tutorial page about [Wireless UART with Arduino and 433MHz or 434MHz module](https://my.cytron.io/tutorial/wireless-uart-arduino-433mhz-434mhz-module).  

## Requirements  

**Hardware:**  
[433MHz RF (UART) Transceiver Module-1km](https://www.cytron.io/p-433mhz-rf-uart-transceiver-module-1km)  
[Arduino UNO](https://www.cytron.io/p-arduino-uno-rev3-main-board) or [UC00A](https://www.cytron.io/p-uc00a-ftdi-usb-to-uart-converter)  
[LM35](https://www.cytron.io/p-temperature-sensor-celsius)  

**Software:**  
Arduino IDE  

## Installation  
The connection between the 434MHz wireless UART Module and Arduino UNO.

| 434MHz wireless UART Module | Arduino UNO |
| --------------------------- | ----------- |
|            VCC              |     5V      |
|            GND              |     GND     |
|            RXD              |TX (Pin 1)   |
|            TXD              |RX (Pin 1)   |

If you are using 433MHz wireless UART Module and UC00A.

| 434MHz wireless UART Module | UC00A       |
| --------------------------- | ----------- |
|            VCC              |VSEL (5V)    |
|            GND              |     GND     |
|            RXD              |TX           |
|            TXD              |RX           |

For the 433MHz wireless UART Module and Arduino UNO.

| 433MHz wireless UART Module | Arduino UNO |
| --------------------------- | ----------- |
|            VCC              |     5V      |
|            GND              |     GND     |
|            RXD              |     D3      |
|            TXD              |     D2      |  


## Documentation  
The documentation for this product can be found here:  
[433 Wireless UART User's Manual](https://docs.google.com/document/d/1inRsy6p3QF0W7xV4hVWeZ0NNwt4nTtFvMHLUxBklLs8/edit)  
[User's Manual (UC00A Rev3.0)](https://docs.google.com/document/d/1pFK7DSRuZB7SeP3aCmjYzWB0i7aT-C_W_D-x25WLops/view)  

## Support  
Welcome to our [technical forum](http://forum.cytron.io) if you have further inquiry.  
