/*
  arduino-nano-halloween-skull

  A halloween skull mask with a sensor activated moving jaw.

  Copywrite 2020 Peter Milne
  License: GPL-3.0 License
*/

#include <Servo.h>

// Pin numbering
const byte PIR = 20;
const byte LED = 3;
const byte SERVO = 4;

// Servo settings - adjust to suit servo
const byte CENTRE = 90;
const byte CLOCKWISE_MAX = 45;

Servo servo;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  servo.attach(SERVO);
  servo.write(CENTRE);  // Start with closed jaw
  delay(1000);
}

void loop() {
  // Check the PIR sensor
  byte state = digitalRead(PIR);
  digitalWrite(LED, state);

  if (state) { // If sensor is triggered
    long randNumber = CENTRE - random(CLOCKWISE_MAX); // Randomise jaw position
    // Open jaw
    for (byte position = CENTRE; position >= randNumber; position -= 2) {
      servo.write(position);

      delay(15);
    }
    // Close jaw
    for (byte position = randNumber; position <= CENTRE; position += 2) {
      servo.write(position);
      delay(15);
    }
  }
}
