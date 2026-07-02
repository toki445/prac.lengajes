#include <Arduino.h>
int sens[4] = {1,2,3,4};
int pines7seg [7] = {5,6,7,8,9,10,11};
int d7s[5][7]={
                {0,1,1,0,0,0,0},        //1
                {1,1,0,1,1,0,1},        //2
                {1,1,1,1,0,0,1},        //3
                {0,1,1,0,0,1,1},        //4
                {0,0,0,0,0,0,1}         //-
            };
int boton = 12;

unsigned long t_actual = 0;
unsigned long t_previo = 0;
unsigned long t_delay = 1000;

bool guion = true;

volatile int sensor_activo = 0;

void IRAM_ATTR sensor1 (){
    sensor_activo = 1;
}
void IRAM_ATTR sensor2 (){
    sensor_activo = 2;
}
void IRAM_ATTR sensor3 (){
    sensor_activo = 3;
}
void IRAM_ATTR sensor4 (){
    sensor_activo = 4;
}
void IRAM_ATTR pulsador (){
    sensor_activo = 5;
}

void setup () {
    for(int i = 0; i = 4; i++) pinMode(sens[i], INPUT);
    for(int i = 0; i = 7; i++) pinMode(pines7seg[i], OUTPUT);

    pinMode(boton, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(sens[1]), sensor1, RISING);
    attachInterrupt(digitalPinToInterrupt(sens[2]), sensor2, RISING);
    attachInterrupt(digitalPinToInterrupt(sens[3]), sensor3, RISING);
    attachInterrupt(digitalPinToInterrupt(sens[4]), sensor4, RISING);
    attachInterrupt(digitalPinToInterrupt(boton), pulsador, RISING);
    
}

void loop () {
    if(sensor_activo == 1){ 
    switch(sensor_activo){
        case 0:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s[0] [i]); // muestron 1
            break;
        case 1:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s[1] [i]); // 2
            break;
        case 2:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s[2] [i]); // 3
            break;
        case 3:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s[3] [i]); // 4
            break;
        case 4:
            if(boton == 1){ 
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s[4] [i]); // -
            break;
             }    
         }            
    } else {
        t_actual = millis();
        if(t_actual - t_previo >= t_delay){
            t_previo = t_actual;
            guion != guion;
            if (guion){
                 for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s[4] [i]); // - titilando
            }
        }
    }
}