// TODO - test for known currents (seems to be working at 0-100mA)

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
}

void loop() {

  // Toggle Power to LED Pin
  digitalWrite(LED, !digitalRead(LED));

  // Display
  Serial.print("LED Status: ");
  Serial.println(digitalRead(LED));

  Serial.println("Fn 1:");
  float current = getCurrent();

  Serial.println();

  // delay 
  delay(1000);

}

