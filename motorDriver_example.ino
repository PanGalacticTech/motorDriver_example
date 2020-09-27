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

    Controls:

    .forward(speed = 255);
    .backward(speed = 255);
    .stop();
    .brake();
    .setSpeed(speed = 255)   // Probably overkill as could just call direction & new speed, but could be useful if a function doesnt care about direction but wants to change the drive speed

    Anything else a motor can do?

    Private:

    setDirectionPin(byte = 0b00001001);  // last 4 bits set direction pins
    setSpeedPin(byte = 255);              // Sets Speed Pin

    Anything else required to make the function work?


*/



#define PIN_A 4
#define PIN_B 5
#define PIN_C 6
#define PIN_D 7

int directionControlPins[4] = {PIN_A, PIN_B, PIN_C, PIN_D};

#define PIN_S 9 // Must be PWM capable pin

//bytes define pin outputs to control motor direction & behaviour
#define FORWARDS 0b1001
#define BACKWARDS 0b0110
#define BRAKE 0b0011
#define OFF 0b0000




void setup() {
  Serial.begin(115200);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}







void setDirectionPin(uint8_t motorDirection = 0b0000) {


  for (int i = 4; i > 0; i--) {

    byte a = (((motorDirection) >> (i-1)) & 0x01);

 
    Serial.print(a);
    

    digitalWrite(directionControlPins[i], a);
  }

}





void loop() {

delay(1000);

setDirectionPin();

/*
byte q = 0b1001;


 byte b = (((q) >> (3)) & 0x01);


    Serial.print(b);
*/

Serial.println();
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
