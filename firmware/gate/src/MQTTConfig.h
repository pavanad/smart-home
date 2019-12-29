#ifndef MQTT_CONFIGURATION_H
#define MQTT_CONFIGURATION_H

#define MQTT_USERNAME ""
#define MQTT_PASSWORD ""

const unsigned short MQTT_PORT = 1883; // port of the Broker MQTT
const char *MQTT_SERVER = "";          // IP or DNS of the Broker MQTT
const char *MQTT_STATE_TOPIC = "";     // device publish
const char *MQTT_COMMAND_TOPIC = "";   // device subscriber

#endif