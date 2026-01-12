#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_Types.h"

typedef uint8 Std_ReturnType;
#define E_OK 0u
#define E_NOT_OK 1u

typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;

} Std_VersionInfoType;

typedef uint8 Std_TransformerErrorCode;

typedef uint8 Std_TransformerClass;
#define STD_TRANSFORMER_UNSPECIFIED 0x00
#define STD_TRANSFORMER_SERIALIZER 0x01
#define STD_TRANSFORMER_SAFETY 0x02
#define STD_TRANSFORMER_SECURITY 0x03
#define STD_TRANSFORMER_CUSTOM 0xFF

typedef struct
{
    Std_TransformerErrorCode errorCode;
    Std_TransformerClass transformerClass;

} Std_TransformerError;

typedef uint8 Std_TransformerForwardCode;
#define STD_SAFETY_INVALID_REP 0x01
#define STD_SAFETY_INVALID_SEQ 0x02
#define STD_SAFETY_INVALID_CRC 0x03

typedef struct
{
    Std_TransformerForwardCode errorCode;
    Std_TransformerClass transformerClass;

} Std_TransformerForward;

typedef uint8 Std_MessageTypeType;
#define STD_MESSAGETYPE_REQUEST 0x00
#define STD_MESSAGETYPE_RESPONSE 0x01

typedef uint8 Std_MessageResultType;
#define STD_MESSAGERESULT_OK 0x00
#define STD_MESSAGERESULT_ERROR 0x01

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
typedef unsigned char StatusType;
#endif

#define STD_HIGH 0x01u
#define STD_LOW 0x00u

#define STD_ACTIVE 0x01u
#define STD_IDLE 0x00u

#define STD_ON 0x01u
#define STD_OFF 0x00u

#define NULL_PTR ((void*)0)

typedef Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType)(const uint8* buffer,
                                                              uint32 bufferLength,
                                                              Std_MessageTypeType* messageType,
                                                              Std_MessageResultType* messageResult);

#endif /* STD_TYPES_H_ */
