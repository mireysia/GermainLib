#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <stdbool.h>

typedef struct _POINT point_t;
typedef struct _BOUNDARY boundary_t;

struct _POINT
{
    int x;
    int y;
};

struct _BOUNDARY
{
    int width;
    int height;
    point_t * point;
};

point_t* point_t_new(void);

point_t* point_t_newData(const int x, const int y);

point_t point_data(const int x, const int y);

void point_t_free(point_t * *point);

bool point_t_comparePoint( point_t* point_1, point_t* point_2);

bool point_vt_comparePoint( void* item_1, void* item_2);

void point_t_printf(void *item);

boundary_t* boundary_t_new(void);

boundary_t* boundary_t_newData(const int width, const int heigth, point_t * point);

point_t* boundary_t_getPoint(boundary_t* boundary);

void boundary_t_free(boundary_t* *boundary);

void boundary_fourSubDivision(boundary_t *boundary, boundary_t **tabBoundary);

void boundary_freeSubDivision(boundary_t **tabBoundary, const int numberSubDiv);

void boundary_printf(boundary_t *boundary);

#endif