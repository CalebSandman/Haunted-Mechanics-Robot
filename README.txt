# Haunted-Mechanics-Robot
Code for Group 14's, Haunted Mechanics, ENG3000L Robot

Fab_Code_Ultrasonic.ion is the main, and only, code file for the Arduino robot
It should be placed in a folder of the same name, "Fab_Code_Ultrasonic", before being uploaded to an Arduino board

Functionality:
Two untrasonic sensors send out a short pulse. The time it takes to revieve the reflected pulse is converted into a distance in centimeters
  This distance is printed in the serial monitor of the Arduino IDE if connected to a computer
After caculating the distance from an object and the average and difference between both sensor's readings the robot will move forward, backward, turn left, turn right, or remain idle

Two code files are provided
  Fab_Code_Ultrasonic_Turning.ino requires TWO ultrasonic sensors and has turning functionality (will continue to be updated as required)
  Fab_Code_Ultrasonic.ino requires ONE ultrasonic sensor and does NOT have turning functionality (will not be updated)
Comments are provided on each block of code to provide further explaniation of each line's functionality
