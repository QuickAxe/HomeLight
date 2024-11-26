#include "secrets.h"


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define lightPin 2

BLYNK_CONNECTED() {
    Blynk.syncAll();
    Serial.println("States synced with the cloud\n");
}

BLYNK_WRITE(V0) {
    // any code you place here will execute when the virtual pin value changes
    Serial.print("Blynk.Cloud is writing something to V0");

    int light = param.asInt();
    Serial.printf("value of v0: %d\n", light);
   
    if(light)
        digitalWrite(lightPin, HIGH);
    else
        digitalWrite(lightPin, LOW);
}

void setup() {
    // Debug console
    Serial.begin(9600);
    pinMode(lightPin, OUTPUT);

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


void loop() {
    Blynk.run();
}
