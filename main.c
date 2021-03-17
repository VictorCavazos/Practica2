/*
 * File:   main.c
 * Author: A01177055
 *
 * Created on February 23, 2021, 12:33 AM
 */
////////////Libraries / Headers SECTION ////////////////
#include "device_config.h"

#include <xc.h>
//////////////////////// Directives SECTION ///////////////////////
#define _XTAL_FREQ 1000000
#define DELAY_SWEEP 1000
//////////////////////// Data Type SECTION ///////////////////////
//Enumeration is a user defined data type in C. It is mainly used to assign
//names to integral constants, the names make a program easy to read and
//maintain.



enum por_dir{ output, input}; //              output = 0, input = 1
enum por_ACDC{ digital, analog};//            digital = 0, analog = 1
enum resistor_state{ set_ON, res_ON};//       set_ON = 0, res_ON = 1
enum led_state{ led_OFF, led_ON};//           led_OFF = 0, led_ON = 1
enum butto_state{ pushed, no_pushed};//       pushed = 0, no_pushed = 1

/////////////////////// ISRs SECTION ////////////////
//ISR for high-priority
void __interrupt ( high_priority ) high_isr( void );
//ISR for low-priority
void __interrupt ( low_priority ) low_isr( void );
////////////////////Function Declaration//////////////////////////
void portsInit( void );
void ApagarLed( void );
void PrenderLed( void );
void ChecarPush( void );
void Secuencia ( void );

///////////////////////////////////Main Section////////////////////
void main(void) {
    int n = 0;
    int x = 0;
    //Configurations
    portsInit();
    //infinite cycle
    while( 1 ) {
PrenderLed();// Encender led aleatorio
__delay_ms(500);// esperar medio segundo
ChecarPush();// checar si un boton fue presionado
if(n==x){ // si el boton coincide con el led
    ApagarLed(); //apagar los leds
Secuencia(); // poner secuencia larson
}
else{ //si no
__delay_ms(250); // esperar 250 ms
}
ChecarPush(); // checar si un boton fue presionado
if(n==x){ // si el boton coincide con el led
    ApagarLed(); //apagar los leds
Secuencia(); // poner secuecnia larson
}
else{ // sino
} 
ApagarLed(); //apagar todos los leds
    }
    }
/////////////////Functions Section/////////////////////////
void portsInit( void ) {//             Ports Configuration.

    ANSELB = digital;//                Set PortB as digital port.
    TRISBbits.TRISB0 = output;//       Set RB0 as output.
    TRISBbits.TRISB1 = output;//       Set RB1 as output.
    TRISBbits.TRISB2 = output;//       Set RB2 as output.
    TRISBbits.TRISB3 = output;//       Set RB3 as output.
    TRISBbits.TRISB4 = output;//       Set RB4 as output.
    TRISBbits.TRISB5 = output;//       Set RB5 as output.
    TRISBbits.TRISB6 = output;//       Set RB6 as output.
    TRISBbits.TRISB7 = output;//       Set RB7 as output.
    ANSELD = digital;//                Set PortD as digital port.
    TRISDbits.TRISD0 = input;//        Set RD0 as input.
    TRISDbits.TRISD1 = input;//        Set RD1 as input.
    TRISDbits.TRISD2 = input;//        Set RD2 as input.
    TRISDbits.TRISD3 = input;//        Set RD3 as input.
    TRISDbits.TRISD4 = input;//        Set RD4 as input.
    TRISDbits.TRISD5 = input;//        Set RD5 as input.
    TRISDbits.TRISD6 = input;//        Set RD6 as input.
    TRISDbits.TRISD7 = input;//        Set RD7 as input.
}
void Secuencia( void ) {
LATBbits.LATB0 = led_ON; //Encender led 0
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB0=led_OFF;// Apagar led 0
LATBbits.LATB1 = led_ON; //Encender led 1
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB1=led_OFF;// Apagar led 1
LATBbits.LATB2 = led_ON; //Encender led 2
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB2=led_OFF;// Apagar led 2
LATBbits.LATB3 = led_ON; //Encender led 3
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB3=led_OFF;// Apagar led 3
LATBbits.LATB4 = led_ON; //Encender led 4
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB4=led_OFF;// Apagar led 4
LATBbits.LATB5 = led_ON; //Encender led 5
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB5=led_OFF;// Apagar led 5
LATBbits.LATB6 = led_ON; //Encender led 6
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB6=led_OFF;// Apagar led 6
LATBbits.LATB7 = led_ON; //Encender led 7
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB7=led_OFF;// Apagar led 7
LATBbits.LATB6 = led_ON; //Encender led 6
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB6=led_OFF;// Apagar led 6
LATBbits.LATB5 = led_ON; //Encender led 5
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB5=led_OFF;// Apagar led 5
LATBbits.LATB4 = led_ON; //Encender led 4
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB4=led_OFF;// Apagar led 4
LATBbits.LATB3 = led_ON; //Encender led 3
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB3=led_OFF;// Apagar led 3
LATBbits.LATB2 = led_ON; //Encender led 2
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB2=led_OFF;// Apagar led 2
LATBbits.LATB1 = led_ON; //Encender led 1
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB1=led_OFF;// Apagar led 1
LATBbits.LATB0 = led_ON; //Encender led 0
__delay_ms(DELAY_SWEEP);// Esperar 300 ms
LATBbits.LATB0=led_OFF;// Apagar led 0
}
void PrenderLed(void){
    int n = 0;
    n = (rand() % 8);//igualar n a un numero aleatorio de 0 a 8
if(n==0){ //si n es igual a 0
LATBbits.LATB0 = led_ON; //encender led 0
}
else if(n==1){//si n es igual a 1
LATBbits.LATB1=led_ON; //encender led 1
}
else if(n==2){//si n es igual a 2
LATBbits.LATB2=led_ON; //encender led 2
}
else if(n==3){//si n es igual a 3
LATBbits.LATB3=led_ON; //encender led 3
}
else if(n==4){//si n es igual a 4
LATBbits.LATB4=led_ON; //encender led 4
}
else if(n==5){//si n es igual a 5
LATBbits.LATB5=led_ON; //encender led 5
}
else if(n==6){//si n es igual a 6
LATBbits.LATB6=led_ON; //encender led 6
}
else {//si n es igual a 7
LATBbits.LATB7=led_ON; //encender led 7
}
}
void ChecarPush(void){
    int x = 0;
if(PORTDbits.RD0==pushed){// checar boton 0
x=0;// igualar x a 0
}
else if(PORTDbits.RD1==pushed){// checar boton 1
x=1;// igualar x a 1
}
else if(PORTDbits.RD2==pushed){// checar boton 2
x=2;// igualar x a 2
}
else if(PORTDbits.RD3==pushed){// checar boton 3
x=3;// igualar x a 3
}
else if(PORTDbits.RD4==pushed){// checar boton 4
x=4;// igualar x a 4
}
else if(PORTDbits.RD5==pushed){// checar boton 5
x=5;// igualar x a 5
}
else if(PORTDbits.RD6==pushed){// checar boton 6
x=6;// igualar x a 6
}
else if(PORTDbits.RD7==pushed){// checar boton 7
x=7;// igualar x a 7
}
else{
x=9;// igualar x a 9
}
}
void ApagarLed(void){
LATBbits.LATB0=led_OFF;// apagar led 0
LATBbits.LATB1=led_OFF;// apagar led 1
LATBbits.LATB2=led_OFF;// apagar led 2
LATBbits.LATB3=led_OFF;// apagar led 3
LATBbits.LATB4=led_OFF;// apagar led 4
LATBbits.LATB5=led_OFF;// apagar led 5
LATBbits.LATB6=led_OFF;// apagar led 6
LATBbits.LATB7=led_OFF;// apagar led 7
}
//////////////////////END//////////////////////////////////////
