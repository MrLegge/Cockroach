#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/******* Wire out Servo board to UNO *****************
 * GND -> GND
 * OE -> not connected
 * SCL -> A5
 * SDA -> A4
 * VCC -> 5V
 * V+ -> Vin
 *****************************************************/
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 

#define SERVO_FREQ 50 

#define LEFT_FRONT 0
#define RIGHT_FRONT 1
#define LEFT_MIDDLE 2
#define RIGHT_MIDDLE 3
#define LEFT_REAR 4
#define RIGHT_REAR 5



void setup() {
	Serial.begin(9600);
	
	pwm.begin();  //start the I2C bus
	pwm.setPWMFreq(SERVO_FREQ);  // servos run at ~50 Hz 
	delay(10);
	stance();
}

int angleToPulse(int requiredAngle){
	int pulse = map(requiredAngle,0, 180, SERVOMIN,SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max 
	Serial.print("Angle: ");Serial.print(requiredAngle);
	Serial.print(" pulse: ");Serial.println(pulse);
	return pulse;
}

void loop() {
	
	for(int i = 0;i<6;i++){
		legTest(i);
    delay(1000);     
	}

}

void stance(){
	pwm.setPWM(LEFT_FRONT, 0, angleToPulse(125));
	pwm.setPWM(RIGHT_FRONT, 0, angleToPulse(25));
	pwm.setPWM(LEFT_MIDDLE, 0, angleToPulse(90));
	pwm.setPWM(RIGHT_MIDDLE, 0, angleToPulse(90));
	pwm.setPWM(LEFT_REAR, 0, angleToPulse(25));
	pwm.setPWM(RIGHT_REAR, 0, angleToPulse(125));
}

void legTest(int leg){
	pwm.setPWM(leg, 0, angleToPulse(120));
	delay(300);
	pwm.setPWM(leg, 0, angleToPulse(60));
	delay(300);
}