#include <Servo.h>

Servo frontLeft, frontRight, middleLeft, middleRight, rearLeft, rearRight;

int position;

void setup() {
	frontLeft.attach(3);
	frontRight.attach(9);
	middleLeft.attach(5);
	middleRight.attach(10);
	rearLeft.attach(6);
	rearRight.attach(11);  
}

void loop() {
	for (position = 0; position <= 180; position += 1) {
		frontLeft.write(position);
		frontRight.write(position);
		middleLeft.write(position);
		middleRight.write(position);
		rearLeft.write(position);
		rearRight.write(position);
		delay(15);   
	}
	for (position = 180; position >= 0; position -= 1) {
		frontLeft.write(position);  
		frontRight.write(position);
		middleLeft.write(position);
		middleRight.write(position);
		rearLeft.write(position);
		rearRight.write(position);
		delay(15);                      
	}
}