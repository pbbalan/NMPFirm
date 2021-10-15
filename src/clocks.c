/*
 * clocks.c
 *
 *  Created on: Oct 11, 2021
 *      Author: pbbal
 */
#include <clocks.h>
#include <msp430.h>


void init_clocks(void){
    // MCLK = SMCLK = DCO = 1MHz

    // Select lowest DC0x and MODx
    DCOCTL = 0;
    // Set DCO freq to 1MHz and ACLK
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
}
