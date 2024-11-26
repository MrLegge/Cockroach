#include <Arduino.h>
#include "RoachView.h"

  RoachView::RoachView(){
    _trigPin = A0;
    _echoPin = A1; 
	_powerPin = 11;
    }
  RoachView::RoachView(int trig, int echo){
    _trigPin = trig;
    _echoPin = echo; 
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
	pinMode(_powerPin, OUTPUT);
	digitalWrite(_powerPin, HIGH);
    }
    
  RoachView::getDistance(){
      digitalWrite(_trigPin, LOW);  
      delayMicroseconds(2);
  
      digitalWrite(_trigPin, HIGH);
      delayMicroseconds(10); 
      digitalWrite(_trigPin, LOW);
  
      duration = pulseIn(_echoPin, HIGH);
      _distance = _duration*0.0343/2;
      return _distance;
      }
