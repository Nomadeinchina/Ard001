//sensor _______ + LCD
#include <DHT.h>
#include <LiquidCrystal.h>

//---------Definiciones-----------
#define DHPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int ledVerde = 8;   // Temperatura normal



void setup() {
  // put your setup code here, to run once: Sensor de tempetarura

}

void loop() {
  // put your main code here, to run repeatedly:

}
