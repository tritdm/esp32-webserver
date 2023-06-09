#ifndef WSHANDLE_H
#define WSHANDLE_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "index.h"

class WebServerHandler
{
    private:
        
    public:
        WebServerHandler() {
            WebServer server(80);
        }
        void handle_OnConnect();
        void handle_NotFound();
        void handle_temperature();
        void handle_humidity();
        void handle_pressure();
        void handle_altitude();
}


#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      #ifndef WSHANDLE_H
#define WSHANDLE_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "index.h"

class WebServerHandler
{
    private:
        
    public:
        WebServerHandler() {
            WebServer server(80);
        }
        void handle_OnConnect();
        void handle_NotFound();
        void handle_temperature();
        void handle_humidity();
        void handle_pressure();
        void handle_altitude();
}


#endif