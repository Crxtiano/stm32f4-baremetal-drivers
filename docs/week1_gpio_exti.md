#Week 1 - GPIO and External Interrupt (EXTI)

## Objective

The objective of this project was to understand GPIO programming at the register level and implement external interrupts (EXTI) without using the STM32 HAL library.

Instead of relying on vendor libraries, all peripherals were configured by directly accessing the STM32F407 registers.

---

# Learning Goals

- Understand STM32 memory-mapped peripherals
- Configure GPIO registers manually
- Configure GPIO as input and output
- Read and write GPIO pins
- Toggle GPIO outputs
- Configure EXTI
- Configure SYSCFG
- Configure NVIC
- Handle interrupts
- Implement basic software debouncing

---

# Hardware

Board

- STM32F407G-DISC1

Components

- User Button (PA0)
- Green LED (PD12)

---

# Registers Used

## RCC

Purpose:

Enable peripheral clocks.

Registers:

-  RCC_AHB1ENR
- RC_APB2ENR

---

## GPIO

Registers

- MODER
- OTYPER
- OSPEEDR
- PUPDR
- IDR
- ODR
- BSRR
- AFRL
- AFRH

Configuration

PD12

- Output
- Push-Pull
- Medium-Speed
- No Pull-up/Pull-down

PA0

- Input
- No Pull-up/Pull-down

---

## SYSCFG

Purpose

Connect GPIO pin to EXTI line.

Register

EXTICR1

Configuration

PA0 -> EXTI0

---

## EXTI

Registers

- IMR
- RTSR
- FTSR
- PR

Configuration

- Interrupt enabled
- Rising edge trigger

---

## NVIC

Interrupt

EXTI0_IRQn

Functions implemented

- Enable IRQ
- Disable IRQ
- Set Priority
-  Clear Pending

---

# Software Architechture

```
Application (main.c)
        |
        V
  GPIO Library
  EXTI Driver
  SYSCFG Driver
  NVIC Driver
        |
        v
  Register Definitions
        |
        v
  STM32 Hardware
```


---

# Driver Functions

GPIO

- LIB_GPIO_Inint()
- LIB_GPIO_ReadPin()
- LIB_GPIO_WritePin()
- LIB_GPIO_TogglePin()

EXTI

- EXTI_Init()
- EXTI_EnableLine()
- EXTI_DisableLine()
- EXTI_SetTrigger()
- EXTI_ClearPending()

SYSCFG

- RCC_SYSCFG_CLK_ENABLE()
- SYSCFG_SetEXTISource()

NVIC

- NVIC_EnableIRQ()
- NVIC_DisableIRQ()
- NVIC_SetPriority()

---

# Interrupt Flow

```
Button Press
    |
    V
   PA0
    |
    V
  SYSCFG
    |
    V
  EXTIO
    |
    V
  NVIC
    |
    V
 EXTI0_IRQHandler()
    |
    v
  Toggle PD12 LED
```

---

# Debouncing

A simple software debounce was implemented inside the interrupt handler.

```c
volatile  uint32_t i;

for(i = 0; i < 10000; i++) {}
```

This approach is simple but blocks the CPU.

A timer-based debounce will be implemented in a futur project.

---

# Testing

## Test 1

Configure PD12 as output.

Expected

LED can be switched on and off.

Result

PASS

---

## Test 2

Configure PA0 as input.

Expected

GPIO input changes when button is pressed.

Result

PASS

---

## Test 3

Configure EXTI.

Expected

Interrupt generated on rising edge.

Result

PASS

---

## Test 4

Toggle LED inside the interrupt.

Expected

LED changes state after every button press.

Result

PASS

---

# Lessons Learned

This project provided a solid understanding of :

- Memory-mapped peripheral programmin
- Bit manipulation
- Register configuration
- Interrupt architechture
- EXTI
- NVIC
- GPIO Configuration
- Startup  files
- Interrupt vector table

It also highlighted  the importance of configuring peripherals in the correct order:

1. Enable peripheral clock
2. Configure GPIO
3. Configure SYSCFG
4. Configure EXTI
5. Enable NVIC interrupt


---

# Limitations

Current implementation uses:

- Busy-wait debounce
- No timer support
- No low-power mode

These limitations will be addressed in future projects.

---

# Next Steps

Week 2

Implement a register-level SysTick driver.

Topics

- Cortex-M4 SysTick
- Sysem Tick Interrupt
- Millisecond Delay
- Tick Counter
- Software Timers

Goal

Replace the software delay loop with an interrupt-driven timing system.

---

# Repository

```
inc/
src/
docs/
examples/Week1_gpio_exti/
```

---

# Project Status

Completed

GPIO Driver 
EXTI Driver
SYSCFG Driver
NVIC Driver
Button Interrupt
LED Toggle

Ready for Week 2 (SysTick)
