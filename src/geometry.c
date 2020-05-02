#include <stdio.h>
#include <stdlib.h>

#include "germainLib/geometry.h"

point_t* point_t_new(void)
{
    point_t *point = NULL;

    point = (point_t*)malloc(sizeof(point_t));

    if( point != NULL )
    {
        point->x = 0;
        point->y = 0;
    }
    return point;
}

point_t* point_t_newData(const int x, const int y)
{
    point_t *point = point_t_new();

    if( point != NULL )
    {
        point->x = x;
        point->y = y;
    }
    return point;
}

point_t point_data(const int x, const int y)
{
    point_t point;

    point.x = x;
    point.y = y;

    return point;
}

void point_t_free(point_t* *point)
{
    if( point != NULL )
    {
        free(*point);
        *point = NULL;
    }
}

bool point_t_comparePoint( point_t* point_1, point_t* point_2)
{
    if( point_1->x == point_2->x && point_1->y == point_2->y )
        return true;
    return false;
}

bool point_vt_comparePoint( void* item_1, void* item_2)
{
    point_t* point_1 = (point_t*)item_1;
    point_t* point_2 = (point_t*)item_2;
    if( point_1->x == point_2->x && point_1->y == point_2->y )
        return true;
    return false;
}

void point_t_printf(void *item)
{
    point_t *point = (point_t *)item;
    printf("x -> %d | y -> %d\n", point->x, point->y);
}

boundary_t* boundary_t_new(void)
{
    boundary_t *boundary = NULL;

    boundary = (boundary_t*)malloc(sizeof(boundary_t));

    if( boundary != NULL )
    {
        boundary->height = 0;
        boundary->width = 0;
        boundary->point = NULL;
    }
    return boundary;
}

boundary_t* boundary_t_newData(const int width, const int heigth, point_t* point)
{
    boundary_t *boundary = boundary_t_new();
    
    if( boundary != NULL )
    {
        boundary->height = heigth;
        boundary->width = width;
        boundary->point = point;
    }
    return boundary;
}

void boundary_t_free(boundary_t **boundary)
{
    boundary_t *_boundary = *boundary;

    if( _boundary != NULL )
    {
        point_t_free(&(_boundary->point));
        free(_boundary);
        _boundary = NULL;
    }
    *boundary=  _boundary;
}

void boundary_fourSubDivision(boundary_t *boundary, boundary_t **tabBoundary)
{
    unsigned int width = boundary->width / 2;
    unsigned int height = boundary->height / 2;
    point_t *tabPoint[4];
            
    tabPoint[0] = point_t_newData( boundary->point->x, boundary->point->y + height);
    tabPoint[1] = point_t_newData( boundary->point->x + width, boundary->point->y + height);
    tabPoint[2] = point_t_newData( boundary->point->x + width, boundary->point->y);
    tabPoint[3] = point_t_newData( boundary->point->x, boundary->point->y);

    tabBoundary[0] = boundary_t_newData( width, boundary->height - height, tabPoint[0]);
    tabBoundary[1] = boundary_t_newData( boundary->width - width, boundary->height - height, tabPoint[1]);
    tabBoundary[2] = boundary_t_newData( boundary->width - width, height, tabPoint[2]);
    tabBoundary[3] = boundary_t_newData( width, height, tabPoint[3]);
}

void boundary_freeSubDivision(boundary_t **tabBoundary, const int numberSubDiv)
{
    for( unsigned int i = 0 ; i < numberSubDiv ; i++ )
        boundary_t_free(&tabBoundary[i]);
}

void boundary_printf(boundary_t *boundary)
{
    if( boundary != NULL )
    {
        printf(" W : %d | H : %d |", boundary->width, boundary->height);
        
        if( boundary->point != NULL )
            printf(" Px : %d | Py : %d\n", boundary->point->x, boundary->point->y);
        else
            printf(" Point NULL\n");
    }
    else
        printf("Boundary NULL\n");
}