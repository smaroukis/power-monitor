
#include "helper.h"
#include "globals.h"
#include <Arduino.h>

float zeroCurrent;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);

  // TODO - sensor 0A configuration
  zeroCurrent = getCurrent();
  Serial.print("Zero Current: ");
  Serial.println(zeroCurrent);
  Serial.println();
}

void loop() {
  static float current;

  // Toggle Power to LED Pin
  digitalWrite(LED, !digitalRead(LED));

  // read data from Analog pin
  current = getCurrent();

  // Display
  Serial.print("LED Status: ");
  Serial.print(digitalRead(LED));
  Serial.print("\t | Sensor Val: ");
  Serial.println(current);

  // delay 
  delay(1000);

}

