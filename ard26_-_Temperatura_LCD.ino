//sensor _______ + LCD
#include <DHT.h>
#include <LiquidCrystal.h>

//---------Definiciones-----------
#define DHPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ledVerde = 8;      // Temperatura normal
const int ledAmarillo = 9;   // Temperatura alta
const int ledRojo = 10 ;     // Temperatura crítica
const int buzzer = 7 ;       // Alarma sonora

void setup() {
lcd.begin(16, 2);
dth.begin();
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojoerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
//------------Apagar todos al inicio-----------
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojoerde, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
float t = dht.readTemperature();   // Grado centígrados 

// Mostrar en LCD
lcd.serCursor(0,0);
lcd.print("Temperatura");
lcd.serCursor(0,1);
lcd.print(t);
lcd.print(" C ");

// Va

}
