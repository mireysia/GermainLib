#ifndef __SHORTER_INT_H__
#define __SHORTER_INT_H__

short int** shorterInt_arrays_newTwoDim(const unsigned int largeur, const unsigned int hauteur);

short int** shorterInt_arrays_newTwoDim_Data(const unsigned int largeur, const unsigned int hauteur, const short int data);

void shorterInt_free_twoDim(short int ***item, const unsigned int largeur);

#endif