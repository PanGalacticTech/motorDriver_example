// >>>>> twoWheelDrive.h Library <<<<<<<

/*
    sets up two instances of the motorObject library.
    to work in tandem for two wheel drive robots capable of
    steering via differential throttle.


    Expands the list of commands to control individal motors
    by treating both motors as a single drivetrain.

    Commands:
  twoWheelDrive.Setup(polarityMotorR = 1, polarityMotorL = 0){               // Sets pinModes to output & defines polarity of forwards/backwards
    }


    Individual Motor Control Methods:

    .forward(speed = 255);
    .backward(speed = 255);
    .stop();
    .brake();
    .setSpeed(speed = 255)   // Probably overkill as could just call direction & new speed, but could be useful if a function doesnt care about direction but wants to change the drive speed


    Public Variables:
    motorState = RUN_FORWARDS or RUN_BACKWARDS or BRAKE_ON or OFF // Slightly changed take anothe look


    TWO WHEEL DRIVE METHODS:

    .driveForwards(speed);
    .driveBackwards(speed);
    .driveDifferential(speedR, speedL);
    .driveBrake
    .driveOff
    .turnRight(speed)
    .turnLeft(speed)



    .calibrateDrive    // Needs a way of sensing a strait line, or compares motor speeds untill driving in a straight line. Saves results into an array

    calibrationArray  (for every speed value for motorR, saves a value for motorL.



*/





#include "twoWheelDrive.h"




void twoWheelDrive::setup(bool monitorSerial) {

  motorObject::printSerial = monitorSerial;

  for (int i = 0; i < 4; i++) {
    pinMode( motorR.directionControlPins[i], OUTPUT);
    pinMode( motorL.directionControlPins[i], OUTPUT);
    if (printSerial) {
      Serial.print("pinMode: Output, Pin ");
      Serial.println(i);
    }
  }

  pinMode(motorR.pinS, OUTPUT);
  pinMode(motorL.pinT, OUTPUT);

  if (motorObject::printSerial) {

    Serial.println("MotorR: Initialized");
  }

  motorR.brake();   // Start by applying brake
  motorL.brake();   // Start by applying brake
}





void twoWheelDrive::driveForward(byte speed) {

  motorR.forward(speed);
  motorL.forward(speed  );


}
