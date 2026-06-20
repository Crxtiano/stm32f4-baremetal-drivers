#ifndef		__MY_STM32F4_NVIC_DRIVER_H__
#define		__MY_STM32F4_NVIC_DRIVER_H__

#include <stdint.h>

#define NVIC_BASE							0xE000E100U

#define	__IO												volatile
	
typedef struct
{
	__IO uint32_t ISER[8];	/* Interrupt Set-enable Registers */
			 uint32_t reserved1[24]; //0xE000E120 - 0xE000E180
	__IO uint32_t ICER[8];	/* Interrupt Clear-enable Registers */
			 uint32_t reserved2[24]; //0xE000E1A0 - 0xE000E200
	__IO uint32_t ISPR[8];	/* Interrupt Set-pending Registers */
	     uint32_t reserved3[24]; //0xE000E220 - 0xE000E280
	__IO uint32_t ICPR[8];	/* Interrupt Clear-pending Registers */
	     uint32_t reserved4[24]; //0xE000E2A0 - 0xE000E300
	__IO uint32_t	IABR[8];	/* Interrupt Active Bit Registers */
	     uint32_t reserved5[56]; //0xE000E320 - 0xE000E400
	__IO uint8_t IPR[240];	/* Interrupt Priority Registers */
			 uint32_t reserved6[644];
	__IO	uint32_t STIR;		/* Software Trigger Interrupt Register */
	
}NVIC_TypeDef;

#define NVIC			((NVIC_TypeDef *)(NVIC_BASE))

typedef enum
{
	EXTI0_IRQn					= 6,
	EXTI1_IRQn					= 7,
	EXTI2_IRQn					= 8,
	EXTI3_IRQn					= 9,
	EXTI4_IRQn					= 10,
	EXTI9_5_IRQn				= 23,
	EXTI15_10_IRQn			= 40
}IRQn_Type;

void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority);
uint32_t NVIC_GetPriority(IRQn_Type IRQn);

#endif