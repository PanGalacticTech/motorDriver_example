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
#include "motorObject.h"




void twoWheelDrive::setup(bool monitorSerial) {

motorR.begin(monitorSerial);
motorL.begin(monitorSerial);

}



void twoWheelDrive::drive(int16_t speedR, int16_t speedL){

constrain(speedR, -254, 255);
constrain(speedL, -254, 255);

motorR.run(speedR);
motorL.run(speedL);

}


void twoWheelDrive::driveForward(byte speed) {

  motorR.forward(speed);
  motorL.forward(speed);

}


void twoWheelDrive::driveBackward(byte speed){

  motorR.backward(speed);
  motorL.backward(speed);
  
}


void twoWheelDrive::applyBrake(){

 motorR.brake();
 motorL.brake();
  
}


void twoWheelDrive::driveOff(){

 motorR.stop();
 motorL.stop();
  
}




void twoWheelDrive::turnLeft(byte speed, byte amount){    //top speed, // turn amount (255 = sharp, 1 = slow)

twoWheelDrive::drive(speed, (speed-amount));
  
}



void twoWheelDrive::turnRight(byte speed, byte amount){

twoWheelDrive::drive((speed-amount), speed);
  
}


void twoWheelDrive::reverseLeft(byte speed, byte amount){    //top speed, // turn amount (255 = sharp, 1 = slow)

  motorR.backward(speed-amount);
  motorL.backward(speed);
  
}

void twoWheelDrive::reverseRight(byte speed, byte amount){

  motorR.backward(speed);
  motorL.backward(speed-amount);
  
}







void twoWheelDrive::spinClockwise(byte speed){

motorR.backward(speed);
motorL.forward(speed);
  
}



void twoWheelDrive::spinAnticlockwise(byte speed){

motorR.forward(speed);
motorL.backward(speed);
  
}


void twoWheelDrive::changeSpeed(byte speed){

  motorR.setSpeed(speed);
  motorL.setSpeed(speed);
  
}
