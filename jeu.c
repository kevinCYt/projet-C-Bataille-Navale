	    // fonction pour créer un "jeu" (2 plateaux, 2 tableaux de bateaux initialisés)
	    // cette fonction place les bateaux de maniere aleatoire (pseudo-aleatoire)
	    // et fait en sorte que 2 bateaux ne se touchent pas 
	    
	 	// fonction pour créer un bateau qui prend les paramètres necessaires
	    // et qui va allouer une structure bateau décrite précédemment
/** 
 * @file jeu.c
 * @brief this file contain the function of the game
 *
 */
 

#include <stdlib.h>
#include <stdio.h>
#include "plateau.h"
#include "bateau.h"
#include "case.h"
#include "jeu.h"
#include "constante.h"//COTE de la matrice plateau
;

/**
 * @brief Create a boat with random attributes.
 *
 * This function creates a boat with a random size (between 1 and 5) and a random orientation (0 for horizontal, 1 for vertical).
 *
 * @return A boat with random attributes.
 */

struct Bateau creerBateau(){
	struct Bateau bateau;
	
	bateau.taille = (rand() % 5) + 1; // taille between 1 and 5 (may be chosen)
	bateau.orientation = rand() % 2;  // 0 for horizontal , 1 for vertical
	
	if(bateau.orientation == 0){	   // if horizontal
		bateau.ligne = rand() % COTE ; 						 // We do not overflow from the array in this way at the row level
		bateau.colonne = rand() % (COTE- bateau.taille + 1);					
	}
	else{
		bateau.colonne = rand() % COTE ;  // oWe do not overflow from the array in this way at the column level
		bateau.ligne = rand() % (COTE- bateau.taille + 1);					   
	}
	return bateau;
};




/**
 * @brief Initialize the game state with dynamically allocated matrices for the player's and computer's boards.
 *
 * This function initializes the game state by allocating memory for the player's and computer's boards.
 *
 * @param plateau Pointer to the game board struct.
 */



void initialiserJeu(struct Plateau *plateau) {
    plateau->taille = COTE;
    // Allocate memory for the matrix
    plateau->plato = malloc(plateau->taille * sizeof(int*));
    if (plateau->plato == NULL) {
        printf("erreur d'allocation pour plateau->plato\n");
        exit(0);
    }
    
    for (int i = 0; i < plateau->taille; i++) {
        plateau->plato[i] = malloc(plateau->taille * sizeof(int));
        if (plateau->plato[i] == NULL) {
            printf("erreur d'allocation pour plateau->plato[%d]\n", i);
            exit(1);
        }

        for (int j = 0; j < plateau->taille; j++) {
            plateau->plato[i][j] = 0;
    	}
    }
}



/**
 * @brief Free the dynamically allocated memory for the game boards.
 *
 * This function frees the memory allocated for the player's and computer's boards.
 *
 * @param plateau Pointer to the game board struct.
 */

void libererJeu(struct Plateau *plateau) {
    for (int i = 0; i < plateau->taille; i++) {
        free(plateau->plato[i]);
    }
    free(plateau->plato);
};



/**
 * @brief Check if a location is available on the player's board for placing a boat.
 *
 * This function checks if the specified location on the player's board is available for placing a boat of given size and orientation.
 *
 * @param jeu Pointer to the game state struct.
 * @param ligne The row index of the top-left corner of the boat.
 * @param colonne The column index of the top-left corner of the boat.
 * @param taille The size of the boat.
 * @param orientation The orientation of the boat (0 for horizontal, 1 for vertical).
 * @return 1 if the location is available, 0 otherwise.
 */



int estEmplacementLibre(struct Jeu *jeu, int ligne, int colonne, int taille, int orientation) {
	
	if(orientation == 0) { // if horizontal
		for(int i = 0; i < taille; i++) {
        	if (taille > 9-colonne){
        		return 0;
        	}
			if(jeu->bateauJoueur.plato[ligne][colonne+i] != 0) {
                return 0; // location not free
            }
        }
    } 
    else { // if vertical
        for(int j = 0; j < taille; j++) {
        	if(taille > 9-ligne){
        		return 0;
        	}
            if(jeu->bateauJoueur.plato[ligne+j][colonne] != 0) {
                return 0; //location not free
            }
        }
    }
    return 1; // location free
};


/**
 * @brief Place boats on the player's board without collision.
 *
 * This function places boats on the player's board without collision by generating random boat attributes and checking for availability.
 *
 * @param jeu Pointer to the game state struct.
 * @return An array of boats placed on the player's board.
 */

void placerBateau(struct Jeu *jeu) {
    struct Bateau* bateaux = malloc(N_BATEAU * sizeof(struct Bateau));
    if(bateaux == NULL){
    	printf("erreur d'allocation");
    	exit(3);
    }

    for (int i = 0; i < N_BATEAU; i++) {
        struct Bateau bateau;

        // verify if location is free before putting the boat
        do {
            bateau = creerBateau(); // Create boat
        } while (!estEmplacementLibre(jeu, bateau.ligne, bateau.colonne, bateau.taille, bateau.orientation));   //tant que l'emplacement n'est pas libre

        bateaux[i] = bateau; // add boat to list/tab
    }

    // place the boat on the board
    for (int i = 0; i < N_BATEAU; i++) {
        struct Bateau bateau = bateaux[i];

        if (bateau.orientation == 0) { // if horizontal
            for (int j = 0; j < bateau.taille; j++) {
                jeu->bateauJoueur.plato[bateau.ligne][bateau.colonne + j] = 1;
            }
        } else { // if vertical
            for (int j = 0; j < bateau.taille; j++) {
                jeu->bateauJoueur.plato[bateau.ligne + j][bateau.colonne] = 1;
            }
        }
    }
	free(bateaux);
};


/**
 * @brief Place computer's boats on its board without collision.
 *
 * This function places computer's boats on its board without collision by generating random boat attributes and checking for availability.
 *
 * @param jeu Pointer to the game state struct.
 * @return An array of boats placed on the computer's board.
 */
 
void placerBatOrdi(struct Jeu *jeu){
	struct Bateau* batOrdix = malloc(N_BATEAU * sizeof(struct Bateau));
	if(batOrdix == NULL){
		printf("erreur d'allocation");
		exit(3);
	}

	for (int i = 0; i < N_BATEAU; i++) {
		struct Bateau bateau;

        // verify if location is free before putting the boat
	do {
		bateau = creerBateau(); // Create boat
	} while (!estEmplacementLibre(jeu, bateau.ligne, bateau.colonne, bateau.taille, bateau.orientation));   //tant que l'emplacement n'est pas libre

	batOrdix[i] = bateau; // add boat to list/tab
	}
 

    // place the boat on the board
	for (int i = 0; i < N_BATEAU; i++) {
		struct Bateau bateau = batOrdix[i];
		if (bateau.orientation == 0) { // if horizontal
			for (int j = 0; j < bateau.taille; j++) {
				jeu->bateauOrdi.plato[bateau.ligne][bateau.colonne + j] = 1;
			}
		}
		else { // Otherwise vertical
			for (int j = 0; j < bateau.taille; j++) {
				jeu->bateauOrdi.plato[bateau.ligne + j][bateau.colonne] = 1;
		    	}
		}
	}
	free(batOrdix);
};

