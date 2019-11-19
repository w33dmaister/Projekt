#define LEDPIN 13
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13
 
#define SENSORPIN 5
#define DRUHYPIN 6
 
// variables will change:
int sensorState = 0, lastState=0, druhyState = 0, druhyLast = 0;         // variable for reading the pushbutton status
int pocet = 500;
unsigned long time1, time2;
 
void setup() {
  // initialize the LED pin as an output:
  //pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  //pinMode(SENSORPIN, INPUT);
  pinMode(DRUHYPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  digitalWrite(DRUHYPIN, HIGH);
  Serial.begin(9600);
}
 
void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  druhyState = digitalRead(DRUHYPIN);
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
  if (sensorState && !lastState) {
    Serial.println("Prvni neprerusen");
  } 
  if (!sensorState && lastState) {
    pocet--;
    Serial.println("Prvni prerusen");
    Serial.println(pocet);
  }
  if (druhyState && !druhyLast) {
    Serial.println("Druhy neprerusen");
  } 
  if (!druhyState && druhyLast) {
    pocet++;
    Serial.println("Druhy prerusen");
    Serial.println(pocet);
  }
 lastState = sensorState;
 druhyLast = druhyState;
 }
