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

#include "libyahtzee.h"
#include "yahtzeeTests.h"

#define NOMBREDES 5 //nombre de dés du Jet
#define MINFACEDES 1
#define MAXFACEDES 6

int main(int argc, char** argv)
{

	srand(time(NULL));

	if ((argc > 1) && 
		(((argv[1][0] = 'T') && (argv[1][1] == 'E') && (argv[1][2] == 'S') && (argv[1][3] == 'T')) || ((argv[1][0] = 't') && (argv[1][1] == 'e') &&  (argv[1][2] == 's') && (argv[1][3] == 't')))) 
	{
		rouleTousTestes();
	}
	else
		printf("inicio\n");
	return 0;
}