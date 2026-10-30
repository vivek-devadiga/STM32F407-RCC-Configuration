# STM32F407 RCC Configuration

## Overview

This project implements the Reset and Clock Control (RCC) configuration of the STM32F407VG microcontroller using Bare-Metal C.

The external High-Speed Clock (HSE) is selected as the system clock source. The clock configuration is performed through direct register access without using STM32 HAL or CMSIS device register definitions.

PLL is not used as the system clock source in this implementation.

## Hardware and Software

* Microcontroller: STM32F407VG
* IDE: STM32CubeIDE
* Language: Embedded C
* Clock source: HSE
* Programming approach: Bare-Metal Register Programming

## Clock Configuration

The following settings are configured in RCC_CFGR.

| Parameter    | Setting  | Description           |
| ------------ | -------- | --------------------- |
| Clock Source | HSE      | External clock        |
| HPRE         | 0000     | AHB divide by 1       |
| PPRE1        | 100      | APB1 divide by 2      |
| PPRE2        | 100      | APB2 divide by 2      |
| PLL          | Not used | HSE selected directly |

## Clock Flow

              HSE
               |
               v
             SYSCLK
               |
          AHB Prescaler
               |
              HCLK
               |
        +------+------+
        |             |
        v             v
       APB1          APB2
        |             |
       /2            /2
        |             |
        v             v
      PCLK1         PCLK2


Clock calculations:

* SYSCLK = HSE
* HCLK = SYSCLK / 1
* PCLK1 = HCLK / 2
* PCLK2 = HCLK / 2

Actual frequencies depend on the external HSE frequency.

## RCC Registers

### 1. RCC_CR – Clock Control Register

Address: `0x40023800`

Bits used:

| Bit | Name   | Function               |
| --- | ------ | ---------------------- |
| 16  | HSEON  | Enable HSE             |
| 17  | HSERDY | Check HSE ready status |

HSE is enabled by setting bit 16. The program waits until hardware sets bit 17.

### 2. RCC_CFGR – Clock Configuration Register

Address: `0x40023808`

Fields used:

| Bits    | Field | Function                    |
| ------- | ----- | --------------------------- |
| [1:0]   | SW    | Select system clock         |
| [3:2]   | SWS   | Check selected system clock |
| [7:4]   | HPRE  | AHB prescaler               |
| [12:10] | PPRE1 | APB1 prescaler              |
| [15:13] | PPRE2 | APB2 prescaler              |

## Implementation

The configuration is performed in the following sequence:

1. Enable the HSE oscillator.
2. Wait for the HSERDY flag.
3. Configure the AHB prescaler.
4. Configure the APB1 prescaler.
5. Configure the APB2 prescaler.
6. Select HSE as the system clock.
7. Wait for the SWS status bits to confirm HSE selection.

## Project Structure

RCC_CONFIGURATION/
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
|   |-- startup_stm32f407vgtx.s
|
|-- STM32F407VGTX_FLASH.ld
|-- STM32F407VGTX_RAM.ld
|-- README.md
|-- .gitignore
|-- .project
|-- .cproject


## Programming Concepts

* Memory-mapped register access
* Volatile pointers
* Bitwise operations
* Bit masking and shifting
* Register configuration
* Hardware status flag polling
* Clock prescalers

## Development Notes

The RCC registers are accessed using their memory addresses and volatile 32-bit pointers.

The implementation uses `stdint.h` for fixed-width integer types.

No STM32 HAL drivers or CMSIS device register definitions are used for RCC configuration.

## Author

**Vivek Devadiga**

Embedded C | STM32 | Bare-Metal Programming
