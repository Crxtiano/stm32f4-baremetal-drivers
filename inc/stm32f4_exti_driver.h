#ifndef		__MY_STM32F4_EXTI_DRIVER_H__
#define		__MY_STM32F4_EXTI_DRIVER_H__

#include "stm32f4_gpio_driver.h"

/* Base addresses */
#define APB2PERIPH_BASE						  (PERIPH_BASE + 0x10000U)
#define	EXTI_BASE										(APB2PERIPH_BASE + 0x03C00U)

/* EXTI Register Definition */
typedef struct
{
	__IO	uint32_t IMR;		/* Interrupt mask register */
	__IO	uint32_t EMR;		/* Event mask register */
	__IO	uint32_t RTSR;	/* Rising trigger selection register */
	__IO	uint32_t FTSR;	/* Falling trigger selection register */
	__IO	uint32_t SWIER;	/* Software interrupt event register */
	__IO	uint32_t PR;		 /* Pending register */
}EXTI_TypeDef;

/* EXTI Peripheral Definition */
#define EXTI			((EXTI_TypeDef	*)(EXTI_BASE))

typedef enum
{
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH
}EXTI_TriggerType;

void EXTI_Init(uint8_t line, GPIO_TypeDef	*GPIOx, EXTI_TriggerType trigger);
void EXTI_EnableLine(uint8_t line);
void EXTI_DisableLine(uint8_t line);
void EXTI_SetTrigger(uint8_t line, EXTI_TriggerType trigger);
void EXTI_ClearPending(uint8_t line);

#endif