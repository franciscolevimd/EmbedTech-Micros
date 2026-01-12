#include "Bfx.h"
#include "Registers.h"

void delay( uint32 cnt )
{
    while ( cnt )
    {
        cnt--;
    }
}

int main( void )
{
    RCC_GPIOA_CLK_EN();

    /* 1.- CONFIGURAR EL MODER (Input/Output/AF/ANALOG) */
    Bfx_ClrBitMask_u32u32( (uint32 *)&PORTA->MODER, ( 0x03 << 10 ) );
    Bfx_SetBitMask_u32u32( (uint32 *)&PORTA->MODER, ( 0x01 << 10 ) );

    /* 2.- CONFIGURAR EL OTYPER (Push-Pull / Open Drain) */
    Bfx_ClrBit_u32u8( (uint32 *)&PORTA->OTYPER, 0x05 );

    /* 3.- CONFIGURAR EL OSPEEDER (Velocidad del pin) */
    Bfx_ClrBitMask_u32u32( (uint32 *)&PORTA->OSPEEDR, ( 0x03 << 10 ) );
    Bfx_SetBitMask_u32u32( (uint32 *)&PORTA->OSPEEDR, ( 0x01 << 10 ) );

    /* 4.- CONFIGURAR PUPDR (Pull-Up / Pull-Down) */
    Bfx_ClrBitMask_u32u32( (uint32 *)&PORTA->PUPDR, ( 0x03 << 10 ) );

    while ( 1 )
    {
        Bfx_SetBit_u32u8( (uint32 *)&PORTA->ODR, 0x05 );
        delay( 2500000 );
        Bfx_ClrBit_u32u8( (uint32 *)&PORTA->ODR, 0x05 );
        delay( 2500000 );
    }

    return 0;
}
