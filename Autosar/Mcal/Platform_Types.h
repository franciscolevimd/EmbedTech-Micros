/**
   @file Platform_types.h
 * @brief SpecificationfPlatformTypes
 *
 * En este archivo estan definidas las macros correspondientes al estandar
 * AUTOSAR para el archivo Platform_Types.h.
 */
#ifndef PLATAFORM_TYPES_H_
#define PLATAFORM_TYPES_H_

typedef unsigned char boolean;
#define TRUE 1u
#define FALSE 0u

/**
 * @defgroup Unsigned. Definiciones para los tipos de datos sin signo de de 8, 16, 32 y 64 bits.
 @{*/
typedef unsigned char uint8;
#define UINT8_MIN 0u

#define UINT8_MAX 255u


typedef unsigned short uint16;
#define UINT16_MIN 0u
#define UNIT16_MAX 65535u

typedef unsigned long uint32;
#define UINT32_MIN 0ul
#define UNIT32_MAX 4294967295ul

typedef unsigned long long uint64;
#define UINT64_MIN 0ull
#define UNIT64_MAX 18446744073709551615ull
/**
@}*/

/**
 * @defgroup Signed. Definiciones para los tipos de datos con signo de de 8, 16, 32 y 64 bits.
 @{*/
typedef char sint8;
#define SINT8_MIN -128
#define SINT8_MAX 127

typedef short sint16;
#define SINT16_MIN -32768
#define SNIT16_MAX 32767

typedef long sint32;
#define SINT32_MIN -2147483648l
#define SNIT32_MAX 2147483647l

typedef long long sint64;
#define SINT64_MIN -9223372036854775808ll
#define SNIT64_MAX 9223372036854775807ll
/**
@}*/

typedef uint8 uint8_least;
typedef uint16 uint16_least;
typedef uint32 uint32_least;

typedef sint8 sint8_least;
typedef sint16 sint16_least;
typedef sint32 sint32_least;

typedef float float32;
typedef double float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;

typedef enum
{
    CPU_TYPE_8,
    CPU_TYPE_16,
    CPU_TYPE_32,
    CPU_TYPE_64
} CPU_TYPE;

typedef enum
{
    MSB_FIRST,
    LSB_FIRST
} CPU_BIT_ORDER;

typedef enum
{
    HIGH_BYTE_FIRST,
    LOW_BYTE_FIRS
} CPU_BYTE_ORDER;

#ifndef TRUE
#define TRUE true
#endif

#ifndef FALSE
#define FALSE false
#endif

#endif /* PLATAFORM_TYPES_H_ */
