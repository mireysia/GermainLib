#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdbool.h>

typedef struct _COLOR color_t;

struct _COLOR
{
    short int red;
    short int green;
    short int blue;
};

color_t* color_new(void);

color_t* color_newData( const short int red, const short int green, const short int blue);

void color_free(color_t **color);

void color_vt_free(void **item);

bool color_compareColor( void* item_1, void* item_2);

bool color_compareColorToRGB( color_t *color, const short int red, const short int green, const short int blue );

void color_printf(void *color);

#endif