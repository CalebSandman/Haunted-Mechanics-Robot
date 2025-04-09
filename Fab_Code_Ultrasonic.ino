/*
Haunted Mechanics LLC
Written by Sandman
*/

int trigPin = 7;  //connects the "trig" pin from the ultrasonic sensor to a digital pin (7 for testing)
int echoPin = 8;  //connects the "echo" pin from the ultrasonic sensor to a digital pin (8 for testing)

float duration, distance; //initializes duration and distance var

//variable names for the motors
int in1 = 4;
int in2 = 5;
int in3 = 9;
int in4 = 10;


void setup()
{
  //starts serial monitor communication
  Serial.begin(9600);

  //sets trig pin to an output
  pinMode(trigPin, OUTPUT);

  //sets echo pin to an input
  pinMode(echoPin, INPUT);

  //sets motor pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  //starts the trig pin at low, waits, changes it to high, waits, changes it back to low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  //reads the duration the echo and converts the time into a distance in cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;

  //prints distance to serial monitor (for testing)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //movement backward when object within 10cm
  if(distance <= 10)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  //idle when object between between 10cm and 15cm
  else if(distance <= 15)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  //movement foward when object within 15cm and 45cm
  else if(distance <= 45)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  //idle when object greater than 45cm away
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  /*
  short delay before looping. Breaks without it. 
  Why? No idea, but I do know that it works.
  */
  delay(5);
}
