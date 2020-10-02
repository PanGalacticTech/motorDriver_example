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

  public:

    // Constructor
    motorObject(byte pin_a = 4, byte pin_b = 5, byte pin_c = 6, byte pin_d = 7, byte pin_s = 8, byte polarity = 1):
      pinS(pin_s),
      motor_polarity(polarity)
    {
      directionControlPins[0] = pin_a;
      directionControlPins[1] = pin_b;
      directionControlPins[2] = pin_c;
      directionControlPins[3] = pin_d;
    }




    // Setup
    void begin(bool monitorSerial = false);

    // Basic Methods

    void forward(byte speed = 255);
    void backward(byte speed = 255);
    void stop();
    void brake();
    void setSpeed(byte speed = 255);

    /*
      #define FORWARD 0b1001
      #define REVERSE 0b0110
      #define BRAKE 0b0011
      #define OFF 0b0000
    */

    enum driveMode
    {
      FORWARD = 0b1001,
      REVERSE = 0b0110,
      BRAKE = 0b0011,
      OFF = 0b0000

    };

    int driveState; // Variable to hold current mode


    // constants (set up within constructor)

    bool printSerial;    // if true prints debug messages to serial monitor

    byte directionControlPins[4];

    byte pinS;    // PWM pin for speed controller

    byte pinT;   //2nd PWM pin for speed controller 2

  private:


    // Hardware Function provide interface between software functions and control of the hardware pins.
    void setDirectionPin(uint8_t motorDirection = 0b0000);     // Defaults to off if not passed any other arguments

    void setSpeedPin(byte = 255);              // Sets Speed Pin







    // constants (set up within constructor)



    byte motor_polarity;

};












#endif
