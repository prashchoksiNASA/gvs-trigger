#include "Waveforms.h"
#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds

int sample = 4900; // Testing shows a 100us delay for squarewave falling edge - this produces exactly a 5ms, 5V squarewave signal
int triggered = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

}

void loop() {

  // Every iteration of this function should produce a new random number in the specified range.
  // NOTE: NEED TO SCALE THE BELOW RANDOM RANGES FOR DESIRED VALUES MILLISECONDS
  long rand = random(15000, 120000);
  delay(rand);


  // Recording time at which the pulse occurred in milliseconds from program start
  float milliseconds = millis();
  Serial.println(milliseconds);

  for (int i = 0; i < 3; i++) {
    analogWrite(12, waveformsTable[3][i]);

    if (i == 1) {
      delayMicroseconds(sample);  // Hold the sample value for the sample time
    }

  }
  // Uncomment the below lines if it's necessary
  // int amplitude = waveformsTable[3][1];
  // Serial.print(",");
  // Serial.println(amplitude);

}
