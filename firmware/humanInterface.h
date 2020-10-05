//#pragma once
//
//
//#define LIST_SIZE 500
//
//#define MIN_DIST 30
//#define MAX_DIST 250
//
//#define CHECK_FREQ 4
//
//TaskHandle_t hiTask;
//
////lista circular de mensagens
//String msglist[LIST_SIZE];
//int msgCount = 0;
//
//long lastCheck = 0;
//
//bool
//checkDistance(
//) {
//
//  if ( millis() - lastCheck < 1000 / CHECK_FREQ ) {
//    return false;
//  }
//  long dist = hcsr04.distanceInMillimeters();
//
//  if ( dist > MIN_DIST && dist < MAX_DIST ) {
//    char payload[MSG_SIZE] = {0};
//
//    messageGenerator(payload, true);
//
//    //adiciona mensagem
//  }
//}
//
//void
//humanInterfaceTask(
//  void *parameter
//) {
//
//  long ledTime = millis();
//  uint16_t ledControl = 0;
//  bool ledIncreasing = true;
//
//  pinMode(LED_PIN, OUTPUT);
//  ledcAttachPin(LED_PIN, 0);
//  ledcSetup(0, 1000, 10);
//
//
//  while (true) {
//
//    //controle do brilho do led enquanto mqtt não conectado
//    if ( !mqttIsConnected()) {
//      if ( millis() - ledTime > 50 ) {
//        if ( ledIncreasing ) {
//          if ( ledControl < 1024 ) {
//            ledControl ++;
//          } else {
//            ledIncreasing = false;
//          }
//        } else {
//          if ( ledControl > 0 ) {
//            ledControl --;
//          } else {
//            ledIncreasing = true;
//          }
//        }
//        ledTime = millis();
//        ledcWrite(0, ledControl);
//      }
//      
//    } else {
//      ledcWrite(0, 0);
//    }
//
//    delay(10);
//
//  }
//}
//
//bool
//msgAvailable(
//) {
//  if ( msgCount > 0 ) {
//    return true;
//  } else {
//    return false;
//  }
//}
