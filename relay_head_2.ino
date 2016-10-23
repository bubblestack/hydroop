
// relay_head_2
// odd

#include <ESP8266WiFi.h>

const char* ssid = "...";
const char* password = "...";

IPAddress ip(2, 2, 2, 225);   
IPAddress gateway(2,2,2,2);
IPAddress subnet(255,255,255,0);

// Create an instance of the server
// specify the port to listen on as an argument
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
 // pinMode(1, OUTPUT);
  pinMode(4, OUTPUT);
    pinMode(15, OUTPUT);
 
 // clear relay state 
  
  digitalWrite(16, 1);
  digitalWrite(14, 1);
  digitalWrite(13, 1);  
  digitalWrite(12, 1);
  digitalWrite(5, 1);
  digitalWrite(3, 1);
  digitalWrite(2, 1);
 // digitalWrite(1, 1);  
  digitalWrite(4, 1);   
    digitalWrite(15, 1); 
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.config(ip, gateway, subnet);
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
 int relay;
 String pwr_state;
 
// # ESP8266   GPIO 4 = pin  22
  if (req.indexOf("/gpio/1/1") != -1)
  {
    pin= 4; 
    state = 0;
    relay = 1;

  }
  else if (req.indexOf("/gpio/1/0") != -1)
  {
    pin = 4;
    state = 1;
    relay = 1;
  }
//# ESP8266   GPIO 2 = pin 20
  else if (req.indexOf("/gpio/3/1") != -1)
  {
    pin= 2; 
    state = 0;
    relay = 3;
    
  }
  else if (req.indexOf("/gpio/3/0") != -1)
  {
    pin = 2;
    state = 1;
    relay = 3;
  }


//# ESP8266   GPIO 5 = PIN 11 
  else if (req.indexOf("/gpio/5/1") != -1)
  {
    pin= 5; 
    state = 0;
    relay = 5;
  }
  else if (req.indexOf("/gpio/5/0") != -1)
  {
    pin = 5;
    state = 1;
    relay = 5;
  }
//# ESP8266   GPIO 12 = pin 16
  else if (req.indexOf("/gpio/7/1") != -1)
  {
    pin= 12; 
    state = 0;
    relay = 7;
  }
  else if (req.indexOf("/gpio/7/0") != -1)
  {
    pin = 12;
    state = 1;
    relay = 7;
  }

//# ESP8266   GPIO 13 = pin 18 
  else if (req.indexOf("/gpio/9/1") != -1)
  {
    pin= 13; 
    state = 0;
    relay = 9;
  }
  else if (req.indexOf("/gpio/9/0") != -1)
  {
    pin = 13;
    state = 1;
    relay = 9;
  }

//# ESP8266   GPIO 14 = pin 17
  else if (req.indexOf("/gpio/11/1") != -1)
  {
    pin= 14; 
    state = 0;
    relay = 11;
  }
  else if (req.indexOf("/gpio/11/0") != -1)
  {
    pin = 14;
    state = 1;
    relay = 11;
  }


//# ESP8266   GOPIO 3 = pin 4
  else if (req.indexOf("/gpio/13/1") != -1)
  {
    pin= 3; 
    state = 0;
    relay = 13;
  }
 else if (req.indexOf("/gpio/13/0") != -1)
  {
    pin = 3;
    state = 1;
    relay = 13;
  }

//# ESP8266   GPIO 16 = pin 15
 else if (req.indexOf("/gpio/15/1") != -1)

  {
    pin= 16; 
    state = 0;
    relay = 15;
    
  } else if (req.indexOf("/gpio/15/0") != -1)
  
  {
    pin = 16;
    state = 1;
    relay = 15;
  

} else {
    client.println("invalid request");
    client.stop();
    return;
  }


  digitalWrite(pin, state);
      Serial.print("pin: ");
      Serial.println(pin);
      Serial.print("state: ");
  Serial.println(state);
  
  client.flush();

if (state == 0 ) {
  pwr_state = "on";
} else {
  pwr_state = "off";
} 
  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nRELAY: ";
  s += (relay);
  s += ("\nSTATE\: " );
  s += pwr_state;
  s += "\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}
