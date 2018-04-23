#include <SparkFun_TB6612.h>
#include <Servo.h>

// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
int val;    // variable to read the value from the analog pin
Servo myservo;  // create servo object to control a servo

const int buttonPin = 2;     // the number of the pushbutton pin

// Pins for all input
#define AIN1 8
#define AIN2 9
#define PWMA 3
#define STBY 10

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  myservo.write(140);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  delay(500);
}

void loop()
{
   myservo.write(140);
   delay(500);
   Serial.println(myservo.read());
  int instruction = Serial.parseInt();
  if (instruction == 5) {
    buttonState = digitalRead(buttonPin);
    pickup();
  }
  else if (instruction == -5) {
    dropoff();
  }
  else {
    myservo.write(120);
    motor1.brake();
  }
}


void pickup() {
  myservo.write(30);
  delay(500);
  while (buttonState == LOW) {
    motor1.drive(255, 100);
    Serial.println(buttonState);
    buttonState = digitalRead(buttonPin);
  }
  Serial.println("gotcha");
  motor1.brake();
  myservo.write(140);
  delay(500);
}

void dropoff() {
  myservo.write(60);
  delay(500);
  motor1.drive(-255, 17000);
  myservo.write(140);
  delay(500);
}


