#include <dht.h>
#include <LiquidCrystal.h>      
#define DHT11_PIN 7   
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Digital pins to which you connect the LCD
const int inPin = 0;//Initialising pin to read value from temperature sensor
const int soilm=A0;
void setup()
{
  lcd.begin(16,2); //Initialising LCD 
  Serial.begin(9600);
}
void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  float soil;
  Serial.print("\nReading temperature\n");
  delay(1000);
  Serial.print("Temp = ");
  Serial.print(DHT.temperature);//reading temperature from sensor 
  Serial.print("C\n");
  delay(1000);
  Serial.print("Reading humidity\n");
  delay(1000);
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);//reading humidity from sensor
  Serial.print("%\n");
  delay(1000);
  Serial.print("Reading soil\n");
  Serial.print("Soil % = ");
  soil=analogRead(soilm);
  soil=map(soil,1023,370,0,100);//these values will have to be changed later 
  Serial.print(soil);
  delay(2000);
}
