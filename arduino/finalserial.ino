#include <dht.h>
#include <LiquidCrystal.h>      
#define DHT11_PIN 7   
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = 0;     //Initialising pin to read value from temperature sensor
const int soilm=A0;
int stand = 10;
int pwma = 6;
int ain1 = 9;
int ain2 = 8;
void setup()
{
  pinMode(13, OUTPUT);// sets the digital pin 13 as output
  lcd.begin(16,2); //Initialising LCD 
  Serial.begin(9600); 
  pinMode(stand,OUTPUT);
  pinMode(pwma,OUTPUT);
  pinMode(ain1,OUTPUT);
  pinMode(ain2,OUTPUT);
}
void loop()
{
  analogWrite(pwma,255);  
  digitalWrite(stand,HIGH);
  digitalWrite(13,LOW);
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
  soil = map(soil,1023,370,0,100);//these values will need to be recalibrated once we have soil
  Serial.print(soil);
  while(soil<50)
  {
   digitalWrite(ain1,HIGH);
   digitalWrite(ain2,LOW);
   Serial.print("\nsoil % low, valve is open");
   soil=analogRead(soilm);
   soil = map(soil,1023,370,0,100);//these values will need to be recalibrated once we have soil
   delay(1000); // polling rate increased to 1s
  }
  digitalWrite(ain1,LOW);
  digitalWrite(ain2,LOW);
  delay(2000);//polling rate = 6 seconds
}
