/*

 */

#include "Waveforms.h"
#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds

int sample = 4900; // Testing shows a 100us delay for squarewave falling edge - this produces exactly a 5ms, 5V squarewave signal
int triggered = 0;

void setup() {
  Serial.begin(9600);
  //Serial.println("<Arduino is ready>");
  delay(1500);

  // NOTE: the analog input here is set to 0 but can be any unconnected input.  The Arduino "noise" fluctuations for this unconnected terminal will provide a random starting point for the Arduino randNumber() algorithm.
  // This prevents us from getting the same random sequence every time the software runs.  If it's preferred to get the same random sequence each time, simply replace analogRead(0) with any constant value.
  randomSeed(analogRead(0));
}

void loop() {

  // Every iteration of this function should produce a new random number in the specified range.
  // NOTE: NEED TO SCALE THE BELOW RANDOM RANGES FOR DESIRED VALUES - currently it will choose between 0-1000 milliseconds.
    rand = random(0, 1000);
    delay(rand);
    
        // Uncomment below if you need to see "Firing!" in the serial port for testing.
        // Serial.println("Firing!");
        for (int i = 0; i < 2; i++) {
          analogWrite(12, waveformsTable[3][i]);
        }
        
          float amplitude = waveformsTable[3][i];

          // Recording time at which the pulse occurred in milliseconds from program start
          float milliseconds = millis();

          Serial.print(milliseconds);
          
          delayMicroseconds(sample);  // Hold the sample value for the sample time

          //Uncomment the below lines if it's necessary
          //Serial.print(",");
          //Serial.println(amplitude);
        
    
}
