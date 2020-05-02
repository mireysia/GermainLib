#include <stdlib.h>

#include "germainLib/type/integer/integerMath.h"

linear_function_t* math_linearFunction_new(void)
{
    linear_function_t *function = NULL;

    function = (linear_function_t*)malloc(sizeof(linear_function_t));

    if( function != NULL )
    {
        function->a = 0;
        function->b = 0;
    }

    return function;
}

linear_function_t* math_linearFunction_newData(const int a, const int b)
{
    linear_function_t *function = NULL;

    function = (linear_function_t*)malloc(sizeof(linear_function_t));

    if( function != NULL )
    {
        function->a = a;
        function->b = b;
    }

    return function;
}

void math_linearFunction_free(linear_function_t **linearFunction)
{
    if( *linearFunction != NULL )
    {
        free(*linearFunction);
        *linearFunction = NULL;
    }
}

linear_function_t* math_determineLinearFunctionWithTwoPoint( const point_t *point_1, const point_t *point_2)
{
    linear_function_t *function = math_linearFunction_new();

    function->a = math_linearFunction_ACoeff( point_1, point_2);
    function->b = math_linearFunction_BCoeff( point_1, function->a);

    return function;
}

int math_linearFunction_ACoeff( const point_t *point_1, const point_t *point_2)
{
    return (point_2->y - point_1->y) / (point_2->x - point_1->x);
}

int math_linearFunction_BCoeff( const point_t *point, const int coefficient_A)
{
    return point->y - ( coefficient_A * point->x);
}

int math_distance(const int x1, const int y1, const int x2, const int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}