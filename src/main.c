#include <msp430.h>
#include <gpio_devices.h>
#include <clocks.h>
#include <pc_comm.h>

int main(void){
    // Disable watchdog
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	// Initialize devices
	init_clocks();
	init_gpio();
	init_pc_uart();

	// Main loop
	while(1){
	    // Will enter LPM0 while waiting for UART activity
	    pc_comm_process();
	}
}

