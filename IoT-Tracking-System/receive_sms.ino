#include <ESP8266WiFi.h>


#include <SoftwareSerial.h>
//Create software serial object to communicate with SIM800L
WiFiClient client;
SoftwareSerial mySerial(D7, D8);  //SIM800L Tx & Rx is connected to Arduino #3 & #2
byte counter = 0;

//WiFi network 
const char ssid[] = "WiFiName";
const char password[] = "WiFiPassword";



void setup() {

  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    counter++;
    if (counter==20){
      break;
    }

  }
  switch (WiFi.status()){
    case WL_CONNECTED:
      Serial.print("WiFi Connected");
      break;
    
    case WL_NO_SSID_AVAIL:
      Serial.print("SSID cannot be reached!!");
      break;
    
    case WL_CONNECT_FAILED:
      Serial.print("Wrong Password");
      break;
    
    default:
      Serial.print("Unknown error");
      delay(5000);
      ESP.restart();

  }
  Serial.print(WiFi.localIP());
  Serial.begin(9600);

  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  mySerial.println("AT");  //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1");  // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0");  // Decides how newly arrived SMS messages should be handled
  updateSerial();
}

void loop() {
  updateSerial();
}

void updateSerial() {
  //delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read());  //Forward what Serial received to Software Serial Port
  }
  while (mySerial.available()) {
    

    if (mySerial.available()) {
      Serial.write(mySerial.read());  //Forward what Software Serial received to Serial Port
      String incomingMessage = mySerial.readString();
      Serial.println("Received message: " + incomingMessage);

      // Split incomingMessage into individual values
      int startTemp = incomingMessage.indexOf("&") + 7;
      int endTemp = incomingMessage.indexOf("|") - 1;
      float temp = incomingMessage.substring(startTemp, endTemp).toFloat();

      int startHum = incomingMessage.indexOf(":", endTemp) + 2;
      int endHum = incomingMessage.indexOf("|", startHum) - 1;
      float hum = incomingMessage.substring(startHum, endHum).toFloat();

      int startLat = incomingMessage.indexOf(":", endHum) + 2;
      int endLat = incomingMessage.indexOf("|", startLat) - 1;
      float lat = incomingMessage.substring(startLat, endLat).toFloat();

      int startLon = incomingMessage.indexOf(":", endLat) + 2;
      int endLon = incomingMessage.length() - 1;
      float lon = incomingMessage.substring(startLon, endLon).toFloat();

      

      Serial.println(temp);
      Serial.println(hum);
      Serial.println(lat, 6);
      Serial.println(lon, 6);

      
     
    }
  }
}
