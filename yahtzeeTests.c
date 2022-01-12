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

/*************************************************/
void printTitreTest(char nomFunction[100])
{
  printf("\n");
  printf("|--------------------------------------------|\n");
  printf(" >>> test de la function \"%s\" \n", nomFunction);
  printf("|--------------------------------------------|\n");
}

/*************************************************/
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

/*************************************************/
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

/*************************************************/
void testlancerLesDes(){
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

/*************************************************/
void testTrierLesDes(){
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

/*************************************************/
void testImprimerJet()
{
  printTitreTest("TestImprimerJet");

  Jet jet = { 1, 5 , 6 , 2 , 3};

  printArrJet("Jet ->" , jet );
  printf("\n");

  imprimerJet(jet);

  printf("\n");
  Jet jet2 = { 3, 5, 1, 4, 2};
   
  printArrJet("Jet ->" , jet2 );
  printf("\n");

  imprimerJet(jet2);
}

/*************************************************/
void testSommeFaces(){

  printTitreTest("testSommeFaces");

  Jet jet_pas_brelan  = { 1, 2 , 6 , 5 , 5};
  printArrJet( "Jet pas Brelan (Attendu 0) ->", jet_pas_brelan);

  int sommePasBrelan = sommeFaces(jet_pas_brelan, FACESBRELAN);

  if (sommePasBrelan == 0)  
    printf("REUSSI, la somme du Jet est 0\n\n");
  else 
    printf("ÉCHEC, la  somme du Jet est diferant de zero\n\n");


  Jet jet_chance  = { 1, 2 , 1 , 3 , 5};
  printArrJet( "Jet chance (Attendu 12) ->", jet_chance);

  int sommechance = sommeFaces(jet_chance, FACESCHANCE);

  if (sommechance == 12)  
    printf("REUSSI, la somme du Jet est 12\n\n");
  else 
    printf("ÉCHEC, la  somme du Jet n'est pas 12\n\n");

  Jet jet_brelan  = { 1, 5 , 6 , 5 , 5};
  printArrJet( "Jet Brelan de 5 (Attendu 22) ->", jet_brelan);

  int sommeBrelan = sommeFaces(jet_brelan, FACESBRELAN);

  if (sommeBrelan == 22)  
    printf("REUSSI, la somme du Jet est 22\n\n");
  else 
    printf("ÉCHEC, la  somme du Jet n'est pas 22\n\n");

  Jet jet_carre  = { 2, 5 , 2 , 2 , 2};
  printArrJet( "Jet Carre de 2 (Attendu 13) ->", jet_carre);

  int sommeCarre = sommeFaces(jet_carre, FACESCARRE);

  if (sommeCarre == 13)  
    printf("REUSSI, la somme du Jet est 13\n\n");
  else 
    printf("ÉCHEC, la  somme du Jet n'est pas 13\n\n\n");


  Jet jet_yahtzee  = { 3, 3 , 3 , 3 , 3};
  printArrJet( "Jet Yahtzee de 3 (Attendu Vrai) ->", jet_yahtzee);

  int sommeYahtzee = sommeFaces(jet_yahtzee, FACESYATHZEE);

  if (sommeYahtzee )  
    printf("REUSSI, le Jet est un Yahtzee\n\n");
  else 
    printf("ÉCHEC, le Jet n'est pas un Yatzee\n\n");

}

/*************************************************/
void testBrelan()
{

  printTitreTest("testBrelan");

	Jet testBrelanUn = {2,1,1,1,5};
	int resultatTestUn = brelan(testBrelanUn);
  printArrJet( "Jet Brelan de 1 (Attendu Vrai et somme 10) ->", testBrelanUn );
	
	if (resultatTestUn == 10)
		printf ("RÉUSSI! :) Le Jet c'est un Brelan est la somme est %d\n\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (Brelan) est %d et aurait dû être 10\\nn", resultatTestUn);	

	Jet testDeuxPasBrelan = {1,2,3,4,5};
  printArrJet( "Jet pas Brelan (Attendu 0) ->", testDeuxPasBrelan );
	int resultatTestDeux = brelan(testDeuxPasBrelan);
	
	if (resultatTestDeux == 0)
		printf ("RÉUSSI! :) Le Jet n'ai pas un Brelan est la somme est %d\n\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (Brelan) est %d et aurait dû être 0\n\n", resultatTestDeux);
}

/*************************************************/
void printArrJet(char msg[100] , Jet jet ){
 printf( "%s %d %d %d %d %d\n" , msg, jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );  
}
/*************************************************/

void rouleTousTestes()
{
  testImprimerLesFaces();
  testlancerDe();
  testlancerLesDes();
  testTrierLesDes();
  testImprimerJet();
  testSommeFaces();
  testBrelan();
}