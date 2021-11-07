#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 0

const int sensor_pin = A0;  /* Connect Soil moisture analog sensor pin to A0 of NodeMCU */

DHT dht(dht_dpin, DHTTYPE); 
void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}
void loop() 
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();  
    float moisture_percentage;
           
    /* Code section for DHT11 */
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    //delay(800);

    /* Code section for Moisture sensor*/
    moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
    Serial.print("Soil Moisture(in Percentage) = ");
    Serial.print(moisture_percentage);
    Serial.println("%");

    delay(1000);
}
