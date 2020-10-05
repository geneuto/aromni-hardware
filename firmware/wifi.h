#pragma once

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "hardware.h"
#include "secrets.h"
#include "ntp.h"

WiFiClientSecure net;

bool
wifiConnect(
) {
  bool result = true;
  long timeout = millis();
  bool ledIncreasing = true;

  if ( WiFi.status() == WL_CONNECTED ) {
    goto FINISH;
  }

  WiFi.setHostname(DEVICE_ID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.printf("Conectando a rede: %s\n", WIFI_SSID);

  ledWaitingModeStart();
  
  while (millis() - timeout < 20000 ) {
    if ( WiFi.status() != WL_CONNECTED ) {
      Serial.print(".");
      delay(500);
    } else {
      break;
    }
  }
  
  ledWaitingModeStop();

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("\nFalha na conexão - TIME OUT");
    result = false;
    goto ERROR;
  } else {
    Serial.println("\nConectado");
  }

  net.setCACert(cacert);
  net.setCertificate(client_cert);
  net.setPrivateKey(privkey);

FINISH:
  NTPSetup();
ERROR:
  return result;
}
