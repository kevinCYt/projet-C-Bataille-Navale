/**
 * @file main2.c
 * @brief Main source file for MyProject.
 *
 * This file contains the main function and orchestrates the flow of the program.
 */


#include "jeu.h"
#include "bateau.h"
#include "constante.h"
#include "case.h"
#include "plateau.h"
#include "jeu.c"
#include <stdio.h>
#include <stdlib.h>
#include"affichage.c"
#include "jeuJoueur.c"
#include "jeuOrdi.c"
#include "vie.c"
#include "plateau.h"
#include "constante.h" 
#include <time.h>


/**
 * @brief Main function to sequence the game and display the winner.
 *
 * This function serves as the main entry point to sequence the game's flow and determine the winner.
 * At the end of the game, all dynamically allocated data is explicitly freed by the program.
 * To check for memory leaks, compile with the following flag: `gcc ... -fsanitize=address`.
 *
 * @return 0 on successful execution.
 */
 
int main(){
	srand(time(NULL));
	struct Jeu jeu;
	printf(" WATER = %d , WATER_SHOT= %d , BOAT = %d , WRECK = %d \n", WATER, WATER_SHOT, BOAT, WRECK);
	initialiserJeu(&jeu.joueur);
	initialiserJeu(&jeu.ordi);
	initialiserJeu(&jeu.bateauJoueur);
	initialiserJeu(&jeu.bateauOrdi);
	
	
	struct Bateau* bateaux = placerBateau(&jeu);
	struct Bateau* batOrdi = placerBatOrdi(&jeu);
	
	
	
	afficherPlateau(&jeu.joueur);
	printf("\n");
	afficherPlateau(&jeu.bateauJoueur);
	int FIN=0;
	while(FIN == 0){
		// Display initial game boards
		tourDeJeuJoueur(&jeu);
		
		
		// Check if computer's boats are still alive
		int batOrdiEnVie = 0;
		
		for (int i = 0; i < N_BATEAU; i++) {
		    if (EnVie(&batOrdi[i], &jeu.bateauOrdi)){
		    	batOrdiEnVie = 1; //at least 1 boat is alive
		    	break;		//no need to continue the loop since there's one alive
		    }
		}
		if (batOrdiEnVie) {
		    printf("there's still boat alive !\n");
		} 
		else {
		    printf("Tvery boat is WRECK , you WIN!\n");
		    FIN=1;
		}
		    
		// computer's turn
		tourDeJeuOrdinateur(&jeu);
		
		// Check if player's boats are still alive
		int bateauxEnVie;
		
		

		for (int i = 0; i < N_BATEAU; i++) {
		    if (EnVie(&bateaux[i], &jeu.bateauJoueur)) {
		        bateauxEnVie = 1; //at least 1 boat is alive
			break;		//no need to continue the loop since there's one alive
		    }
		}

		if (bateauxEnVie) {
		    printf("there's still boat alive  !\n");
		} 
		else {
		    printf("every boat is WRECK , you lose!\n");
		    FIN=1;
		}
		
		// Display updated game boards
		printf("enemy board : \n");
		afficherPlateau(&jeu.joueur);
		printf("\n");
		printf("your boat : \n");
		afficherPlateau(&jeu.bateauJoueur);
	
	
	}
	
	// Free allocated memory
	libererJeu(&jeu.joueur);
	libererJeu(&jeu.ordi);
	libererJeu(&jeu.bateauJoueur);
	libererJeu(&jeu.bateauOrdi); 
	return 0;
}


