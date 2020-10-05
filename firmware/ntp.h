#pragma once

#define UTC_TIME_ZONE_BRAZIL_HOURS -3
#define UTC_TIME_ZONE_BRAZIL_SECONDS UTC_TIME_ZONE_BRAZIL_HOURS * 3600
#define DST_HOURS 0
#define DST_SECONDS DST_HOURS * 3600
#define CURRENT_TIME_APROXIMATION_AS_EPOCH_SECONDS 1510592825
#define NTP_SERVER_0 "pool.ntp.org"
#define NTP_SERVER_1 "time.nist.gov"

time_t now;
time_t nowish = CURRENT_TIME_APROXIMATION_AS_EPOCH_SECONDS;
long lastSetup = 0;

void
NTPSetup(
) {
  if ( lastSetup != 0 &&
       millis() - lastSetup < ( 1 * 60 * 60 * 1000 )) { //atualiza a cada hora
    return;
  }

  Serial.println("Ajustando Data/Hora.");

  // Configure the NTP servers
  configTime( UTC_TIME_ZONE_BRAZIL_SECONDS,
              DST_SECONDS,
              NTP_SERVER_0,
              NTP_SERVER_1);

  // Wait for the current time to be updated
  now = time(nullptr);
  while (now < nowish) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }

  Serial.println(" ");

  lastSetup = millis();

}
