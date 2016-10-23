#include "DHT.h"
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "bubblestack.io";    // name address for Google (using DNS)
IPAddress ip(2, 2, 2, 226);
EthernetClient client;

long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long lastConnectionTime = 0;             // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10L * 1000L; // delay between updates, in milliseconds
long interval = 150000; // READING INTERVAL

float cistern_temp;


#define DHT1PIN 2     // what pin we're connected to
#define DHT2PIN 3
#define DHT1TYPE DHT11   // DHT 11 
#define DHT2TYPE DHT11  
 
DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);

String data;

void setup() {
  Serial.begin(9600); 
  pinMode(4, OUTPUT);
  dht1.begin();
  dht2.begin();
  delay(4000);
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  
  
    // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip);
  }
}


  
void loop() {

   cistern_temp = read_temp();
 Serial.println(cistern_temp);
  
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
delay(1000);


  if (isnan(t1) || isnan(h1)) {
    Serial.println("Failed to read from DHT #1");
  } else {
    Serial.print("Humidity 1: "); 
    Serial.print(h1);
    Serial.print(" %\t");
    Serial.print("Temperature 1: "); 
    Serial.print(t1);
    Serial.println(" *C");
  }
  if (isnan(t2) || isnan(h2)) {
    Serial.println("Failed to read from DHT #2");
  } else {
    Serial.print("Humidity 2: "); 
    Serial.print(h2);
    Serial.print(" %\t");
    Serial.print("Temperature 2: "); 
    Serial.print(t2);
    Serial.println(" *C");
  }
  Serial.println();

  data = "&temp1=" + String(t1)+  "&hum1="+ String(h1)+ "&temp2=" +String(t2)+ "&hum2=" +String(h2)+ "&cistern_tmp=" +String(cistern_temp);

    if (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if ten seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }

}

// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    // send the HTTP PUT request:
    client.println("POST /greenhouse/env.php HTTP/1.1");
    client.println("Host: bubblestack.io");
    client.println("User-Agent: arduino-ethernet");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(data.length());
    client.println();
    client.print(data);
    client.println();
    


    // note the time that the connection was made:
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
 if (client.connected()) {

client.stop();// DISCONNECT FROM THE SERVER

} 
  
}


  
float read_temp(void){
 float v_out;
 float cistern_temp;
 digitalWrite(A0, LOW);
 digitalWrite(4, HIGH);
 delay(2);
 v_out = analogRead(0);
 digitalWrite(4, LOW);
 v_out*=.0048;
 v_out*=1000;
 cistern_temp= 0.0512 * v_out -20.5128;
return cistern_temp;
}

  
