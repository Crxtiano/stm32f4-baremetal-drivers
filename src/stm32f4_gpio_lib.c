#include "stm32f4_gpio_lib.h"
#include "stm32f4_rcc_driver.h"

#define GPIO_NUMBER				16U
#define	GPIO_MODE_MASK		0x03U
#define	GPIO_OTYPE_MASK		0x01U
#define	GPIO_AF_MASK			0x0FU

void LIB_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef	*GPIO_Init){
	
	uint32_t	position;
	uint32_t	temp;
	uint32_t ioposition;
	uint32_t	iocurrent;
	
	for (position = 0U; position < GPIO_NUMBER; position++){
		ioposition = (1U << position);
		iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;
		
		if(iocurrent == ioposition){
			
			/* MODER */
			temp =  GPIOx->MODER;
			temp &= ~(0x03U << (position * 2U));
			temp |= ((GPIO_Init->Mode & GPIO_MODE_MASK) << (position * 2U));
			GPIOx->MODER = temp;
			
			/* PUPDR */
			temp = GPIOx->PUPDR;
			temp &= ~(0x03U << (position * 2U));
			temp |= (GPIO_Init->Pull << (position * 2U));
			GPIOx->PUPDR = temp;
			
			/* Output / Alternate Function configuration */
			if((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD)||
				 (GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
			{
				/* OSPEEDR */
				temp = GPIOx->OSPEEDR;
				temp &= ~(0x03U << (position * 2U));
				temp |= (GPIO_Init->Speed << (position * 2U));
				GPIOx->OSPEEDR = temp;
				
				/* OTYPER */
				temp = GPIOx->OTYPER;
				temp &= ~(0x01U << position);
				temp |= (((GPIO_Init->Mode & 0x10U) >> 4U) << position);
				GPIOx->OSPEEDR = temp;
			}
			
			/* Alternate Function */
			if ((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
			{
				temp = GPIOx->AFR[position >> 3U];
				temp &= ~(GPIO_AF_MASK << ((uint32_t)(position & 0x07U) * 4U));
				temp |= (GPIO_Init->Alternate << ((uint32_t)(position & 0x07U) * 4U));
				GPIOx->AFR[position >> 3U] = temp;
			}					
		}
	}
}

/******************************************************************/
GPIO_PinState	LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx,	uint16_t GPIO_Pin){
	if ((GPIOx->IDR & GPIO_Pin) != 0U){
		return GPIO_PIN_SET;
	}
	return GPIO_PIN_RESET;
}

/*****************************************************************/
void LIB_GPIO_WritePin(GPIO_TypeDef	*GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
	if(PinState == GPIO_PIN_SET){
		GPIOx->BSRR = GPIO_Pin;
	}
	else {
		GPIOx->BSRR = ((uint32_t)GPIO_Pin <<16U);
	}
}

/****************************************************************/
void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	GPIOx->ODR ^= GPIO_Pin;
}

/**********************************************/
/* RCC Clock Enable Functions */
/**********************************************/

void __LIB_RCC_GPIOA_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;}
void __LIB_RCC_GPIOB_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;}
void __LIB_RCC_GPIOC_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;}
void __LIB_RCC_GPIOD_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;}
void __LIB_RCC_GPIOE_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;}
void __LIB_RCC_GPIOF_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;}
void __LIB_RCC_GPIOG_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;}
void __LIB_RCC_GPIOH_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;}
void __LIB_RCC_GPIOI_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;}
void __LIB_RCC_GPIOJ_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;}
void __LIB_RCC_GPIOK_CLK_ENABLE(void){RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN;}