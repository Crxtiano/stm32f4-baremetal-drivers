#ifndef		__MY_STM32F4_GPIO_DRIVER_H__
#define		__MY_STM32F4_GPIO_DRIVER_H__

#include <stdint.h>

#define PERIPH_BASE									0x40000000U
#define AHB1PERIPH_BASE						  (PERIPH_BASE + 0x20000U)

#define GPIOA_BASE									(AHB1PERIPH_BASE + 0x0000U)		
#define GPIOB_BASE									(AHB1PERIPH_BASE + 0x0400U)		
#define GPIOC_BASE									(AHB1PERIPH_BASE + 0x0800U)		
#define GPIOD_BASE									(AHB1PERIPH_BASE + 0x0C00U)		
#define GPIOE_BASE									(AHB1PERIPH_BASE + 0x1000U)		
#define GPIOF_BASE									(AHB1PERIPH_BASE + 0x1400U)		
#define GPIOG_BASE									(AHB1PERIPH_BASE + 0x1800U)		
#define GPIOH_BASE									(AHB1PERIPH_BASE + 0x1C00U)		
#define GPIOI_BASE									(AHB1PERIPH_BASE + 0x2000U)
#define GPIOJ_BASE									(AHB1PERIPH_BASE + 0x2400U)
#define GPIOK_BASE									(AHB1PERIPH_BASE + 0x2800U)

#define	__IO												volatile
	
typedef struct
{
	__IO		uint32_t MODER;
	__IO		uint32_t OTYPER;
	__IO		uint32_t OSPEEDR;
	__IO		uint32_t PUPDR;
	__IO		uint32_t IDR;
	__IO		uint32_t ODR;
	__IO		uint32_t BSRR;
	__IO		uint32_t LCKR;
	__IO		uint32_t AFR[2];
}GPIO_TypeDef;

#define GPIOA							((GPIO_TypeDef *)(GPIOA_BASE))
#define GPIOB							((GPIO_TypeDef *)(GPIOB_BASE))
#define GPIOC							((GPIO_TypeDef *)(GPIOC_BASE))
#define GPIOD							((GPIO_TypeDef *)(GPIOD_BASE))
#define GPIOE							((GPIO_TypeDef *)(GPIOE_BASE))
#define GPIOF							((GPIO_TypeDef *)(GPIOF_BASE))
#define GPIOG							((GPIO_TypeDef *)(GPIOG_BASE))
#define GPIOH							((GPIO_TypeDef *)(GPIOH_BASE))
#define GPIOI							((GPIO_TypeDef *)(GPIOI_BASE))
#define GPIOJ							((GPIO_TypeDef *)(GPIOJ_BASE))
#define GPIOK							((GPIO_TypeDef *)(GPIOK_BASE))

#endif