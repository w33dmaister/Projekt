#define PRVNIPIN 5
#define DRUHYPIN 6
 
// variables will change:
//int prvniState = 0, druhyState = 0;       // variable for reading the pushbutton status
int pocet = 500, zmereno = 0;
unsigned long time1 = 0, time2 = 0;
float distance = 100.0, interval = 0, velocity = 0;
 
void setup() {
  // initialize the LED pin as an output:
  //pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(PRVNIPIN, INPUT_PULLUP);
  pinMode(DRUHYPIN, INPUT_PULLUP);     
  /*digitalWrite(PRVNIPIN, HIGH); // turn on the pullup
  digitalWrite(DRUHYPIN, HIGH);*/
  Serial.begin(9600);
}
 
void loop(){
  // read the state of the pushbutton value:
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
 
  while(time1 == 0) {
    if(digitalRead(PRVNIPIN) == LOW)
      time1 = micros();
      pocet--;
  }
  while(time2 == 0) {
    if(digitalRead(DRUHYPIN) == LOW)
      time2 = micros();
      zmereno = 1;
  }
  while(zmereno == 1){
    /*interval = float(time2-time1);
    velocity = distance*1000*3.28/interval;
    Serial.println(velocity);*/
    Serial.println(pocet);
    time1 = 0;
    time2 = 0;
    zmereno = 0;
    }
 }
