/* >>>> Two Wheel Drive - Drivetrain Library Example <<<<<<<
 *  
 *  
 *  Library to implement simple control paradigm for a two wheel drivetrain,
 *  capable of steering via differential throttle. (simple robot, tank, screw propelled vehicle, etc)
 *  
 *  motorObject library handles the hardware interface between the microcontroller,
 *  and H-bridge Motor Drivers with Throttle Control. 
 *  (requires 4 logic outputs for direction control & 1 PWM output for Throttle Control)
 *  
 *  twoWheelDrive library creates two instances of motorObject to control two motors in tandem.
 *  
 *  twoWheelDrive handles the software implementation of drive functions, 
 *  allowing complex control via simple instructions (driveForwards, driveBackwards, turnLeft, turnRight, etc)
 *  
 *  Full control requires 4 logic channels per motor (8 in total) and 1 PWM throttle control pin per channel (2 in total)
 *  
 *  As this implementation takes almost all of the digital pins available on an arduino UNO,
 *  it is suggested that this library be incorperated into a standalone motor controller using an arduino Nano, which could be
 *  controlled via 4 PWM lines or digital interface from another controller, which would handle higher functions, sensors, navigation etc.
 *  

   Declan Heard
   Pan Galactic Tech
   03/10/2020

   Released for public use
 *  
 *  
 *  
 *  
*/



//#include "motorObject.h"    // This is included in headers so not required here

#include "twoWheelDrive.h"


// Motor R pin outputs
#define PIN_A 4       // Logic
#define PIN_B 5
#define PIN_C 6
#define PIN_D 7

#define PIN_S 3        // PWM

// Motor L pin outputs
#define PIN_E 10         // Logic
#define PIN_F 11
#define PIN_G 12
#define PIN_H 13

#define PIN_T 9        // PWM


// Preset Variables (defined in motorObject.h file)

//#define MOTOR_DIRECTION_NORMAL 1    // 0 inverts direction control
//#define MOTOR_DIRECTION_REVERSED 0

//#define MONITOR_SERIAL_TRUE 1
//#define MONITOR_SERIAL_FALSE 0



// Calibration Variable (Set from -100 to +100 to calibrate steering. This value is written to steerCal in setup, but could be modified via other functions later to allow for self calibration

#define STEERING_CALIBRATION 10  // + values turn right, - values turn left


// Old constructors for individual motor controller

//motorObject motorR(PIN_A, PIN_B, PIN_C, PIN_D, PIN_S, MOTOR_DIRECTION_NORMAL);
//motorObject motorL(PIN_E, PIN_F, PIN_G, PIN_H, PIN_T, MOTOR_DIRECTION_REVERSED);


// New Constructor for combined two wheel drive object

twoWheelDrive twd(PIN_A, PIN_B, PIN_C, PIN_D, PIN_S, PIN_E, PIN_F, PIN_G, PIN_H, PIN_T, MOTOR_DIRECTION_NORMAL, MOTOR_DIRECTION_REVERSED);    // passed 5 pins per motor + motor polarity






// Drive Disable

#define disablePin 8   // Will change later. Need a pin that can be shorted to GND to disable drive functions to make programming easier.





void setup() {

  Serial.begin(115200);

  twd.setup(MONITOR_SERIAL_TRUE, STEERING_CALIBRATION);     // Begin passes pins to arrays to work with the control structure. Boolean argument sets debug/serial test output

  delay(2000);

}










void loop() {

  twd.driveForward(255);

  delay(5000);


//  twd.applyBrake();

  delay(2000);

 // twd.driveBackward(200);

  delay(2000);

//  twd.applyBrake();

  delay(2000);


 // twd.spinClockwise(100);

  delay(2000);

 // twd.applyBrake();


  delay(2000);

 // twd.turnLeft();

  delay(2000);

//  twd.driveForward(200);

  delay(2000);

 // twd.turnRight(200, 190);

  delay(2000);

 /// twd.driveForward(200);

  delay(2000);

 // twd.driveOff();

  delay(10000);

 // twd.spinAnticlockwise(255);

  delay(2000);


 // twd.applyBrake();

  delay(2000);

 // twd.drive(50, 30);     // feed arguments from -254 to 255 to control each motor individually

  delay(2000);

 // twd.drive(50, 70);     // feed arguments from -254 to 255 to control each motor individually

  delay(2000);

//  twd.drive(-50, 70);

  delay(5000);

 // twd.applyBrake();

  delay(2000);

//  twd.reverseLeft(100, 20);

  delay(2000);

 // twd.reverseRight(50, 20);

  delay(2000);

 // twd.driveOff();

  delay(20000);


}
