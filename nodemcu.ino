#include <LiquidCrystal_I2C.h>
#include "MQ135.h"
#include <ESP8266WiFi.h>
#define RZERO 76.63
#define LED D7
LiquidCrystal_I2C lcd(0x27, 16,2);
String apiKey = " "; //  Enter your Write API key here     
const char *ssid =  " "; // Enter your WiFi Name   
const char *pass =  " "; // Enter your WiFi Password
const char* server = "api.thingspeak.com";
const int sensorPin= 0;
int air_quality;

WiFiClient client;
void setup() 
{
       pinMode (LED,OUTPUT);
       lcd.begin(); 
       //lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
       lcd.backlight();
       lcd.setCursor(0,0);
       lcd.print("   Air Quality   ");
       lcd.setCursor(0,1);
       lcd.print("Monitoring System");
       Serial.begin(115200); 
       delay(10);
       
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
       while (WiFi.status() != WL_CONNECTED) 
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 }
void loop() 
{
     MQ135 gasSensor = MQ135(A0);
     float rzero = gasSensor.getRZero();
     air_quality = gasSensor.getPPM();
                      if (client.connect(server,80))   
                      {  
                             air_quality = ((analogRead(A0)/1024.0)*100.0); 
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(air_quality);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
                             Serial.print("Air Quality: ");
                             Serial.print(air_quality);
                             Serial.println(" PPM. Send to Thingspeak.");
                             
                             if (air_quality < 100)
                             {
                       
                             Serial.print("Good Air Quality: ");
                               lcd.clear();
                               lcd.setCursor(0,0);
                               lcd.print("Quality :");
                               lcd.print(air_quality);
                               lcd.print(" PPM");
                               lcd.setCursor(0,1);
                               lcd.print("Good Air Quality!");
                               delay(10000);
                               lcd.clear();
                              }
                              else{
                                
                                Serial.print("Poor Air Quality: ");
                                lcd.clear();
                               lcd.setCursor(0,0);
                               lcd.print("Quality:");
                               lcd.print(air_quality);
                               lcd.print("PPM");
                               lcd.setCursor(0,1);
                               lcd.print("Unhealthy Air!");
                               delay(10000);
                               lcd.clear();
                              }
                              
                             
                        }
          client.stop();
          Serial.println("Waiting...");
          lcd.print("Waiting...");
    delay(10000);
}
