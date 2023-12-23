// fonction qui sequence un tour de jeu (ordi)
	    // qui effectue un tir aleatoire là ou on a pas deja tiré (au mieux !!)
/** 
 * @file jeuOrdi.c
 * @brief this file contain the function of the computer's turn
 *
 */
 

#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"
#include "constante.h"

/**
 * @brief Perform the computer's turn in the game.
 *
 * The function randomly selects a position on the player's board to attack.
 * If the selected position contains a boat, it is marked as "hit" (2 in the matrix),
 * otherwise, it is marked as "missed" (-1 in the matrix).
 *
 * @param jeu Pointer to the game state struct.
 */
void tourDeJeuOrdinateur(struct Jeu *jeu) {
    int ligne, colonne;

    // Generate random position until an untargeted position is found
    do {
        ligne = rand() % COTE;
        colonne = rand() % COTE;
    } while (jeu->bateauJoueur.plato[ligne][colonne] == 2 || jeu->bateauJoueur.plato[ligne][colonne] == -1);

    // Verify if there's a boat at the selected position
    if (jeu->bateauJoueur.plato[ligne][colonne] == 1) {
        // A hit: replace 1 with 2 in the matrix
        jeu->bateauJoueur.plato[ligne][colonne] = 2;
        printf("The computer hit at (%d, %d)!\n", ligne, colonne);
    } else {
        // A miss: mark as -1 in the matrix
        jeu->bateauJoueur.plato[ligne][colonne] = -1;	
        printf("The computer missed.\n");
    }
}

