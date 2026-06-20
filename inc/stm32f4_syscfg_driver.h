#ifndef		__MY_STM32F4_SYSCFG_DRIVER_H__
#define		__MY_STM32F4_SYSCFG_DRIVER_H__

#include "stm32f4_exti_driver.h"

/* Port-Definition for EXTI-Mapping */
#define  SYSCFG_EXTICR_PORTA		0x0U
#define  SYSCFG_EXTICR_PORTB		0x1U
#define  SYSCFG_EXTICR_PORTC		0x2U
#define  SYSCFG_EXTICR_PORTD		0x3U
#define  SYSCFG_EXTICR_PORTE		0x4U
#define  SYSCFG_EXTICR_PORTF		0x5U
#define  SYSCFG_EXTICR_PORTG		0x6U
#define  SYSCFG_EXTICR_PORTH		0x7U
#define  SYSCFG_EXTICR_PORTI		0x8U
#define  SYSCFG_EXTICR_PORTJ		0x9U
#define  SYSCFG_EXTICR_PORTK		0x10U

/* Base addresses */
#define	SYSCFG_BASE										(APB2PERIPH_BASE + 0x03800U)

/* SYSCFG Register Definition */
typedef struct
{
	__IO	uint32_t MEMRMP;	/* Memory remap register */
	__IO	uint32_t PMC;			/* Peripheral mode configuration register */
	__IO	uint32_t EXTICR[4];	/* External interrupt configuration register 1-4 */
	__IO	uint32_t CMPCR;		/* Compensation cell control register */			
}SYSCFG_TypeDef;

/* SYSCFG Peripheral Definition */
#define SYSCFG			((SYSCFG_TypeDef	*)(SYSCFG_BASE))

void RCC_SYSCFG_CLK_ENABLE(void);
void SYSCFG_SetEXTISource(GPIO_TypeDef *GPIOx, uint8_t line);

#endif