#include "germainLib/tools/math.h"

/*long integer_pow(long base, long exp)
{
     if( exp == 0 )
        return 1;

    long result = 1;

    for(unsigned long i = 0 ; i < exp ; i++)
        result *= base;

    return result;
}*/

long integer_pow(long base, long exp)
{
    long result = 1;
    while(exp > 0)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}