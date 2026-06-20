#include "stm32f4_syscfg_driver.h"
#include "stm32f4_rcc_driver.h"

/*************************************************
* Enable SYSCFG Clock
**************************************************/

void RCC_SYSCFG_CLK_ENABLE(void){RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;}

/*************************************************
* Configure GPIO Port as EXTI Source
*
* Example:
* PA0 -> EXTI0
* PC13 -> EXTI13
**************************************************/

void SYSCFG_SetEXTISource(GPIO_TypeDef *GPIOx, uint8_t line){
	uint32_t portcode;
	uint32_t exticr_index;
	uint32_t exticr_position;
	
	/* Determine port code */
	if (GPIOx == GPIOA){portcode = SYSCFG_EXTICR_PORTA;}
	else if(GPIOx == GPIOB){portcode = SYSCFG_EXTICR_PORTB;}
	else if(GPIOx == GPIOC){portcode = SYSCFG_EXTICR_PORTC;}
	else if(GPIOx == GPIOD){portcode = SYSCFG_EXTICR_PORTD;}
	else if(GPIOx == GPIOE){portcode = SYSCFG_EXTICR_PORTE;}
	else if(GPIOx == GPIOF){portcode = SYSCFG_EXTICR_PORTF;}
	else if(GPIOx == GPIOG){portcode = SYSCFG_EXTICR_PORTG;}
	else if(GPIOx == GPIOH){portcode = SYSCFG_EXTICR_PORTH;}
	else if(GPIOx == GPIOI){portcode = SYSCFG_EXTICR_PORTI;}
	else if(GPIOx == GPIOJ){portcode = SYSCFG_EXTICR_PORTJ;}
	else if(GPIOx == GPIOK){portcode = SYSCFG_EXTICR_PORTK;}
	else{
		return;
	}
	
	/* EXTICR Register index */
	exticr_index = line / 4U;
	
	/* Position inside EXTICR Register */
	exticr_position = (line % 4U) * 4U;
	
/* Clear old configuration */
	SYSCFG->EXTICR[exticr_index] &= ~(0xFU << exticr_position);
	
	/* Write new port selection */
	SYSCFG->EXTICR[exticr_index] |= (portcode << exticr_position);
}