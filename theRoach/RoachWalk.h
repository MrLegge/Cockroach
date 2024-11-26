#ifndef ROACHWALK_H
#define ROACHWALK_H

#include <Adafruit_PWMServoDriver.h>

class RoachWalk{

	public:
		RoachWalk();
		void stance();
		void turn(bool);
		void legTest(int);
		void walkForward();
		void walkBackwards();

	protected:
		Adafruit_PWMServoDriver *pwm;
		int angleToPulse(int);

};
#endif