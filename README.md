\# STM32F407 RCC Configuration – Bare-Metal C



\## 1. Project Overview



This project demonstrates Reset and Clock Control (RCC) configuration on the STM32F407VG microcontroller using Bare-Metal C programming.



The objective is to configure the External High-Speed Clock (HSE) as the system clock without using the Phase-Locked Loop (PLL), HAL drivers, or CMSIS libraries.



All RCC configurations are performed through direct memory-mapped register access.



\## 2. Project Objectives



\* Understand STM32 RCC architecture.

\* Configure the external HSE oscillator.

\* Understand RCC\_CR and RCC\_CFGR registers.

\* Configure AHB and APB prescalers.

\* Select HSE as the system clock.

\* Verify system clock switching through hardware status flags.

\* Practice register-level Embedded C programming.



\## 3. Hardware Requirements



\* Microcontroller: STM32F407VG

\* Development Environment: STM32CubeIDE

\* Programming Language: Embedded C

\* Clock Source: External High-Speed Clock (HSE)



\## 4. Clock Configuration



| Clock Parameter | Configuration |

| --------------- | ------------- |

| Clock Source    | HSE           |

| PLL             | Not Used      |

| SYSCLK Source   | HSE           |

| AHB Prescaler   | DIV1          |

| APB1 Prescaler  | DIV2          |

| APB2 Prescaler  | DIV2          |



Actual clock frequencies depend on the external HSE frequency.



\## 5. Clock Architecture





&#x20;         External HSE

&#x20;              |

&#x20;              |

&#x20;         HSE Oscillator

&#x20;              |

&#x20;              |

&#x20;            SYSCLK

&#x20;              |

&#x20;              |

&#x20;         AHB Prescaler

&#x20;            DIV1

&#x20;              |

&#x20;              |

&#x20;            HCLK

&#x20;           /    \\

&#x20;          /      \\

&#x20;     APB1          APB2

&#x20;   Prescaler     Prescaler

&#x20;     DIV2          DIV2

&#x20;       |             |

&#x20;     PCLK1         PCLK2



\## 6. RCC Registers Used



\### RCC\_CR – Clock Control Register



Address: 0x40023800



Used for:



\* HSE oscillator enable (HSEON).

\* HSE ready status verification (HSERDY).



\### RCC\_CFGR – Clock Configuration Register



Address: 0x40023808



Used for:



\* System clock source selection (SW).

\* System clock status verification (SWS).

\* AHB prescaler configuration (HPRE).

\* APB1 prescaler configuration (PPRE1).

\* APB2 prescaler configuration (PPRE2).



\## 7. Project Structure



```text

RCC\_CONFIGURATION/

|

|-- Inc/

|   |-- rcc.h

|

|-- Src/

|   |-- main.c

|   |-- rcc.c

|   |-- syscalls.c

|   |-- sysmem.c

|

|-- Startup/

|   |-- startup\_stm32f407vgtx.s

|

|-- STM32F407VGTX\_FLASH.ld

|-- STM32F407VGTX\_RAM.ld

|-- README.md

|-- .gitignore

|-- .project

|-- .cproject

```



\## 8. Programming Concepts



\* Direct memory-mapped register access.

\* Volatile register pointers.

\* Bitwise AND and OR operations.

\* Bit shifting.

\* Bit masking.

\* Hardware status flag polling.

\* Clock prescaler configuration.



\## 9. Libraries



This project uses:



\* Bare-Metal C

\* Standard C integer types (`stdint.h`)



Not used:



\* STM32 HAL

\* CMSIS device register definitions

\* PLL configuration



\## 10. Learning Outcome



Through this project, I developed an understanding of STM32 clock architecture and gained practical experience configuring RCC registers using direct register-level programming.



\## 11. Author



Vivek Devadiga



Embedded Firmware Engineer | Embedded C | STM32 | Bare-Metal Programming



