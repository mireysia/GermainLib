#include <stdio.h>
#include "germainLib/tools/binary.h"

void decimal_to_binaryNBytes(binary_t *binary, const long number, long size)
{
    for( long i = size - 1 ; i >= 0 ; i-- )
        binary[i] = ((number >> i) & 1) ? 1 : 0;
}

long binaryNBytes_to_integer(binary_t *binary, long size)
{
    long resultat = 0;

    for( long i = size - 1 ; i >= 0 ; i-- )
        resultat += integer_pow(2, i) * binary[i];
       
    return resultat;
}