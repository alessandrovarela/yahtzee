// *****************************************************************************
// Nom : libyahtzee.c
//
// Auteurs : Alessandro Varela, Lucas Mendes
//
// Date : 07 dec 2021
//
// Liste de toutes les fonctions pour le jeu Yahtzee
//
// *****************************************************************************


#include "libyahtzee.h"

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
