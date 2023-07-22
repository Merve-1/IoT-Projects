#include <dht.h>
#include <TinyGPS++.h>

#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object
TinyGPSPlus gps;

unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 10000;  // interval at which to blink (milliseconds)

float t = 0.0;
float h = 0.0;
float lat_gps = 0.0;
float lng_gps = 0.0;
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
}

void loop()
{
      get_temp();
    get_location();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    send_SMS();

  }

}

void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    Serial2.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (Serial2.available())
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
  }
}

void send_SMS()
{

  Serial.println("Initializing...");
  delay(1000);
  Serial2.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  Serial2.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  Serial2.println("AT+CMGS=\"+zzxxxxxxxxxxx\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  Serial2.print("Temp: " + String(t) + " | Hum:"+String(h)+" | Latitude: "+String(lat_gps, 6)+" | Longitude: "+String(lng_gps, 6)); //text content
  updateSerial();
  Serial2.write(26);
}

void get_temp()
{
  int readData = DHT.read22(dataPin); // DHT22/AM2302
  //int readData = DHT.read11(dataPin); // DHT11

  t = DHT.temperature; // Gets the values of the temperature
  h = DHT.humidity; // Gets the values of the humidity
  //Serial.println("Temp.....Done");
}

void get_location()
{
  while (Serial1.available() > 0)
    if (gps.encode(Serial1.read()))
      displayInfo();
}

void displayInfo()
{
  if (gps.location.isValid())
  {
    lat_gps = gps.location.lat();
    lng_gps = gps.location.lng();
  }
}
