#include <dht.h>
#include <LiquidCrystal.h>      
#define DHT11_PIN 7   
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = 0;                   //Initialising pin to read value from temperature sensor
void setup()
{
  lcd.begin(16,2); //Initialising LCD 
  Serial.begin(9600);
  
 
  
}
void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print("Temperature");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);\
  lcd.print("Temp = ");
  lcd.print(DHT.temperature);
  lcd.print("C");
  delay(2000);
  lcd.clear();
  lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print("Humidity");
  delay(1000);
  lcd.clear();
  lcd.print("Humidity=");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(2000);
}