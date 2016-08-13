int SER_Pin = 6;   //pin 14 on the 75HC595
int RCLK_Pin = 7;  //pin 12 on the 75HC595
int SRCLK_Pin = 5; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 6

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
int dev33=32;
int dev34=33;
int dev35=34;
int dev36=35;
int dev37=36;
int dev38=37;
int dev39=38;
int dev40=39;
int dev41=40;
int dev42=41;
int dev43=42;
int dev44=43;
int dev45=44;
int dev46=45;
int dev47=46;
int dev48=47;




void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  Serial.begin(9600); // baud rate
  Serial.flush();


  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


/*
PROBLEM. to be fixed:
Random shift register's output states at power up
maybe solution:
OE / MR pins 
pullup resistors
*/

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

  relaycontroll();
  
  
}



void relaycontroll()
{
  
  
  int delayTime=200;
  String input = "";
 
     // Read any serial input
     while (Serial.available() > 0)
     {
         input += (char) Serial.read(); // Read in one char at a time
         delay(5); // Delay for 5 ms so the next char has time to be received
     }



/////////////////////////// Relay 1
     if (input == "dev1_on")
     {
      setRegisterPin(dev1, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev1_off") 
{ 
      setRegisterPin(dev1, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 1
/////////////////////////// Relay 2
     if (input == "dev2_on")
     {
      setRegisterPin(dev2, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev2_off") 
{ 
      setRegisterPin(dev2, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 2
/////////////////////////// Relay 3
     if (input == "dev3_on")
     {
      setRegisterPin(dev3, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev3_off") 
{ 
      setRegisterPin(dev3, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 3
/////////////////////////// Relay 4
     if (input == "dev4_on")
     {
      setRegisterPin(dev4, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev4_off") 
{ 
      setRegisterPin(dev4, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 4
/////////////////////////// Relay 5
     if (input == "dev5_on")
     {
      setRegisterPin(dev5, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev5_off") 
{ 
      setRegisterPin(dev5, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 5
/////////////////////////// Relay 6
     if (input == "dev6_on")
     {
      setRegisterPin(dev6, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev6_off") 
{ 
      setRegisterPin(dev6, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 6
/////////////////////////// Relay 7
     if (input == "dev7_on")
     {
      setRegisterPin(dev7, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev7_off") 
{ 
      setRegisterPin(dev7, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 7
/////////////////////////// Relay 8
     if (input == "dev8_on")
     {
      setRegisterPin(dev8, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev8_off") 
{ 
      setRegisterPin(dev8, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 8
/////////////////////////// Relay 9
     if (input == "dev9_on")
     {
      setRegisterPin(dev9, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev9_off") 
{ 
      setRegisterPin(dev9, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 9
/////////////////////////// Relay 10
     if (input == "dev10_on")
     {
      setRegisterPin(dev10, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev10_off") 
{ 
      setRegisterPin(dev10, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 10
/////////////////////////// Relay 11
     if (input == "dev11_on")
     {
      setRegisterPin(dev11, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev11_off") 
{ 
      setRegisterPin(dev11, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 11
/////////////////////////// Relay 12
     if (input == "dev12_on")
     {
      setRegisterPin(dev12, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev12_off") 
{ 
      setRegisterPin(dev12, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 12
/////////////////////////// Relay 13
     if (input == "dev13_on")
     {
      setRegisterPin(dev13, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev13_off") 
{ 
      setRegisterPin(dev13, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 13
/////////////////////////// Relay 14
     if (input == "dev14_on")
     {
      setRegisterPin(dev14, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev14_off") 
{ 
      setRegisterPin(dev14, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 14
/////////////////////////// Relay 15
     if (input == "dev15_on")
     {
      setRegisterPin(dev15, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev15_off") 
{ 
      setRegisterPin(dev15, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 15
/////////////////////////// Relay 16
     if (input == "dev16_on")
     {
      setRegisterPin(dev16, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev16_off") 
{ 
      setRegisterPin(dev16, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 16
/////////////////////////// Relay 17
     if (input == "dev17_on")
     {
      setRegisterPin(dev17, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev17_off") 
{ 
      setRegisterPin(dev17, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 17
/////////////////////////// Relay 18
     if (input == "dev18_on")
     {
      setRegisterPin(dev18, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev18_off") 
{ 
      setRegisterPin(dev18, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 18
/////////////////////////// Relay 19
     if (input == "dev19_on")
     {
      setRegisterPin(dev19, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev19_off") 
{ 
      setRegisterPin(dev19, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 19
/////////////////////////// Relay 20
     if (input == "dev20_on")
     {
      setRegisterPin(dev20, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev20_off") 
{ 
      setRegisterPin(dev20, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 20
/////////////////////////// Relay 21
     if (input == "dev21_on")
     {
      setRegisterPin(dev21, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev21_off") 
{ 
      setRegisterPin(dev21, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 21
/////////////////////////// Relay 22
     if (input == "dev22_on")
     {
      setRegisterPin(dev22, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev22_off") 
{ 
      setRegisterPin(dev22, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 22
/////////////////////////// Relay 23
     if (input == "dev23_on")
     {
      setRegisterPin(dev23, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev23_off") 
{ 
      setRegisterPin(dev23, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 23
/////////////////////////// Relay 24
     if (input == "dev24_on")
     {
      setRegisterPin(dev24, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev24_off") 
{ 
      setRegisterPin(dev24, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 24
/////////////////////////// Relay 25
     if (input == "dev25_on")
     {
      setRegisterPin(dev25, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev25_off") 
{ 
      setRegisterPin(dev25, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 25
/////////////////////////// Relay 26
     if (input == "dev26_on")
     {
      setRegisterPin(dev26, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev26_off") 
{ 
      setRegisterPin(dev26, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 26
/////////////////////////// Relay 27
     if (input == "dev27_on")
     {
      setRegisterPin(dev27, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev27_off") 
{ 
      setRegisterPin(dev27, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 27
/////////////////////////// Relay 28
     if (input == "dev28_on")
     {
      setRegisterPin(dev28, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev28_off") 
{ 
      setRegisterPin(dev28, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 28
/////////////////////////// Relay 29
     if (input == "dev29_on")
     {
      setRegisterPin(dev29, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev29_off") 
{ 
      setRegisterPin(dev29, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 29
/////////////////////////// Relay 30
     if (input == "dev30_on")
     {
      setRegisterPin(dev30, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev30_off") 
{ 
      setRegisterPin(dev30, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 30
/////////////////////////// Relay 31
     if (input == "dev31_on")
     {
      setRegisterPin(dev31, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev31_off") 
{ 
      setRegisterPin(dev31, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 31
/////////////////////////// Relay 32
     if (input == "dev32_on")
     {
      setRegisterPin(dev32, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev32_off") 
{ 
      setRegisterPin(dev32, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 32
/////////////////////////// Relay 33
     if (input == "dev33_on")
     {
      setRegisterPin(dev33, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev33_off") 
{ 
      setRegisterPin(dev33, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 33
/////////////////////////// Relay 34
     if (input == "dev34_on")
     {
      setRegisterPin(dev34, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev34_off") 
{ 
      setRegisterPin(dev34, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 34
/////////////////////////// Relay 35
     if (input == "dev35_on")
     {
      setRegisterPin(dev35, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev35_off") 
{ 
      setRegisterPin(dev35, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 35
/////////////////////////// Relay 36
     if (input == "dev36_on")
     {
      setRegisterPin(dev36, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev36_off") 
{ 
      setRegisterPin(dev36, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 36
/////////////////////////// Relay 37
     if (input == "dev37_on")
     {
      setRegisterPin(dev37, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev37_off") 
{ 
      setRegisterPin(dev37, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 37
/////////////////////////// Relay 38
     if (input == "dev38_on")
     {
      setRegisterPin(dev38, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev38_off") 
{ 
      setRegisterPin(dev38, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 38
/////////////////////////// Relay 39
     if (input == "dev39_on")
     {
      setRegisterPin(dev39, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev39_off") 
{ 
      setRegisterPin(dev39, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 39
/////////////////////////// Relay 40
     if (input == "dev40_on")
     {
      setRegisterPin(dev40, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev40_off") 
{ 
      setRegisterPin(dev40, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 40
/////////////////////////// Relay 41
     if (input == "dev41_on")
     {
      setRegisterPin(dev41, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev41_off") 
{ 
      setRegisterPin(dev41, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 41
/////////////////////////// Relay 42
     if (input == "dev42_on")
     {
      setRegisterPin(dev42, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev42_off") 
{ 
      setRegisterPin(dev42, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 42
/////////////////////////// Relay 43
     if (input == "dev43_on")
     {
      setRegisterPin(dev43, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev43_off") 
{ 
      setRegisterPin(dev43, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 43
/////////////////////////// Relay 44
     if (input == "dev44_on")
     {
      setRegisterPin(dev44, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev44_off") 
{ 
      setRegisterPin(dev44, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 44
/////////////////////////// Relay 45
     if (input == "dev45_on")
     {
      setRegisterPin(dev45, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev45_off") 
{ 
      setRegisterPin(dev45, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 45
/////////////////////////// Relay 46
     if (input == "dev46_on")
     {
      setRegisterPin(dev46, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev46_off") 
{ 
      setRegisterPin(dev46, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 46
/////////////////////////// Relay 47
     if (input == "dev47_on")
     {
      setRegisterPin(dev47, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev47_off") 
{ 
      setRegisterPin(dev47, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 47
/////////////////////////// Relay 48
     if (input == "dev48_on")
     {
      setRegisterPin(dev48, HIGH);
      writeRegisters();
      delay(delayTime);
   //   clearRegisters();
     }
     else if(input == "dev48_off") 
{ 
      setRegisterPin(dev48, LOW);
      writeRegisters();
      delay(delayTime);
  //    clearRegisters();
  
}
////////////////////////// end Relay 48




}
