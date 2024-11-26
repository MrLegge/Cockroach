#ifndef ROACHVIEW_H
#define ROACHVIEW_H

  class RoachView{

    protected:
      int _trigPin;
      int _echoPin;
	  int powerPin;
      long _duration;
      uint8_t _distance;

    public:
      RoachView();
      RoachView(int,int);
      int getDistance();
    
    };
   #endif
