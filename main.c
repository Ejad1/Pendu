/*
    Name: main.c
    Goal: Déroulement du jeu du pendu
    Author: EJAD
    Date: 31-08-2023
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

void printHangman(int attempts) {
    switch (attempts) {
        case 6:
            printf("\n\n");
            break;
        case 5:
            printf("\n\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 4:
            printf("\n\n");
            printf(" |---|\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 3:
            printf("\n\n");
            printf(" |---|\n");
            printf(" |   O\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 2:
            printf("\n\n");
            printf(" |---|\n");
            printf(" |   O\n");
            printf(" |   |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 1:
            printf("\n\n");
            printf(" |---|\n");
            printf(" |   O\n");
            printf(" |  /|\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        case 0:
            printf("\n\n");
            printf(" |---|\n");
            printf(" |   O\n");
            printf(" |  /|\\n");
            printf(" |  / \\n");
            printf(" |\n");
            printf("_|_\n");
            break;
        default:
            break;
    }
}


int main() {

    setlocale(LC_CTYPE, "");

    char word[] = "PENDU";
    int wordLength = strlen(word);
    char guessedWord[wordLength];
    memset(guessedWord, '_', wordLength);
    int attempts = 6;

    printf("Bienvenue dans le jeu du Pendu!\n");

    while (attempts > 0) {
        printf("Mot actuel: %s\n", guessedWord);
        printf("Tentatives restantes: %d\n", attempts);
        char guess;
        printf("Devinez une lettre: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            attempts--;
            printHangman(attempts);
        }

        if (strcmp(guessedWord, word) == 0) {
            printf("Félicitations, vous avez gagné ! Le mot était : %s\n", word);
            break;
        }
    }

    if (attempts == 0) {
        printf("Désolé, vous avez perdu. Le mot était : %s\n", word);
    }

    return 0;
}
