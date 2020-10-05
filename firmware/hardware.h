#pragma once

#include <hcsr04.h>

#define TRIG_PIN 4
#define ECHO_PIN 5

hw_timer_t *timer = NULL;
bool ledIncBright = true;

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

#define LED_PIN 26
#define FAN_PIN 19

static uint16_t  ledBright = 0;

void setLedBright(
  uint16_t value
) {
  if (value > 1023) {
    ledBright = 1023;
  } else {
    ledBright = value;
  }

  ledcWrite(0, ledBright);
}

bool
increaseLedBright(
  uint8_t value
) {
  if ( ledBright + value < 1023) {
    ledBright += value;
    ledcWrite(0, ledBright);
    return true;
  } else {
    ledBright = 1023;
    ledcWrite(0, ledBright);
    return false;
  }
}

bool
decreaseLedBright(
  uint16_t value
) {
  if ( ledBright > value ) {
    ledBright = ledBright - value;
    ledcWrite(0, ledBright);
    return true;
  } else {
    ledBright = 0;
    ledcWrite(0, ledBright);
    return false;
  }
}

void 
hardwareSetup(
) {

  Serial.begin(115200);
  delay(1000);

  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  ledcAttachPin(LED_PIN, 0);
  ledcSetup(0, 1000, 10);

}

void
ledWaitingModeTask(
) {
  if ( ledIncBright ) {
    if ( !increaseLedBright(10) ) {
      ledIncBright = false;
    }
  }
  else {
    if ( !decreaseLedBright(10)) {
      ledIncBright = true;
    }
  }
}

void
ledWaitingModeStop(
) {
  if (timer != NULL) {
    timerEnd(timer);
    timer = NULL;
  }
  setLedBright(0);
}

void
ledWaitingModeStart(
) {

  if ( timer != NULL) {
    ledWaitingModeStop();
    delay(100);
  }

  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &ledWaitingModeTask, true);
  timerAlarmWrite(timer, 10000, true);
  timerAlarmEnable(timer);

}

void 
activateFan(
) {
  digitalWrite(FAN_PIN, HIGH);
  delay(2000);
  digitalWrite(FAN_PIN, LOW);
}

long
getDistance(
) {
  long dist = hcsr04.distanceInMillimeters();
  if (dist < 0) {
    dist = 0;
  }
  return dist;
}
