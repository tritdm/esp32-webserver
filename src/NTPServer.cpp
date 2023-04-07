#include "NTPServer.h"

NTPServer::NTPServer() 
{

}

NTPServer::~NTPServer() 
{
    
}

void NTPServer::NTPServer_Setup(void) 
{
    configTime(NTPServer::gmtOffset_sec, NTPServer::daylightOffset_sec, NTPServer::ntpServer);
}

void NTPServer::NTPServer_GetTime(char *timeWeekday, char *timeMonth, char *timeDay, char *timeYear, 
                                    char *timeHour, char *timeMinute, char *timeSecond) 
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("F#include "NTPServer.h"

NTPServer::NTPServer() 
{

}

NTPServer::~NTPServer() 
{
    
}

void NTPServer::NTPServer_Setup(void) 
{
    configTime(NTPServer::gmtOffset_sec, NTPServer::daylightOffset_sec, NTPServer::ntpServer);
}

void NTPServer::NTPServer_GetTime(char *timeWeekday, char *timeMonth, char *timeDay, char *timeYear, 
                                    char *timeHour, char *timeMinute, char *timeSecond) 
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return;
    }
    strftime(timeWeekday, 10, "%A", &timeinfo);
    strftime(timeMonth  , 9, "%B", &timeinfo);
    strftime(timeDay    , 3, "%d", &timeinfo);
    strftime(timeYear   , 5, "%Y", &timeinfo);
    strftime(timeHour   , 3, "%H", &timeinfo);
    strftime(timeMinute , 3, "%M", &timeinfo);
    strftime(timeSecond , 3, "%S", &timeinfo);
    return;
}
