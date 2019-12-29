#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define RELAY 4

// name of the device
const String HOSTNAME = "SocialGate";

unsigned char relayOn[] = {0xA0, 0x01, 0x00, 0xA1};
unsigned char relayOff[] = {0xA0, 0x01, 0x01, 0xA2};

#endif