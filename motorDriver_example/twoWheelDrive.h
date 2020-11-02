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




#ifndef twoWheelDrive_h
#define twoWheelDrive_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif


#include "motorObject.h"




//class twoWheelDrive: public motorObject {

class twoWheelDrive {

  private:

    motorObject motorR , motorL;



  public:


    // Constructor
    twoWheelDrive(byte Rpin_a = 4, byte Rpin_b  = 5, byte Rpin_c = 6, byte Rpin_d = 7, byte Rpin_s = 3, byte Lpin_e = 8, byte Lpin_f = 9, byte Lpin_g = 10, byte Lpin_h = 12, byte Lpin_t = 11, byte Rpolarity = 1, byte Lpolarity = 0):
      motorR(Rpin_a, Rpin_b , Rpin_c, Rpin_d, Rpin_s, Rpolarity),
      motorL(Lpin_e, Lpin_f, Lpin_g, Lpin_h, Lpin_t, Lpolarity)
    {
    }



    //  int16_t steerCal = 0;   // Steering calibraton value from -100% to + 100%, 0 = No Calibration



    // Setup

    void setup(bool monitorSerial = 0, int16_t calibration = 0);



    void drive(int16_t speedR = 255, int16_t speedL = 255);     // feed arguments from -254 to 255 to control each motor individually. cal factor is still applied

    void driveForward(byte speed = 255);

    void driveBackward(byte speed = 255);

    void applyBrake();

    void driveOff();

    void turnLeft(byte speed = 150, byte amount = 100);

    void turnRight(byte speed = 150, byte amount = 100);

    void reverseLeft(byte speed = 100, byte amount = 50);

    void reverseRight(byte speed = 100, byte amount = 50);

    void spinClockwise(byte speed = 200);

    void spinAnticlockwise(byte speed = 200);

    void changeSpeed(byte speed = 255);

    int16_t calLeft(int16_t input);   // returns calibrated motor value for left motor

    int16_t calRight(int16_t input);   // returns calibrated motor value for Right Motor

    int16_t steerCal = 0;   // Steering calibraton value from -100% to + 100%, 0 = No Calibration



};



#endif
