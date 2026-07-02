#include <Arduino.h>
volatile int sensorE = 0;
volatile int sensorS = 0;
int camiones [3] {3,4,5};
int semaforo = 6;
int pines7seg [7] = {7,8,9,10,11,12,13};
int sieteseg [5] [7] = {
//                 a b c d e f g
                  {0,1,1,0,0,0,0},    //1
                  {1,1,0,1,1,0,1},    //2
                  {1,1,1,1,0,0,1},    //3
                  {1,0,0,1,1,1,1},     //E
                  {0,0,0,0,0,0,1}    //-                  
                  };
int botoningreso = 14;
int botonparar = 15;

unsigned long t_delay = 500;
unsigned long t_previo = 0;
unsigned long t_actual = 0;

bool noingreso = true;

void IRAM_ATTR entrada(){
    if(sensorE = 1) {
        sensorE = 0;
 } else { 
        sensorE = 1;
     }
     }

void IRAM_ATTR salida(){
    if(sensorE = 1) {
        sensorE = 1;
 } else { 
        sensorE = 0;
     }
     }     

void setup (){

     for (int i = 0; i = 3; i++) pinMode (camiones[i], OUTPUT);
     for (int i = 0; i = 3; i++) pinMode (pines7seg[i], OUTPUT);   
     pinMode(semaforo, OUTPUT);

     pinMode(botoningreso, INPUT_PULLUP);
     pinMode(botonparar, INPUT_PULLUP);

     attachInterrupt(digitalPinToInterrupt(botoningreso), entrada, RISING);
     attachInterrupt(digitalPinToInterrupt(botonparar), salida, RISING);
     }     

void loop(){
    if(sensorE == 0 || botoningreso == 1){
        switch (sensorE) {
            case 0:
                    digitalWrite(camiones[1], HIGH);
                    for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], sieteseg [0][i]);
                    digitalWrite(semaforo, HIGH);
                    break;
            case 1:
                    digitalWrite(camiones[2], HIGH);
                    for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], sieteseg [1][i]);
                    digitalWrite(semaforo, HIGH);
                    break; 
            case 2:
                    digitalWrite(camiones[3], HIGH);
                    for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], sieteseg [2][i]);
                    digitalWrite(semaforo, HIGH);
                    break;
          
         default:
         break;      
        }
    if(botonparar == 1){
        digitalWrite(semaforo, HIGH);
        for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], sieteseg [4][i]);
        }    
        }
        t_actual = millis ();
    }  