	    // fonction pour créer un bateau qui prend les paramètres necessaires
	    // et qui va allouer une structure bateau décrite précédemment
/** 
 * @file bateau.c
 * @brief this file contain the function of boat creation
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "bateau.h"
#include "constante.h" //COTE de la matrice plateau
;

/**
 * @brief Create a boat with random attributes.
 *
 * This function creates a boat with a random size (between 1 and 5) and a random orientation (0 for horizontal, 1 for vertical).
 * If the orientation is horizontal, the row index is randomly selected to avoid exceeding the array boundaries.
 * If the orientation is vertical, the column index is randomly selected to avoid exceeding the array boundaries.
 *
 * @return A boat with random attributes.
 */
struct Bateau creerBateau(){
	struct Bateau bateau;
	
	bateau.taille = (rand() % 5) + 1; // taille entre 1 et 5
	bateau.orientation = rand() % 2;  // 0 pour horizontale, 1 pour verticale
	
	if(bateau.orientation == 0){	   // si horizontale
		bateau.ligne = rand() % (COTE - bateau.taille + 1);  // on ne déborde pas du tableau de cette manière au niveau de la ligne
		bateau.colonne = rand() % COTE;					 // pas de contrainte
	}
	else{
		bateau.colonne = rand() % (COTE - bateau.taille + 1);  // on ne déborde pas du tableau de cette manière au niveau de la colonne
		bateau.ligne = rand() % COTE;					   // pas de contrainte
	}
	return bateau;
}
