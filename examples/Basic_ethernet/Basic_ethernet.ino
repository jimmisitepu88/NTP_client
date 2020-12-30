#include <SPI.h>
#include <Ethernet.h>
#include <HTTPClient.h>
#include <NTPClient.h>
#include <EthernetUdp.h>

EthernetUDP Udp_eth;
NTPClient timeClient(Udp_eth, "pool.ntp.org", 25200, 60000);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 1, 20};
byte dns[] = {255, 255, 255, 0};

void setup(){
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(5000);
  Serial.begin(115200);
  Serial.println("mulai membaca ntp");
  
  Ethernet.init(5);
  Ethernet.begin(mac, ip);
  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFullFormattedTime());

  delay(1000);
}
