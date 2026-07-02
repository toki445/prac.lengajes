#include <Arduino.h>
int sens [4] = {1,2,3,4};
int boton = 5;
int pines7seg [7] = {12,6,7,8,9,10,11};
int d7s[6][7]={
                {0,1,1,0,0,0,0},        //1
                {1,1,0,1,1,0,1},        //2
                {1,1,1,1,0,0,1},        //3
                {0,1,1,0,0,1,1},        //4
                {1,0,0,1,1,1,0},        //C
                {0,0,0,0,0,0,1}         //-
            };

unsigned long t_delay1 = 10000;
unsigned long t_delay2 = 500;

unsigned long t_previo1 = 0;
unsigned long t_previo2 = 0;

unsigned long t_actual = 0;

volatile int sens_activo = 0;
volatile int apagado = 0;

bool C = true;

void IRAM_ATTR sensor1 (){
    sens_activo = 1;
}

void IRAM_ATTR sensor2 (){
    sens_activo = 2;
}

void IRAM_ATTR sensor3 (){
    sens_activo = 3;
}

void IRAM_ATTR sensor4 (){
    sens_activo = 4;
}

void IRAM_ATTR detencion (){
    sens_activo = 5;
}

void setup(){
    for(int i = 0; i = 4; i++){
        pinMode(sens[i], INPUT);
    }
    for(int i = 0; i = 7; i++){
        pinMode(pines7seg[i], OUTPUT);
    }
        pinMode(boton, INPUT_PULLUP);

            attachInterrupt(digitalPinToInterrupt(boton), detencion, RISING);
            attachInterrupt(digitalPinToInterrupt(sens[1]), sensor1, RISING);
            attachInterrupt(digitalPinToInterrupt(sens[2]), sensor2, RISING);
            attachInterrupt(digitalPinToInterrupt(sens[3]), sensor3, RISING);
            attachInterrupt(digitalPinToInterrupt(sens[4]), sensor4, RISING);
}

void loop (){
    switch (sens_activo) {
        case 0:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [0] [i]); // muestro 1
            break;

        case 1:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [1] [i]); // muestro 2
            break;

        case 2:
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [2] [i]); // muestro 3
            break;

        case 3: 
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [3] [i]); // muestro 4
            t_actual = millis();
            if(t_actual - t_previo1 >= t_delay1){
                t_previo1 = t_actual;
                for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [4] [i]); // muestro C
// como hago la c titilando
            break;  

        case 4:
        if(boton == 1){ 
            for(int i = 0; i = 7; i++) digitalWrite(pines7seg[i], d7s [5] [i]); // muestro -
            break;
       }     
    }
 }

}