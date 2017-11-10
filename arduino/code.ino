#include <dht.h>
#include <LiquidCrystal.h>      
#define DHT11_PIN 7   
dht DHT;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
const int inPin = 0;//Initialising pin to read value from temperature sensor
const int soilm=A0;//Initialising pin to read value from soil moisture sensor
int stand = 10;//standby pin for the solenoid
int pwma = 6;//pulse width modulation pin for solenoid
int ain1 = 9;//positive pin for solenoid
int ain2 = 8;//negative pin for solenoid
int lt = A1;//light sensor pin
int ltc = 0;//light sensor variable
void setup()
{
  pinMode(13, OUTPUT);// sets the digital pin 13 as output
  lcd.begin(16,2); //Initialising LCD 
  Serial.begin(9600);//starting serial communication at 9600bps
  pinMode(stand,OUTPUT);//declaring pinmode for standby
  pinMode(pwma,OUTPUT);//declaring pinmode for pulse width modulation
  pinMode(ain1,OUTPUT);//declaring pinmode for positive terminal of solenoid
  pinMode(ain2,OUTPUT);//declaring pinmode for negative terminal of solenoid
}
void loop()
{
  ltc = analogRead(lt);
  lcd.clear();
  while(ltc<10)//putting the circuit in low power mode at night. 
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Night time");
    lcd.setCursor(0,1);
    lcd.print("Controller off");
    //Serial.print("\nNight time, controller in standby\n");
    ltc = analogRead(lt);
    delay(1000);//polling rate of 1 second
  }
  analogWrite(pwma,255);  
  digitalWrite(stand,HIGH);
  digitalWrite(13,LOW);
  int chk = DHT.read11(DHT11_PIN);
  float soil;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print("Tempterature");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature=");
  lcd.print(DHT.temperature);//reading temperature from sensor 
  lcd.print("C");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print("Humidity");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity=");
  lcd.print(DHT.humidity);//reading humidity from sensor
  lcd.print("%");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print("Soil %");
  soil=analogRead(soilm);
  soil = map(soil,1023,370,0,100);//these values will need to be recalibrated once we have soil
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Soil % = ");
  lcd.print(soil);
  lcd.print("%");
  while(soil<50)//low soil % loop
  {
   lcd.clear();
   lcd.setCursor(0,0);
   digitalWrite(ain1,HIGH);//opening solenoid valve
   digitalWrite(ain2,LOW);
   lcd.print("Soil % low");
   lcd.setCursor(0,1);
   lcd.print("Valve is open");
   soil=analogRead(soilm);
   soil = map(soil,1023,370,0,100);//these values will need to be recalibrated once we have soil
   delay(1000); // polling rate increased to 1 second, up from 12 seconds to cut down on water usage
  }
  digitalWrite(ain1,LOW);//closing solenoid valve
  digitalWrite(ain2,LOW);
  delay(2000);//polling rate = 12 seconds
}
