/**
 * @file Bfx_8bits.h
 */
#ifndef BFX_8BITS_H_
#define BFX_8BITS_H_

#include "Std_Types.h"

/**
 * @brief Set the logical status as '1'.
 *
 * This function shall set the logical status of input data as '1' at the requested bit position.
 *
 * @param Data Pointer to input data.
 * @param BitPn Bit position.
 */
static inline void Bfx_SetBit_u8u8(uint8 *Data, uint8 BitPn)
{
    *Data |= (0x01 << BitPn);
}

/**
 * @brief Clear the logical status to '0'.
 *
 * This function shall clear the logical status of the input data to '0' at the requested bit
 * position.
 *
 * @param Data Pointer to input data.
 * @param BitPn Bit position.
 */
static inline void Bfx_CtrlBit_u8u8(uint8 *Data, uint8 BitPn)
{
    *Data = (*Data & ~(0x01 << BitPn));
}

/**
 * @brief Return the logical status.
 *
 * This function shall return the logical status of the input data for the requested bit position.
 *
 * @param Data Input data.
 * @param BitPn Bit position.
 * @return Bit Status.
 */
static inline boolean Bfx_GetBit_u8u8_u8(uint8 Data, uint8 BitPn)
{
    boolean Result = FALSE;

    if ((Data & (0x01 << BitPn)) != 0)
    {
        Result = TRUE;
    }

    return Result;
}

/**
 * @brief Set the input data as '1' or '0' as per 'Status' value.
 *
 * This function shall set the input data as '1' or '0' as per 'Status' value starting from
 * 'BitStartPn' for the length 'BitLn'.
 *
 * @param Data Pointer to input data.
 * @param BitStartPn Start bit position.
 * @param BitLn Bit field length.
 * @param Status Status value.
 * @Note The value of 'BitStartPn' cannot be greater than 7, and the value of 'BitLn', added to the
 * value of 'BitStartPn', cannot be greater than 8.
 */
static inline void Bfx_SetBits_u8u8u8u8(uint8 *Data, uint8 BitStartPn, uint8 BitLn, uint8 Status)
{
    uint8 Mask = 0x00;

    for (uint8 i = 0x00; i < BitLn; i++)
    {
        Mask |= (0x01 << i);
    }

    if (Status == 0x01)
    {
        *Data |= (Mask << BitStartPn);
    }
    else if (Status == 0x00)
    {
        *Data &= ~(Mask << BitStartPn);
    }
}

/**
 * @brief Return the Bits of the input data starting from 'BitStartPn'.
 *
 * This function shall return the Bits of the input data starting from 'BitStartPn' for the length
 * of 'BitLn'.
 *
 * @param Data Input data.
 * @param BitStartPn Start bit position.
 * @param BitLn Bit field length.
 * @return Bit Status.
 * @Note The value of 'BitStartPn' cannot be greater than 7, and the value of 'BitLn', added to the
 * value of 'BitStartPn', cannot be greater than 8.
 */
static inline uint8 Bfx_GetBits_u8u8u8_u8(uint8 Data, uint8 BitStartPn, uint8 BitLn)
{
    uint8 Resultado = UINT8_MIN;
    uint8 j = 0x00;

    for (uint8 i = BitStartPn; i < (BitStartPn + BitLn); i++)
    {
        if ((Data & (0x01 << i)) != 0)
        {
            Resultado |= (0x01 << j);
        }
        j++;
    }

    return Resultado;
}

/**
 * @brief Set the data to logical status '1' as per the corresponding Mask bits.
 *
 * This function shall set the data to logical status '1' as per the corresponding Mask bits when
 * set to value 1 and remaining bits will retain their original values.
 *
 * @param Data Pointer to input data.
 * @param Mask Mask used to set bits.
 */
static inline void Bfx_SetBitMask_u8u8(uint8 *Data, uint8 Mask)
{
    *Data |= Mask;
}

/**
 * @brief Clear the logical status to '0' for the input data for all the bit positions as per the
 * mask.
 *
 * This function shall clear the logical status to '0' for the input data for all the bit positions
 * as per the mask.
 *
 * @param Data Pointer to input data.
 * @param Mask Mask value.
 */
static inline void Bfx_ClrBitMask_u8u8(uint8 *Data, uint8 Mask)
{
    *Data &= ~Mask;
}

/**
 * @brief Return TRUE, if all bits defined in Mask value are set in the input Data value.
 *
 * This function shall return TRUE, if all bits defined in Mask value are set in the input Data
 * value. In all other cases this function shall return FALSE.
 *
 * @param Data Inout data.
 * @param Mask Mask value.
 * @return Value.
 */
static inline boolean Bfx_TstBitMask_u8u8_u8(uint8 Data, uint8 Mask)
{
    boolean Result = FALSE;

    if ((Data & Mask) == Mask)
    {
        Result = TRUE;
    }

    return Result;
}

/**
 * @brief If at least one bit of the netrada data is set according to the mask, it returns TRUE.
 *
 * This function makes a test on the input data and if at least one bit is set as per the mask, then
 * the function shall return TRUE, otherwise it shall return FALSE.
 *
 * @param Data Input data.
 * @param Mask Mask value.
 * @return Data.
 */
static inline boolean Bfx_TstBitLnMask_u8u8_u8(uint8 Data, uint8 Mask)
{
    boolean Result = FALSE;

    for (uint8 i = 0x00; i < 0x08; i++)
    {
        if (((Mask & (0x01 << i)) != 0) && ((Data & (0x01 << i)) != 0))
        {
            Result = TRUE;
            break;
        }
    }

    return Result;
}

/**
 * @brief Toggles all the bits of data.
 *
 * This function toggles all the bits of data (1’s Complement Data).
 *
 * @param Data Pointer to input data.
 */
static inline void Bfx_ToggleBits_u8(uint8 *Data)
{
    *Data = ~(*Data);
}

/**
 * @brief Toggles the bits of data when the corresponding bit of the mask is enabled.
 *
 * This function toggles the bits of data when the corresponding bit of the mask is enabled and set
 * to 1.
 *
 * @param Data Pointer to input data.
 * @param Mask Mask.
 */
static inline void Bfx_ToogleBitMask_u8u8(uint8 *Data, uint8 Mask)
{
    *Data ^= Mask;
}

/**
 * @brief Shift data to the right by ShiftCnt.
 *
 * This function shall shift data to the right by ShiftCnt. The most significant bit (left-most bit)
 * is replaced by a '0' bit and the least significant bit (right-most bit) is discarded for every
 * single bit shift cycle.
 *
 * @param Data Pointer to input data.
 * @param ShiftCnt Shift right count.
 */
static inline void Bfx_ShiftBitRt_u8u8(uint8 *Data, uint8 ShiftCnt)
{
    *Data = (*Data >> ShiftCnt);
}

/**
 * @brief Shift data to the left by ShiftCnt.
 *
 * This function shall shift data to the left by ShiftCnt. The least significant bit (right-most
 * bit) is replaced by a '0' bit and the most significant bit (left-most bit) is discarded for every
 * single bit shift cycle.
 *
 * @param Data Pointer to input data.
 * @param ShiftCnt Shift left count.
 */
static inline void Bfx_ShiftBitLt_u8u8(uint8 *Data, uint8 ShiftCnt)
{
    *Data = (*Data << ShiftCnt);
}

/**
 * @brief
 *
 * This function shall update the bit specified by BitPn of input data as '1' or '0' as per 'Status'
 value.

 * @param Data Pointer to input data.
 * @param Status Status vale.
 * @param BitPn Bit position.
 */
static inline void Bfx_PutBit_u8u8(uint8 *Data, uint8 BitPn, boolean Status)
{
    uint8 Mask = (0x01 << BitPn);

    if (Status == TRUE)
    {
        *Data |= Mask;
    }
    else
    {
        *Data &= ~Mask;
    }
}

#endif /* BFX_8BITS_H_ */
