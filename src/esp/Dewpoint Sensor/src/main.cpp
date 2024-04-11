#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "PubSubClient.h"
#include "SHT85.h"
#include "../include/conf.h"

WiFiClient espClient;
PubSubClient client(espClient);

#define MSG_BUFFER 50
char msg[MSG_BUFFER];

#define SHT85_ADDRESS         0x44
SHT85 sht(SHT85_ADDRESS);

float temp = 0;
float hum = 0;

long lastMillisSend = 0;

void setup_wifi();

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  int shtCheck = -1;
  while(shtCheck != 0)
  {
    Wire.begin();
    Wire.setClock(100000);
    sht.begin();
    shtCheck = sht.getError();
    Serial.println(shtCheck);
  }
  delay(1000);
  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void readSensor()
{
  sht.read();   
  temp = sht.getTemperature();  
  hum = sht.getHumidity();
}

void sendData()
{  
  snprintf(msg, MSG_BUFFER, "{\"t\":%.1f,\"h\":%.1f}", temp, hum);
  client.publish("sensor_indoor", msg);
  //client.publish("indoor_sensor/humidity", humStr);
}

void loop()
{
  if(WiFi.status() != WL_CONNECTED){
    setup_wifi();
  }

  if(!client.connected())
  {
    reconnect();
  }
  client.loop();

  readSensor();
  Serial.print("T: ");
  Serial.print(temp);
  Serial.print("H: ");
  Serial.println(hum);

  sendData();
  delay(500);
  ESP.deepSleep(5*(60e6));
  
}


//  -- END OF FILE --