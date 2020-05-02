#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "germainLib/color.h"

color_t* color_new(void)
{
    color_t *color = NULL;

    color = (color_t*)malloc(sizeof(color_t));

    if( color != NULL )
        color->blue = color->green = color->red = -1;

    return color;
}

color_t* color_newData( const short int red, const short int green, const short int blue)
{
    color_t *color = NULL;

    color = (color_t*)malloc(sizeof(color_t));

    if( color != NULL )
    {
        color->blue = blue;
        color->green = green;
        color->red = red;
    }
    return color;
}

void color_free(color_t **color)
{
    if( *color != NULL )
    {
        free(*color);
        *color = NULL;
    }
}

void color_vt_free(void **item)
{
    color_t *color = (color_t*)*item;
    if( color != NULL )
    {
        free(color);
        color = NULL;
    }
    *item = color;
}

bool color_compareColor( void* item_1, void* item_2)
{
    color_t *color_1 = (color_t*)item_1;
    color_t *color_2 = (color_t*)item_2;

    if( color_1->blue == color_2->blue && color_1->green == color_2->green && color_1->red == color_2->red )
        return true;
    return false;
}

bool color_compareColorToRGB( color_t *color, const short int red, const short int green, const short int blue )
{
    if( color->blue == blue && color->green == green && color->red == red )
        return true;
    return false;
}

void color_printf(void *color)
{
    color_t *item = (color_t*)color;
    printf("color R : %d | G : %d | B : %d\n", item->red, item->green, item->blue);
}
