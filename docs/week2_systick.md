#Week 2 - SysTick Driver

## Objective

Implement a custom SysTick driver without HAL

---

## Theory

-  Cortex-M4 SysTick
- 24-bit down counter
-  Reload register
- Current value register
- Interrupt

---

##Registers

| Register  | Description |
|-----------|-------------|
|CTRL | Control register  |
|LOAD | Reload value      |
|VAL  | Current value     |
|CALIB| Calibration       |

---

## Implementation

- SysTick_Init()
- SysTIck_Enable()
- SysTick_Disable()
- Delay_ms()

---

## Test

The LED flashes every 500 ms.

---

## Findings

- Reload = 16000 - 1
- Interrupt increments the tick counter
- Delay is based on the tick counter

----

## Images


## Next steps

TIM2
