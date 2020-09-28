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




#include "motorObject.h"


//bytes define pin outputs to control motor direction & behaviour
#define FORWARD 0b1001
#define REVERSE 0b0110
#define BRAKE 0b0011
#define OFF 0b0000

// Setup

void motorObject::begin() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinS, OUTPUT);
}



// Basic Methods

void forward(byte speed) {
  
motorObject::setDirectionPin(FORWARD);
motorObject::setSpeed(speed);

}


void backward(byte speed = 255) {


}



void stop() {



}



void brake() {



}




void setSpeed(byte speed = 255) {



}



//Private

void motorObject::setDirectionPin(uint8_t motorDirection) {


  for (int i = 0; i < 4; i++) {

    byte a = (((motorDirection) >> (3 - i)) & 0x01);


    Serial.print(a);


    digitalWrite(directionControlPins[i], a);
  }

}
