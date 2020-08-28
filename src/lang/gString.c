#include "germainLib/lang/gString.h"

gString* gString_new(void)
{
    gString *string = NULL;

    string = (gString*)malloc(sizeof(gString));

    if( string != NULL )
    {
        string->lenght = 0UL;
        string->string = NULL;
    }
    return string;
}

void gString_free( gString **string)
{
    if( *string != NULL )
    {
        free((*string)->string);
        (*string)->string = NULL;

        free(*string);
        *string = NULL;
    }
}

gString* gString_duplicateCharacter( const char* begin, const char* end)
{
    gString *new = gString_new();

    if( new != NULL )
    {
        new->lenght = end - begin;
        new->string = (char*)malloc(sizeof(char) * (new->lenght + 1));

        if( new->string != NULL )
        {
            memcpy( new->string, begin, new->lenght);
            new->string[ new->lenght ] = '\0';
        }
    }
    return new;
}

char* gString_t_duplicateCharacter( const char* begin, const char* end)
{
    const size_t len = end - begin;
    char *s = (char*)malloc(sizeof(char) * ( len + 1));

    if( s != NULL )
    {
        memcpy( s, begin, len);
        s[ len ] = '\0';
    }
    return s;
}

gString* gString_duplicate( const gString* string)
{
    gString* s = gString_new();

    if( s != NULL )
    {
        s->lenght = string->lenght;
        s->string = gString_t_duplicateCharacter( string->string, string->string + string->lenght);
    }
    return s;
}

void gString_printfMetaData( const gString* string)
{
    printf("size %lu | %s", string->lenght, string->string);
    printf("\n");
}

void gString_printf( const gElement_t e)
{
    gString* s = (gString*)e;
    printf("size %lu | %s", s->lenght, s->string);
    printf("\n");
}

gList_ll* gString_splitString( const gString* string, const char* symbol)
{
    gList_ll* list = gListll_new();
    char *begin = NULL;
    char *parser = NULL;
    gString *s = NULL;
    begin = parser = string->string;

    while ( *parser != '\0' )
    {
        if( *parser == *symbol )
        {
            if( parser != begin )
            {
                s = gString_duplicateCharacter( begin, parser);
                gListll_addLast( list, s);
                s = NULL;
            }
            begin = parser + 1;
        }
        parser++;
    }

    if( parser > begin && *parser == '\0' )
    {
        s = gString_duplicateCharacter( begin, parser);
        gListll_addLast( list, s);
        s = NULL;
    }
    return list;
}