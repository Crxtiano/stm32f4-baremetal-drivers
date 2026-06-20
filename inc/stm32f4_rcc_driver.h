#ifndef		__MY_STM32F4_RCC_DRIVER_H__
#define		__MY_STM32F4_RCC_DRIVER_H__

#include "stm32f4_gpio_driver.h"

#define RCC_BASE								(AHB1PERIPH_BASE + 0x3800U)

typedef struct
{
	__IO		uint32_t CR;
	__IO		uint32_t PLLCFGR;
	__IO		uint32_t CFGR;
	__IO		uint32_t CIR;
	__IO		uint32_t AHB1RSTR;
	__IO		uint32_t AHB2RSTR;
	__IO		uint32_t AHB3RSTR;
					uint32_t Dummy1;		//0x1C
	__IO		uint32_t APB1RSTR;
	__IO		uint32_t APB2RSTR;
	        uint32_t Dummy2[2]; //0x28-0x2C
	__IO		uint32_t AHB1ENR;
	__IO		uint32_t AHB2ENR;
	__IO		uint32_t AHB3ENR;
					uint32_t Dummy3;    //0x3C
	__IO		uint32_t APB1ENR;
	__IO		uint32_t APB2ENR;
					uint32_t Dummy4[2]; //0x48-0x4C
	__IO		uint32_t AHB1LPENR;
	__IO		uint32_t AHB2LPENR;
	__IO		uint32_t AHB3LPENR;
					uint32_t Dummy5;    //0x5C
	__IO		uint32_t APB1LPENR;
	__IO		uint32_t APB2LPENR;
					uint32_t Dummy6[2]; //0x68-0x6C
	__IO		uint32_t BDCR;
	__IO		uint32_t CSR;
					uint32_t Dummy7[2]; //0x78-0x7C
	__IO		uint32_t SSCGR;
	__IO		uint32_t PLLI2SCFGR;
}RCC_TypeDef;

#define RCC								((RCC_TypeDef *)(RCC_BASE))

/*------------- RCC GPIO -----------------*/
#define RCC_AHB1ENR_GPIOAEN			(1UL << 0)
#define RCC_AHB1ENR_GPIOBEN			(1UL << 1)
#define RCC_AHB1ENR_GPIOCEN			(1UL << 2)
#define RCC_AHB1ENR_GPIODEN			(1UL << 3)
#define RCC_AHB1ENR_GPIOEEN			(1UL << 4)
#define RCC_AHB1ENR_GPIOFEN			(1UL << 5)
#define RCC_AHB1ENR_GPIOGEN			(1UL << 6)
#define RCC_AHB1ENR_GPIOHEN			(1UL << 7)
#define RCC_AHB1ENR_GPIOIEN			(1UL << 8)
#define RCC_AHB1ENR_GPIOJEN			(1UL << 9)
#define RCC_AHB1ENR_GPIOKEN			(1UL << 10)

/*------------- RCC USART ----------------*/
#define RCC_APB1ENR_USART2EN (1UL << 17)
#define RCC_APB1ENR_USART3EN (1UL << 18)
#define RCC_APB1ENR_UART4EN	 (1UL << 19)
#define RCC_APB1ENR_UART5EN	 (1UL << 20)

/*------------- SYSCFG ------------------*/
#define RCC_APB2ENR_SYSCFGEN	(1UL << 14)




#endif