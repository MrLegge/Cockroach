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

#define SERVO_FREQ 60 

#define LEFT_FRONT 0
#define RIGHT_FRONT 1
#define LEFT_MIDDLE 2
#define RIGHT_MIDDLE 3
#define LEFT_BACK 4
#define RIGHT_BACK 5



void setup() {
	Serial.begin(9600);
	
	pwm.begin();  //start the I2C bus
	pwm.setPWMFreq(SERVO_FREQ);  // servos run at ~60 Hz 
	delay(10);
}

int angleToPulse(int requiredAngle){
	int pulse = map(requiredAngle,0, 180, SERVOMIN,SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max 
	Serial.print("Angle: ");Serial.print(requiredAngle);
	Serial.print(" pulse: ");Serial.println(pulse);
	return pulse;
}

void loop() {
	pwm.setPWM(LEFT_FRONT, 0, angleToPulse(100));
	delay(200);
	pwm.setPWM(LEFT_FRONT, 0, angleToPulse(80));
	delay(200);
	/*for (uint8_t i = 0;i<180; i++){  //these to loops will sweep
		pwm.setPWM(LEFT_FRONT, 0, angleToPulse(i)); 
    delay(10); 
	}
	for (uint8_t i = 180;i>0; i--){
		pwm.setPWM(LEFT_FRONT, 0, angleToPulse(i)); 
    delay(10); 
	}*/
}