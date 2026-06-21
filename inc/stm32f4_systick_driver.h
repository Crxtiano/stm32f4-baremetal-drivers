#ifndef  __MY_STM32F4_SYSTICK_H__
#define  __MY_STM32F4_SYSTICK_H__

#include <stdint.h>

#define SYSTICK_BASE							0xE000E010U

#define __IO									volatile
	
typedef struct
{
	__IO	uint32_t STK_CTRL;	/* Systick control and status register */
	__IO	uint32_t STK_LOAD;	/* Systick reload value register */
	__IO	uint32_t STK_VAL;		/* Systick current value register */
	__IO	uint32_t STK_CALIB;	/* Systick calibration value register */
	
}SYSTICK_TypeDef;

#define SYSTICK					((SYSTICK_TypeDef *)(SYSTICK_BASE))

/* CTRL Registers Bits */
#define SYSTICK_CTRL_ENABLE			(1UL << 0)
#define SYSTICK_CTRL_TICKINT		(1UL << 1)
#define SYSTICK_CTRL_CLKSOURCE	(1UL << 2)
#define SYSTICK_CTRL_COUNTFLAG	(1UL << 16)



void SysTick_Init(uint32_t ticks);
void SysTick_Enable(void);
void SysTick_Disable(void);
uint32_t SysTick_GetTick(void);
void Delay_ms(uint32_t ms);
void SysTick_EnableInterrupt(void);
void SysTick_DisableInterrupt(void);
void SysTick_SetReload(uint32_t ticks);
void SysTick_Reset(void);

#endif