#STM32F4 Bare-Metal Drivers (Register Level)

## Overview
This project implements low-level STM32F4 drivers without HAL:
- GPIO
- EXTI (Interrupts)
- NVIC
- UART (USART2)
- SYSCFG

## Goals
- Unterstand register-level programming
- Learn interrupt architechture (EXTI + NVIC)
- Build embedded driver stack from scratch

## Features
- Button interrupt -> LED toggle
- UART printf debugging
- Custom GPIO driver
- Manual RCC clock control

## Architechture
Application -> Drivers -> Register Layer -> Hardware

## Build
```bash
make
