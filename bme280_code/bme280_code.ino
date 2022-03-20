/*
Description:
Prototype code used for BME280 sensor module. Reads Tempreature, Humidty and barometric
pressure. Using pressure readings estimation about altitude can also be made.

Communication protocol: I2C or SPI

Reads: Temperature, Humidity and barometric pressure

Connection:
  I2C:
      -SCK(SCL Pin) --> A5
      -SDI(SDA Pin) --> A4  
      -VCC --> 5V
      -GND --> GND
*/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme280;

unsigned long delayTime = 1000;

void setup() {
  Serial.begin(9600);


  //Check sensor status 
  bool status;
  status = bme280.begin();  
  if (!status) {
    Serial.println("Invalid BME280, control sensor connection!");
    while (1);
  }
}


void loop() { 
  printValues();
  delay(delayTime);
}


void printValues() {

  Serial.println("-------------------------------");
  //Read temp and print to serial monitor in Celsius
  Serial.print("Temperature = ");
  Serial.print(bme280.readTemperature());
  Serial.println(" *C");

  //Read humidty and print to serial monitor in percentage
  Serial.print("Humidity = ");
  Serial.print(bme280.readHumidity());
  Serial.println(" %");

  //Read and convert pressure data and print to serial monitor 
  Serial.print("Pressure = ");
  Serial.print(bme280.readPressure() / 100.0F);
  Serial.println(" hPa");
}
