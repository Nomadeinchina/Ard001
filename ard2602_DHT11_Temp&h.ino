// Código completo para medir la temperatura y la humedad con el sensor DHT11
// + LCD 16x2

#include "DHT.h"                       // Incluimos librería
#include <LiquidCrystal.h>

#define DHTPIN 8                       // Pin digital donde se conecta el sensor DHT11
                                       // Dependiendo del tipo de sensor
#define DHTTYPE DHT11
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pines de LCD en placa
           
DHT dht(DHTPIN, DHTTYPE);              // Inicializamos el sensor DHT11
 
void setup() {
lcd.begin(16, 2);                      // Define Formato de LCD (Columnas, Filas)
Serial.begin(9600);                    // Inicializamos comunicación serie

dht.begin();                           // Comenzamos el sensor DHT
 
}
 
void loop() {
   
  delay(5000);   // Esperamos 5 segundos entre medidas
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }


  // Calcular el índice de calor en Fahreheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);

// Datos enviados al monitor LCD
lcd.setCursor(0,0);
lcd.print("Temp.: ");
lcd.print(t);
lcd.print(" C ");
lcd.setCursor(0,1);
lcd.print("Humedad: ");
lcd.print(h);
lcd.print(" % ");

// Datos enviados al monitor Serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
 
}
