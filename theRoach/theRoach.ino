#include "RoachView.h"
#include "RoachWalk.h"

RoachView *myView;
RoachWalk *myWalk;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	myView = new RoachView(A0, A1);
	myWalk = new RoachWalk();
	myWalk->stance();
}

void loop() {
	// put your main code here, to run repeatedly:
	Serial.println(myView->getDistance());
	delay(1000);
}
