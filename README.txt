# Haunted-Mechanics-Robot
Code for Group 14's, Haunted Mechanics, ENG3000L Robot

Fab_Code_Ultrasonic.ion is the main, and only, code file for the Arduino robot
It should be placed in a folder of the same name, "Fab_Code_Ultrasonic", before being uploaded to an Arduino board

Functionality:
An untrasonic sensor sends out a short pulse. The time it takes to revieve the reflected pulse is converted into a distance in centimeters
  This distance is printed in the serial monitor of the Arduino IDE if connected to a computer
After caculating the distance from an object the robot will move forward, backward, or remain idle
  obj <= 10cm - backward
  10cm <= obj <= 15cm - idle
  15cm <= obj <= 45cm - forward
  obj <= 45cm - idle
Comments are provided on each block of code to provide further explaniation of each line's functionality
