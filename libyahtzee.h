// *****************************************************************************
// Nom : yahtzee.h
//
// Auteurs : Alessandro Varela, Lucas Mendes
//
// Date : 07 Dec 2021
//
// Documentation de toute les fonctions pour pour le jeu Yahtzee
//
// *****************************************************************************

#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOMBREDES 5 //nombre de dés du jeu
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

int lancerDe (int min, int max );
void imprimerLesFaces(int faces, int nombreRangee);
void lancerLesDes(Jet* jet , char choix[NOMBREDES]);

