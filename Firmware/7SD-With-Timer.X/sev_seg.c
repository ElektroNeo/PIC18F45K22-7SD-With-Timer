/*
 * File:   sev_seg.c
 * Author: Bahtiyar Bayram
 *
 * Created on January 30, 2023, 6:05 AM
 */


#include "sev_seg.h"

void sev_seg_init(sev_seg_t *seven_seg)
{
    /* Initialise pins. */
    for (uint8_t i = 0; i < SEVEN_SEG_NUM_OF_DIGITS; i++)
    {
        gpio_init(seven_seg->digits[i], GPIO_OUTPUT);
    }

    for (uint8_t i = 0; i < 7; i++)
    {
        gpio_init(seven_seg->segments[i], GPIO_OUTPUT);
    }

    /* Initialise the timer. */
    tmr0_init();
    /* Start the timer */
    tmr0_start();
}

void sev_seg_set(sev_seg_t *seven_seg, int16_t num)
{
    /* Set the 7SD number. */
    seven_seg->number = num;
}

void sev_seg_update(sev_seg_t *seven_seg)
{
    int16_t num = seven_seg->number;
    int8_t digit_num = 0;

    /* Turn off digits. */
    for (uint8_t i = 0; i < SEVEN_SEG_NUM_OF_DIGITS; i++)
    {
        digital_write(seven_seg->digits[i], HIGH);
    }

    /* Get digit number if it is positive otherwise get '-' sign. */
    if (seven_seg->number < 0 && (seven_seg->digit_count == (SEVEN_SEG_NUM_OF_DIGITS - 1)))
    {
        digit_num = 10; /* Minus sign. */
    }
    else
    {
        if (num < 0) num *= -1;

        /* Get digit number. */
        for (uint8_t i = 0; i < seven_seg->digit_count; i++)
        {
            num /= 10;
        }
        digit_num = num % 10;
    }

    /* Update segments of current digit. */
    for (uint8_t i = 0; i < 7; i++)
    {
        digital_write(seven_seg->segments[i], (sev_seg_digits[digit_num] >> i) & 0x01);
    }

    /* Turn on digit. */
    digital_write(seven_seg->digits[SEVEN_SEG_NUM_OF_DIGITS - seven_seg->digit_count - 1], LOW);

    /* Increase digit counter to the next digit. */
    if (++(seven_seg->digit_count) >= SEVEN_SEG_NUM_OF_DIGITS)
        seven_seg->digit_count = 0;
}