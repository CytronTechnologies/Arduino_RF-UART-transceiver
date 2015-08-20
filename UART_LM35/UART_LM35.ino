/*  Example of temperature update via UART
     Cytron Arduino examples
     Tutorial: Wireless UART with Arduino and 433MHz or 434MHz module
     URL: http://tutorial.cytron.com.my/2014/05/15/wireless-uart-with-arduino-and-433mhz-or-434mhz-module/
     This example code uses hardware serial to receive and trasmit data from/to 434Mhz 100m wireless module, it cannot be used on 433MHz 1KM wireless module
     It is due to 1K series resistor on RX and TX pin of 433MHz (1KM) module, and hardware serial pin (pin 0 and 1) on Arduino are also have 1K series resistors.
     These resistors will cause the transmit to Arduino to fail, receiving data from Arduino and transmit out wirelessly is not issue.
     If you need to use 433MHz 1KM wireless module, please download another version of example which uses software serial
     434MHz (100M) wireless UART module: http://www.cytron.com.my/viewProduct.php?pcode=RF-UART-434-100M&name=434MHz%20RF%20Transceiver%20Module%20(UART)-100m
     http://www.cytron.com.my
*/
#define   LM35    A0  //LM35 connected to A0, analog input 
int analog = 0;  //variable to store analog value
float temperature = 0.0;  //varaible to store temperature value
int LED = 13;  //LED on Arduino board
byte rx_data = 0; //variable to store receive data

void setup() {
  pinMode(LED, OUTPUT);  
  Serial.begin(9600); //initialize UART for 9600bps 
}

void loop(){  
  analog = analogRead(LM35);
  temperature = ((analog * 5.0) / 10.24); //convert to degree Celsuis
    
  Serial.print("Temperature = " );                       
  Serial.print(temperature);
  Serial.print(' ');  
  Serial.write(176);  //degree symbol 
  Serial.println('C');  
  delay(200);   
  
  if(Serial.available()) // check if UART receive data
  {
    rx_data = Serial.read();  //store data received
    if(rx_data == 'a')  //if the character received is 'a'
    digitalWrite(LED, HIGH);  
    else if ( rx_data == 'A') //if the character received is 'A'
    digitalWrite(LED, LOW); 
  }
}
