// Commented code is yet to be tested and isn't final. 
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
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  lcd.print(DHT.temperature);//reading temperature from sensor and outputting to display
  lcd.print("C");
  delay(2000);
  lcd.clear();
  lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print("Humidity");
  delay(1000);
  lcd.clear();//
  lcd.print("Humidity=");
  lcd.print(DHT.humidity);//reading humidity from sensor and outputting to display 
  lcd.print("%");
/*int sm;//soil moisture variable  <-- newly added code starts here 
  sm=analogRead(A0);//reading analog value from sensor via pin A0
  if(sm<$predetermined_value)//change this line later before uploading to board
  	{
		digitalWrite(8,HIGH);//opening solenoid valve
  		while(sm<$predetermined_value)//change this line too 
		{
			delay(100)//polling rate is 100ms
			sm=analogRead(A0);//getting new soil %
		}
	digitalWrite(8,LOW);//closing solenoid valve
  
  	}*/ <-- newly added code ends here
  delay(2000);//standard polling rate of 2 seconds
}
