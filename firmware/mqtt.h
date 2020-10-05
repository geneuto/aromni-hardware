#pragma once

#include <PubSubClient.h>
#include "wifi.h"

#define MQTT_BROKER "logicalis-eugeniostg-iothub.azure-devices.net"
#define MQTT_PORT   8883
#define MQTT_USER   "logicalis-eugeniostg-iothub.azure-devices.net/" DEVICE_ID "/api-version=2019-03-30"

#define MQTT_SUB_CLOUD_TO_DEVICE_TOPIC  "devices/" DEVICE_ID "/messages/devicebound/#"
#define MQTT_SUB_INVOKE_BASE_TOPIC      "$iothub/methods/POST/"
#define MQTT_SUB_INVOKE_TOPIC           "$iothub/methods/POST/#"

#define MQTT_PUB_INVOKE_REPLY_TOPIC     "$iothub/methods/res/{status_code}/?$rid={rid}"
#define MQTT_PUB_DEVICE_TO_CLOUD_TOPIC  "devices/" DEVICE_ID "/messages/events/"

PubSubClient client(net);

void
mqtt_client_callback(
  char *topic,
  byte *payload,
  unsigned int length
);

String
pubSubStatus(
  int8_t MQTTStatus
) {

  if (MQTTStatus == MQTT_CONNECTION_TIMEOUT)
    return "TIMEOUT";
  else if (MQTTStatus == MQTT_CONNECTION_LOST)
    return "CONEXÃO PERDIDA";
  else if (MQTTStatus == MQTT_CONNECT_FAILED)
    return "FALHOU";
  else if (MQTTStatus == MQTT_DISCONNECTED)
    return "DESCONCETADO";
  else if (MQTTStatus == MQTT_CONNECTED)
    return "CONECTADO";
  else if (MQTTStatus == MQTT_CONNECT_BAD_PROTOCOL)
    return "ERRO DE PROTOCOLO";
  else if (MQTTStatus == MQTT_CONNECT_BAD_CLIENT_ID)
    return "ERRO DE ID";
  else if (MQTTStatus == MQTT_CONNECT_UNAVAILABLE)
    return "INDISPONIVEL";
  else if (MQTTStatus == MQTT_CONNECT_BAD_CREDENTIALS)
    return "ERRO DE CREDENCIAIS";
  else if (MQTTStatus == MQTT_CONNECT_UNAUTHORIZED)
    return "NÃO AUTORIZADO";
  else
    return "DESCONHECIDO";

}

bool
mqttIsConnected(
) {
  return client.connected();
}

bool
mqttConnect(
) {
  bool result = true;

  if (client.connected()) {
    goto FINISH;
  }

  client.setServer(MQTT_BROKER, MQTT_PORT);
  client.setCallback(mqtt_client_callback);

  ledWaitingModeStart();
  Serial.print("Conectando ao mqtt - ");
  if (client.connect(DEVICE_ID, MQTT_USER, NULL)) {
    Serial.println(pubSubStatus(client.state()));
    if (!client.subscribe(MQTT_SUB_CLOUD_TO_DEVICE_TOPIC)) {
      Serial.printf( "Erro ao subscrever no topico %s - ", MQTT_SUB_CLOUD_TO_DEVICE_TOPIC);
      result = false;
      goto ERROR;
    } else {
      Serial.printf("Inscrito no topico %s\n", MQTT_SUB_CLOUD_TO_DEVICE_TOPIC);
    }
    if (!client.subscribe(MQTT_SUB_INVOKE_TOPIC)) {
      Serial.printf( "Erro ao subscrever no topico %s - ", MQTT_SUB_INVOKE_TOPIC);
      result = false;
      goto ERROR;
    } else {
      Serial.printf("Inscrito no topico %s\n", MQTT_SUB_INVOKE_TOPIC);
    }

    ledWaitingModeStop();
    goto FINISH;
  } else {
    Serial.println(pubSubStatus(client.state()));
    result = false;
  }

ERROR:
  client.disconnect();
FINISH:
  return result;
}

void
mqtt_publish(
  char *payload
) {
  if (client.connected()) {
    if (!client.publish(MQTT_PUB_DEVICE_TO_CLOUD_TOPIC, payload)) {
      Serial.printf("Erro ao publicar no topico %s - %s\r\n",
                    MQTT_PUB_DEVICE_TO_CLOUD_TOPIC ,
                    pubSubStatus(client.state()));
    } else {
      Serial.printf("Mensagem publicada no topico %s: \r\n%s\r\n",
                    MQTT_PUB_DEVICE_TO_CLOUD_TOPIC ,
                    payload);
    }
  } else {
    Serial.println("Mqtt desconectado");
  }
}

void
mqtt_client_callback(
  char *topic,
  byte *payload,
  unsigned int length
) {

}
