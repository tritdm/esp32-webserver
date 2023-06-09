#ifndef NTP_H
#define NTP_H

#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

class NTPServer 
{
    private:
        const char* ntpServer = "pool.ntp.org";
        const long  gmtOffset_sec = 7 * 3600;
        const int   daylightOffset_sec = 0;
        NTPServer();
        ~NTPServer();
    public:
        static NTPServer* getInstance() 
        {
            static NTPServer* instace = new NTPServer();
            return instace;
        }
        void NTPServer_Setup(void);
        void NTPServer_GetTime(char *timeWeekday, char *timeMonth, char *timeDay, char *timeYear, 
                                char *timeHour, char *timeMinute, char *timeSecond);
};

#endif
                                                                                                                                                                                                                           #ifndef NTP_H
#define NTP_H

#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

class NTPServer 
{
    private:
        const char* ntpServer = "pool.ntp.org";
        const long  gmtOffset_sec = 7 * 3600;
        const int   daylightOffset_sec = 0;
        NTPServer();
        ~NTPServer();
    public:
        static NTPServer* getInstance() 
        {
            static NTPServer* instace = new NTPServer();
            return instace;
        }
        void NTPServer_Setup(void);
        void NTPServer_GetTime(char *timeWeekday, char *timeMonth, char *timeDay, char *timeYear, 
                                char *timeHour, char *timeMinute, char *timeSecond);
};

#endif
