/*
Description:
SENDER CODE
Prototype code used for LoRa communication using the sx1276 module. The library used is not the one which will be used
when implementing into a wider network. Only used to test P2P communication between sender and reciever to verify
functionality.

This implementation is very basic and is not representing the complexity needed to connect using solution such as LMIC which is provided by IBM.
LMIC is used to add end nodes to a network based upon LoRaWAN.

Communication protocol: SPI

Connection:
  SPI:
      -NSS --> D10
      -MOSI --> D11
      -MISO --> D12
      -SCK --> D13

      -RST --> D9
      -DIO0 --> D2
      -VCC --> 3.3V
      -GND --> GND 
      
*/
#include <SPI.h>
#include <LoRa.h>

void setup() {    
  Serial.begin(9600);

  while (!Serial);
  Serial.println("LoRa Sender");

  //check that module is properly connected
  if (!LoRa.begin(868E6)) {
    Serial.println("LoRa start-up failed");
    
    //endless loop
    while (1);
  }

  int counter = 0;
}
 
void loop() 
{
 
  Serial.println("Sending packet: ");
 
  // send packet
  LoRa.beginPacket();

  
  //add content to data
  LoRa.print(counter);

  //end packet
  LoRa.endPacket();
  delay(1000);
}
