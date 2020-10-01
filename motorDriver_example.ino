// >>>>> Motor Driver Library <<<<<<<

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
#include "twoWheelDrive.h"

// Motor R pin outputs
#define PIN_A 4
#define PIN_B 5
#define PIN_C 6
#define PIN_D 7
#define PIN_S 3

// Motor L pin outputs
#define PIN_E 8
#define PIN_F 9
#define PIN_G 10
#define PIN_H 12
#define PIN_T 11





#define MOTOR_DIRECTION_NORMAL 1    // 0 inverts direction control
#define MOTOR_DIRECTION_REVERSED 0

#define MONITOR_SERIAL_TRUE 1
#define MONITOR_SERIAL_FALSE 0

//motorObject motorR(PIN_A, PIN_B, PIN_C, PIN_D, PIN_S, MOTOR_DIRECTION_NORMAL);
//motorObject motorL(PIN_E, PIN_F, PIN_G, PIN_H, PIN_T, MOTOR_DIRECTION_REVERSED);


twoWheelDrive twd(PIN_A, PIN_B, PIN_C, PIN_D, PIN_S, PIN_E, PIN_F, PIN_G, PIN_H, PIN_T, MOTOR_DIRECTION_NORMAL, MOTOR_DIRECTION_NORMAL);

void setup() {
  Serial.begin(115200);
  
 //motorR.begin(MONITOR_SERIAL_FALSE);
 // motorL.begin(MONITOR_SERIAL_TRUE);

 twd.setup(MONITOR_SERIAL_TRUE);
}










void loop() {

twd.driveForward();

delay(10000);

/*
  delay(1000);

 motorR.forward(255);
  motorL.forward(255);
  delay(10000);
  motorR.brake();
  motorL.brake();
  delay(2000);
  motorR.backward();
  motorL.backward();
  delay(10000);
 motorR.stop();
  motorL.stop();
  delay(5000);
 motorR.backward();
  motorL.forward();
  delay(10000);
 motorR.brake();
  motorL.brake();
  delay(2000);
  motorR.forward();
  motorL.backward();
  delay(10000);
 motorR.brake();
  motorL.brake();
  delay(2000);
*/
}



/*

  int x=bitRead(int x,2); // (reads the 2nd bit in int x)

  int x=(((5) >> (2)) & 0x01);   //macro expands to this


  int x = INPUT >> (bitshift 2)


  0x01 is the least significant bit set, hence the decimal value is 1.

  0x80 is the most significant bit of an 8-bit byte set.

  If it is stored
  in a signed char (on a machine that uses 2's-complement notation
  - as most machines you are likely to come across will),
  it is the most negative value (decimal -128);
  in an unsigned char, it is decimal +128.
*/
