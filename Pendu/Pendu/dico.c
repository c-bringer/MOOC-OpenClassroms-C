//
//  dico.c
//  Pendu
//
//  Created by Corentin Bringer on 27/09/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "dico.h"

int takeWord(char *takenWord)
{
    FILE* dico = NULL;
    int numberWords = 0, numberWordChose = 0, i = 0;
    int readChar = 0;
    dico = fopen("/Users/corentinbringer/Documents/GitHub/MOOC-OpenClassroms-C/Pendu/Pendu/dico.txt", "r");

    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }

    do
    {
        readChar = fgetc(dico);
        if (readChar == '\n')
            numberWords++;
    } while(readChar != EOF);

    numberWordChose = randomNumber(numberWords);

    rewind(dico);
    while (numberWordChose > 0)
    {
        readChar = fgetc(dico);
        if (readChar == '\n')
            numberWordChose--;
    }

    fgets(takenWord, 100, dico);

    takenWord[strlen(takenWord) - 1] = '\0';
    fclose(dico);

    return 1;
}

int randomNumber(int numberMax)
{
    srand(time(NULL));
    return (rand() % numberMax);
}
