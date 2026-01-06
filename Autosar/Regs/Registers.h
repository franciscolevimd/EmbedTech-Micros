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

#define PORTA ((Port_RegisterType *)PORTA_BASE);
#define PORTB ((Port_RegisterType *)PORTB_BASE);
#define PORTC ((Port_RegisterType *)PORTC_BASE);
#define PORTD ((Port_RegisterType *)PORTD_BASE);
#define PORTE ((Port_RegisterType *)PORTE_BASE);
#define PORTF ((Port_RegisterType *)PORTF_BASE);
#define PORTG ((Port_RegisterType *)PORTG_BASE);
#define PORTH ((Port_RegisterType *)PORTH_BASE);

#endif /* REGISTERS_H_ */
