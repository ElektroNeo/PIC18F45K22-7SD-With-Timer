/* 
 * File:   sev_seg.h
 * Author: Bahtiyar Bayram
 * Comments:
 * Revision history: v0.1
 */
 
#ifndef SEV_SEG_H
#define	SEV_SEG_H

#include <stdint.h>
#include "gpio.h"
#include "tmr0.h"

#define SEVEN_SEG_NUM_OF_DIGITS 4

/* Struct of the 7SD */
typedef struct
{
    uint16_t digits[SEVEN_SEG_NUM_OF_DIGITS];
    uint16_t segments[7];
    int16_t number;
    uint8_t digit_count;
} sev_seg_t;

const unsigned char sev_seg_digits[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40};

#ifdef	__cplusplus

extern "C"
{

#endif /* __cplusplus */

    /**
  Section: SEV_SEG APIs
 */

/**
  @Summary
    7SD Initialisation

  @Description
    This function initialises the 7SD with a given sev_seg_t struct.

  @Preconditions
    Define and initialise connections of the sev_seg_t variable before calling this function.

  @Param
    Variable of the 7SD to be initialise.

  @Returns
    None

  @Example
    <code>
    // Initialize 7SD variable.
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
    
    int main(void)
    {
        // Oscillator initialisation...

        // Initialise seven segment display.
        sev_seg_init(&sev_seg);

        sev_seg_set(&sev_seg, 145);

        while (1)
        {
            // Do something else...
            __delay_ms(10);
        }
    }
    </code>
 */
void sev_seg_init(sev_seg_t *seven_seg);

/**
  @Summary
    Set 7SD value

  @Description
    This function sets the value of the given 7SD.

  @Preconditions
    Call and initialise sev_seg_init() before calling this function.

  @Param
    Variable of the 7SD to be set.

  @Param
    Value to be set.

  @Returns
    None

  @Example
    <code>
    // Initialize 7SD variable.
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
    
    int main(void)
    {
        // Oscillator initialisation...

        // Initialise seven segment display.
        sev_seg_init(&sev_seg);

        sev_seg_set(&sev_seg, 145);

        while (1)
        {
            // Do something else...
            __delay_ms(10);
        }
    }
    </code>
 */
void sev_seg_set(sev_seg_t *seven_seg, int16_t num);

/**
  @Summary
    Update 7SD

  @Description
    This function updates 7SD. Call this function in a timer interrupt.

  @Preconditions
    Call and initialise sev_seg_init() before calling this function.

  @Param
    Variable of the 7SD to be update.

  @Returns
    None

  @Example
    <code>
    // Initialize 7SD variable.
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
    }
    
    int main(void)
    {
        // Oscillator initialisation...

        // Initialise seven segment display.
        sev_seg_init(&sev_seg);

        sev_seg_set(&sev_seg, 145);

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
    </code>
 */
void sev_seg_update(sev_seg_t *seven_seg);

#ifdef	__cplusplus

}

#endif /* __cplusplus */

#endif	/* SEV_SEG_H */

