
#include <Stepper.h>

const int stepsPerRevolution = 215;  // change this to fit the number of steps per revolution
// for your motor 
// 1 step is 1.8 degrees. Once microsteps are involved this will become a variable!

const int sliderLength = 1000; //lengte slider in mm
const float gearDiameter = 13.5; //gear diameter in mm
const float pi = 3.1415926536; // pi!!
float gearCircumference = gearDiameter * pi; //nu kunnen we met distance gaan werken. 
float stepDistance = gearCircumference / stepsPerRevolution;  //distance traveled per step 
float slideDistance = 40.0; //slideDistance in mm
int targetSteps = slideDistance / stepDistance; //number of steps needed to achieve slideDistance
float travelTime = 2.0; //seconden
int stepperSpeed = 60 / travelTime * slideDistance / gearCircumference; //inRPM -- max speed of stepper1 is about 27 RPM / 1.145mm/min

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);//swap 8 & 9 voor inverse

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);

  myStepper.setSpeed(stepperSpeed); //speed in RPM 

  Serial.begin(9600);
  Serial.print("gearCircumference="); //checken of mijn float dingen werken 
  Serial.println(gearCircumference); //checken of mijn float werkt 
  Serial.print("targetSteps=");
  Serial.println(targetSteps);
  Serial.print("stepperSpeed=");
  Serial.println(stepperSpeed);
}

void loop() {

  if ( stepCount <= targetSteps) { //targetSteps if Distance is input, stepsPerRevolution if 1 revolution)

    // step one step:
    myStepper.step(1);
    Serial.print("steps:" );
    Serial.println(stepCount);
    stepCount++;
  }

  for (int i = 8; i < 12; i++) {
    digitalWrite(i, LOW);
  }

}
