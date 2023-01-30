/*
 * File:   main.c
 * Author: Bahtiyar Bayram
 *
 * Created on 25 August 2022, 15:07
 */


#include "main.h"
#include <stdint.h>

sev_seg_t sev_seg = {
    .digits[0] = B0,
    .digits[1] = B1,
    .digits[2] = B2,
    .digits[3] = B3,
    .segments[0] = D0,
    .segments[1] = D1,
    .segments[2] = D2,
    .segments[3] = D3,
    .segments[4] = D4,
    .segments[5] = D5,
    .segments[6] = D6,
};

void __interrupt() interrupt_manager(void)
{
    // TMR0 interrupt handler
    if (INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1)
    {
        // Update seven segment display.
        sev_seg_update(&sev_seg);

        // Clear interrupt flag and reload timer.
        tmr0_isr();
    }
    else
    {
        // Unhandled Interrupt
    }
}

int main(void)
{
    // SCS INTOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCON = 0x72;
    // PRISD enabled; SOSCGO disabled; MFIOSEL disabled; 
    OSCCON2 = 0x04;
    // INTSRC disabled; PLLEN disabled; TUN 0; 
    OSCTUNE = 0x00;

    // Initialise seven segment display.
    sev_seg_init(&sev_seg);

    // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
    RCONbits.IPEN = 0;
    // Enable peripheral interrupts.
    INTCONbits.PEIE = 1;
    // Enable global interrupt.
    INTCONbits.GIE = 1;

    // Set 7SD with a value n.
    int16_t n = 50;
    sev_seg_set(&sev_seg, n);

    int16_t counter = 0;

    while (1)
    {
        counter = 0;
        n--;
        // Set 7SD with a new value n.
        sev_seg_set(&sev_seg, n);

        __delay_ms(10);
    }
}
