#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void setup_STAmode(const char* ssid, const char* password);
void setup_SAPmode(const char* ssid, const char* password, IPAddress local_ip, IPAddress gateway, IPAddress subnet);
void setupboth_SAPandSTAmode(const char* ssid_STA, const char* password_STA,
                            const char* ssid_SAP, const char* password_SAP, IPAddress local_ip, IPAddress gateway, IPAddress subnet);

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        #ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void setup_STAmode(const char* ssid, const char* password);
void setup_SAPmode(const char* ssid, const char* password, IPAddress local_ip, IPAddress gateway, IPAddress subnet);
void setupboth_SAPandSTAmode(const char* ssid_STA, const char* password_STA,
                            const char* ssid_SAP, const char* password_SAP, IPAddress local_ip, IPAddress gateway, IPAddress subnet);

#endif