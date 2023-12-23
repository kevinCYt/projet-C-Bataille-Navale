	    // fonction pour vérifier si un bateau est encore en vie ou pas ?
	    // en paramètre l'adresse d'une structure bateau, retour booléen

/** 
 * @file Vie.c
 * @brief this file contain the function of the end game condition
 *
 */
 
#include <stdio.h>
#include "bateau.h"
#include "case.h"
#include "plateau.h"


/**
 * @brief Check if a boat is still alive on the game board.
 *
 * This function determines whether a boat is still alive on the game board based on its position, size, and orientation.
 * If the boat is oriented vertically, it checks the corresponding column for any non-WRECK cells.
 * If the boat is oriented horizontally, it checks the corresponding row for any non-WRECK cells.
 *
 * @param bateau Pointer to the boat struct.
 * @param plateau Pointer to the game board struct.
 * @return 1 if the boat is still alive, 0 if the boat is wrecked.
 */
 
 
 
int EnVie(struct Bateau *bateau, struct Plateau *plateau){
	int colonne = bateau->colonne;
	int ligne = bateau->ligne;
	int taille = bateau->taille;
	int orientation = bateau->orientation;
	if(orientation==1){ 									//vertical
		for(int i = ligne; i<ligne+taille; i++){ 	
		
        	
			if(plateau->plato[i][colonne] != WRECK){ 
				return 1;
			}
		}
	}
	if(orientation==0){ 									//horizontal
		for(int i = colonne; i<colonne+taille; i++){	
			if(plateau->plato[ligne][i] != WRECK){ 
				return 1;		
			}
		
		}
	}
	return 0;	//WRECKED BOAT

}
