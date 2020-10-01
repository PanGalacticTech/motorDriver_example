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







class twoWheelDrive: public motorObject
{
  public:

    // Constructor
    twoWheelDrive(byte Rpin_a, byte Rpin_b , byte Rpin_c, byte Rpin_d, byte Rpin_s, byte Lpin_e, byte Lpin_f, byte Lpin_g, byte Lpin_h, byte Lpin_t, byte Rpolarity, byte Lpolarity):
      motorObject(Rpin_a, Rpin_b , Rpin_c,  Rpin_d, Rpin_s, Rpolarity),  motorObject(Lpin_e, Lpin_f, Lpin_g, Lpin_h, Lpin_t, Lpolarity)
    {
 
    }

// Can this be done by vector? However, even if your class already has a default constructor, you should try to use std::vector<Fred> rather than an array (arrays are evil). std::vector lets you decide to use any constructor, not just the default constructor:

/*
#include <vector>
int main()
{
  std::vector<Fred> a(10, Fred(5,7));  // The 10 Fred objects in std::vector a will be initialized with Fred(5,7)
  // ...
}
*/


    // Setup
    void setup(bool monitorSerial = false);



   void driveForwards(byte speed);

   
void driveBackwards( byte speed);
void driveDifferential(int16_t speedR, int16_t speedL);
void driveBrake();
void driveOff();
void turnRight(byte speed);
void turnLeft(byte speed);

void spinRight(byte speed);
void spinLeft(byte speed);





};



#endif
