
#include <Arduino.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#include "Config.h"
#include "MQTTConfig.h"

WiFiClient wifiClient;
PubSubClient client(MQTT_SERVER, MQTT_PORT, wifiClient);

// prototype function
void mqttCallback(char *topic, byte *payload, unsigned int length);

void setup()
{
    // init serial
    Serial.begin(9600);

    // set pin modes
    pinMode(RELAY, OUTPUT);

    // init WifiManager
    WiFiManager wifiManager;
    wifiManager.setTimeout(180);
    wifiManager.autoConnect(HOSTNAME.c_str());

    // function that will respond to messages coming from MQTT
    client.setCallback(mqttCallback);
}

void toggleRelay()
{
    Serial.write(relayOn, RELAY);
    delay(1000);
    Serial.write(relayOff, RELAY);
    delay(1000);
    Serial.write(relayOn, RELAY);
}

/**
 * Messega receive call.
 */
void mqttCallback(char *topic, byte *payload, unsigned int length)
{
    String payloadStr = "";
    for (unsigned int i = 0; i < length; i++)
    {
        payloadStr += (char)payload[i];
    }
    String topicStr = String(topic);
    if (topicStr.equals(MQTT_COMMAND_TOPIC))
    {
        Serial.println(payloadStr);
        if (payloadStr.equals("ON"))
        {
            toggleRelay();

            // case set state ON in broker use the below command
            // client.publish(MQTT_STATE_TOPIC, "ON", true);
        }

        // this device is a pulse switcher and not work with state off
        // else if (payloadStr.equals("OFF"))
        // {
        //     digitalWrite(RELAY, LOW);
        //     client.publish(MQTT_STATE_TOPIC, "OFF", true);
        // }
    }
}

/**
 * Check if the connection is active and if not try to connect
 */
bool checkMqttConnection()
{
    if (!client.connected())
    {
        if (client.connect(HOSTNAME.c_str(), MQTT_USERNAME, MQTT_PASSWORD))
        {
            Serial.println("Connected to MQTT Broker " + String(MQTT_SERVER));
            client.subscribe(MQTT_COMMAND_TOPIC);
        }
    }
    return client.connected();
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        if (checkMqttConnection())
        {
            client.loop();
        }
    }
}