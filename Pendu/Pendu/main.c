//
//  main.c
//  Pendu
//
//  Created by Corentin Bringer on 23/09/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "dico.h"

char readChar(void);
int win(int findLetter[]);
int searchLetter(char letter, char secretWord[], int findLetter[]);

int main(int argc, const char * argv[]) {
    int i = 0;
    int lives = 10;
    int *findLetter = NULL;
    char letter = 0;
    char secretWord[100] = {0};
    long wordSize = 0;
    
    printf("Bienvenue dans le Pendu !\n\n");
    
    if (!takeWord(secretWord)) {
        exit(0);
    }
    
    wordSize = strlen(secretWord);
    
    findLetter = malloc(wordSize * sizeof(int));
    
    if (findLetter == NULL) {
        exit(0);
    }

    for (i = 0 ; i < wordSize ; i++) {
        findLetter[i] = 0;
    }
    
    while (lives > 0 && !win(findLetter)) {
        printf("\n\nIl vous reste %d coups a jouer", lives);
        printf("\nQuel est le mot secret ? ");

        for (i = 0 ; i < 6 ; i++) {
            if (findLetter[i]) {
                printf("%c", secretWord[i]);
            } else {
                printf("*");
            }
        }
        
        printf("\nProposez une lettre : ");
        letter = readChar();
        
        if (!searchLetter(letter, secretWord, findLetter)) {
                lives--;
        }
    }
    
    if (win(findLetter)) {
        printf("\n\nGagne ! Le mot secret etait bien : %s", secretWord);
    } else {
        printf("\n\nPerdu ! Le mot secret etait : %s", secretWord);
    }
    
    free(findLetter);
    
    return 0;
}

char readChar() {
    char charLetter = 0;
 
    charLetter = getchar();
    charLetter = toupper(charLetter);
 
    while (getchar() != '\n');
 
    return charLetter;
}

int win(int findLetter[]) {
    int i = 0;
    int playerWin = 1;

    for (i = 0 ; i < 6 ; i++) {
        if (findLetter[i] == 0)
            playerWin = 0;
    }

    return playerWin;
}

int searchLetter(char letter, char secretWord[], int findLetter[])
{
    int i = 0;
    int rightLetter = 0;

    for (i = 0 ; secretWord[i] != '\0' ; i++) {
        if (letter == secretWord[i]) {
            rightLetter = 1;
            findLetter[i] = 1;
        }
    }

    return rightLetter;
}
