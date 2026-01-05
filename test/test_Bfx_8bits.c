#include "unity.h"
#include "Bfx_8bits.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * Original:  10001010b
 * Resultado: 10001110b
 */
void test_Bfx_SetBit_u8u8()
{
    uint8 Esperado = 0x8E;  // 10001110b
    uint8 Data     = 0x8A;  // 10001010b
    uint8 BitPin   = 0x02;
    Bfx_SetBit_u8u8(&Data, BitPin);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  10001010b
 * Resultado: 10001000b
 */
void test_Bfx_ClrBit_u8u8()
{
    uint8 Esperado = 0x88;  // 10001000b
    uint8 Data     = 0x8A;  // 10001010b
    uint8 BitPin   = 0x01;
    Bfx_ClrBit_u8u8(&Data, BitPin);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Valor:     10001010b
 * Resultado: TRUE
 */
void test_Bfx_GetBit_u8u8_u8_TRUE()
{
    uint8 Data        = 0x8A;
    uint8 BitPin      = 0x01;
    boolean Resultado = Bfx_GetBit_u8u8_u8(Data, BitPin);
    TEST_ASSERT_EQUAL_UINT8(TRUE, Resultado);
}

/**
 * Valor:     10001010b
 * Resultado: FALSE
 */
void test_Bfx_GetBit_u8u8_u8_FALSE()
{
    uint8 Data        = 0x8A;
    uint8 BitPin      = 0x05;
    boolean Resultado = Bfx_GetBit_u8u8_u8(Data, BitPin);
    TEST_ASSERT_EQUAL_UINT8(FALSE, Resultado);
}

/**
 * Original:  00000111b
 * Resultado: 01110111b
 */
void test_Bfx_SetBits_u8u8u8u8_Set1()
{
    uint8 Esperado   = 0x77;  // 01110111b
    uint8 Data       = 0x07;  // 00000111b
    uint8 BitStartPn = 0x04;
    uint8 BitLn      = 0x03;
    uint8 Status     = 0x01;
    Bfx_SetBits_u8u8u8u8(&Data, BitStartPn, BitLn, Status);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  00000111b
 * Resultado: 00000001b
 */
void test_Bfx_SetBits_u8u8u8u8_Set0()
{
    uint8 Esperado   = 0x01;  // 00000001b
    uint8 Data       = 0x07;  // 00000111b
    uint8 BitStartPn = 0x01;
    uint8 BitLn      = 0x02;
    uint8 Status     = 0x00;
    Bfx_SetBits_u8u8u8u8(&Data, BitStartPn, BitLn, Status);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  11010011b
 * Resultado: 00001010b
 */
void test_Bfx_GetBits_u8u8u8_u8()
{
    uint8 Esperado   = 0x0A;  // 00001010b
    uint8 Data       = 0xD3;  // 11010011b
    uint8 BitStartPn = 0x03;
    uint8 BitLn      = 0x04;
    uint8 Resultado  = Bfx_GetBits_u8u8u8_u8(Data, BitStartPn, BitLn);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Resultado);
}

/**
 * Original:  10101010b
 * Resultado: 11101011b
 */
void test_Bfx_SetBitMask_u8u8()
{
    uint8 Esperado = 0xEB;  // 11101011
    uint8 Data     = 0xAA;  // 10101010
    uint8 Mask     = 0x41;  // 01000001
    Bfx_SetBitMask_u8u8(&Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  10101010b
 * Resultado: 10001000b
 */
void test_Bfx_ClrBitMask_u8u8()
{
    uint8 Esperado = 0x88;  // 10001000
    uint8 Data     = 0xAA;  // 10101010
    uint8 Mask     = 0x22;  // 00100010
    Bfx_ClrBitMask_u8u8(&Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Dato:      10010011b
 * Mascara:   10010000b
 * Resultado: TRUE
 */
void test_Bfx_TstBitMask_u8u8_u8_TRUE()
{
    uint8 Data      = 0x93;  // 10010011
    uint8 Mask      = 0x90;  // 10010000
    uint8 Resultado = Bfx_TstBitMask_u8u8_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(TRUE, Resultado);
}

/**
 * Dato:      10010011b
 * Mascara:   10010100b
 * Resultado: FALSE
 */
void test_Bfx_TstBitMask_u8u8_u8_FALSE()
{
    uint8 Data      = 0x93;  // 10010011
    uint8 Mask      = 0x94;  // 10010100
    uint8 Resultado = Bfx_TstBitMask_u8u8_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(FALSE, Resultado);
}

/**
 * Dato:      10110011b
 * Mascara:   10100000b
 * Resultado: TRUE
 */
void test_Bfx_TstBitLnMask_u8u8_u8_TRUE()
{
    uint8 Data      = 0xB3;  // 10110011
    uint8 Mask      = 0xA0;  // 10100000
    uint8 Resultado = Bfx_TstBitMask_u8u8_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(TRUE, Resultado);
}

/**
 * Dato:      10110011b
 * Mascara:   00001000b
 * Resultado: FALSE
 */
void test_Bfx_TstBitLnMask_u8u8_u8_FALSE()
{
    uint8 Data      = 0xB3;  // 10110011
    uint8 Mask      = 0x08;  // 00001000
    uint8 Resultado = Bfx_TstBitMask_u8u8_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(FALSE, Resultado);
}

/**
 * Original:  11110000b
 * Resultado: 00001111b
 */
void test_Bfx_ToggleBits_u8()
{
    uint8 Esperado = 0x0F;  // 00001111
    uint8 Data     = 0xf0;  // 11110000
    Bfx_ToggleBits_u8(&Data);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  10101010b
 * Mask:      00111000b
 * Resultado: 10010010b
 */
void test_Bfx_ToogleBitMask_u8u8()
{
    uint8 Esperado = 0x92;  // 10010010
    uint8 Data     = 0xAA;  // 10101010
    uint8 Mask     = 0x38;  // 00111000
    Bfx_ToogleBitMask_u8u8(&Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  10101011b
 * Resultado: 01010101b
 */
void test_Bfx_ShiftBitRt_u8u8()
{
    uint8 Esperado = 0x55;  // 01010101
    uint8 Data     = 0xAB;  // 10101011
    uint8 ShiftCnt = 0x01;
    Bfx_ShiftBitRt_u8u8(&Data, ShiftCnt);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original:  11111010b
 * Resultado: 10100000b
 */
void test_Bfx_ShiftBitLt_u8u8()
{
    uint8 Esperado = 0xA0;  // 10100000
    uint8 Data     = 0xFA;  // 11111010
    uint8 ShiftCnt = 0x04;
    Bfx_ShiftBitLt_u8u8(&Data, ShiftCnt);
    TEST_ASSERT_EQUAL_UINT8(Esperado, Data);
}

/**
 * Original: 11100111b
 * Resltado: 11110111b
 */
void test_Bfx_PutBit_u8u8u8_SetTRUE()
{
    uint8 Esperado = 0xF7;  // 11110111
    uint8 Data     = 0xE7;  // 11100111
    uint8 BitPn    = 0x04;
    Bfx_PutBit_u8u8u8(&Data, BitPn, TRUE);
}

/**
 * Original: 11100111b
 * Resltado: 11100011b
 */
void test_Bfx_PutBit_u8u8u8_SetFALSE()
{
    uint8 Esperado = 0xE3;  // 11100011
    uint8 Data     = 0xE7;  // 11100111
    uint8 BitPn    = 0x02;
    Bfx_PutBit_u8u8u8(&Data, BitPn, FALSE);
}
