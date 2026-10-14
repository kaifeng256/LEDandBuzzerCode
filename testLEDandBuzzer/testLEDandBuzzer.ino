#include <Arduino.h>
#include "esp_idf_version.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include "pitches.h"

#define LEDPIN 5
#define LEDCHANNEL 1
#define LEDFREQ 5000
#define LEDRESOLUTION 8
#define BUZZER_PIN 15 // The Arduino pin connected to the buzzer


uint32_t delayMS;

// notes in the melody:
int melody[] = {
  NOTE_G4, NOTE_A3, NOTE_G4, NOTE_A3, NOTE_G4, NOTE_A3, NOTE_G4, NOTE_A3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8
};

// PWM DutyCycle
int brightness = 15;
void setup() {
  ledcAttachChannel(LEDPIN,LEDFREQ,LEDRESOLUTION,LEDCHANNEL);
  ledcWriteChannel(LEDCHANNEL, brightness);
}

void loop() {
  ledcWriteChannel(LEDCHANNEL, brightness);
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.40;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER_PIN);
  }
  
}
//Buzzer code adapted from: https://arduinogetstarted.com/tutorials/arduino-piezo-buzzer