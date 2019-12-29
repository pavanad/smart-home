# Device firmware

## Social Gate

### Hardware

Relay Module Based ESP8266 ESP-01

### Software

Arduino framework with vscode and PlatformIO

### How to use

```
git clone
```

Change file **MQTTConfig.h** with configurations of the MQTT Broker

```c++
#ifndef MQTT_CONFIGURATION_H
#define MQTT_CONFIGURATION_H

#define MQTT_USERNAME ""
#define MQTT_PASSWORD ""

const unsigned short MQTT_PORT = 1883; // port of the Broker MQTT
const char *MQTT_SERVER = "";          // IP or DNS of the Broker MQTT
const char *MQTT_STATE_TOPIC = "";     // device publish
const char *MQTT_COMMAND_TOPIC = "";   // device subscriber

#endif
```

Build and upload esp8266 board