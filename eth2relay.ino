//ARDUINO 1.0+ ONLY
//ARDUINO 1.0+ ONLY


#include <Ethernet.h>
#include <SPI.h>
boolean reading = false;

////////////////////////////////////////////////////////////////////////
//CONFIGURE
////////////////////////////////////////////////////////////////////////
  //byte ip[] = { 192, 168, 0, 199 };   //Manual setup only
  //byte gateway[] = { 192, 168, 0, 1 }; //Manual setup only
  //byte subnet[] = { 255, 255, 255, 0 }; //Manual setup only

  // if need to change the MAC address (Very Rare)
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

  EthernetServer server = EthernetServer(80); //port 80
////////////////////////////////////////////////////////////////////////



int SER_Pin = 6;   //pin 14 on the 75HC595  ------------- BLUE
int RCLK_Pin = 7;  //pin 12 on the 75HC595  -------------  GREEN
int SRCLK_Pin = 5; //pin 11 on the 75HC595 ------------ YELLOW

//How many of the shift registers - change this
#define number_of_74hc595s 2

//register pins
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];


int dev1=0;
int dev2=1;
int dev3=2;
int dev4=3;
int dev5=4;
int dev6=5;
int dev7=6;
int dev8=7;
int dev9=8;
int dev10=9;
int dev11=10;
int dev12=11;
int dev13=12;
int dev14=13;
int dev15=14;
int dev16=15;
int dev17=16;
int dev18=17;
int dev19=18;
int dev20=19;
int dev21=20;
int dev22=21;
int dev23=22;
int dev24=23;
int dev25=24;
int dev26=25;
int dev27=26;
int dev28=27;
int dev29=28;
int dev30=29;
int dev31=30;
int dev32=31;

////////////////////////////////////////////////////////



void setup(){
  Serial.begin(9600);

  //Pins 10,11,12 & 13 are used by the ethernet shield
 pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  clearRegisters();
  writeRegisters();
  
  Ethernet.begin(mac);
  //Ethernet.begin(mac, ip, gateway, subnet); //for manual setup

  server.begin();
  Serial.println(Ethernet.localIP());

}

//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
  writeRegisters();
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}




void loop(){

  // listen for incoming clients, and process qequest.
  checkForClient();

}

void checkForClient(){

  EthernetClient client = server.available();

  if (client) {

    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    boolean sentHeader = false;

    while (client.connected()) {
      if (client.available()) {

        if(!sentHeader){
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          sentHeader = true;
        }

        char c = client.read();

        if(reading && c == ' ') reading = false;
        if(c == '?') reading = true; //found the ?, begin reading the info

        if(reading){
          Serial.print(c);

           switch (c) {


  case 'A':
             //add code here to trigger on 2
              triggerPin(dev1, client);
              break;
          case 'a':
            //add code here to trigger on 3
              triggerOff(dev1, client);
              break;

  case 'B':
             //add code here to trigger on 2
              triggerPin(dev2, client);
              break;
          case 'b':
            //add code here to trigger on 3
              triggerOff(dev2, client);
              break;

  case 'C':
             //add code here to trigger on 2
              triggerPin(dev3, client);
              break;
          case 'c':
            //add code here to trigger on 3
              triggerOff(dev3, client);
              break;

  case 'D':
             //add code here to trigger on 2
              triggerPin(dev4, client);
              break;
          case 'd':
            //add code here to trigger on 3
              triggerOff(dev4, client);
              break;

  case 'E':
             //add code here to trigger on 2
              triggerPin(dev5, client);
              break;
          case 'e':
            //add code here to trigger on 3
              triggerOff(dev5, client);
              break;

  case 'F':
             //add code here to trigger on 2
              triggerPin(dev6, client);
              break;
          case 'f':
            //add code here to trigger on 3
              triggerOff(dev6, client);
              break;

  case 'G':
             //add code here to trigger on 2
              triggerPin(dev7, client);
              break;
          case 'g':
            //add code here to trigger on 3
              triggerOff(dev7, client);
              break;

  case 'H':
             //add code here to trigger on 2
              triggerPin(dev8, client);
              break;
          case 'h':
            //add code here to trigger on 3
              triggerOff(dev8, client);
              break;

  case 'I':
             //add code here to trigger on 2
              triggerPin(dev9, client);
              break;
          case 'i':
            //add code here to trigger on 3
              triggerOff(dev9, client);
              break;

  case 'J':
             //add code here to trigger on 2
              triggerPin(dev10, client);
              break;
          case 'j':
            //add code here to trigger on 3
              triggerOff(dev10, client);
              break;

  case 'K':
             //add code here to trigger on 2
              triggerPin(dev11, client);
              break;
          case 'k':
            //add code here to trigger on 3
              triggerOff(dev11, client);
              break;

  case 'L':
             //add code here to trigger on 2
              triggerPin(dev12, client);
              break;
          case 'l':
            //add code here to trigger on 3
              triggerOff(dev12, client);
              break;

  case 'M':
             //add code here to trigger on 2
              triggerPin(dev13, client);
              break;
          case 'm':
            //add code here to trigger on 3
              triggerOff(dev13, client);
              break;

  case 'N':
             //add code here to trigger on 2
              triggerPin(dev14, client);
              break;
          case 'n':
            //add code here to trigger on 3
              triggerOff(dev14, client);
              break;

  case 'O':
             //add code here to trigger on 2
              triggerPin(dev15, client);
              break;
          case 'o':
            //add code here to trigger on 3
              triggerOff(dev15, client);
              break;

  case 'P':
             //add code here to trigger on 2
              triggerPin(dev16, client);
              break;
          case 'p':
            //add code here to trigger on 3
              triggerOff(dev16, client);
              break;

  case 'Q':
             //add code here to trigger on 2
              triggerPin(dev17, client);
              break;
          case 'q':
            //add code here to trigger on 3
              triggerOff(dev17, client);
              break;

  case 'R':
             //add code here to trigger on 2
              triggerPin(dev18, client);
              break;
          case 'r':
            //add code here to trigger on 3
              triggerOff(dev18, client);
              break;

  case 'S':
             //add code here to trigger on 2
              triggerPin(dev19, client);
              break;
          case 's':
            //add code here to trigger on 3
              triggerOff(dev19, client);
              break;

  case 'T':
             //add code here to trigger on 2
              triggerPin(dev20, client);
              break;
          case 't':
            //add code here to trigger on 3
              triggerOff(dev20, client);
              break;

  case 'U':
             //add code here to trigger on 2
              triggerPin(dev21, client);
              break;
          case 'u':
            //add code here to trigger on 3
              triggerOff(dev21, client);
              break;

  case 'V':
             //add code here to trigger on 2
              triggerPin(dev22, client);
              break;
          case 'v':
            //add code here to trigger on 3
              triggerOff(dev22, client);
              break;

  case 'W':
             //add code here to trigger on 2
              triggerPin(dev23, client);
              break;
          case 'w':
            //add code here to trigger on 3
              triggerOff(dev23, client);
              break;

  case 'X':
             //add code here to trigger on 2
              triggerPin(dev24, client);
              break;
          case 'x':
            //add code here to trigger on 3
              triggerOff(dev24, client);
              break;

  case 'Y':
             //add code here to trigger on 2
              triggerPin(dev25, client);
              break;
          case 'y':
            //add code here to trigger on 3
              triggerOff(dev25, client);
              break;

  case 'Z':
             //add code here to trigger on 2
              triggerPin(dev26, client);
              break;
          case 'z':
            //add code here to trigger on 3
              triggerOff(dev26, client);
              break;


      
      
      
           }

        }

        if (c == '\n' && currentLineIsBlank)  break;

        if (c == '\n') {
          currentLineIsBlank = true;
        }else if (c != '\r') {
          currentLineIsBlank = false;
        }

      }
    }

    delay(1); // give the web browser time to receive the data
    client.stop(); // close the connection:

  } 

}







void triggerOff(int offdev, EthernetClient client){
  int delayTime=1000;
  
    client.print("Turning OFF dev ");
  client.println(offdev);
  client.print("<br>");
   client.print("<br>MAINC SRULDEBA???");
   
      setRegisterPin(offdev, LOW);
      writeRegisters();
      delay(delayTime);
;

}
  
void triggerPin(int ondev, EthernetClient client){
  
    int delayTime=1000;
  
  client.print("Turning on dev ");
  client.println(ondev);
  client.print("<br>");
   
      setRegisterPin(ondev, HIGH);
      writeRegisters();
      delay(delayTime);
;


}
