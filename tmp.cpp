#include <Arduino.h>
#include "WifiAndWebServer.h"
#include "NTPServer.h"

const char* ssid_STAmode       = "FPT QuocPhuong";
const char* password_STAmode   = "0908893146";

const char* ssid_SAPmode       = "ESP32";
const char* password_SAPmode   = "matkhaudai16kytu";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

char timeWeekday[10], timeDay[3], timeMonth[9], timeYear[5], timeHour[3], timeMinute[3], timeSecond[3];

void printLocalTime()
{
    NTPServer::getInstance()->NTPServer_GetTime(timeWeekday, timeMonth, timeDay, timeYear, timeHour, timeMinute, timeSecond);
    Serial.print(timeWeekday);
    Serial.print(timeMonth);
    Serial.print(timeDay);
    Serial.print(timeYear);
    Serial.print(timeHour);
    Serial.print(timeMinute);
    Serial.println(timeSecond);
}

void setup()
{
    Serial.begin(115200);
  
    //connect to WiFi
    //setup_SAPmode(ssid_SAPmode, password_SAPmode, local_ip, gateway, subnet);
    setupboth_SAPandSTAmode(ssi#include <Arduino.h>
#include "WifiAndWebServer.h"
#include "NTPServer.h"

const char* ssid_STAmode       = "FPT QuocPhuong";
const char* password_STAmode   = "0908893146";

const char* ssid_SAPmode       = "ESP32";
const char* password_SAPmode   = "matkhaudai16kytu";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

char timeWeekday[10], timeDay[3], timeMonth[9], timeYear[5], timeHour[3], timeMinute[3], timeSecond[3];

void printLocalTime()
{
    NTPServer::getInstance()->NTPServer_GetTime(timeWeekday, timeMonth, timeDay, timeYear, timeHour, timeMinute, timeSecond);
    Serial.print(timeWeekday);
    Serial.print(timeMonth);
    Serial.print(timeDay);
    Serial.print(timeYear);
    Serial.print(timeHour);
    Serial.print(timeMinute);
    Serial.println(timeSecond);
}

void setup()
{
    Serial.begin(115200);
  
    //connect to WiFi
    //setup_SAPmode(ssid_SAPmode, password_SAPmode, local_ip, gateway, subnet);
    setupboth_SAPandSTAmode(ssid_STAmode, password_STAmode, ssid_SAPmode, password_SAPmode, local_ip, gateway, subnet);

    //init and get the time
    NTPServer::getInstance()->NTPServer_Setup();
    //printLocalTime();

}

void loop()
{
    delay(1000);
    printLocalTime();
}

#include <Arduino.h>
#include <WebServer.h>
#include "WifiConnector.h"
#include "index.h"

int temperature, humidity, pressure, altitude;

/*Put your SSID & Password*/
const char* ssid = "Mike";  // Enter SSID here
const char* password = "Tri25082002";  //Enter Password here

WebServer server(80);

void handle_OnConnect();
void handle_NotFound();
void handle_update();


void TaskSensorRead(void *pvParameters);
void TaskWebServerHandle(void *pvParameters);


void setup(void) 
{
    Serial.begin(115200);
    delay(100);

    setup_STAmode(ssid, password);

    server.on("/", handle_OnConnect);
    server.on("/update", handle_update);
    server.onNotFound(handle_NotFound);
    server.begin();
   
    Serial.println("HTTP server started");

    xTaskCreatePinnedToCore(TaskSensorRead, "Sensor Read", 1024, NULL, 2 , NULL , 0);
    xTaskCreatePinnedToCore(TaskWebServerHandle, "WebServer Handle", 8192, NULL, 1 , NULL , 0);
}

void loop(void) 
{
    
}

void TaskSensorRead(void *pvParameters) 
{
    (void) pvParameters;
 
    for (;;)
    {
        /* sensor read */
        temperature = touchRead(13);
        humidity = touchRead(12);
        pressure = touchRead(14);
        altitude = touchRead(27);
        /* print out read values*/
        Serial.print("temperature: ");
        Serial.println(temperature);
        Serial.print("humidity: ");
        Serial.println(humidity);
        Serial.print("pressure: ");
        Serial.println(pressure);
        Serial.print("altitude: ");
        Serial.println(altitude);
        /* delay between reads for stability */
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void TaskWebServerHandle(void *pvParameters) 
{
    (void) pvParameters;

    for (;;) 
    {
        server.handleClient();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void handle_OnConnect()
{
    temperature = touchRead(13);
    humidity = touchRead(12);
    pressure = touchRead(14);
    altitude = touchRead(27);
    String index = html;
    server.send(200, "text/html", index); 
}
void handle_NotFound()
{
    server.send(404, "text/plain", "Not found");
}
void handle_update()
{
    String a, b, c, d, m;
    a = String(temperature);
    b = String(humidity);
    c = String(pressure);
    d = String(altitude);
    m = a + b + c + d;
    server.send(200, "text/plain", m);
}
