/*
 * gpio_devics.c
 *
 *  Created on: Oct 6, 2021
 *      Author: pbbal
 */

#include <gpio_devices.h>
#include <msp430.h>

void init_gpio(void){
    // N-FET signal = P2.3
    // Board power LED = P2.4
    // Sensor Power LED = P2.5

    // Configure pins 3, 4, and 5 on port 2 as digital outputs
    P2DIR = BIT3 | BIT4 | BIT5;
    // Disable all outputs (outputs low) except board power LED
    P2OUT = BIT4;
    // Disable pullup / pulldown resistors for inputs
    P2REN = 0;

    // Configure rest of ports to use all pins as inputs
    // with no resistors (good idea, not required)
    P1DIR = 0;
    P1OUT = 0;
    P1REN = 0;

    P3DIR = 0;
    P3OUT = 0;
    P3REN = 0;

    TACCTL0 |= CCIE;
    // SMCLK / 8, upmode.
    TA0CTL = TASSEL_2 + MC_1 + ID_3 + TACLR;
    TACCR0 = 62500;
}

void enable_sensors(){
    // P1.3 high to allow N-FET to ground sensors
    // P1.5 high to turn on sensor power LED
    P2OUT |= BIT3 | BIT5;
}

void disable_sensors(){
    // P1.3 low to disable ground connection for sensors
    // P1.5 low to turn off sensor power LED
    // Set pin 3's output to 0 (low) without affecting other outputs.
    P2OUT &= ~(BIT3 | BIT5);
}


#pragma vector = TIMER0_A0_VECTOR
__interrupt void blink_power_led(void) {
    P2OUT ^= BIT4;
}
