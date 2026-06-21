#include "stm32f4_gpio_lib.h"
#include "stm32f4_exti_driver.h"
#include "stm32f4_nvic_driver.h"

/* Interrupt Handler Prototype */
void EXTI0_IRQHandler(void);

int main(void)
{
		
	GPIO_InitTypeDef led;
	GPIO_InitTypeDef button;
	
	/* Enable GPIO Clocks */
	__LIB_RCC_GPIOA_CLK_ENABLE();
	__LIB_RCC_GPIOD_CLK_ENABLE();

	/****************************
	* Configure LED (PD12)
	****************************/
	led.Pin = GPIO_PIN_12;
	led.Mode = GPIO_MODE_OUTPUT_PP;
	led.Pull = GPIO_NOPULL;
	led.Speed = GPIO_MSP;
	
	LIB_GPIO_Init(GPIOD, &led);
	
	/****************************
	* Configure Button (PA0)
	****************************/
	button.Pin = GPIO_PIN_0;
	button.Mode = GPIO_MODE_INPUT;
	button.Pull = GPIO_NOPULL;
	
	LIB_GPIO_Init(GPIOA, &button);
	
	/****************************
	* Configure EXTI0 on PA0
	****************************/
	EXTI_Init(0, GPIOA, EXTI_TRIGGER_RISING);
	
	/****************************
	* Enable EXTI0 Interrupt in NVIC
	****************************/
	NVIC_EnableIRQ(EXTI0_IRQn);
	
	/****************************
	* TEST:
	* Trigger EXTI0 by Software
	* Uncomment for debugging
	****************************/
	//EXTI->SWIER |= (1UL << 0);
	
	
	while(1){		
		/* Main loop */
	}
}
void EXTI0_IRQHandler(void){
	
	EXTI_ClearPending(0);
	
	for(volatile	uint32_t i=0; i < 50000; i++); // simple debounce
	
	LIB_GPIO_TogglePin(GPIOD, GPIO_PIN_12);

}
