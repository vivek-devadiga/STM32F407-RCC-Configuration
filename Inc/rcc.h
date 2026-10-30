
#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_CR  (*(volatile uint32_t*)( 0x40023800U))
#define RCC_CFGR (*(volatile uint32_t*)( 0x40023808U))

#endif /* RCC_H_ */
