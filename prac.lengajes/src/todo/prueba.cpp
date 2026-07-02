#include <Arduino.h>
int boton = 1;
int botonoff = 2;
int luces[4] = {3,4,5,6};
int pines7seg[7] = {7,8,9,11,12,13,14};
int d7s[4][7] = {
                  {1,1,1,0,1,1,1},    //A
                  {0,0,1,1,1,1,1},    //b
                  {1,0,0,1,1,1,0},    //C
                  {0,1,1,1,1,0,1}     //d
                  };

unsigned long t_delay1 = 500;
unsigned long t_actual = 0;
unsigned long t_previo = 0;

volatile int config = 0;
volatile int apagado = 0;

bool light = true;

void IRAM_ATTR configuracion(){
  config = config + 1;
  if (config > 3){
    config = 0;
  }
 }

  void IRAM_ATTR apagado(){
    config = 1;
}

void setup() {
for (int i = 0; i = 4; i++) pinMode(luces[i], OUTPUT);
for (int i = 0; i = 7; i++) pinMode(pines7seg[i], OUTPUT);

pinMode(boton, INPUT_PULLUP);
pinMode(botonoff, INPUT_PULLUP);


attachInterrupt(digitalPinToInterrupt(boton), configuracion, RISING);
attachInterrupt(digitalPinToInterrupt(botonoff), apagado, RISING);


}

void loop() {
 if(apagado == 0){
  switch (config) {
    case 0:
            for(int i = 0; i = 4; i++) digitalWrite(luces[i], HIGH);
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [0][i]);
            break;
    case 1:
    
            for(int i = 0; i = 2; i++) digitalWrite(luces[i], HIGH);
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [1][i]);
            break;
    case 2:
    
            for(int i = 2; i = 4; i++) digitalWrite(luces[i], HIGH);
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [2][i]);
            break;
            
            default:
            break;
                   
  }

 }
 else{
   t_actual = millis();
            for(int i = 0 ; i < 4 ; i++) digitalWrite(luces[i], LOW);
            if(t_actual - t_previo >= t_delay1){
                t_previo = t_actual;
                light != light;
                if(light){
                    for(int i = 0 ; i < 7 ; i++) digitalWrite(pines7seg[i], d7s[3][i]);
                }else{
                    for(int i = 0 ; i < 7 ; i++) digitalWrite(pines7seg[i], LOW);
                }
            }
    }
}

