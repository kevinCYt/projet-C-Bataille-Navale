// Structure plateau de jeu (1 plateau par joueur)
	    // double pointeur pour la matrice
	    // taille du cote de la matrice
	    // initialisé à vide
	    
#ifndef	PLATEAU_H
#define PLATEAU_H
;

/**
 * @struct Plateau
 * @brief Represents a game board.
 *
 * A game board is defined by a matrix of size size x size.
 * Each element in the matrix may contain specific information.
 */

struct Plateau{
	int** plato;/**< Matrix representing the game board. */
	int taille;  /**< Size of the game board (number of rows/columns). */
};
#endif
