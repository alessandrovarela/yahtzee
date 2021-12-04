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
#include <stdlib.h>
#include <time.h>

#define NUMDES 5
#define NUMMINDES 1
#define NUMMAXDES 6



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

int lancerDes (int min, int max )
{
    return rand() % max + min;
}

void imprimerLesFaces(int faces, int nombreRangee)
{
    if (nombreRangee == 1 || nombreRangee == 5)
    {
        printf("+-----+");   
    }
    switch (faces)
    {
    case 1:
        switch (nombreRangee)
        {
        case 2:
            printf("|     |");
            break;
        case 3:
            printf("|  O  |");
            break;
        case 4:
            printf("|     |");
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (nombreRangee)
        {
        case 2:
            printf("|    O|");
            break;
        case 3:
            printf("|     |");
            break;
        case 4:
            printf("|O    |");
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (nombreRangee)
        {
        case 2:
            printf("|    O|");
            break;
        case 3:
            printf("|  O  |");
            break;
        case 4:
            printf("|O    |");
            break;
        default:
            break;
        }
        break;
    case 4:
        switch (nombreRangee)
        {
        case 2:
            printf("|O   O|");
            break;
        case 3:
            printf("|     |");
            break;
        case 4:
            printf("|O   O|");
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (nombreRangee)
        {
        case 2:
            printf("|O   O|");
            break;
        case 3:
            printf("|  O  |");
            break;
        case 4:
            printf("|O   O|");
            break;
        default:
            break;
        }
        break;
    case 6:
        switch (nombreRangee)
        {
        case 2:
            printf("|O O O|");
            break;
        case 3:
            printf("|     |");
            break;
        case 4:
            printf("|O O O|");
            break;
        default:
            break;
        }
        break;
     
    default:
        break;
    }
}

void printTitreTest(char nomFunction[100])
{
  printf("|--------------------------------------------|\n");
  printf(" >>> test de la function \"%s\" \n", nomFunction);
  printf("|--------------------------------------------|\n");
}

void testImprimerLesFaces()
{
  printTitreTest("testImprimerLesFaces");

  imprimerLesFaces(1,1); printf("\n");
  imprimerLesFaces(1,2); printf("\n");
  imprimerLesFaces(1,3); printf("\n");
  imprimerLesFaces(1,4); printf("\n");
  imprimerLesFaces(1,5); printf("\n");

  imprimerLesFaces(2,1); printf("\n");
  imprimerLesFaces(2,2); printf("\n");
  imprimerLesFaces(2,3); printf("\n");
  imprimerLesFaces(2,4); printf("\n");
  imprimerLesFaces(2,5); printf("\n");

  imprimerLesFaces(3,1); printf("\n");
  imprimerLesFaces(3,2); printf("\n");
  imprimerLesFaces(3,3); printf("\n");
  imprimerLesFaces(3,4); printf("\n");
  imprimerLesFaces(3,5); printf("\n");

  imprimerLesFaces(4,1); printf("\n");
  imprimerLesFaces(4,2); printf("\n");
  imprimerLesFaces(4,3); printf("\n");
  imprimerLesFaces(4,4); printf("\n");
  imprimerLesFaces(4,5); printf("\n");

  imprimerLesFaces(5,1); printf("\n");
  imprimerLesFaces(5,2); printf("\n");
  imprimerLesFaces(5,3); printf("\n");
  imprimerLesFaces(5,4); printf("\n");
  imprimerLesFaces(5,5); printf("\n");

  imprimerLesFaces(6,1); printf("\n");
  imprimerLesFaces(6,2); printf("\n");
  imprimerLesFaces(6,3); printf("\n");
  imprimerLesFaces(6,4); printf("\n");
  imprimerLesFaces(6,5); printf("\n");
}

void testLancerDes()
{
  printTitreTest("testLancerDes");
  int test1 = lancerDes(NUMMINDES, NUMMAXDES);
    if (test1 >= NUMMINDES && test1 <= NUMMAXDES )
      printf("REUSSI, le numero returné %d est entre %d et %d\n", test1, NUMMINDES, NUMMAXDES);
    else
      printf("ÉCHEC, le numero returné %d est dehors %d et %d\n", test1, NUMMINDES, NUMMAXDES);
    
  test1 = lancerDes(NUMMINDES, NUMMAXDES);
    if (test1 >= NUMMINDES && test1 <= NUMMAXDES )
      printf("REUSSI, le numero returné %d est entre %d et %d\n", test1, NUMMINDES, NUMMAXDES);
    else
      printf("ÉCHEC, le numero returné %d est dehors %d et %d\n", test1, NUMMINDES, NUMMAXDES);
  
  test1 = lancerDes(NUMMINDES, NUMMAXDES);
    if (test1 >= NUMMINDES && test1 <= NUMMAXDES )
      printf("REUSSI, le numero returné %d est entre %d et %d\n", test1, NUMMINDES, NUMMAXDES);
    else
      printf("ÉCHEC, le numero returné %d est dehors %d et %d\n", test1, NUMMINDES, NUMMAXDES);
}

void rouleTousTestes()
{
  testImprimerLesFaces();
  testLancerDes();
} 


int main()
{
  srand(time(NULL));
  printf("inicio\n");
  rouleTousTestes();
  
}