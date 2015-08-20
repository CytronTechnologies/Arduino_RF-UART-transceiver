/*  Example of temperature update via UART
     Cytron Arduino examples
     Tutorial: Wireless UART with Arduino and 433MHz or 434MHz module
     URL: http://tutorial.cytron.com.my/2014/05/15/wireless-uart-with-arduino-and-433mhz-or-434mhz-module/
     This example code uses software serial to receive and trasmit data from/to 433MHz 1KM wireless module, it can be used for 434Mhz 100m wireless module too
     The reason to use software serial is due to 1K series resistor on RX and TX pin of 433MHz (1KM) module and also hardware UART pin on Arduino.
     These resistors will cause the transmit to Arduino to fail, receiving data from Arduino and transmit out wirelessly is not issue.
     Of course, this example code can be used on 434MHz 100 meters wireless module. 
     433MHz (1KM) wireless UART module: http://www.cytron.com.my/viewProduct.php?pcode=RF-UART-433-1KM&name=433MHz%20RF%20(UART)%20Transceiver%20Module-1km
     434MHz (100M) wireless UART module: http://www.cytron.com.my/viewProduct.php?pcode=RF-UART-434-100M&name=434MHz%20RF%20Transceiver%20Module%20(UART)-100m
     http://www.cytron.com.my
*/

#include <SoftwareSerial.h>
#define   LM35    A0  //LM35 connected to A0, analog input 
int analog = 0;  //variable to store analog value
float temperature = 0.0;  //varaible to store temperature value
int LED = 13;  //LED on Arduino board
byte rx_data = 0; //variable to store receive data

SoftwareSerial mySerial(2, 3); // RX = pin D2, TX = pin D3

void setup() {
  pinMode(LED, OUTPUT);  
  mySerial.begin(9600); //initialize software UART for 9600bps 
}

void loop(){  
  analog = analogRead(LM35);  //read the analog voltage from LM35
  temperature = ((analog * 5.0) / 10.24); //convert to degree Celsuis
  
  mySerial.print("Temperature = " );    //print string on Serial monitor                     
  mySerial.print(temperature);
  mySerial.print(' ');  
  mySerial.write(176);  //degree symbol 
  mySerial.println('C');  
  delay(200);   
  
  if(mySerial.available()) // check if UART receive data
  {
    rx_data = mySerial.read();  //store data received
    if(rx_data == 'a')  //if the character received is 'a'
    digitalWrite(LED, HIGH);  
    else if ( rx_data == 'A') //if the character received is 'A'
    digitalWrite(LED, LOW); 
  }
}
