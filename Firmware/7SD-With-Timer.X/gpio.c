/*
 * File:   digital.c
 * Author: neon
 *
 * Created on January 30, 2023, 5:55 AM
 */

#include <xc.h>
#include "gpio.h"

void gpio_init(uint16_t gpio, uint8_t type)
{
    uint8_t port = gpio >> 8;
    uint8_t pin = gpio & 0x0F;

    volatile unsigned char *tris_x = &TRISA + port;
    volatile unsigned char *ansel_x = &ANSELA + port;

    /* Disable ADC for this pin. */
    *ansel_x &= ~(1 << pin);

    if (type == GPIO_OUTPUT)
    {
        /* Set direction register as output. */
        *tris_x &= ~(1 << pin);
    }
    else if (type == GPIO_INPUT)
    {
        /* Set direction register as input. */
        *tris_x |= (1 << pin);
    }
}

void digital_write(uint16_t gpio, uint8_t mode)
{
    uint8_t port = gpio >> 8;
    uint8_t pin = gpio & 0x0F;

    /* Set port register */
    volatile unsigned char *port_x = &PORTA + port;

    if (mode == HIGH)
    {
        /* Set pin */
        *port_x |= (1 << pin);
    }
    else if (mode == LOW)
    {
        /* Clear pin */
        *port_x &= ~(1 << pin);
    }
    else if (mode == TOGGLE)
    {
        /* Toggle pin. */
        *port_x ^= (1 << pin);
    }
}

uint8_t digital_read(uint16_t gpio)
{
    uint8_t port = gpio >> 8;
    uint8_t pin = gpio & 0x0F;

    /* Set port register */
    volatile unsigned char *port_x = &PORTA + port;

    if (((*port_x >> pin) & 0x01) == HIGH)
    {
        return HIGH;
    }

    return LOW; /* Else */
}