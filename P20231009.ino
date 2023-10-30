#include <ESP32Servo.h>

#define LFP 15
#define LFN 2
#define LBP 0
#define LBN 4
#define RBP 33
#define RBN 32
#define RFP 26
#define RFN 25
#define LS 23
#define RS 36
#define MS 14
#define B 19
#define trig 17 //發出聲波腳位(ESP32 GPIO17)
#define echo 16 //接收聲波腳位(ESP32 GPIO16)


void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  // put your setup code here, to run once:
    pinMode(15, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(0, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(33, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
    //Left Sensor
    pinMode(23, INPUT);
    //Right Sensor
    pinMode(36, INPUT);
    ///Middle Sensor
    pinMode(14,INPUT);

    pinMode(B,INPUT);
    
   //A set per wheel(LF)
    digitalWrite(15,0);
    digitalWrite(2,0);
   //A set per wheel(LB)
    digitalWrite(0,0);
    digitalWrite(4,0);
   //A set per wheel(RB)
    digitalWrite(33,0);
    digitalWrite(32,0);
   //A set per wheel(RF)
    digitalWrite(26,0);
    digitalWrite(25,0);
   //Ultrasonic
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    while(digitalRead(B) == 0){
      STOP();
    }
   tone(5, 262, 500);
}

void loop() {
if(digitalRead(RS)){
  if(digitalRead(LS)){
    STOP();
    tone(5, 262, 500);
    while(digitalRead(B) == 0){
    }
    tone(5, 262, 500);
  } else {
    R();
    delay(200);
}
  
} else {
  if(digitalRead(LS)){
    L();
    delay(200);
  } else {
    FORWARD();
  }
}
//  Serial.print(digitalRead(LS)); //B:1 W:0
//  Serial.print(digitalRead(MS));
//  Serial.println(digitalRead(RS));
//  delay(1000);
}


unsigned long ping() { 
  digitalWrite(trig, HIGH); //啟動超音波
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trig, LOW);  //關閉超音波
  return pulseIn(echo, HIGH); //計算傳回時間
 }
void FORWARD(){
  analogWrite(LFP,255);
  analogWrite(LFN,0);
  analogWrite(LBP,255);
  analogWrite(LBN,0);
  analogWrite(RFP,255);
  analogWrite(RFN,0);
  analogWrite(RBP,255);
  analogWrite(RBN,0);
}

void STOP(){
  analogWrite(LFP,0);
  analogWrite(LFN,0);
  analogWrite(LBP,0);
  analogWrite(LBN,0);
  analogWrite(RFP,0);
  analogWrite(RFN,0);
  analogWrite(RBP,0);
  analogWrite(RBN,0);
}

void RT(){
  analogWrite(LFP,255);
  analogWrite(LFN,0);
  analogWrite(LBP,255);
  analogWrite(LBN,0);
  analogWrite(RFP,0);
  analogWrite(RFN,255);
  analogWrite(RBP,0);
  analogWrite(RBN,255);
}

void LT(){
  analogWrite(LFP,0);
  analogWrite(LFN,255);
  analogWrite(LBP,0);
  analogWrite(LBN,255);
  analogWrite(RFP,255);
  analogWrite(RFN,0);
  analogWrite(RBP,255);
  analogWrite(RBN,0);
}

void L(){
  analogWrite(LFP,0);
  analogWrite(LFN,255);
  analogWrite(LBP,0);
  analogWrite(LBN,255);
  analogWrite(RFP,255);
  analogWrite(RFN,0);
  analogWrite(RBP,255);
  analogWrite(RBN,0);
}

void R(){
  analogWrite(LFP,255);
  analogWrite(LFN,0);
  analogWrite(LBP,255);
  analogWrite(LBN,0);
  analogWrite(RFP,0);
  analogWrite(RFN,255);
  analogWrite(RBP,0);
  analogWrite(RBN,255);
}
