	    // fonction pour vérifier si un bateau est encore en vie ou pas ?
	    // en paramètre l'adresse d'une structure bateau, retour booléen

/** 
 * @file Vie.c
 * @brief this file contain the function of the end game condition
 *
 */
 
#include <stdio.h>
#include "constante.h"
#include "case.h"
#include "plateau.h"


/**
 * @brief Check if a boat is still alive on the game board.
 *
 * This function determines whether there is still boat alive on the game board 
 *
 * @param plateau Pointer to the game board struct.
 * @return 1 if there is boat still alive, 0 if all boat are wrecked.
 */
 
 

int alive(struct Plateau *plateau){
	int taille = COTE;
	for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (plateau->plato[i][j] == BOAT) {
                return 1;
		     }
        }
    }
	return 0;	//no boat alive
}
