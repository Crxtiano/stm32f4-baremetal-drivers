#include "stm32f4_systick_driver.h"

/* Global tick counter */
static volatile uint32_t uwTick = 0;

/**********************************
* Initialize SysTick
*
* ticks = Reload value
**********************************/
void SysTick_Init(uint32_t ticks){
	/* Disable SysTick */
	SYSTICK->STK_CTRL = 0;
	
	/* Set reload value */
	SYSTICK->STK_LOAD = ticks - 1U;
	
	/* Clear current value */
	SYSTICK->STK_VAL = 0U;
	
	/* Processor clock, interrupt enable */
	SYSTICK->STK_CTRL = SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_TICKINT;

}

/****************************
* Enable SysTick
****************************/
void SysTick_Enable(void){
	SYSTICK->STK_CTRL |= SYSTICK_CTRL_ENABLE;
}

/***************************
* Disable SysTick
***************************/
void SysTick_Disable(void){
	SYSTICK->STK_CTRL &= ~ SYSTICK_CTRL_ENABLE;
}

/**************************
* Enable SysTick Interrupt
**************************/
void SysTick_EnableInterrupt(void){
	SYSTICK->STK_CTRL |= SYSTICK_CTRL_TICKINT;
}

/**************************
* Desable SysTick Interrupt
**************************/
void SysTick_DisableInterrupt(void){
	SYSTICK->STK_CTRL &= ~SYSTICK_CTRL_TICKINT;
}

/**************************
* Reset current counter
**************************/
void SysTick_Reset(void){
	SYSTICK->STK_VAL = 0U;
}

/**************************
* Return system tick
**************************/
uint32_t SysTick_GetTick(void){
	return uwTick;
}

/**************************
* Delay in milliseconds
**************************/
void Delay_ms(uint32_t ms){
	
	uint32_t startTick = uwTick;
	
	while((uwTick - startTick) < ms)
	{
		/* Wait */
	}
}

/**************************
* SysTick Interrupt Handler
**************************/
void SysTick_Handler(void){
	
	uwTick++;
}