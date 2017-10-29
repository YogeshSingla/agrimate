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
  lcd.print("T = ");
  lcd.print(DHT.temperature);
  lcd.print("C ");
  lcd.print("H =  ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(2000);
}