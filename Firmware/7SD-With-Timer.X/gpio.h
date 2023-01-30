/* 
 * File:   gpio.h
 * Author: Bahtiyar Bayram
 * Comments:
 * Revision history: v0.1
 */

#ifndef GPIO_H
#define	GPIO_H

#include <stdint.h>

/**
  Section: Defines
 */

/* GPIO Type */
#define GPIO_OUTPUT     0
#define GPIO_INPUT      1

/* Digital State */
#define LOW     0
#define HIGH    1
#define TOGGLE  2

/* Pin definitions. */
#define A0 0x0000
#define A1 0x0001
#define A2 0x0002
#define A3 0x0003
#define A4 0x0004
#define A5 0x0005
#define A6 0x0006
#define A7 0x0007

#define B0 0x0100
#define B1 0x0101
#define B2 0x0102
#define B3 0x0103
#define B4 0x0104
#define B5 0x0105
#define B6 0x0106
#define B7 0x0107

#define C0 0x0200
#define C1 0x0201
#define C2 0x0202
#define C3 0x0203
#define C4 0x0204
#define C5 0x0205
#define C6 0x0206
#define C7 0x0207

#define D0 0x0300
#define D1 0x0301
#define D2 0x0302
#define D3 0x0303
#define D4 0x0304
#define D5 0x0305
#define D6 0x0306
#define D7 0x0307

#define E0 0x0400
#define E1 0x0401
#define E2 0x0402
#define E3 0x0403
#define E4 0x0404
#define E5 0x0405
#define E6 0x0406
#define E7 0x0407

#ifdef	__cplusplus

extern "C"
{
    
#endif /* __cplusplus */

/**
  @Summary
    Initialise GPIO pin

  @Description
    This function initialises given gpio pin.

  @Preconditions
    None

  @Param
    GPIO pin to be initialise in a 2-byte format.

  @Param
    Mode of the gpio pin.

  @Returns
    None

  @Example
    <code>
    // Initialize 7SD variable.
    gpio_init(D0, GPIO_OUTPUT);
    
    int main(void)
    {
        // Oscillator initialisation...

        // Set D0 to HIGH
        digital_write(D0, HIGH);      

        while (1)
        {
            // Do something else...
            __delay_ms(10);
        }
    }
    </code>
 */
void gpio_init(uint16_t gpio, uint8_t type);

/**
  @Summary
    Change the pin output

  @Description
    This function can set digital pin as LOW, HIGH or can TOGGLE pin.

  @Preconditions
    Initialise gpio pin as GPIO_OUTPUT.

  @Param
    GPIO pin to be initialise in a 2-byte format.

  @Param
    Type (HIGH, LOW, or TOGGLE) of the gpio pin.

  @Returns
    None

  @Example
    <code>
    // Initialize 7SD variable.
    gpio_init(D0, GPIO_OUTPUT);
    
    int main(void)
    {
        // Oscillator initialisation...

        // Set D0 to HIGH
        digital_write(D0, HIGH);      

        while (1)
        {
            // Do something else...
   
            // Toggle D0 pin.
            digital_write(D0, TOGGLE);      
            __delay_ms(500);
        }
    }
    </code>
 */
void digital_write(uint16_t gpio, uint8_t mode);

/**
  @Summary
    Get value of the pin

  @Description
    This function gets the value of the digital pin.

  @Preconditions
    Initialise gpio pin as GPIO_INPUT.

  @Param
    GPIO pin to be initialise in a 2-byte format.

  @Returns
    Read value of the given pin.

  @Example
    <code>
    // Initialize 7SD variable.
    gpio_init(A0, GPIO_OUTPUT);
    gpio_init(D0, GPIO_OUTPUT);
    
    int main(void)
    {
        // Oscillator initialisation...    

        while (1)
        {
            // Do something else...
   
            // Set D0 value to readed A0 value.
            digital_write(D0, digital_read(A0));      
            __delay_ms(50);
        }
    }
    </code>
 */
uint8_t digital_read(uint16_t gpio);

#ifdef	__cplusplus // Provide C++ Compatibility
    
}

#endif /* __cplusplus */

#endif	/* GPIO_H */
/**
 End of File
 */

