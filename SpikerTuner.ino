#include<Servo.h>
Servo steps;
#define trig 2
#define echo 4
void setup() {
  // put your setup code here, to run once:

  pinMode(A0, OUTPUT);
  steps.attach(A0);
  steps.write(180); //initial motor position

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long t = pulseIn(echo, HIGH);

  long inches = t / 74 / 2;
  long cm = t / 29 / 2;

  Serial.print(inches);
  Serial.println("in\t");
  Serial.println(cm);
  Serial.print("cm");

  if(inches<5)
  {
    step2();
    }

}

//creating function
void step2()  //release motor according to ultra sonic sensor acknowledgement
{
  for (int i = 180; i >= 90; i--) //release ball
  {
    steps.write(i);
    delay(10);
  }
  
  for (int j = 90; j <= 180; j++) //set motor to catch ball
  {
    steps.write(j);
    delay(10);
  }
}
