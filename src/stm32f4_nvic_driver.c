#include "stm32f4_nvic_driver.h"

/*******************************************
* Enables an interrupt or exception
*******************************************/
void NVIC_EnableIRQ(IRQn_Type IRQn){
	NVIC->ISER[IRQn/32U] = (1UL << (IRQn % 32U));
}

/*******************************************
* Disables an interrupt or exception
*******************************************/
void NVIC_DisableIRQ(IRQn_Type IRQn){
	NVIC->ICER[IRQn/32U] = (1UL << (IRQn % 32U)); 
}

/*******************************************
* Sets the pending status of interrupt or
exception to 1.
*******************************************/
void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	NVIC->ISPR[IRQn/32U] = (1UL << (IRQn % 32U));
}

/*******************************************
* Clears the pending status of interrupt or
exception to 0
*******************************************/
void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	NVIC->ICPR[IRQn/32U] = (1UL << (IRQn % 32U));
}

/*******************************************
* Reads the pending status of interrupt or
exception. This function returns non-
zero value if the pending status is set to
1
*******************************************/
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn){
	return (NVIC->ISPR[IRQn/32U] >> (IRQn % 32U)) & 0x1U;
}
/*******************************************
* Sets the priority of an interrupt or
exception with configurable priority level
to 1.
*******************************************/
void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority){
	priority &= 0x0FU;
	NVIC->IPR[IRQn] = (priority << 4U);
}

/*******************************************
* Reads the priority of an interrupt or
exception with configurable priority
level. This function return the current
priority level
*******************************************/
uint32_t NVIC_GetPriority(IRQn_Type IRQn){
	return (NVIC->IPR[IRQn] >> 4U);
	
}