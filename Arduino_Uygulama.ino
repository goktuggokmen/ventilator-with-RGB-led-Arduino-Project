int kirmiziLed = 6;
int yesilLed = 7;
int kirmiziPin = 8;
int yesilPin = 9; 
int maviPin = 10; 
int motorPin = 13;
int ldr = A0;
int sensorPin = A5;

unsigned int ldr_deger;
float LM35deger;
float analogdeger;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(motorPin, OUTPUT);
  pinMode(kirmiziPin, OUTPUT); 
  pinMode(yesilPin, OUTPUT); 
  pinMode(maviPin, OUTPUT);
  pinMode(kirmiziLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
}

void loop(){
  ldr_deger = analogRead(ldr);
  
  analogdeger = analogRead(sensorPin);
  analogdeger = (analogdeger/1023)*5000;
  LM35deger = analogdeger/10;
  
  lcd.setCursor(0, 0);
  lcd.print(String("Sicaklik:") + String(LM35deger) + String(" C"));
  lcd.setCursor(1, 1);
  
  if (ldr_deger > 1000 && LM35deger > 30){
    digitalWrite(motorPin, HIGH);
    digitalWrite(yesilLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
    lcd.print("Ortam Karanlik");
    analogWrite(kirmiziPin,255); 
    analogWrite(yesilPin,0); 
    analogWrite(maviPin,0);  
    delay(2000);
    analogWrite(kirmiziPin,0);     
    analogWrite(yesilPin,255); 
    analogWrite(maviPin,0);    
    delay(2000);
    analogWrite(kirmiziPin,0);    
    analogWrite(yesilPin,0);  
    analogWrite(maviPin,255); 
    delay(2000); 
    analogWrite(kirmiziPin,255);    
    analogWrite(yesilPin,255);  
    analogWrite(maviPin,255); 
    delay(2000); 
  }
  else if (ldr_deger < 1000 && LM35deger > 30){
    digitalWrite(motorPin, HIGH);
    digitalWrite(yesilLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
    lcd.print("Ortam Aydinlik");
    analogWrite(kirmiziPin,0); 
    analogWrite(yesilPin,0); 
    analogWrite(maviPin,0);
  }
  else if (ldr_deger < 1000 && LM35deger < 30){
    digitalWrite(motorPin, LOW);
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(yesilLed, LOW);
    lcd.print("Ortam Aydinlik");
    analogWrite(kirmiziPin,0); 
    analogWrite(yesilPin,0); 
    analogWrite(maviPin,0);
}
    else if (ldr_deger > 1000 && LM35deger < 30){
    digitalWrite(motorPin, LOW);
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(yesilLed, LOW);
    lcd.print("Ortam Karanlik");
    analogWrite(kirmiziPin,255); 
    analogWrite(yesilPin,0); 
    analogWrite(maviPin,0);  
    delay(2000);
    analogWrite(kirmiziPin,0);     
    analogWrite(yesilPin,255); 
    analogWrite(maviPin,0);    
    delay(2000);
    analogWrite(kirmiziPin,0);    
    analogWrite(yesilPin,0);  
    analogWrite(maviPin,255); 
    delay(2000); 
    analogWrite(kirmiziPin,255);    
    analogWrite(yesilPin,255);  
    analogWrite(maviPin,255); 
    delay(2000); 
  }
}
