/*
Description:
RECIEVER CODE
Prototype code used for LoRa communication using the sx1276 module. The library used is not the one which will be used
when implementing into a wider network. Only used to test P2P communication between sender and reciever to verify
functionality.

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
 
void setup() 
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(868E6)) {
    Serial.println("LoRa start-up failed");
    
    //endless loop
    while (1);
  }
}
 
void loop() {
  //inspect packet
  int packet = LoRa.parsePacket();
  
  if (packet) 
  {
    Serial.println("Packet: ");
    
    // read and print data if available
    while (LoRa.available()) {

      //type cast packet data to characters
      char recievedPacketData = (char)LoRa.read();
      if (recievedPacketData == 'c')
      {
        Serial.print("Error");
      }
      else
      {
        Serial.print(incoming);
      }
    }
  }
}
