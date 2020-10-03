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

/*
  //bytes define pin outputs to control motor direction & behaviour
  #define FORWARD 0b1001
  #define REVERSE 0b0110
  #define BRAKE 0b0011
  #define OFF 0b0000
*/


// Setup

void motorObject::begin(bool monitorSerial) {
  printSerial = monitorSerial;

  for (int i = 0; i < 4; i++) {
    pinMode( directionControlPins[i], OUTPUT);

    if (printSerial) {
      Serial.print("pinMode: Output, Pin ");
      Serial.println(i);
    }
  }

  pinMode(pinS, OUTPUT);


  if (printSerial) {

    Serial.println("Motor: Initialized");
  }

  motorObject::brake();   // Start by applying brake
}




// Basic Methods

void motorObject::forward(byte speed) {

  if (motor_polarity) {
    motorObject::setDirectionPin(FORWARD);
  } else {
    motorObject::setDirectionPin(REVERSE);
  }
  motorObject::setSpeed(speed);

  driveState = FORWARD;

  if (printSerial) {
    Serial.println("Motor: Forwards");
  }


}


void  motorObject::backward(byte speed) {
  
  if (motor_polarity) {
    motorObject::setDirectionPin(REVERSE);
  } else {
    motorObject::setDirectionPin(FORWARD);
  }
  motorObject::setSpeed(speed);

  driveState = REVERSE;

  if (printSerial) {
    Serial.println("Motor: Reverse");
  }

}


void motorObject::run(int16_t speed){

 if (speed > 0){
  motorObject::forward(speed);
 } else if ( speed < 0){
motorObject::backward(speed);
 }
 
  
}



void  motorObject::stop() {

  motorObject::setDirectionPin(OFF);
  motorObject::setSpeed(0);


  driveState = OFF;

  if (printSerial) {
    Serial.println("Motor: Stop");
  }

}



void  motorObject::brake() {

  motorObject::setDirectionPin(BRAKE);
  motorObject::setSpeed(0);

  driveState = BRAKE;

  if (printSerial) {
    Serial.println("Motor: Brake");
  }

}




void  motorObject::setSpeed(byte speed) {

  analogWrite(pinS, speed);

}



//Private

void motorObject::setDirectionPin(uint8_t motorDirection) {


  for (int i = 0; i < 4; i++) {

    byte a = (((motorDirection) >> (3 - i)) & 0x01);

    if (printSerial) {
      Serial.print(a);
    }

    digitalWrite(directionControlPins[i], a);
  }

  if (printSerial) {
    Serial.println();
  }

}
