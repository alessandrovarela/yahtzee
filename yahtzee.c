// ****************************************************************************
// 
// File name : yahtzee.c
//
// Author : Lucas
// 
// Creation date : 29/11/2021
//
// 
//
// ****************************************************************************

#include <stdio.h>
#include <stdio.h>

#define NUMDES 5


// *****************************************************************************
// Structure Jet
//
// Nombre de dés du jeu
//
//*****************************************************************************
typedef struct Jet Jet;
struct Jet
{
    int des[NUMDES];
};

// *****************************************************************************
// Structure Pointage
//
// Liste de type de pointage du jeu. Comprend touts le possibilité de 
// ponctuation.
//
//*****************************************************************************
typedef struct Pointage Pointage; 
struct Pointage 
{
    int un; 
    int deux;
    int trois;
    int quatre;
    int cinq;
    int six;
    int brelan;
    int carre;
    int mainPleine;
    int pSuite;
    int gSuite;
    int yahtzee;
    int chance;
};

/* int rollTheDice (int max, int min )
{
    srand(time(NULL));
    return rand() % max + min;
}
 */

int main()
{
 printf("inicio");

}