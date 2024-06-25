// Author: Wei Ting Teo
// Uses HX711 Library written by Bogdan Necula
#include <HX711.h>


// Define system I/O pins
#define DOUT  2
#define CLK  3

// Initialise ADC Load Cell object
HX711 scale;

// Global parameters
float calibration_factor = -69100; // Do not change this!!! This has been callibrated for the current setup 


void setup() {
 
  Serial.begin(115200);

  // Begin load cell operation
  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loop() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print(scale.get_units(), 2);
  Serial.print(" N"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  Serial.println();

  
}