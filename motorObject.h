// >>>>> motorObject.h Library <<<<<<<

/*

     Sets up a single Drive Motor Object

     Direction Control Pins:
     A
     B
     C
     D

     & PWM Drive Speed Pin

     S

   _______________________________________________
   Outline & Concept
   >>>>>>><<<<<<<<
   Public:
    setup:

    motorSetup(direction = 1 OR 0){               // Sets pinModes to output & defines polarity of forwards/backwards
    }

    Control Methods:

    .forward(speed = 255);
    .backward(speed = 255);
    .stop();
    .brake();
    .setSpeed(speed = 255)   // Probably overkill as could just call direction & new speed, but could be useful if a function doesnt care about direction but wants to change the drive speed

    Anything else a motor can do?

    Public Variables:
    motorState = RUN_FORWARDS or RUN_BACKWARDS or BRAKE_ON or OFF

    Private:

    setDirectionPin(byte = 0b00001001);  // last 4 bits set direction pins
    setSpeedPin(byte = 255);              // Sets Speed Pin

    Anything else required to make the function work?


*/


#ifndef motorObject_h
#define motorObject_h


#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif






class motorObject
{

    // constants (set up within constructor)
    byte pinA;
    byte pinB;
    byte pinC;
    byte pinD;

    byte pinS;

    byte motor_direction;



  public:

    // Constructor
    motorObject(byte pin_a = 4, byte pin_b = 5, byte pin_c = 6, byte pin_d = 7, byte pin_s = 3, byte polarity = 1):
      pinA(pin_a),
      pinB(pin_b),
      pinC(pin_c),
      pinD(pin_d),
      pinS(pin_s),
      motor_direction(polarity)
    {
    }

    // Setup
    void begin();

    // Basic Methods

    void forward(byte speed = 255);
    void backward(byte speed = 255);
    void stop();
    void brake();
    void setSpeed(byte speed = 255);   




  private:

    void setDirectionPin(uint8_t motorDirection = 0b0000);     // Defaults to off if not passed any other arguments

    void setSpeedPin(byte = 255);              // Sets Speed Pin

};












#endif
