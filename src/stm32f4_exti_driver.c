#include "stm32f4_exti_driver.h"
#include "stm32f4_syscfg_driver.h"

#define EXTI_LINE_MASK(line)			(1UL << (line))

/*******************************************
* Enable Interrupt Line
*******************************************/
void EXTI_EnableLine(uint8_t line){
	EXTI->IMR |= EXTI_LINE_MASK(line);
}

/*******************************************
* Disable Interrupt Line
*******************************************/
void EXTI_DisableLine(uint8_t line){
	EXTI->IMR &=~ EXTI_LINE_MASK(line);
}

/*******************************************
* Configure Trigger
********************************************/
void EXTI_SetTrigger(uint8_t line, EXTI_TriggerType trigger){
	
	switch(trigger)
	{
		case EXTI_TRIGGER_RISING:
			EXTI->RTSR |= EXTI_LINE_MASK(line);
			EXTI->FTSR &= ~EXTI_LINE_MASK(line);
			break;
		
		case EXTI_TRIGGER_FALLING:
			EXTI->FTSR |= EXTI_LINE_MASK(line);
			EXTI->RTSR &= ~EXTI_LINE_MASK(line);
			break;
		
		case EXTI_TRIGGER_BOTH:
			EXTI->RTSR |= EXTI_LINE_MASK(line);
			EXTI->FTSR |= EXTI_LINE_MASK(line);
			break;
		
		default:
			break;
	}
}

/******************************************
* Clear Pending Bit
******************************************/
void EXTI_ClearPending(uint8_t line){
	EXTI->PR = EXTI_LINE_MASK(line);
}

/*******************************************
* Initialize EXTI
*******************************************/
void EXTI_Init(uint8_t line, GPIO_TypeDef	*GPIOx, EXTI_TriggerType trigger){
	/* Enable SYSCFG Clock */
	RCC_SYSCFG_CLK_ENABLE();
	
	/* Connect GPIO pin to EXTI line */
	SYSCFG_SetEXTISource(GPIOx, line);
	
	/* Configure trigger */
	EXTI_SetTrigger(line, trigger);
	
	/* Clear pending bit */
	EXTI_ClearPending(line);
	
/* Enable interrupt line */
	EXTI_EnableLine(line);
}
