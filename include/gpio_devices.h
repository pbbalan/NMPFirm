/*
 * gpio_devics.h
 *
 *  Created on: Oct 6, 2021
 *      Author: pbbal
 */

#ifndef INCLUDE_GPIO_DEVICS_H_
#define INCLUDE_GPIO_DEVICS_H_


// This line is a function declaration
// It states that a function with this signature exists in some source file
// This does not define (implement) the function
void init_gpio(void);

void enable_sensors();

void disable_sensors();

__interrupt void blink_power_led(void);

#endif /* INCLUDE_GPIO_DEVICS_H_ */


