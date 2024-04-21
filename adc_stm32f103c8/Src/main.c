/* Define all needed address BusReg to toggle a led attached pin5 on port B with proteus 8*/
#include <stdio.h>
#include "uart_stm32f1.h"
#include "adc_stm32f1.h"

int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}
uint32_t value;
void main(void)
{
	uart2_rxtx_init();
    pa1_adc_init();
	start_conversion();

    while (1) {
        value = adc_read();
		printf("ADC value: %ld\n\r", value);
        for (int i=0;i<100000;i++){}
		}
}