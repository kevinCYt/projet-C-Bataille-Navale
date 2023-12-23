// fonction qui sequence un tour de jeu (joueur) 
	    // demande case X / Y
	    // effectue le tir et modifie en conséquence
	    // affiche un message en fonction
/** 
 * @file jeuJoueur.c
 * @brief this file contain the function of the player's turn
 *
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"
#include "constante.h"

/**
 * @brief Simulate a player's turn in the game.
 *
 * The function prompts the user to enter the coordinates (row, column) to attack.
 * If the selected position contains an opponent's boat, it is marked as "hit" (2 in the matrix),
 * otherwise, it is marked as "missed" (-1 in the matrix).
 *
 * @param jeu Pointer to the game state struct.
 */
void tourDeJeuJoueur(struct Jeu *jeu) {
    int ligne, colonne;

    // Prompt the user to enter the coordinates (row, column)
    printf("Enter the row (0-%d): ", COTE - 1);
    if (scanf("%d", &ligne) != 1) {
        exit(0);
    }
    if (ligne > COTE - 1 || ligne < 0) {
        printf("Out of range\n");
        exit(0);
    }

    printf("Enter the column (0-%d): ", COTE - 1);
    if (scanf("%d", &colonne) != 1) {
        exit(1);
    }
    if (colonne > COTE - 1 || colonne < 0) {
        printf("Out of range\n");
        exit(0);
    }

    // Check if the position contains an opponent boat
    if (jeu->bateauOrdi.plato[ligne][colonne] == 1) {
        // Hit! Replace 1 with 2 in the matrix
        jeu->bateauOrdi.plato[ligne][colonne] = 2;
        jeu->joueur.plato[ligne][colonne] = 2;
        printf("Hit!\n");
    } else {
        // Miss! Replace 1 with -1 in the matrix
        jeu->bateauOrdi.plato[ligne][colonne] = -1;
        jeu->joueur.plato[ligne][colonne] = -1;
        printf("Missed!\n");
    }
}





