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
int carre(Jet jet)
{
    return sommeFaces(jet, FACESCARRE);
}
/***********************************************************/
int chance(Jet jet)
{
    return sommeFaces(jet, FACESCHANCE);
}
/***********************************************************/
int lancerDe (int min, int max )
{
    return rand() % max + min;
}
/***********************************************************/
int yahtzee(Jet jet)
{
    return sommeFaces(jet, FACESYATHZEE) > 0 ? 50 : 0;
}
/***********************************************************/
int mainPleine (Jet jet)
{
    jet = trierLesDes(jet);

    Boolean estValide1 = (jet.des[0] == jet.des[1]) && ((jet.des[2] == jet.des[3]) && (jet.des[3] == jet.des[4]));
    Boolean estValide2 = ((jet.des[0] == jet.des[1]) && (jet.des[1] == jet.des[2])) && (jet.des[3] == jet.des[4]);

    return(estValide1 || estValide2) ? 25 : 0;
}

/***********************************************************/
int valideSequence (Jet jet, int sequence)
{
    jet = trierLesDes(jet);

    int compte = 1; 

    for(int i = 0; i < NOMBREDES; i++)
    {
        // Faire le test jusqu'à position avant la dernière
        if (i < (NOMBREDES - 1))
        {
            if (jet.des[i + 1] == (jet.des[i] + 1)) 
            {    
                compte++;
                if ( compte == sequence )
                   return VRAI;
            }
            else
            {                
                 if (jet.des[i + 1] != (jet.des[i]))  
                {                
                    compte = 1; 
                }
            }            
        }
    }
    return FAUX;
}
/***********************************************************/
int petiteSuite(Jet jet)
{
    if (valideSequence(jet, SEQPETITESUITE))
        return POINTSPETITSUITE;
    else
        return 0;    
}
/***********************************************************/
int grandeSuite (Jet jet)
{
    jet = trierLesDes(jet);
    
    Boolean estValide1 = (jet.des[1] == jet.des[0] + 1) && (jet.des[2] == jet.des[1] + 1) && (jet.des[3] == jet.des[2] + 1) && (jet.des[4] == jet.des[3] + 1);

    return(estValide1) ? 40 : 0;
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
/***********************************************************/
void garderPointage(Jet jet, Pointage* feuilleScore, char figure)
{
    switch (figure)
    {
    case '1':
        feuilleScore->un = nbDeFace(jet, FACE1);
        break;
    case '2':
        feuilleScore->deux = nbDeFace(jet, FACE2);
        break;
    case '3':
        feuilleScore->trois = nbDeFace(jet, FACE3);
        break;
    case '4':
        feuilleScore->quatre = nbDeFace(jet, FACE4);
        break;
    case '5':
        feuilleScore->cinq = nbDeFace(jet, FACE5);
        break;
    case '6':
        feuilleScore->six = nbDeFace(jet, FACE6);
        break;
    case 'b': 
    case 'B': 
        feuilleScore->brelan = brelan(jet);
        break;
    case 'c':
    case 'C':
        feuilleScore->carre = carre(jet);
        break;
    case 'm':
    case 'M':
        feuilleScore->mainPleine = mainPleine(jet);
        break;
    case 'p':
    case 'P':
        feuilleScore->pSuite = petiteSuite(jet);
        break;
    case 'g':
    case 'G':
        feuilleScore->gSuite = grandeSuite(jet);
        break;
    case 'y':
    case 'Y':
        feuilleScore->yahtzee = yahtzee(jet);
        break;
    case 'h':
    case 'H':
        feuilleScore->chance = chance(jet);
        break;

    default:
        break;
    }
}
/***********************************************************/
int sommeScoreSup(Pointage* feuilleScore)
{
    return feuilleScore->un + 
           feuilleScore->deux +  
           feuilleScore->trois + 
           feuilleScore->quatre + 
           feuilleScore->cinq + 
           feuilleScore->six;
}
/***********************************************************/
int sommeScoreInf(Pointage* feuilleScore)
{
    return feuilleScore->brelan + 
           feuilleScore->carre +  
           feuilleScore->mainPleine + 
           feuilleScore->pSuite + 
           feuilleScore->gSuite + 
           feuilleScore->yahtzee +
           feuilleScore->chance;

}
/***********************************************************/
int sommeScoreTotal(Pointage* feuilleScore)
{
    return sommeScoreSup(feuilleScore) + sommeScoreInf(feuilleScore) + feuilleScore->bonus; 
}
/***********************************************************/
int nbDeFace (Jet jet, int face)
{
    int compteur = 0;
    for (int i = 0; i < NOMBREDES; i++)
    {
            if (jet.des[i] == face)
            {
                compteur++;
            }
    }
    return compteur * face;
}
/***********************************************************/
void imprimerScoresPossibles(Jet jet)
{
    printf("**********************************************\n");
    printf("*    QUEL POINTAGE VOULEZ-VOUS GARDER?       *\n");
    printf("**********************************************\n");
    printf("*     (1) :  %2d       *       (B)relan = %2d  *\n", nbDeFace(jet, FACE1), brelan(jet));
    printf("*     (2) :  %2d       *        (C)arre = %2d  *\n", nbDeFace(jet, FACE2), carre(jet));
    printf("*     (3) :  %2d       *  (M)ain Pleine = %2d  *\n", nbDeFace(jet, FACE3), mainPleine(jet));
    printf("*     (4) :  %2d       * (P)etite suite = %2d  *\n", nbDeFace(jet, FACE4), 0);
    printf("*     (5) :  %2d       * (G)rande suite = %2d  *\n", nbDeFace(jet, FACE5), grandeSuite(jet));
    printf("*     (6) :  %2d       *      (Y)ahtzee = %2d  *\n", nbDeFace(jet, FACE6), yahtzee(jet));
    printf("*                     *       C(h)ance = %2d  *\n", chance(jet));
    printf("**********************************************\n");
}
/***********************************************************/
void imprimerFeuilleScore(Pointage* feuilleScore, int tour)
{
    
printf("************************************************************************************\n");
printf("*                              FEUILLE DE SCORE TOUR  %2d/%2d                        *\n", tour, NTOTALTOUR);
printf("************************************************************************************\n");
printf("*                                                                                  *\n");
printf("**********  Partie superieurem **********    **********  Partie inferieure *********\n");
printf("*                                      *    *                                      *\n");
printf("*                1 :  %2d               *    *               Brelan =  %2d           *\n",feuilleScore->un, feuilleScore->brelan );
printf("*                2 :  %2d               *    *               Carre  =  %2d           *\n",feuilleScore->deux, feuilleScore->carre );
printf("*                3 :  %2d               *    *          Main Pleine =  %2d           *\n",feuilleScore->trois, feuilleScore->mainPleine);
printf("*                4 :  %2d               *    *         Petite suite =  %2d           *\n",feuilleScore->quatre, feuilleScore->pSuite);
printf("*                5 :  %2d               *    *         Grande suite =  %2d           *\n",feuilleScore->cinq, feuilleScore->gSuite);
printf("*                6 :  %2d               *    *              Yahtzee =  %2d           *\n",feuilleScore->six, feuilleScore->yahtzee);
printf("*                                      *    *               Chance =  %2d           *\n",feuilleScore->chance);
printf("*                                      *    *                                      *\n");
printf("*     Somme partie superieure :   %2d   *    *     Somme partie inferieure :  %2d    *\n", sommeScoreSup(feuilleScore), sommeScoreInf(feuilleScore));
printf("****************************************    ****************************************\n");
if (feuilleScore->bonus > 0)
    printf("*                                    Bonus = %2d                                    *\n", feuilleScore->bonus);
else
    printf("*                                                                                  *\n");
printf("************************************************************************************\n");
printf("*                                     Score =  %2d                                  *\n", sommeScoreTotal(feuilleScore));
printf("************************************************************************************\n");
}