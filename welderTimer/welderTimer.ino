/*
  Welder Timer project
Control the ON time of pulse with a potentiometer and fire up with a button.
 This sketch uses:
 - A potentiometer
 - A button
 - A 10K Resistor
 - A USB power supplier
 - An Arduino (Nano / Uno or any other)
 
 Circuit:
 * Arduino Board
 * Potentiometer pins to {VCC, potentiometer (Analog pin), GND}
 * Button to isON digital pin (normally low)
 * 
 * Output:
 * Machine to control attached to pulsePin digital pin (maybe through a resistor)
 * 
 * Purpose:
 * Send a time critical pulse to any machine. F.E. TIG welder etc...
 * 
  April 2019
  Author: Rafael Brouzos
  Welder Timer project
 */
 //declare pins
int potentiometer = A0; //pin attached with the center pin of a potentiometer 
int pulsePin = 2;       //pin that outputs the final Pulse (to machine)
int isON = 3;           //pin that detects the input pulse (from button)
//declare other variables
unsigned long ONtime;   //pulse ON time value
int sensorValue;        //value of the potentiometer


void setup() {
  // set up output pin
  pinMode(pulsePin, OUTPUT);
  //set up the input pin
  pinMode(isON, INPUT);
  //serial monitor for debugging
  Serial.begin(9600);
}

void loop() {
  //wait for button press loop
  do{
    //read potentiometer
    int sensorValue = analogRead(A0);
    
    //TODO: map potentiometer value to a pulse ONtime value
    //here just ONtime is the analog input level
    ONtime = sensorValue;
    
  //read button
  }while(digitalRead(isON) != HIGH);
  
  //Pulse ON (machine ON)
  digitalWrite(pulsePin, HIGH);
  delay(ONtime);
  //Pulse OFF (machine OFF)
  digitalWrite(pulsePin, LOW);
  
  // wait for button release loop
  do{
    delay(1);
    //read button
  }while(digitalRead(isON) != LOW);
}
