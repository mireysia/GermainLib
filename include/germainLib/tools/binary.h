#ifndef __BINARY_H__
#define __BINARY_H__

#include "math.h"

#define __SHORT_BINARY__ sizeof(short)
#define __INT_BINARY__ sizeof(int)

#define __4_OCTET__ 4
#define __8_OCTET__ 8
#define __16_OCTET__ 16
#define __32_OCTET__ 32
#define __64_OCTET__ 64

typedef char binary_t;

void decimal_to_binaryNBytes(binary_t *binary, const long number, long size);

long binaryNBytes_to_integer(binary_t *binary, long size);

#endif