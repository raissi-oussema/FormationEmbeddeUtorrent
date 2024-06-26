/* Define all needed address BusReg to toggle a led attached pin5 on port B with proteus 8*/
#include 			"stm32f401xc.h"
#include 			"tim.h"
#include            "systick.h"
#include            <stdio.h>
#include 			"uart.h"


int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}
int timestamp=0;
void main(void)
{
	uart2_rxtx_init();
	tim2_pa5_compare_mode();
	tim3_pin6_input_capture();
	while (1){
		/*Wait until edge is captured*/
		while (!(TIM3->SR & TIM_SR_CC1IF)){}
		/*Read the value captured*/
		//timestamp = TIM3->CCR1;
		char str[11];
		convertToString(TIM3->CCR1, str);
		//sprintf(buffer, "0x%ld", timestamp);
		printf("Value reg is %s \n\r", str);
		//systicDelayMs(1000);
	}
}
