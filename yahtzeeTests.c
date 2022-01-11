// *****************************************************************************
// Nom : yahtzeeTests.c
//
// Auteurs : Alessandro Varela, Lucas Mendes
//
// Date : 07 dec 2021
//
// Liste de toutes les fonctions des testes du jeu Yahtzee
//
// *****************************************************************************

#include "yahtzeeTests.h"

// Fonctions pour les tests

void printTitreTest(char nomFunction[100])
{
  printf("\n");
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

void TestTrierLesDes(){
  printTitreTest("TestTrierLesDes");

  Jet jet_avant = { 1, 5 , 6 , 2 , 3};
  Jet jet;

  printf ( "Jet Avant ->%d %d %d %d %d\n" , jet_avant.des[0], jet_avant.des[1] ,  jet_avant.des[2] , jet_avant.des[3], jet_avant.des[4] );
  jet = trierLesDes(jet_avant);

  if ( jet.des[0] == 1  && jet.des[1] == 2 && jet.des[2] == 3 && jet.des[3] == 5 && jet.des[4] == 6) 
      printf("REUSSI, le Jet est triée: ");
  else
      printf("ÉCHEC, le Jet n'est pas triée: ");

  printf ( "%d %d %d %d %d\n" , jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );
}

void testImprimerJet()
{
  printTitreTest("TestImprimerJet");

  Jet jet = { 1, 5 , 6 , 2 , 3};
   
  printf( "Jet ->%d %d %d %d %d\n" , jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );
  printf("\n");

  imprimerJet(jet);

  printf("\n");
  Jet jet2 = { 3, 5, 1, 4, 2};
   
  printf( "Jet ->%d %d %d %d %d\n" , jet2.des[0], jet2.des[1] ,  jet2.des[2] , jet2.des[3], jet2.des[4] );
  printf("\n");

  imprimerJet(jet2);
}

void rouleTousTestes()
{
  testImprimerLesFaces();
  testlancerDe();
  TestlancerLesDes();
  TestTrierLesDes();
  testImprimerJet();
}