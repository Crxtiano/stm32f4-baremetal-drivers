#include "stm32f4_gpio_lib.h"
#include "stm32f4_exti_driver.h"
#include "stm32f4_nvic_driver.h"
#include "stm32f4_systick_driver.h"

/* Interrupt Handler Prototype */
void EXTI0_IRQHandler(void);

int main(void)
{
		
	GPIO_InitTypeDef led;
	
	__LIB_RCC_GPIOD_CLK_ENABLE();

	/****************************
	* Configure LED (PD12)
	****************************/
	led.Pin = GPIO_PIN_12;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Pull = GPIO_NOPULL;
	led.Speed = GPIO_MSP;
	
	LIB_GPIO_Init(GPIOD, &led);
	
	SysTick_Init(16000);
	SysTick_Enable();
	
	while(1){		
		
		LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
		Delay_ms(500);
	}
}
