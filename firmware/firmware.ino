
#include "wifi.h"
#include "ntp.h"
#include "mqtt.h"
#include "hardware.h"

long lastMessageTime = 0;
long lastMeasure = millis();
long lastActivation = millis() - 30000;

void
sendHeartBeat(
) {

  if (lastMessageTime == 0 ||
      millis() - lastMessageTime > (60000) ) {

    char payload[MSG_SIZE] = {0};

    messageGenerator(payload, true);

    mqtt_publish(payload);

    lastMessageTime = millis();

  }
}

void
sendMessage(
) {
  char payload[MSG_SIZE] = {0};
  messageGenerator(payload, false);
  mqtt_publish(payload);
  lastMessageTime = millis();
}

void setup() {

  hardwareSetup();

  //Debug Fan
  //  while(1){
  //    activateFan();
  //    delay(2000);
  //  }

  Serial.println(" ");
  Serial.println(" ");
  Serial.println(VERSION);
  Serial.println(" ");

}

void loop() {

  now = time(nullptr);

  while ( !wifiConnect() || !mqttConnect() ) {
    Serial.println("Nova tentativa em 5 segundos");
    delay(5000);
  }

  client.loop();

  sendHeartBeat( );

  if ( millis() - lastMeasure > 250 &&
       millis() - lastActivation > 30000 ) {

    setLedBright(1000);
    long mm = getDistance();
    Serial.printf("distancia: %ld\n", mm);
    int count = 0;
    while ( mm > 50 && mm < 200 ) {

      if ( count == 2 ) {
        setLedBright(0);
        lastActivation = millis();
        activateFan();
        sendMessage();
        break;
      }

      mm = getDistance();
      count++;

      delay(250);
    }

    lastMeasure = millis();
  }
}
