//
//  main.c
//  Pendu
//
//  Created by Corentin Bringer on 23/09/2021.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char readChar(void);

int main(int argc, const char * argv[]) {
    int i = 0;
    int lives = 10;
    int findLetter[6] = {0};
    char letter = 0;
    char secretWord[] = "MARRON";
    
    printf("Bienvenue dans le Pendu !\n\n");
    
    while (lives > 0 && !gagne(findLetter)) {
        printf("\n\nIl vous reste %d coups a jouer", lives);
        printf("\nQuel est le mot secret ? ");

        for (i = 0 ; i < 6 ; i++) {
            if (findLetter[i]) {
                printf("%c", secretWord[i]);
            } else {
                printf("*");
            }
        }
    }
}

char readChar() {
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n');
 
    return caractere; // On retourne le premier caractère qu'on a lu
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
