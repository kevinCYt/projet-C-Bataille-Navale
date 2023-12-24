  // fonction qui affiche un plateau avec l'etat des bateaux (vue joueur) ou bien (booleen paramètre) affiche un plateau avec juste le résultat des tirs (vue du terrain de l'ordi)    
  
  /** 
 * @file affichage.c
 * @brief this file contain the function of display for the board
 *
 */
 
#include <stdio.h>
#include "plateau.h"
/**
 * @brief Display the game board in a grid format.
 *
 * This function prints the contents of the game board in a grid format. Each cell is represented by its value,
 * and the grid is surrounded by '+' and '-' characters to create a visual representation of the game board.
 *
 * @param plateau Pointer to the game board struct.
 */

void afficherPlateau(struct Plateau *plateau) {
    // column number
    printf("   ");
    for (int j = 0; j < plateau->taille; j++) {
        printf("%5d", j);
    }
    printf("\n");

    for (int i = 0; i < plateau->taille; i++) {
        printf("   ");
        for (int j = 0; j < plateau->taille; j++) {
            printf("+----");
        }
        printf("+\n");

        // line number
        printf("%2d ", i);
        for (int j = 0; j < plateau->taille; j++) {
            printf("| %2d ", plateau->plato[i][j]);
        }
        printf("|\n");
    }
	printf("   ");
    for (int j = 0; j < plateau->taille; j++) {
        printf("+----");
    }
    printf("+\n");
}
