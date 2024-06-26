/* Define all needed address BusReg to toggle a led attached pin5 on port B with proteus 8*/
#define 			GPIOBEN			(1U<<1)
#define 			LED				(1U<<5)
#define				LED_PIN			LED

void main(void)
{
	RCC_AHB1EN_R |= (1UL << 1);//set one at second field in RCC register to enable clock for register GPIO_PORT_B

	GPIOB_MODR_R |= (1UL<<10); // set 1 at position 10 (counting from 0) in GPIO_MODE_REGISETR to set pin5 port B as an output
	GPIOB_MODR_R &=~ (1UL<<11); //set 0 at position 11 (counting from 0) in GPIO_MODE_REGISETR to set pin5 port B as an output

	GPIO_OD_R |= (1UL<<5); // set 1 at postion 5 in GPIO_OUTPUT_DATA_REGISTER to turn on the diode
	while (1)
	{
		GPIO_OD_R ^= (1UL<<5); // xor function to change just bit number 5
		for (int i=0;i<180000;i++){} //do nothing
	}
}
