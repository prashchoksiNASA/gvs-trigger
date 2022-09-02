/*

 */

#include "Waveforms.h"
#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds

int sample = 4900; // Testing shows a 100us delay for squarewave falling edge - this produces exactly a 5ms, 5V squarewave signal
int triggered = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  delay(1500);
}

void loop() {
  if (Serial.available()) {
      if (triggered == 0) {
        Serial.println("Firing!");
        for (int i = 0; i < 2; i++) {
          analogWrite(12, waveformsTable[3][i]);      
          delayMicroseconds(sample);  // Hold the sample value for the sample time
        }
        
        triggered = 1;
        
        // May be able to remove this section, as the randomized trigger will probably be handled by other code (Inquisit, Python, C++, etc.)
        Serial.println("Cooldown Started");
        Serial.end();
        delay(5000); // in ms
        Serial.begin(9600);
        Serial.println("Cooldown Ended");
        triggered = 0;    
    }
  }
}
