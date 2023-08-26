
#include <Arduino.h>
#include "globals.h"

// Get Current
float getCurrent() {
  /*
  For N analog samples:
  - take analog reading
  - scale to an actual mV with the ADC resolution
  - I = V / sensitivity to get the equivalent in amps
  - Average those and subtract any offset "no load" measured current that we setup when the board booted up (e.g. for temperature or board noise)
  */
  static int Vref = 5;
  static int ADC_RES = 8;
  static float Vq_ = 0.5; // 0A output voltage as proportion of Vref, from Vout vs Primary Current from datasheet
  static int Verr= 0; // Calibration/Correction output voltage TODO - determine via testing - this is fixed voltage error not "startup/boot" zero current error
  static int sensitivity = 22; // mv per A per datasheet
  int samples = 100;
  int reading;
  float voltage, current;
  float avgCurrent = 0;

  for(int i=0; i < samples; i++) {
    // Loop for N samples 
    reading = analogRead(SENSOR_PIN);
    Serial.print("Raw: "); Serial.print(reading); Serial.print(" | ");
    delay(2);

    // Transform Raw Voltage Output → "real" Volts → Current
    voltage = (reading) * (Vref /  (pow(2,ADC_RES)-1)) - ( Vq_ * Vref) + Verr; 
    Serial.print("V: "); Serial.println(voltage);
    current = voltage / sensitivity;

    // Sum For Averaging
    avgCurrent += current;
  }

  avgCurrent /= samples; 
  // TODO - subtract startup zero current measurement if nec.

  return avgCurrent; 
}
