// structure "JEU"
	    // qui contient 2 plateaux alloués dynamiquement
	    // et qui contient 2 tableaux de bateaux (1 pour chaque joueur)
	    
#ifndef JEU_H
#define JEU_H
#include "plateau.h"
;

/**
 * @file jeu.h
 * @brief Header file containing the struct for representing the game
 */

/**
 * @struct Jeu
 * @brief Represents a game state.
 *
 * The game state includes the game boards for the player and the computer, as well
 * as the status of the player's and computer's boats.
 */
struct Jeu {
    struct Plateau joueur;      /**< Game board for the player. */
    struct Plateau ordi;        /**< Game board for the computer. */
    struct Plateau bateauJoueur;/**< Status of the player's boats. */
    struct Plateau bateauOrdi;  /**< Status of the computer's boats. */
};


/*
struct Jeu {
	struct Plateau joueur;
	struct Plateau ordi;
	struct Plateau bateauJoueur;
	struct Plateau bateauOrdi;
};*/
#endif
