// connect motor controller pins to Arduino digital pins
// motor one
int enA = 5;
int in1 = 12;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);

  analogWrite(enA, 177);

  delay(2000);
  
  // now change motor directions
  digitalWrite(in1, LOW);
    analogWrite(enA, 177);

  delay(2000);
  
  // now turn off motors
  analogWrite(enA, 0);

}



void loop()
{
  demoOne();
  delay(1000);
}
