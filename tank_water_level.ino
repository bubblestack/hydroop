
#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define MAX_DISTANCE 300


float distance;
float tH=86; // Total Height of Tank in cm. 
float radius=10;
float sqr_R=sq(radius); // Square Radius of Tank 10cm*10cm;
float litre=1000; //1 litre 1000 ml;
float volume;
float f; // fill height
float Pi=3.14; 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  delay(1000);
  int uS = sonar.ping_median(15); // median filter, error correction 
   distance=(uS / US_ROUNDTRIP_CM); // calculate distance 
   f=(tH-distance); //  calculate fill height of tank
   volume=(Pi*sqr_R*f/1000); // calculate volume of liquid 
  Serial.println(volume);
   

  
  
  
 }
