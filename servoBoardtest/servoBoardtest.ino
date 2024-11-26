#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 

#define SERVO_FREQ 60 

#define LEFT_FRONT 15
#define RIGHT_FRONT 14
#define LEFT_MIDDLE 13
#define RIGHT_MIDDLE 12
#define LEFT_REAR 11
#define RIGHT_REAR 10

#define powerPin 11
#define trigPin 12
#define echoPin 13


uint8_t servoNumber = 0;
uint8_t leftStart = 125;
uint8_t rightStart = 55;
long duration;
uint8_t distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Cockroach test");

  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);  // servos run at ~60 Hz 
  delay(10);
  getSet();
  delay(1000);

  pinMode(powerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

  digitalWrite(powerPin, HIGH);
  Serial.println("end of setup");
}

int angleToPulse(int requiredAngle){
   int pulse = map(requiredAngle,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
  // Serial.print("Angle: ");Serial.print(requiredAngle);
  // Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void getSet(){
  pwm.setPWM(LEFT_FRONT, 0, angleToPulse(125));
  pwm.setPWM(RIGHT_FRONT, 0, angleToPulse(55));
  pwm.setPWM(LEFT_MIDDLE, 0, angleToPulse(90));
  pwm.setPWM(RIGHT_MIDDLE, 0, angleToPulse(90));
  pwm.setPWM(LEFT_REAR, 0, angleToPulse(55));
  pwm.setPWM(RIGHT_REAR, 0, angleToPulse(125));
  Serial.println("in getSet");
}

int ultraFun(){
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("We have the number   ");Serial.print(distance);Serial.println("   in ultrafun");

  return distance;
  }

void loop() {
   
  // Drive each servo one at a time using setPWM()
  pwm.setPWM(LEFT_FRONT, 0, angleToPulse(125));
  pwm.setPWM(RIGHT_MIDDLE, 0, angleToPulse(55));
  delay(200);
  pwm.setPWM(RIGHT_FRONT, 0, angleToPulse(55));
  pwm.setPWM(LEFT_REAR, 0, angleToPulse(125)); 
  delay(200);
  pwm.setPWM(LEFT_MIDDLE, 0, angleToPulse(125));
  pwm.setPWM(RIGHT_REAR, 0, angleToPulse(55));
  delay(200);
  
  //delay(200);
    
  //delay(200); 
  
  //delay(200);
 
  for (uint8_t i = 0;i<12; i++){
    pwm.setPWM(LEFT_FRONT, 0, angleToPulse(leftStart - i*5));
    pwm.setPWM(RIGHT_FRONT, 0, angleToPulse(rightStart + i*5));
    pwm.setPWM(LEFT_MIDDLE, 0, angleToPulse(leftStart - i*5));
    pwm.setPWM(RIGHT_MIDDLE, 0, angleToPulse(rightStart + i*5));
    pwm.setPWM(LEFT_REAR, 0, angleToPulse(leftStart - i*5));
    pwm.setPWM(RIGHT_REAR, 0, angleToPulse(rightStart + i*5));
  }
  delay(500);
  Serial.println(ultraFun());
  }
