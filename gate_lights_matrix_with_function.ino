#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#include "pauseLED.h"

const char* ssid = "cnd";
const char* password = "ConderoWLAN2000";

WebServer server(80);

const int led = 13;

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "LEDs sind bereit!");
  digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}


const int pixelsPin = 4;
const int horizontalPixels = 8;
const int verticalPixels = 8;

const int buttonPin = 27;
int buttonState = 0;
const int buttonPin2 = 26;
int buttonState2 = 0;

Adafruit_NeoPixel pixels(horizontalPixels* verticalPixels, pixelsPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixels.begin();
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pixels.clear();
  pixels.show();

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/scan", []() {
    scanLED();
    server.send(200, "text/plain", "Pause");
  });
  
  server.on("/error", []() {
    server.send(200, "text/plain", "Fehler X");
  });
  
  server.on("/goleft", []() {
    
    server.send(200, "text/plain", "Freigabe links");
  }); 

  server.on("/goright", []() {
    server.send(200, "text/plain", "Freigabe rechts");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void scanLED() {
  Serial.println("scanLED"); 

  Serial.println("LOW-HIGH");

  setLedMatrix(50, 50, 0, myPins1);
  delay(200);

  setLedMatrix(50, 50, 0, myPins2);
  delay(200);

  setLedMatrix(50, 50, 0, myPins3);
  delay(200);

  setLedMatrix(50, 50, 0, myPins4);
  delay(200);

  setLedMatrix(50, 50, 0, myPins5);
  delay(200);
   
  setLedMatrix(50, 50, 0, myPins6);
  delay(200);
  
  setLedMatrix(50, 50, 0, myPins7);
  delay(200);
  
  setLedMatrix(50, 50, 0, myPins8);
  delay(200);

  setLedMatrix(50, 50, 0, myPins9);
  delay(200);
 
  setLedMatrix(50, 50, 0, myPins10);
  delay(200);

  setLedMatrix(50, 50, 0, myPins11);
  delay(200);

  setLedMatrix(50, 50, 0, myPins12);
  delay(200);

  setLedMatrix(50, 50, 0, myPins13);
  delay(200);

  setLedMatrix(50, 50, 0, myPins14);
  delay(200);

  setLedMatrix(50, 50, 0, myPins15);
  delay(200);

  setLedMatrix(50, 50, 0, myPins17);
  delay(200);
  
  setLedMatrix(50, 50, 0, myPins17);
  delay(200);

  setLedMatrix(50, 50, 0, myPins18);
  delay(200);
   
  setLedMatrix(50, 50, 0, myPins19);
  delay(200);
    
  setLedMatrix(50, 50, 0, myPins20);
  delay(200);
    
  setLedMatrix(50, 50, 0, myPins21);
  delay(200);
}

void errorLED() {
  Serial.println("errorLED"); 

 int myPins1[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(50, 0, 0, myPins1);
    delay(200);
    Serial.println("HIGH-HIGH");

    int myPins2[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(50, 0, 0, myPins2);
    delay(200);

    int myPins3[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(50, 0, 0, myPins3);
    delay(200);

    int myPins4[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(50, 0, 0, myPins4);
    delay(200);

    int myPins5[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(50, 0, 0, myPins5);
    delay(200);

    int myPins6[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(50, 0, 0, myPins6);
    delay(200);

    int myPins7[][8] = {
      { 1, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 1, 0, 0, 1, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 1, 0 },
      { 1, 0, 0, 0, 0, 0, 0, 1 },
    };
    setLedMatrix(50, 0, 0, myPins7);
    delay(200);

    // int myPins8[][8] = {
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    // };
    // setLedMatrix(50, 0, 0, myPins8);
    // delay(200);

    // int myPins9[][8] = {
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    // };
    // setLedMatrix(50, 0, 0, myPins9);
    // delay(200);

    // int myPins10[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins10);
    // delay(200);


}

void loop() {
  server.handleClient();

  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState == HIGH && buttonState2 == HIGH) {

    errorLED();

    // int myPins1[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins1);
    // delay(200);
    // Serial.println("HIGH-HIGH");

    // int myPins2[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins2);
    // delay(200);

    // int myPins3[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins3);
    // delay(200);

    // int myPins4[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins4);
    // delay(200);

    // int myPins5[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 0, 1, 1, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins5);
    // delay(200);

    // int myPins6[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins6);
    // delay(200);

    // int myPins7[][8] = {
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    // };
    // setLedMatrix(50, 0, 0, myPins7);
    // delay(200);

    // int myPins8[][8] = {
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    // };
    // setLedMatrix(50, 0, 0, myPins8);
    // delay(200);

    // int myPins9[][8] = {
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 1, 0, 0, 0, 0, 0, 0, 1 },
    // };
    // setLedMatrix(50, 0, 0, myPins9);
    // delay(200);

    // int myPins10[][8] = {
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    //   { 0, 0, 1, 0, 0, 1, 0, 0 },
    //   { 0, 1, 0, 0, 0, 0, 1, 0 },
    //   { 0, 0, 0, 0, 0, 0, 0, 0 },
    // };
    // setLedMatrix(50, 0, 0, myPins10);
    // delay(200);

    
  } else if (buttonState == LOW && buttonState2 == HIGH) {
  //   int myPins1[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins1);
  //   delay(200);
  //   Serial.println("LOW-HIGH");

  //  int myPins2[][8] = {
  //     { 0, 0, 1, 1, 0, 0, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins2);
  //   delay(200);

  //   int myPins3[][8] = {
  //     { 0, 0, 1, 1, 1, 0, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 0, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins3);
  //   delay(200);

  //   int myPins4[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 0, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 0 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins4);
  //   delay(200);

  //   int myPins5[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 0 },
  //     { 1, 0, 0, 0, 0, 0, 0, 0 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins5);
  //   delay(200);

  //   int myPins6[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 0 },
  //     { 1, 0, 0, 0, 0, 0, 0, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins6);
  //   delay(200);

  //   int myPins7[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins7);
  //   delay(200);

  //   int myPins8[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 0, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins8);
  //   delay(200);

  //   int myPins9[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 0, 0 },
  //     { 0, 0, 1, 1, 1, 0, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins9);
  //   delay(200);

  //   int myPins10[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 0, 0, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins10);
  //   delay(200);

  //   int myPins11[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 0, 0, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins11);
  //   delay(200);

  //   int myPins12[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 0, 0, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins12);
  //   delay(200);

  //   int myPins13[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 0, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 0, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins13);
  //   delay(200);

  //   int myPins14[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 0, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 0, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins14);
  //   delay(200);

  //   int myPins15[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 0, 0, 0, 0, 0, 0, 0, 1 },
  //     { 0, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins15);
  //   delay(200);

  //   int myPins16[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 0, 0, 0, 0, 0, 0, 1 },
  //     { 0, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins16);
  //   delay(200);

  //   int myPins17[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins17);
  //   delay(200);

  //   int myPins18[][8] = {
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //     { 0, 0, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins18);
  //   delay(200);

  //   int myPins19[][8] = {
  //     { 0, 0, 0, 1, 1, 1, 0, 0 },
  //     { 0, 0, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins19);
  //   delay(200);

  //   int myPins20[][8] = {
  //     { 0, 0, 0, 0, 1, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins20);
  //   delay(200);

  //   int myPins21[][8] = {
  //     { 0, 0, 1, 0, 0, 1, 0, 0 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 0, 0, 0, 0, 0, 1 },
  //     { 1, 0, 1, 1, 1, 1, 0, 1 },
  //     { 0, 1, 0, 0, 0, 0, 1, 0 },
  //     { 0, 0, 1, 1, 1, 1, 0, 0 },
  //   };
  //   setLedMatrix(50, 50, 0, myPins21);
  //   delay(200);
  } else if (buttonState == HIGH && buttonState2 == LOW) {
    int myPins1[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
   setLedMatrix(0, 50, 0, myPins1);
    delay(200);

    int myPins2[][8] = {
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
    };
   setLedMatrix(0, 50, 0, myPins2);
    delay(200);

    int myPins3[][8] = {
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
    };
   setLedMatrix(0, 50, 0, myPins3);
    delay(200);

    int myPins4[][8] = {
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
    };
   setLedMatrix(0, 50, 0, myPins4);
    delay(200);

    int myPins5[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
   setLedMatrix(0, 50, 0, myPins5);
    delay(200);

    int myPins6[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },      
    };
   setLedMatrix(0, 50, 0, myPins6);
    delay(200);

    int myPins7[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },   
      { 0, 0, 0, 1, 1, 0, 0, 0 },         
    };
   setLedMatrix(0, 50, 0, myPins7);
    delay(200);

    int myPins8[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },   
      { 0, 0, 0, 1, 1, 0, 0, 0 }, 
      { 0, 0, 0, 1, 1, 0, 0, 0 },              
    };
   setLedMatrix(0, 50, 0, myPins8);
    delay(200);
  } else if (buttonState == LOW && buttonState2 == LOW) {

    Serial.println("LOW-LOW");

    int myPins1[][8] = {
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
    };
    setLedMatrix(0, 50, 0, myPins1);
    delay(200);
    int myPins2[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
    };
    setLedMatrix(0, 50, 0, myPins2);
    delay(200);
    int myPins3[][8] = {
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
    };
    setLedMatrix(0, 50, 0, myPins3);
    delay(200);
    int myPins4[][8] = {
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
    setLedMatrix(0, 50, 0, myPins4);
    delay(200);
    int myPins5[][8] = {
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
    };
    setLedMatrix(0, 50, 0, myPins5);
    delay(200);
    int myPins6[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
    };
    setLedMatrix(0, 50, 0, myPins6);
    delay(200);
    int myPins7[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
    };
    setLedMatrix(0, 50, 0, myPins7);
    delay(200);
    int myPins8[][8] = {
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 1, 1, 1, 1 },
      { 0, 1, 1, 1, 1, 1, 1, 0 },
      { 0, 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    setLedMatrix(0, 50, 0, myPins8);
    delay(200);
  }
}

void setLedMatrix(int r, int g, int b, int pins[][8]) {
  pixels.clear();
  for (int i = 0; i < verticalPixels; i++) {
    int k = horizontalPixels - 1;
    for (int j = 0; j < horizontalPixels; j++) {
      if (i % 2 == 0 && pins[i][j] == 1 || i % 2 != 0 && pins[i][k] == 1) {
        pixels.setPixelColor(i * horizontalPixels + j, pixels.Color(r, g, b));
      }
      k--;
    }
  }
  pixels.show();
}


/*
TODO paul:
- neues projekt: file->examples->adafruit neomatrix (ist weit unten)->matrixtest und matrixgfxdemo ausprobieren (dort jeweils den pin auf 4 ändern)
- das hier muss bei neomatrix eingestellt werden: NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG (start ist oben links, es is spaltenweise und zickzack)
- mit einem von den beiden die aufgabe von hier nochmal umsetzen
*/