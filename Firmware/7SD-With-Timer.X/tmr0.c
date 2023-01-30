#include "main.h"

void (*tmr0_isr_handler)(void);

volatile uint8_t tmr0_reload_val;

void tmr0_init(void)
{
    // Set TMR0 to the options

    // TMR0H 0; 
    TMR0H = 0x00;

    // TMR0L 131; 
    TMR0L = 0x83;

    // Load TMR0 value to the 8-bit reload variable
    tmr0_reload_val = 31;

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
    // Clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    // Reload TMR0
    TMR0L = tmr0_reload_val;

    // Check for null
    if (tmr0_isr_handler)
    {
        tmr0_isr_handler();
    }

    // Add your TMR0 interrupt custom code
}

void tmr0_set_isr_handler(void (* isr_handler)(void))
{
    tmr0_isr_handler = isr_handler;
}