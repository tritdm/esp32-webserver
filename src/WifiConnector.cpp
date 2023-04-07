#include "WifiConnector.h"

void setup_STAmode(const char* ssid, const char* password)
{
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected..!");
    Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
}

void setup_SAPmode(const char* ssid, const char* password, IPAddress local_ip, IPAddress gateway, IPAddress subnet)
{
    //WiFi.mode(WIFI_MODE_APSTA);
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);
}

void setupboth_SAPandSTAmode(const cha#include "WifiConnector.h"

void setup_STAmode(const char* ssid, const char* password)
{
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected..!");
    Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
}

void setup_SAPmode(const char* ssid, const char* password, IPAddress local_ip, IPAddress gateway, IPAddress subnet)
{
    //WiFi.mode(WIFI_MODE_APSTA);
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);
}

void setupboth_SAPandSTAmode(const char* ssid_STA, const char* password_STA,
                            const char* ssid_SAP, const char* password_SAP, IPAddress local_ip, IPAddress gateway, IPAddress subnet)
{
    //WiFi.mode(WIFI_MODE_APSTA);
    WiFi.softAP(ssid_SAP, password_SAP);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);
    Serial.printf("Connecting to %s ", ssid_STA);
    WiFi.begin(ssid_STA, password_STA);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected..!");
    Serial.print("Got IP: ");  Serial.println(WiFi.localIP());
}

