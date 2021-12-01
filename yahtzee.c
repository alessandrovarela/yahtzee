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
#include <stdio.h>

 #define NUMDES 5

typedef struct Jet Jet;
struct Jet
{
    int jet[NUMDES];
};

int rollTheDice (int max, int min )
{
    srand(time(NULL));
    return rand() % max + min;
}


int main()
{
 printf("inicio");

}