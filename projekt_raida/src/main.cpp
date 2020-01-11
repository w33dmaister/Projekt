#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PRVNIPIN 2
#define DRUHYPIN 3
 
// variables will change:
volatile byte prvniState = HIGH, druhyState = HIGH;       // variable for reading the pushbutton status
int pocet = 500, zmereno = 0;
unsigned long time1 = 0, time2 = 0, mezicas1 = 0, mezicas2 = 0, oldtime1 = 0, oldtime2 = 0;
float distance = 100.0, interval = 0, velocity = 0;
LiquidCrystal_I2C lcd(0x20,16,2); 


void inter1() {
  oldtime1 = millis();
  if((mezicas1 + 10) < oldtime1){
     pocet++;
     time1 = millis();
  }
  mezicas1 = oldtime1;
}

void inter2() {
   oldtime2 = millis();
  if((mezicas2 + 10) < oldtime2){
     time2 = millis();
  }
  mezicas2 = oldtime2;  
}

void setup() {
  // initialize the LED pin as an output:
  //pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(PRVNIPIN, INPUT);
  pinMode(DRUHYPIN, INPUT);     
  lcd.begin();// inicializuje displej
  lcd.backlight();
  /*digitalWrite(PRVNIPIN, HIGH); // turn on the pullup
  digitalWrite(DRUHYPIN, HIGH);*/
  attachInterrupt(digitalPinToInterrupt(PRVNIPIN), inter1, RISING);
  attachInterrupt(digitalPinToInterrupt(DRUHYPIN), inter2, RISING);
  lcd.print(pocet);
  Serial.begin(9600);
}
int zmena = 0;
void loop(){
  // read the state of the pushbutton value:
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
 
  /*while(time1 == 0) {
    if(digitalRead(PRVNIPIN) == LOW){
      time1 = micros();
      pocet--;
      Serial.println("prvni");
    }
  }
  while(time2 == 0) {
    if(digitalRead(DRUHYPIN) == LOW){
      time2 = micros();
      zmereno = 1;
      Serial.println("druhy");
    }
  }
  */
  /*if(zmereno == 1){
    interval = float(time2-time1);
    velocity = distance*1000*3.28/interval;
    Serial.println(velocity);
    Serial.println(pocet);
    time1 = 0;
    time2 = 0;
    zmereno = 0;
    }*/
    
    if (pocet != zmena){
      Serial.println(pocet);
      lcd.setCursor(0,0);
      lcd.print(pocet);
      zmena = pocet;
      interval = float(time2-time1);
      velocity = float((distance*1000)*3.28)/interval;
      Serial.println(velocity);
      lcd.setCursor(0,1);
      lcd.print(velocity);
    }
 }


