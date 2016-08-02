/*
Using this sketch you can calculate water volume in cylinder.
Based on ultrasonic sensor and NewPing library(which provides output smoothing).
tH = Total Height (tank height)
distance = Difference between ultrasonic sensor and water surface. (automaticaly calculated)
f= Fill height calculated by: tH - distance 
v= volume calculated by: V(tank) = (πr2*f/1000)
bubblestack - 2016
by 
Nika Chkhikvishvili & Davit Gokadze
http://bubblestack.io
*/

#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define MAX_DISTANCE 200// donot increse this range for HY-SRF05  sensor.

float distance; // just vaiable declaration.
float tH=80; // Total Height of Tank in cm. 
int  offset=35; // Difference above tank total height and ultrasonic placement in cm. this value depends on installation and its constant.
float radius=38; // radius of tank.
float sqr_R=sq(radius); // Square Radius of Tank 10cm*10cm.
float litre=1000; //1 litre 1000 ml.
float volume;
float f; // water/liquid fill height.
float Pi=3.14; // no comments.


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  delay(1000);
  int uS = sonar.ping_median(15) ; // median filter, error correction 
   distance=(uS / US_ROUNDTRIP_CM - offset); // calculate distance 
   f=(tH-distance); //  calculate fill height of tank
   volume=(Pi*sqr_R*f/1000); // calculate volume of liquid 

/*   ************** for DEBUG *****************
       Serial.print("Distance: ");
       Serial.println(distance); // debug 
       Serial.print("Square Radius: ");
       Serial.println(sqr_R);
       Serial.print("Total Heilght: ");
       Serial.println(tH);
       Serial.print("FILL Height: ");
       Serial.println(f);
       Serial.print("Formula: ");
       Serial.print( Pi );
       Serial.print(" * ");
       Serial.print(sqr_R);
       Serial.print(" * ");
       Serial.print(f);
       Serial.println(" /1000");
*/
      

   if (distance > 0) { // error detection & hot add
    Serial.print(volume);
      Serial.println(" L");
   } else  {
        Serial.println("couldn't communicate to sensor");
   }
  
 }
 

