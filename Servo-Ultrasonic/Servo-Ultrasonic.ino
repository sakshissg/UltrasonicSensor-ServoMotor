/*  Ultrasonic Sensor and Servo motor with Arduino
 * 
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - Servo Motor
 *  - Ultrasonic Sensor
 *  - Connecting cables
 *  - Arduino IDE
 *  
 *  
 */
#include<Servo.h>
Servo servo;
float duration=0;
int bpin=9;
float distance=0;
int triggerPin=3;
int echoPin=2;
int servoPin=7;
void setup() {
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  servo.attach(servoPin);
}

void loop() {
  digitalWrite(triggerPin,LOW);
  delay(100);       
  digitalWrite(triggerPin,HIGH);
  delay(200);
  digitalWrite(triggerPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.0324/2;
  if(distance>5){
    servo.write(180);
     noTone(bpin);
  }
  else{
     servo.write(0);
      tone(bpin,100);
  }
  Serial.print(distance);
  Serial.println("cm");
}
