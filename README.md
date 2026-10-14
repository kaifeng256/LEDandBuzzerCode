# LEDandBuzzerCode
Basic code for an ESP32 that drives LEDs and Buzzers. 

How to Use: 
Run testLEDandBuzzer.ino in the arduino IDE
Ensure that the LED power is in Pin 5 of the ESP32. 
Ensure that the Data pin of the Active Buzzer is connected to pin 15 of the ESP32

Note: 
Make sure that pitches.h is open in another tab of the arduino IDE, since the main code includes it and takes the constants that are referenced in int melody[]. 

The buzzer code and pitches.h is adapted from example code in this website: https://arduinogetstarted.com/tutorials/arduino-piezo-buzzer.
(Example code is in the public domain)
