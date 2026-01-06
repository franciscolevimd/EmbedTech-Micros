#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Platform_Types.h"

#define AHB1PERPIH_ADDRESS 0x40020000UL  //< Direccion de inicio AHB1.

#define PORTA_BASE (AHB1PERPIH_ADDRESS + 0x0000)  ///< DIRECCION BASE DEL PUERTO A
#define PORTB_BASE (AHB1PERPIH_ADDRESS + 0x0400)  ///< DIRECCION BASE DEL PUERTO B
#define PORTC_BASE (AHB1PERPIH_ADDRESS + 0x0800)  ///< DIRECCION BASE DEL PUERTO C
#define PORTD_BASE (AHB1PERPIH_ADDRESS + 0x0C00)  ///< DIRECCION BASE DEL PUERTO D
#define PORTE_BASE (AHB1PERPIH_ADDRESS + 0x1000)  ///< DIRECCION BASE DEL PUERTO E
#define PORTF_BASE (AHB1PERPIH_ADDRESS + 0x1400)  ///< DIRECCION BASE DEL PUERTO F
#define PORTG_BASE (AHB1PERPIH_ADDRESS + 0x1800)  ///< DIRECCION BASE DEL PUERTO G
#define PORTH_BASE (AHB1PERPIH_ADDRESS + 0x1C00)  ///< DIRECCION BASE DEL PUERTO H

#define RCC_BASE (AHB1PERPIH_ADDRESS + 0x3800UL)  ///< DIRECCION BASE DEL RCC

typedef struct _Port_RegisterType
{
    volatile uint32 MODER;
    volatile uint32 OTYPER;
    volatile uint32 OSPEEDR;
    volatile uint32 PUPDR;
    volatile uint32 IDR;
    volatile uint32 ODR;
    volatile uint32 BSRR;
    volatile uint32 LCKR;
    volatile uint32 AFLR;
    volatile uint32 AFRH;

} Port_RegisterType;

typedef struct _RCC_RegisterType
{
    volatile uint32 CR;
    volatile uint32 PLLCFGR;
    volatile uint32 CFGR;
    volatile uint32 CIR;
    volatile uint32 AHB1RSTR;
    volatile uint32 AHB2RSTR;
    volatile uint32 AHB3RSTR;
    volatile uint32 RESERVADO1;
    volatile uint32 APB1RSTR;
    volatile uint32 APB2RSTR;
    volatile uint32 RESERVADO2[2];
    volatile uint32 AHB1ENR;
    volatile uint32 AHB2ENR;
    volatile uint32 AHB3ENR;
    volatile uint32 RESERVADO3;
    volatile uint32 APB1ENR;
    volatile uint32 APB2ENR;
    volatile uint32 RESERVADO4[2];
    volatile uint32 AHB1LPENR;
    volatile uint32 AHB2LPERN;
    volatile uint32 AHB3LPERN;
    volatile uint32 RESERVADO5;
    volatile uint32 APB1LPERN;
    volatile uint32 APB2LPERN;
    volatile uint32 RESERVADO6[2];
    volatile uint32 BDCR;
    volatile uint32 CSR;
    volatile uint32 RESERVADO7[2];
    volatile uint32 SSCGR;
    volatile uint32 PLLI2SCFGR;
    volatile uint32 PLLSAICFGR;
    volatile uint32 DCKCFGR;
    volatile uint32 CKGATENR;
    volatile uint32 DCKCFGR2;

} RCC_RegisterType;

#define PORTA ((Port_RegisterType *)PORTA_BASE);
#define PORTB ((Port_RegisterType *)PORTB_BASE);
#define PORTC ((Port_RegisterType *)PORTC_BASE);
#define PORTD ((Port_RegisterType *)PORTD_BASE);
#define PORTE ((Port_RegisterType *)PORTE_BASE);
#define PORTF ((Port_RegisterType *)PORTF_BASE);
#define PORTG ((Port_RegisterType *)PORTG_BASE);
#define PORTH ((Port_RegisterType *)PORTH_BASE);

#define RCC ((RCC_RegisterType *)RCC_BASE);

#define RCC_GPIOA_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x00U))
#define RCC_GPIOB_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x01U))
#define RCC_GPIOC_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x02U))
#define RCC_GPIOD_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x03U))
#define RCC_GPIOE_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x04U))
#define RCC_GPIOF_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x05U))
#define RCC_GPIOG_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x06U))
#define RCC_GPIOH_CLK_EN() (RCC->AHB1ENR |= (0x01U << 0x07U))

#define RCC_GPIOA_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x00U))
#define RCC_GPIOB_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x01U))
#define RCC_GPIOC_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x02U))
#define RCC_GPIOD_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x03U))
#define RCC_GPIOE_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x04U))
#define RCC_GPIOF_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x05U))
#define RCC_GPIOG_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x06U))
#define RCC_GPIOH_CLK_DIS() (RCC->AHB1ENR &= ~(0x01U << 0x07U))

#endif /* REGISTERS_H_ */
