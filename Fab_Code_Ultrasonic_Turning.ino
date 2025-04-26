/*
Haunted Mechanics LLC
Written by Sandman
*/

int trigPinL = 7;  //connects the "trig" pin from the ultrasonic sensor to a digital pin (7 for testing)
int echoPinL = 8;  //connects the "echo" pin from the ultrasonic sensor to a digital pin (8 for testing)

int trigPinR = 1;
int echoPinR = 2;

float durationL, distanceL, durationR, distanceR, distanceAvg, distanceDif; //initializes duration and distance var

char move = 'I';

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
  pinMode(trigPinL, OUTPUT);
  pinMode(trigPinR, OUTPUT);

  //sets echo pin to an input
  pinMode(echoPinL, INPUT);
  pinMode(echoPinR, INPUT);

  //sets motor pins to outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  //starts the trig pin at low, waits, changes it to high, waits, changes it back to low
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPinL, LOW);

  delayMicroseconds(10);

  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPinR, LOW);

  //reads the duration the echo and converts the time into a distance in cm
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL * 0.034/2;

  durationR = pulseIn(echoPinR, HIGH);
  distanceR = durationR * 0.034/2;

  distanceAvg = (distanceL+distanceR)/2; //average distance between both sensors
  distanceDif = abs(distanceL-distanceR); //the difference in distance between both sensors

  //prints distance to serial monitor (for testing)
  Serial.print("DistanceL: ");
  Serial.print(distanceL);
  Serial.println(" cm");

  Serial.print("DistanceR: ");
  Serial.print(distanceR);
  Serial.println(" cm");

  if((distanceL > 100 || distanceL == 0) && (distanceR > 100 || distanceR == 0)) //if both sensors report a distance of 0cm or greater than 100cm - Idle
    move = 'I';
  else if(distanceDif <= 10) //else, if the sensors are reporting distances within 10cm of each other
  {
    if(distanceAvg <= 10) //if the average distance is less than 10cm (close to an obj) - Move backward
      move = 'B';
    else if(distanceAvg <= 30) //else, if the average distance is between 10cm and 30cm (close but not too close to an obj) - Move forward
      move = 'F';
    else //distance is greater than 30cm - Idle
      move = 'I';
  }
  else //sensors should have readings greater than 10cm apart
  {
    if(distanceL < distanceR) //if obj is closer to left sensor - Turn left
      move = 'L';
    else //obj should be closer to right sensor - Turn right
      move = 'R';
  }

switch(move)
{
  case 'F': //move forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("F");
    break;

  case 'B': //move backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("B");
    break;

  case 'L': //turn left
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("L");
    break;

  case 'R': //turn right
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("R");
    break;

  default: //idle
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("I");
}
  /*
  //movement backward when object within 10cm
  if(distanceL <= 10 && distanceR <= 10)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  //idle when object between between 10cm and 15cm
  else if(distanceL <= 15 && distanceR <= 15)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  //movement foward when object within 15cm and 45cm
  else if(distanceL <= 45 && distanceR <= 45)
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
 */

  /*
  short delay before looping. Breaks without it. 
  Why? No idea, but I do know that it works.
  */
  delay(5);
}
