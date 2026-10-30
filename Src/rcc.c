
#include "rcc.h"

void RCC_Configuration(void)
{
	/*
	 RCC clock control register (RCC_CR)
	 Address offset: 0x00
	 Bit 16 HSEON: HSE clock enable
	 Set and cleared by software.
	 Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
	 bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
	 0: HSE oscillator OFF
	 1: HSE oscillator ON
	 */
	RCC_CR |= (1U << 16); //HSE Enable

	// Wait until HSE is ready
	/*
	  Bit 17 HSERDY: HSE clock ready flag
	  Set by hardware to indicate that the HSE oscillator is stable. After the HSEON bit is cleared,
	  HSERDY goes low after 6 HSE oscillator clock cycles.
	  0: HSE oscillator not ready
	  1: HSE oscillator ready
	 */
	while((RCC_CR & (1U << 17)) == 0) 	// Wait until HSE is ready
	{

	}

	/*
	 * ============================================================
	 * HPRE: AHB PRESCALER (RCC_CFGR BITS [7:4])
	 * ============================================================
	 *
	 * PURPOSE:
	 * HPRE controls the division of SYSCLK to generate HCLK.
	 *
	 * FORMULA:
	 * HCLK = SYSCLK / AHB Prescaler
	 *
	 * HPRE BIT CONFIGURATION:
	 *
	 * 0xxx  = SYSCLK / 1
	 * 1000  = SYSCLK / 2
	 * 1001  = SYSCLK / 4
	 * 1010  = SYSCLK / 8
	 * 1011  = SYSCLK / 16
	 * 1100  = SYSCLK / 64
	 * 1101  = SYSCLK / 128
	 * 1110  = SYSCLK / 256
	 * 1111  = SYSCLK / 512
	 *
	 * EXAMPLE:
	 * SYSCLK = 8 MHz
	 * HPRE   = 0000 (Divide by 1)
	 * HCLK   = 8 / 1 = 8 MHz
	 *
	 * ============================================================
	 * CONFIGURATION: AHB PRESCALER = DIVIDE BY 1
	 * ============================================================
	 */

	RCC_CFGR &= ~(0xFU << 4);

	/*
	 * EXPLANATION:
	 *
	 * 0xF = 1111 (4-bit mask)
	 *
	 * (0xFU << 4)
	 * Moves the mask to bits [7:4].
	 *
	 * ~(0xFU << 4)
	 * Inverts the mask.
	 *
	 * RCC_CFGR &= ...
	 * Clears bits [7:4] without changing other register bits.
	 *
	 * Result:
	 * HPRE = 0000
	 *
	 * Therefore:
	 * HCLK = SYSCLK / 1
	 */

	/*
	 * ============================================================
	 * PPRE1: APB1 PRESCALER (RCC_CFGR BITS [12:10])
	 * ============================================================
	 *
	 * PURPOSE:
	 * PPRE1 controls the division of HCLK to generate PCLK1.
	 *
	 * FORMULA:
	 * PCLK1 = HCLK / APB1 Prescaler
	 *
	 * BIT CONFIGURATION:
	 *
	 * 0xx = HCLK / 1
	 * 100 = HCLK / 2
	 * 101 = HCLK / 4
	 * 110 = HCLK / 8
	 * 111 = HCLK / 16
	 *
	 * IMPORTANT:
	 * APB1 clock frequency must not exceed 42 MHz.
	 *
	 * ============================================================
	 * CONFIGURATION: APB1 PRESCALER = DIVIDE BY 2
	 * ============================================================
	 */

	/* Clear PPRE1 bits [12:10] */
	RCC_CFGR &= ~(7U << 10);

	/* Set PPRE1 = 100 (Divide by 2) */
	RCC_CFGR |= (4U << 10);

	/*
	 * ============================================================
	 * PPRE2: APB2 PRESCALER (RCC_CFGR BITS [15:13])
	 * ============================================================
	 *
	 * PURPOSE:
	 * PPRE2 controls the division of HCLK to generate PCLK2.
	 *
	 * FORMULA:
	 * PCLK2 = HCLK / APB2 Prescaler
	 *
	 * BIT CONFIGURATION:
	 *
	 * 0xx = HCLK / 1
	 * 100 = HCLK / 2
	 * 101 = HCLK / 4
	 * 110 = HCLK / 8
	 * 111 = HCLK / 16
	 *
	 * IMPORTANT:
	 * APB2 clock frequency must not exceed 84 MHz.
	 *
	 * ============================================================
	 * CONFIGURATION: APB2 PRESCALER = DIVIDE BY 2
	 * ============================================================
	 */

	/* Clear PPRE2 bits [15:13] */
	RCC_CFGR &= ~(7U << 13);

	/* Set PPRE2 = 100 (Divide by 2) */
	RCC_CFGR |= (4U << 13);

/* -----------------------------------------------------------------------*/
	/*
	RCC clock configuration register (RCC_CFGR)
    Address offset: 0x08
	Bits 1:0 SW: System clock switch
	Set and cleared by software to select the system clock source.
	Set by hardware to force the HSI selection when leaving the Stop or Standby mode or in
	case of failure of the HSE oscillator used directly or indirectly as the system clock.
	00: HSI oscillator selected as system clock
	01: HSE oscillator selected as system clock
	10: PLL selected as system clock
	11: not allowed
	 */

	RCC_CFGR &= ~(3U << 0);
	RCC_CFGR |= (1U << 0);

	/*
	Bits 3:2 SWS: System clock switch status
	Set and cleared by hardware to indicate which clock source is used as the system clock.
	System clock switch status
	00: HSI oscillator used as the system clock
	01: HSE oscillator used as the system clock
	10: PLL used as the system clock
	11: not applicable

	*/

	while((RCC_CFGR & (3U << 2)) != (1U << 2 ))
	{

	}

}





