/*
 * File:   main.c
 * Author: Bahtiyar Bayram
 *
 * Created on 25 August 2022, 15:07
 */


#include "main.h"

void __interrupt() interrupt_manager (void)
{
    // interrupt handler
    if(INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1)
    {
        tmr0_isr();
    }
    else
    {
        //Unhandled Interrupt
    }
}

/* Struct of the gpio_t */
typedef struct {
    volatile unsigned char *led_dir;
    volatile unsigned char *led_port;
    volatile unsigned char *dig_dir;
    volatile unsigned char *dig_port;
    uint8_t pin;
} seven_seg_t;

void sev_seg_init()
{
    /* Initialise pins. */
    /* Disable analog inputs for the digit pins. */
    ANSELB &= ~(0b00001111);
    /* Disable analog inputs for the led segments pins. */
    ANSELD &= ~(0b11111111);
    /* Set digit pins as output. */
    TRISB &= ~(0b00001111);
    /* Set led segments as output. */
    TRISD &= ~(0b11111111);
    /* Reset outputs. */
    LATB &= ~(0b00001111);
    LATB &= ~(0b11111111);
    
    /* Initialise timer. */
    
}

int main(void)
{
    // SCS INTOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCON = 0x72;
    // PRISD enabled; SOSCGO disabled; MFIOSEL disabled; 
    OSCCON2 = 0x04;
    // INTSRC disabled; PLLEN disabled; TUN 0; 
    OSCTUNE = 0x00;
    
    tmr0_init();
    sev_seg_init();
    tmr0_start();
    
    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    RCONbits.IPEN = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    while (1)
    {
        
    }
}
