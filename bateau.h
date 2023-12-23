// structure pour chaque bateau
	    // - taille bateau
	    // - position de référence (coordonnées, soit du milieu, soit du pt en haut à gauche)
	    // - orientation
	    
#ifndef BATEAU_H
#define BATEAU_H

/**
 * @file bateau.h
 * @brief Header file containing the struct for representing boats in the game.
 */

/**
 * @struct Bateau
 * @brief Represents a boat in the game.
 *
 * This struct defines the attributes of a boat:
 * - taille: The size of the boat.
 * - ligne: The row index of the boat on the game board.
 * - colonne: The column index of the boat on the game board.
 * - orientation: 0 for horizontal, 1 for vertical.
 */
struct Bateau {
    int taille;       /**< The size of the boat. */
    int ligne;        /**< The row index of the boat on the game board. */
    int colonne;      /**< The column index of the boat on the game board. */
    int orientation;  /**< 0 for horizontal, 1 for vertical. */
};


#endif
