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

/**
 * @brief 
 * 
 * @return gString* 
 */
gString* gString_new(void);

/**
 * @brief 
 * 
 * @param string 
 */
void gString_free( gString **string);

/**
 * @brief 
 * 
 * @param begin 
 * @param end 
 * @return gString* 
 */
gString* gString_duplicateCharacter( const char* begin, const char* end);

/**
 * @brief 
 * 
 * @param begin 
 * @param end 
 * @return char* 
 */
char* gString_t_duplicateCharacter( const char* begin, const char* end);

/**
 * @brief 
 * 
 * @param string 
 * @return gString* 
 */
gString* gString_duplicate( const gString* string);

/**
 * @brief 
 * 
 * @param string 
 */
void gString_printfMetaData( const gString* string);

/**
 * @brief 
 * 
 * @param e 
 */
void gString_printf( const gElement_t e);

/**
 * @brief 
 * 
 * @param string 
 * @param symbol 
 * @return gList_ll* 
 */
gList_ll* gString_splitString( const gString* string, const char* symbol);

#endif