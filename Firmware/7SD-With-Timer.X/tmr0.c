#include "main.h"

void (*tmr0_interrupt_handler)(void);

volatile uint8_t timer0_reload_val;

void tmr0_init(void)
{
    // Set TMR0 to the options selected in the User Interface

    // TMR0H 0; 
    TMR0H = 0x00;

    // TMR0L 131; 
    TMR0L = 0x83;
	
    // Load TMR0 value to the 8-bit reload variable
    timer0_reload_val = 131;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE = 1;

    // T0PS 1:32; T08BIT 8-bit; T0SE Increment_hi_lo; T0CS FOSC/4; TMR0ON enabled; PSA assigned; 
    T0CON = 0xD4;
}

void tmr0_start(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON = 1;
}

void tmr0_stop(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON = 0;
}

void tmr0_isr(void)
{

    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    // reload TMR0
    TMR0L = timer0_reload_val;

    if(tmr0_interrupt_handler)
    {
        tmr0_interrupt_handler();
    }

    // add your TMR0 interrupt custom code
}


void tmr0_set_interrupt_handler(void (* interrupt_handler)(void)){
    tmr0_interrupt_handler = interrupt_handler;
}