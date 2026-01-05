#include "unity.h"
#include "Bfx_32bits.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * Original:  0x00
 * Posicion:  0x1C | 28
 * Resultado: 0x10000000
 */
void test_Bfx_SetBit_u32u8()
{
    uint32 Data     = 0x00ul;
    uint32 Esperado = 0x10000000;
    uint8 BitPin    = 0x1C;

    Bfx_SetBit_u32u8(&Data, BitPin);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:  0xFFFFFFFF
 * Posicion:  0x1C | 28
 * Resultado: 0xEFFFFFFF
 */
void test_Bfx_ClrBit_u32u8()
{
    uint32 Data     = 0xFFFFFFFF;
    uint32 Esperado = 0xEFFFFFFF;
    uint8 BitPin    = 0x1C;

    Bfx_ClrBit_u32u8(&Data, BitPin);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Valor:     0x90000000
 * Posicion:  0x1F | 31
 * Resultado: TRUE | 0x01
 */
void test_Bfx_GetBit_u32u8_u8_TRUE()
{
    uint32 Data  = 0x90000000;
    uint8 BitPin = 0x1F;

    boolean Resultado = Bfx_GetBit_u32u8_u8(Data, BitPin);
    TEST_ASSERT_EQUAL_UINT8(TRUE, Resultado);
}

/**
 * Valor:     0x7FFFFFFF
 * Posicion:  0x1F  | 31
 * Resultado: FALSE | 0x00
 */
void test_Bfx_GetBit_u32u8_u8_FALSE()
{
    uint32 Data  = 0x7FFFFFFF;
    uint8 BitPin = 0x1F;

    boolean Resultado = Bfx_GetBit_u32u8_u8(Data, BitPin);
    TEST_ASSERT_EQUAL_UINT8(FALSE, Resultado);
}

/**
 * Original:   0x00
 * Posicion:   0x01
 * Total bits: 0x1E | 30
 * Resultado:  0x7FFFFFFE
 */
void test_Bfx_SetBits_u32u8u8u8_Set1()
{
    uint32 Data      = 0x00ul;
    uint8 BitStartPn = 0x01;
    uint8 BitLn      = 0x1E;
    uint8 Status     = 0x01;

    uint32 Esperado = 0x7FFFFFFE;

    Bfx_SetBits_u32u8u8u8(&Data, BitStartPn, BitLn, Status);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:   0xFFFFFFFF
 * Posicion:   0x01
 * Total bits: 0x1E | 30
 * Resultado:  0x80000001
 */
void test_Bfx_SetBits_u32u8u8u8_Set0()
{
    uint32 Data      = 0xFFFFFFFF;
    uint8 BitStartPn = 0x01;
    uint8 BitLn      = 0x1E;
    uint8 Status     = 0x00;

    uint32 Esperado = 0x80000001;

    Bfx_SetBits_u32u8u8u8(&Data, BitStartPn, BitLn, Status);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:   0xA000000
 * Posicion:   0x14 | 20
 * Total bits: 0x04
 * Resultado:  0x0A
 */
void test_Bfx_GetBits_u32u8u8_u32()
{
    uint32 Data      = 0xA000000;
    uint8 BitStartPn = 0x18;
    uint8 BitLn      = 0x04;

    uint32 Esperado = 0x0A;

    uint32 Resultado = Bfx_GetBits_u32u8u8_u32(Data, BitStartPn, BitLn);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Resultado);
}

/**
 * Original:  0x8000000F
 * Mask:      0xB0000000
 * Resultado: 0xB000000F
 */
void test_Bfx_SetBitMask_u32u32()
{
    uint32 Data = 0x8000000F;
    uint32 Mask = 0xB0000000;

    uint32 Esperado = 0xB000000F;

    Bfx_SetBitMask_u32u32(&Data, Mask);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:  0xB000000F
 * Mask:      0x30000000
 * Resultado: 0x8000000F
 */
void test_Bfx_ClrBitMask_u32u32()
{
    uint32 Data = 0xB000000F;
    uint32 Mask = 0x30000000;

    uint32 Esperado = 0x8000000F;

    Bfx_ClrBitMask_u32u32(&Data, Mask);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Dato:    0xB000000F
 * Mascara: 0xB0000000
 */
void test_Bfx_TstBitMask_u32u32_u8_TRUE()
{
    uint32 Data = 0xB000000F;
    uint32 Mask = 0xB0000000;

    uint8 Resultado = Bfx_TstBitMask_u32u32_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(TRUE, Resultado);
}

/**
 * Dato:    0xB000000F
 * Mascara: 0xE0000000
 */
void test_Bfx_TstBitMask_u32u32_u8_FALSE()
{
    uint32 Data = 0xB000000F;
    uint32 Mask = 0xE0000000;

    uint8 Resultado = Bfx_TstBitMask_u32u32_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(FALSE, Resultado);
}

/**
 * Dato:    0xB000000F
 * Mascara: 0xB0000000
 */
void test_Bfx_TstBitLnMask_u32u32_u8_TRUE()
{
    uint32 Data = 0xB000000F;
    uint32 Mask = 0xB0000000;

    uint8 Resultado = Bfx_TstBitMask_u32u32_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(TRUE, Resultado);
}

/**
 * Dato:    0xB000000F
 * Mascara: 0xB0000010
 */
void test_Bfx_TstBitLnMask_u32u32_u8_FALSE()
{
    uint32 Data = 0xB000000F;
    uint32 Mask = 0xB0000010;

    uint8 Resultado = Bfx_TstBitMask_u32u32_u8(Data, Mask);
    TEST_ASSERT_EQUAL_UINT8(FALSE, Resultado);
}

/**
 * Original:
 * Resultado:
 */
void test_Bfx_ToggleBits_u32()
{
    uint32 Data     = 0xFFFFFFFF;
    uint32 Esperado = 0x00ul;

    Bfx_ToggleBits_u32(&Data);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:  0xBF000000
 * Mask:      0x0F00000F
 * Resultado: 0xB000000F
 */
void test_Bfx_ToogleBitMask_u32u32()
{
    uint32 Data = 0xBF000000;
    uint32 Mask = 0x0F00000F;

    uint32 Esperado = 0xB000000F;

    Bfx_ToogleBitMask_u32u32(&Data, Mask);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:  0xF0000000
 * Desplazar: 0x1C | 28
 * Resultado: 0x0000000F
 */
void test_Bfx_ShiftBitRt_u32u8()
{
    uint32 Data    = 0xF0000000;
    uint8 ShiftCnt = 0x1C;

    uint32 Esperado = 0x0000000F;

    Bfx_ShiftBitRt_u32u8(&Data, ShiftCnt);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original:  0x0000000F
 * Desplazar: 0x1C | 28
 * Resultado: 0xF0000000
 */
void test_Bfx_ShiftBitLt_u32u8()
{
    uint32 Data    = 0x0000000F;
    uint8 ShiftCnt = 0x1C;

    uint32 Esperado = 0xF0000000;

    Bfx_ShiftBitLt_u32u8(&Data, ShiftCnt);
    TEST_ASSERT_EQUAL_UINT32(Esperado, Data);
}

/**
 * Original: 0x70000001
 * Pin:      0x1F
 * Resltado: 0xF0000001
 */
void test_Bfx_PutBit_u32u8u8_SetTRUE()
{
    uint32 Data = 0x70000001;
    uint8 BitPn = 0x1F;

    uint32 Esperado = 0xF0000001;

    Bfx_PutBit_u32u8u8(&Data, BitPn, TRUE);
}

/**
 * Original: 0xF0000001
 * Pin:      0x1F
 * Resltado: 0x70000001
 */
void test_Bfx_PutBit_u32u8u8_SetFALSE()
{
    uint32 Data  = 0xF0000001;
    uint8 BitPn = 0x02;

    uint32 Esperado = 0x70000001;

    Bfx_PutBit_u32u8u8(&Data, BitPn, FALSE);
}
