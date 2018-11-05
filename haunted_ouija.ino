/* The Haunted Ouija
 *  by Dave Latham
 *  An arduino application that controls a stepper motor from hell
 *  Lots of stepper mojo taken from Adafruit, thanks.
 */

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Stepper motor with 200 steps per revolution (1.8 degree)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

const int limit = 7;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("There are spirits in the room!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  myMotor->setSpeed(5);  // 10 rpm 
  pinMode(limit, INPUT_PULLUP);
}

void loop() {
  Serial.println("Homing the spirits...");
  while(digitalRead(limit)==HIGH){
     myMotor->step(5, BACKWARD, MICROSTEP);
  }
  Serial.println("Now we're channeling spirits forward...");
  myMotor->step(2500, FORWARD, MICROSTEP);

}
