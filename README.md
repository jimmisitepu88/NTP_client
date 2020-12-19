# NTPClient

[![Build Status](https://travis-ci.org/arduino-libraries/NTPClient.svg?branch=master)](https://travis-ci.org/arduino-libraries/NTPClient)

Connect to a NTP server, here is how:

```cpp
#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>

const char *ssid     = "YOUR_SSID_WIFI";
const char *password = "YOUR_PASS_WIFI";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 25200, 60000);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFullFormattedTime());

  delay(1000);
}
```
