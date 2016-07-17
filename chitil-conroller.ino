// atlas cinetific & Adafruit code

#include "DHT.h"
#define DHTPIN 3
#define HeatPad 13
#define DCCooler  12
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
float temp; 


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(HeatPad,OUTPUT);
    pinMode(DCCooler,OUTPUT);
  dht.begin();
}

void loop() {
  temp = read_temp();
  delay(12000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Micro Climat Temp: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("plant root Temp: ");
  Serial.print(temp);
  Serial.println(" *C");
  
  ///////

if (temp >27) {
		digitalWrite(HeatPad, LOW);
	} else {
		digitalWrite(HeatPad, HIGH);
	}



if (h > 75) {
  digitalWrite(DCCooler, HIGH);
 } else {
  digitalWrite(DCCooler, LOW );
 }
    
}


float read_temp(void){
float v_out;
float temp;
digitalWrite(A0, LOW);
digitalWrite(2, HIGH);
delay(2);
v_out = analogRead(0);
digitalWrite(2, LOW);
v_out*=.0048;
v_out*=1000;
temp= 0.0512 * v_out -20.5128;
return temp;
}
