#include <Arduino.h>

#define RXD2 16 // Conectar al PA9 (TX) del STM32
#define TXD2 17 // Conectar al PA10 (RX) del STM32
int pines[7]={14,27,26,25,33,32,35};
int an[10][7]={
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1}
};

void setup() {
  for(int i=0;i<10;i++){
  pinMode(pines[i],OUTPUT);
  }
  
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);


}

void loop() {
    if (Serial2.available() > 0) {
        int num = Serial2.read();
      for(int i=0;i<7;i++){
        digitalWrite(pines[i],an[num][i]);
      }
    }
}