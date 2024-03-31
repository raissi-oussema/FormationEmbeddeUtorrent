/* Define all needed address BusReg to toggle a led attached pin5 on port B with proteus 8*/
#include 			"stm32f401xc.h"
#include 			"systick.h"
#include            <stdio.h>
#include 			"uart.h"

int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}
void main(void)
{
	uart2_rxtx_init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//set one at second field in RCC register to enable clock for register GPIO_PORT_B

	GPIOA->MODER |=  GPIO_MODER_MODE5_0; // set 1 at position 10 (counting from 0) in GPIO_MODE_REGISETR to set pin5 port B as an output
	GPIOA->MODER &=~ GPIO_MODER_MODE5_1;
	
	while (1){
		GPIOA->ODR ^= (1UL<<5);
		printf ("A second just passed \n\r");
		// wait for one second
		systicDelayMs(1000);
	}
}