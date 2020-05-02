#ifndef __INTEGER_MATH_H__
#define __INTEGER_MATH_H__

#include <math.h>

#include "germainLib/geometry.h"

typedef struct _MATH_LINEAR_FUNCTION linear_function_t;

struct _MATH_LINEAR_FUNCTION
{
    int a;
    int b;
};

linear_function_t* math_linearFunction_new(void);
linear_function_t* math_linearFunction_newData(const int a, const int b);

void math_linearFunction_free(linear_function_t **linearFunction);

linear_function_t* math_determineLinearFunctionWithTwoPoint( const point_t *point_1, const point_t *point_2);
int math_linearFunction_ACoeff( const point_t *point_1, const point_t *point_2);
int math_linearFunction_BCoeff( const point_t *point, const int coefficient_A);

int math_distance(const int x1, const int y1, const int x2, const int y2);

#endif