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
#include <stdlib.h>
#include <time.h>

// #include "libyahtzee.h"
// #include "yahtzeeTests.h"

#define NOMBREDES 5 //nombre de dés du Jet
#define MINFACEDES 1
#define MAXFACEDES 6



// *****************************************************************************
// Structure Jet
//
// Nombre de dés du jeu
//
//*****************************************************************************
typedef struct Jet Jet;
struct Jet
{
    int des[NOMBREDES];
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

int lancerDe (int min, int max )
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

// *****************************************************************************
// lancerLesDes
//
// Lance les dés a chaque tour et a chaque choix d'utilisateur.
// Mettre la valeur d'un dé a chaque position du jet compte tenu la choix
// de l'utilisateur.
// Si la valeur de la position du Jet est = 1 un nouveau numéro sera tiré.
//
// INPUT :
//     jet: Adresse mémoire d'un Jet
//     char: Vecteur avec les choix de l'utilisateur 
//
// OUTPUT : 
//     void
//        
// *****************************************************************************
void lancerLesDes(Jet* jet , char choix[NOMBREDES])
{
    for(int i = 0; i < NOMBREDES; i++)
    {
        if (choix[i] == '1')
        jet->des[i] = lancerDe( MINFACEDES , MAXFACEDES);
    }
}


// Fonctions pour les tests

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

void testlancerDe()
{
  printTitreTest("testlancerDe");
  int test1 = lancerDe(MINFACEDES, MAXFACEDES);
    if (test1 >= MINFACEDES && test1 <= MAXFACEDES )
      printf("REUSSI, le numero returné %d est entre %d et %d\n", test1, MINFACEDES, MAXFACEDES);
    else
      printf("ÉCHEC, le numero returné %d est dehors %d et %d\n", test1, MINFACEDES, MAXFACEDES);
    
  test1 = lancerDe(MINFACEDES, MAXFACEDES);
    if (test1 >= MINFACEDES && test1 <= MAXFACEDES )
      printf("REUSSI, le numero returné %d est entre %d et %d\n", test1, MINFACEDES, MAXFACEDES);
    else
      printf("ÉCHEC, le numero returné %d est dehors %d et %d\n", test1, MINFACEDES, MAXFACEDES);
  
  test1 = lancerDe(MINFACEDES, MAXFACEDES);
    if (test1 >= MINFACEDES && test1 <= MAXFACEDES )
      printf("REUSSI, le numero returné %d est entre %d et %d\n", test1, MINFACEDES, MAXFACEDES);
    else
      printf("ÉCHEC, le numero returné %d est dehors %d et %d\n", test1, MINFACEDES, MAXFACEDES);
}

void TestlancerLesDes(){
  Jet jet = { 1, 5 , 6 , 2 , 3};

  char choix[] = "10001";
 
  printf ( "Jet Avant ->%d %d %d %d %d\n" , jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );
  lancerLesDes(&jet, choix);
  printf ( "Jet Aprés pour changer 10001 -> %d %d %d %d %d\n" , jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );

  char choix2[] = "11000";

  lancerLesDes(&jet, choix2);
  printf ( "Jet Aprés pour changer 11000 -> %d %d %d %d %d\n" , jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );

  char choix3[] = "00011";

  lancerLesDes(&jet, choix3);
  printf ( "Jet Aprés pour changer 00011 -> %d %d %d %d %d\n" , jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );

}

void rouleTousTestes()
{
  testImprimerLesFaces();
  testlancerDe();
  TestlancerLesDes();
} 


int main()
{
  srand(time(NULL));
  printf("inicio\n");
  rouleTousTestes();
  
}