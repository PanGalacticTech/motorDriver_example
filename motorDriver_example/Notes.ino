

/*
 * 
 * 
 *  "is this a 'has a' or an 'is a' relationship? What you're talking about above seems to me that it is a "has a" relationship. in other words:
TwoWheelDrive HAS two motorObjects
Thus you end up more with something that looks like:
class TwoWheelDrive {
private:
motorObjects fLeft, fRight;
public:
const byte LEFT = 0;
const byte RIGHT = 1;
const byte BOTH = -1;
TwoWheelDrive(bye a, byte b, byte c, byte d) :
fLeft(a, b, c, f), fRight(a, b, c, d) { };
motorOn(byte inbWhichMotor, float inrMagnitude);
motorOff(byte inbWhichMotor);
etc.
which you might call with:
TwoWheelDrive myMotors(a, b, c, d);
myMotors.motorOn(LEFT, 0.50); // Turn left motor on at 50%;
sleep(0.1);
myMotors.motorOn(BOTH, 0.50); // Move forward.
etc.
As a brief explanation of the difference between "has a" and "is a"...
a car "is a" vehicle
a car "has a" 4 wheels.
a unicycle "is a" vehicle
a unicycle "has a" 1 wheel
"is a" says, "How is this the exact same as all other things of this family of things?"
"has a" says, "How is this thing special or different from all other things of this family of things?"
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
