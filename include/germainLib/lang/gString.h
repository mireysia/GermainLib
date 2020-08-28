#ifndef __G_STRING_H__
#define __G_STRING_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "../utils/gElement.h"
#include "../collection/gDoubleLinkedList.h"

typedef struct _G_STRING gString;

struct _G_STRING
{
    size_t lenght;
    char *string;
};

gString* gString_new(void);
void gString_free( gString **string);
gString* gString_duplicateCharacter( const char* begin, const char* end);
char* gString_t_duplicateCharacter( const char* begin, const char* end);
gString* gString_duplicate( const gString* string);
void gString_printfMetaData( const gString* string);
void gString_printf( const gElement_t e);
gList_ll* gString_splitString( const gString* string, const char* symbol);

#endif