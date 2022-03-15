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

  printTitreTest("testlancerLesDes");
  Jet jet = { 1, 5 , 6 , 2 , 3};

  char choix[] = "10001";
 
  printArrJet ( "Jet Avant ->" ,  jet);
  lancerLesDes(&jet, choix);
  printArrJet ( "Jet Aprés pour changer 10001 ->", jet);

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

  Jet jet_avant = { 3, 6 , 5 , 2 , 1};
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
void testCarre()
{
  printTitreTest("testCarre"); 

	Jet testcarreUn = {1,1,1,1,5};
	int resultatTestCarre = carre(testcarreUn);
  printArrJet( "Jet carre de 1 (Attendu Vrai et somme 9) ->", testcarreUn );

  if (resultatTestCarre == 9)
		printf ("RÉUSSI! :) Le Jet c'est un carre est la somme est %d\n\n", resultatTestCarre);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 9\n\n", resultatTestCarre);
  

	Jet testcarre2 = {3,4,3,3,3};
	resultatTestCarre = carre(testcarre2);
  printArrJet( "Jet carre de 1 (Attendu Vrai et somme 16) ->", testcarre2);

  if (resultatTestCarre == 16)
		printf ("RÉUSSI! :) Le Jet c'est un carre est la somme est %d\n\n", resultatTestCarre);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 16\n\n", resultatTestCarre);
  

	Jet testcarre3 = {1,1,2,2,5};
	resultatTestCarre = carre(testcarre3);
  printArrJet( "Jet carre de 1 (Attendu Vrai et somme 0) ->", testcarre3 );

  if (resultatTestCarre == 0)
		printf ("RÉUSSI! :) Le Jet c'est un carre est la somme est %d\n\n", resultatTestCarre);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 9\n\n", resultatTestCarre);
}
/*************************************************/
void testGrandeSuite()
{
  printTitreTest("testGrandeSuite"); 

	Jet testGrandeSuite1 = {1,6,4,2,5};
	int resultatTestGrandeSuite = grandeSuite(testGrandeSuite1);
  printArrJet( "Jet grande suite de 1 (Attendu Vrai et somme 40) ->", testGrandeSuite1 );

  if (resultatTestGrandeSuite == 40)
		printf ("RÉUSSI! :) Le Jet c'est un carre est la somme est %d\n\n", resultatTestGrandeSuite);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 40\n\n", resultatTestGrandeSuite);

	Jet testGrandeSuite2 = {6,3,4,2,5};
	resultatTestGrandeSuite = grandeSuite(testGrandeSuite2);
  printArrJet( "Jet grande suite de 1 (Attendu Vrai et somme 40) ->", testGrandeSuite2);

  if (resultatTestGrandeSuite == 40)
		printf ("RÉUSSI! :) Le Jet c'est un carre est la somme est %d\n\n", resultatTestGrandeSuite);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 40\n\n", resultatTestGrandeSuite);
}
/*************************************************/
void printArrJet(char msg[100] , Jet jet ){
 printf( "%s %d %d %d %d %d\n" , msg, jet.des[0], jet.des[1] ,  jet.des[2] , jet.des[3], jet.des[4] );  
}
/*************************************************/
void testNbDeFace()
{
  printTitreTest("testNbDeFace");

  Jet jet1 = {3,4,1,1,5};
  int face1 = 1;
  int result1 = nbDeFace(jet1, face1);

  printArrJet("jet1 -> ",jet1);
  printf("face1 -> %d\n", face1);

  if(result1 == 2)
      printf("REUSSI! :), la fonction retourne 2\n");
    else
      printf("ECHEC! :(, la fonction ne retourne pas 2, elle retourne %d\n", result1);

  Jet jet2 = {3,4,1,3,3};
  int face2 = 3;
  int result2 = nbDeFace(jet2, face2);

  printArrJet("\njet2 -> ",jet2);
  printf("face2 -> %d\n", face2);

  result2 == 9 ? printf("REUSSI! :), la fonction retourne 9\n") : printf("ECHEC! :(, la fonction ne retourne pas 9, elle retourne %d\n", result2);

  Jet jet3 = {5,5,5,5,5};
  int face3 = 5;
  int result3 = nbDeFace(jet3, face3);

  printArrJet("\njet3 -> ",jet3);
  printf("face3 -> %d\n", face3);

  result3 == 25 ? printf("REUSSI! :), la fonction retourne 25\n") : printf("ECHEC! :(, la fonction ne retourne pas 25, elle retourne %d\n", result3);
}
/*************************************************/
void testMainPLeine()
{
  printTitreTest("testMainPLeine");

  Jet testMainPleine1 = {4,4,3,3,3};
  int resultatTest1 = mainPleine(testMainPleine1);
  printArrJet("Main pleine, 1 paire et 1 brelan, ->", testMainPleine1);

  if (resultatTest1 != 0)
    printf("cerrto\n\n");
  else
    printf("errrado\n\n");

  Jet testMainPleine2 = {4,4,4,3,3};
  int resultatTest2 = mainPleine(testMainPleine2);
  printArrJet("Main pleine, 1 paire et 1 brelan, ->", testMainPleine2);

  if (resultatTest2 != 0)
    printf("cerrto\n");
  else
    printf("errrado\n");

  Jet testMainPleine3 = {4,4,4,4,3};
  int resultatTest3 = mainPleine(testMainPleine3);
  printArrJet("Main pleine, 1 paire et 1 brelan, ->", testMainPleine3);

  if (resultatTest3 != 0)
    printf("cerrto\n");
  else
    printf("errrado\n");
}
/*************************************************/
void testChance()
{
   printTitreTest("testChance");

  Jet testyahtzee = {3,2,5,5,1};
  int resultatTestyahtzee = chance(testyahtzee);
  printArrJet("chance, ->", testyahtzee);

  if (resultatTestyahtzee == 16)
		printf ("RÉUSSI! :) Le Jet c'est un chance est la somme est %d\n\n", resultatTestyahtzee);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 chance est %d et aurait dû être 16\n\n", resultatTestyahtzee);

  Jet testChance2 = {1,3,5,4,4};
  int resultatTestChance2 = chance(testChance2);
  printArrJet("chance, ->", testChance2);

  if (resultatTestChance2 == 17)
		printf ("RÉUSSI! :) Le Jet c'est un carre est la somme est %d\n\n", resultatTestChance2);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 17\n\n", resultatTestChance2);
}
/*************************************************/
void testYahtzee()
{
  printTitreTest("testYahtzee");

  Jet testYahtzee1 = {3,2,5,5,1};
  int resultatTestyahtzee = yahtzee(testYahtzee1);
  printArrJet("yahtzee, ->", testYahtzee1);

  if (resultatTestyahtzee == 50)
		printf ("RÉUSSI! :) Le Jet c'est un yahtzee et le resultat est %d\n\n", resultatTestyahtzee);
	else 
		printf ("ÉCHEC! :( Le resultat du testYahtzee est %d et aurait dû être 50\n\n", resultatTestyahtzee);

  Jet testYahtzee2 = {4,4,4,4,4};
  int resultatTestYahtzee2 = yahtzee(testYahtzee2);
  printArrJet("yahtzee, ->", testYahtzee2);

  if (resultatTestYahtzee2 == 50)
		printf ("RÉUSSI! :) Le Jet c'est un yahtzee et le resultat est %d\n\n", resultatTestYahtzee2);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 est %d et aurait dû être 50\n\n", resultatTestYahtzee2);
}
/*************************************************/
void testeImprimerScoresPossibles(Jet jet)
{
  printTitreTest("testeImprimerScoresPossibles");
  Jet testeImprimerScoresPossibles1 = {2,2,3,3,3};
  imprimerScoresPossibles(testeImprimerScoresPossibles1);
}

void rouleTousTestes()
{
  testImprimerLesFaces();
  testlancerDe();
  testlancerLesDes();
  testTrierLesDes();
  testImprimerJet();
  testSommeFaces();
  testBrelan();
  testCarre();
  testChance();
  testNbDeFace();
  testMainPLeine();
  testGrandeSuite();
  testYahtzee();
 // testeImprimerScoresPossibles();
}