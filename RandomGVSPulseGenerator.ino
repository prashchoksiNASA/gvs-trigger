#include <WiFiNINA.h>
#include <ArduinoMqttClient.h>
#include "Waveforms.h"
#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds

int sample = 4900; // Testing shows a 100us delay for squarewave falling edge - this produces exactly a 5ms, 5V squarewave signal
int triggered = 0;

char ssid[] = "js-er-psion-ng_2G";
char pass[] = "psion_lab_123";
char mqtt_server[] = "10.20.8.126";
char mqtt_topic[] = "psion/data/gvs-fire";

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);


int status = WL_IDLE_STATUS;


void setup() {
  Serial.begin(9600);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // connect to client
  if (!mqttClient.connect(mqtt_server,1883)){
    Serial.print("MQTT Connection failed");
  } else {
    Serial.print("MQTT Client connected");
  }

  mqttClient.subscribe(mqtt_topic);

  randomSeed(analogRead(0));

}

void trigger(){
  
  // Recording time at which the pulse occurred in milliseconds from program start
  float milliseconds = millis();
  Serial.println(milliseconds);

  for (int i = 0; i < 3; i++) {
    analogWrite(12, waveformsTable[3][i]);

    if (i == 1) {
      delayMicroseconds(sample);  // Hold the sample value for the sample time
    }
  }
}
void loop() {
  
  // check if received message, then fire
  int messageSize = mqttClient.parseMessage();
  if (messageSize){
    trigger();
  }

  
  // Every iteration of this function produces a new random number in the specified range of the random() argument in milliseconds.
  // long rand = random(15000, 120000);
  // delay(rand);

  // Uncomment the below lines if it's necessary
  // int amplitude = waveformsTable[3][1];
  // Serial.print(",");
  // Serial.println(amplitude);


  }
