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

/*******************************************/
Jet trierLesDes(Jet jet)
{
    int min;

    for(int i = 0; i < NOMBREDES; i++)
    {
        for(int j = 0; j < NOMBREDES; j++)
        {
            if (jet.des[j] > jet.des[i])
            {
                min = jet.des[i];
                jet.des[i] = jet.des[j];
                jet.des[j] = min;
            }
        }
    }
    return jet;
}
/*************************************************/
int sommeFaces(Jet jet, int nombreFaces) 
{
    jet = trierLesDes(jet);

    int compte = 1;
    int somme  = 0;
    Boolean estValide = FAUX;

    for(int i = 0; i < NOMBREDES; i++)
    {
        // Faire le test le test jusqu'à position avant la dernière
        if (i < (NOMBREDES - 1))
        {
            if ( jet.des[i] == jet.des[ i + 1])
            {    
                compte++;
                if (compte >= nombreFaces)
                    estValide = VRAI; 
            }
            else
                compte = 1;
        }
        somme += jet.des[i]; 
    }
    if ((estValide) || (nombreFaces == FACESCHANCE))
        return somme;
    else
        return FAUX;    
}

/***********************************************************/
int brelan(Jet jet)
{
    return sommeFaces(jet, FACESBRELAN);
}

/***********************************************************/
int lancerDe (int min, int max )
{
    return rand() % max + min;
}
/***********************************************************/
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

/***********************************************************/
void lancerLesDes(Jet* jet , char choix[NOMBREDES])
{
    for(int i = 0; i < NOMBREDES; i++)
    {
        if (choix[i] == '1')
        jet->des[i] = lancerDe( MINFACEDES , MAXFACEDES);
    }
}
/***********************************************************/
void imprimerJet(Jet jet) 
{
    for (int i = 1;i <= 5; i++)
    {
        printf(" ");
        for (int j = 0;j < NOMBREDES; j++)
        {
            printf(" ");
            imprimerLesFaces(jet.des[j], i);
        }
        printf("\n");
    }
}

