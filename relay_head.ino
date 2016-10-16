
#include <ESP8266WiFi.h>

const char* ssid = "";
const char* password = "";


WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // prepare GPIO  pins
  pinMode(16, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
 // pinMode(0, OUTPUT);
  
 
 // clear relay state 
  
  digitalWrite(16, 1);
  digitalWrite(14, 1);
  digitalWrite(13, 1);  
  digitalWrite(12, 1);
  digitalWrite(5, 1);
  digitalWrite(3, 1);
  digitalWrite(2, 1);
  digitalWrite(1, 1);  
  //digitalWrite(0, LOW);   
  
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
 int pin;
 int state;

// # ESP8266   GPIO 1 = pin 3
  if (req.indexOf("/gpio/1/1") != -1)
  {
    pin= 1; 
    state = 0;
  }
  if (req.indexOf("/gpio/1/0") != -1)
  {
    pin = 1;
    state = 1;
  }
//# ESP8266   GPIO 2 = pin 20
  if (req.indexOf("/gpio/2/1") != -1)
  {
    pin= 2; 
    state = 0;
  }
  if (req.indexOf("/gpio/2/0") != -1)
  {
    pin = 2;
    state = 1;
  }


//# ESP8266   GPIO 5 = PIN 11
  if (req.indexOf("/gpio/3/1") != -1)
  {
    pin= 5; 
    state = 0;
  }
  if (req.indexOf("/gpio/3/0") != -1)
  {
    pin = 5;
    state = 1;
  }
//# ESP8266   GPIO 12 = pin 16
  if (req.indexOf("/gpio/4/1") != -1)
  {
    pin= 12; 
    state = 0;
  }
  if (req.indexOf("/gpio/4/0") != -1)
  {
    pin = 12;
    state = 1;
  }

//# ESP8266   GPIO 13 = pin 18 
  if (req.indexOf("/gpio/5/1") != -1)
  {
    pin= 13; 
    state = 0;
  }
  if (req.indexOf("/gpio/5/0") != -1)
  {
    pin = 13;
    state = 1;
  }

//# ESP8266   GPIO 14 = pin 17
  if (req.indexOf("/gpio/6/1") != -1)
  {
    pin= 14; 
    state = 0;
  }
  if (req.indexOf("/gpio/6/0") != -1)
  {
    pin = 14;
    state = 1;
  }


//# ESP8266   GOPIO 3 = pin 4
  if (req.indexOf("/gpio/7/1") != -1)
  {
    pin= 3; 
    state = 0;
  }
  if (req.indexOf("/gpio/7/0") != -1)
  {
    pin = 3;
    state = 1;
  }



//# ESP8266   GPIO 16 = pin 15
  if (req.indexOf("/gpio/8/1") != -1)
  {
    pin= 16; 
    state = 0;
  }
  if (req.indexOf("/gpio/8/0") != -1)
  {
    pin = 16;
    state = 1;
  }

  digitalWrite(pin, state);
      Serial.print("pin: ");
      Serial.println(pin);
      Serial.print("state: ");
  Serial.println(state);
  
  client.flush();

  // response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nRELAY: ";
  s += (pin);
  s += (" is: " );
  s += (state);
  s += "</html>\n";

  // response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

}
