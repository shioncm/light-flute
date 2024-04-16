/*
  Example of BH1750 library usage. This example initialises the BH1750 object using the default high resolution continuous mode and then makes a light level reading every second.
*/

#include <Wire.h>
#include <BH1750.h>

BH1750 LM1;
BH1750 LM2;
BH1750 LM3;
BH1750 LM4;

#define THRESHHOLD 200

// Select I2C BUS
void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
  Serial.print(bus);
}

void setup(){
  Serial.begin(9600);

  // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  
  TCA9548A(2); // Init sensor on bus number 2
  if (!LM1.begin(0x76)) {
    Serial.println("Could not find a valid light sensor on bus 2, check wiring!");
    while (1);
  }
  Serial.println("BH1750 1 initialised");
  
  TCA9548A(3); // Init sensor on bus number 3
  if (!LM2.begin(0x76)) {
    Serial.println("Could not find a valid light sensor on bus 3, check wiring!");
    while (1);
  }
  Serial.println("BH1750 2 initialised");
  
  TCA9548A(4); // Init sensor on bus number 4
  if (!LM3.begin(0x76)) {
    Serial.println("Could not find a valid light sensor on bus 4, check wiring!");
    while (1);
  }
  Serial.println("BH1750 3 initialised");
  
  TCA9548A(5); // Init sensor on bus number 5
  if (!LM4.begin(0x76)) {
    Serial.println("Could not find a valid light sensor on bus 5, check wiring!");
    while (1);
  }
  Serial.println("BH1750 4 initialised");
}

void loop() {
  float lux1 = LM1.readLightLevel();
  float lux2 = LM2.readLightLevel();
  float lux3 = LM3.readLightLevel();
  float lux4 = LM4.readLightLevel();

  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);

  if (lux1 > THRESHHOLD){
    // note
  }
  if (lux1 > THRESHHOLD){
    // note
  }
  if (lux1 > THRESHHOLD){
    // note
  }
  if (lux1 > THRESHHOLD){
    // note
  }
}



#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {

  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
}

void loop() {

  // no need to repeat the melody.
}
