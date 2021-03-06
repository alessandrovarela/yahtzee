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
// #define MINFACEDES 1
// #define MAXFACEDES 6

// *****************************************************************************
// Enum 
//
// Quantité des faces de chaque possibilité de pointage du jeu.
//
//*****************************************************************************
enum {FACESCHANCE    = 1,
      FACESDOUBLE    = 2,
      FACESBRELAN    = 3,
      FACESCARRE     = 4,
      FACESYATHZEE   = 5,
      SEQPETITESUITE = 4,
      SEQGRANDESUITE = 5,
      MINFACEDES     = 1,
      MAXFACEDES     = 6}; 
// *****************************************************************************
enum {FACE1 = 1,
      FACE2 = 2,
      FACE3 = 3,
      FACE4 = 4,
      FACE5 = 5,
      FACE6 = 6};
// Structure Boolean
//
// Vrai ou Faux
//
//*****************************************************************************
typedef enum Boolean Boolean;
enum Boolean {FAUX,VRAI};
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
// *****************************************************************************
// trierLesDes
// 
// Organize les dés dans l'ordre croissant
// 
// INPUT : 
//     jet : cinq dés.
//
// OUTPUT : 
//     un structure avec les 5 dés triés par ordre croissant.
//
// *****************************************************************************
Jet trierLesDes(Jet jet);

// *****************************************************************************
// sommeFaces
//
// Valide le nombre des faces pour les figures "brelan", "carre", "yahtzee" et 
// "chance".
//
// INPUT :
//     jet : cinq dés.
//     int : nombre de faces
//
// OUTPUT : 
//     La somme de tout les faces si le nombre de faces est valide pour les figures
//     "brelan", "carre", "yahtzee" et "chance".
//
// *****************************************************************************
int sommeFaces(Jet jet, int nombreFaces);
// *****************************************************************************
// brelan
//
// Calcule le pointage pour la figure "brelan"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour brelan dans jet. Un brelan est trois faces
//     identiques. Il vaut la somme de dés.
//
// Exemples :
//     brelan({5,5,1,3,2}) = 0;
//     brelan({2,2,1,5,2}) = 2 + 2 + 1 + 5 + 2 = 12;
// *****************************************************************************
int brelan(Jet jet);

// *****************************************************************************
// lancerDe
//
// Retourne un nombre au hasard de 1 a 6 entre le min et max
// de l'utilisateur. 
//
// INPUT :
//     min: min nobmre hasard
//     max: max nombre hasard
//
// OUTPUT : 
//     int: nombre hasard
//        
// *****************************************************************************
int lancerDe (int min, int max );

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

void lancerLesDes(Jet* jet , char choix[NOMBREDES]);
void imprimerLesFaces(int faces, int nombreRangee);
void imprimerJet(Jet jet);
void garderPointage(Jet jet, Pointage* feuilleScore, char figure);
int nbDeFace (Jet jet, int face);
int mainPleine (Jet jet);
void imprimerScoresPossibles(Jet jet);
int carre(Jet jet);
int grandeSuite (Jet jet);
int chance(Jet jet);
int yahtzee(Jet jet);