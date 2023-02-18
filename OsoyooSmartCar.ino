/* 
 * Tutorial URL http://osoyoo.com/2018/12/19/osoyoo-robot-car-kit-lesson-4-obstacle-avoidance-robot-car/
 * CopyRight www.osoyoo.com
 */

#include "Servo.h"
#include "configuration.h"
#include "functions.h"


void setup() 
{

  Serial.begin(9600);
  

  /*setup L298N pin mode*/
  pinMode(RightDirectPin1, OUTPUT); 
  pinMode(RightDirectPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
  pinMode(LeftDirectPin1, OUTPUT);
  pinMode(LeftDirectPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
  stop();//stop move

  /*init HC-SR04*/
  pinMode(Trig_PIN, OUTPUT); 
  pinMode(Echo_PIN,INPUT);
  digitalWrite(Trig_PIN,LOW); 

  /*init buzzer*/
  pinMode(peizoPin, OUTPUT);
  digitalWrite(peizoPin, HIGH);  
  buzz_OFF(); 

  
  /*init servo*/
  head.attach(SERVO_PIN); 
  head.write(90);
  delay(2000);

  playGreatingMelody(); 
  testDance();

}

void loop() 
{
  collisionAvoidance();
}
