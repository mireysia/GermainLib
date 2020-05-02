#include <stdio.h>
#include <stdlib.h>

#include "germainLib/type/shorterInt.h"

short int** shorterInt_arrays_newTwoDim(const unsigned int largeur, const unsigned int hauteur)
{
    short int** tab = NULL;

    tab = (short int**)malloc(sizeof(short int*) * hauteur);

    if( tab != NULL)
        for(unsigned int i = 0 ; i < hauteur ; i++)
            tab[i] = (short int*)malloc(sizeof(short int) * largeur);

    return tab;
}

short int** shorterInt_arrays_newTwoDim_Data(const unsigned int largeur, const unsigned int hauteur, const short int data)
{
    short int** tab = NULL;

    tab = (short int**)malloc(sizeof(short int*) * hauteur);

    if( tab != NULL)
    {
        for(unsigned int i = 0 ; i < hauteur ; i++)
        {
            tab[i] = (short int*)malloc(sizeof(short int) * largeur);
            for(unsigned int j = 0 ; j < largeur ; j++)
            {
                tab[i][j] = data;
            }      
        }
    }
    return tab;
}

void shorterInt_free_twoDim(short int ***item, const unsigned int largeur)
{
    if( (**item) != NULL )
    {
        for(unsigned int i = 0 ; i < largeur ; i++)
        {
            free((*item)[i]);
            (*item)[i] = NULL;
        }

        free(*item);
        *item = NULL;
    }
}