#include "jeu.h"


/*
============================================================
				PUISSANCE 4 Nouvelle Version
============================================================
*/



int main()
{
	Joueur ja={21,'X',"Joueur A"};	//On définit le joueur A (21;X)
	Joueur jb={21,'O',"Joueur B"};	//On définit le joueur B (21;O)
	char plateau[6][7]={""};		//On définit le plateau de jeu (6 lignes par 7 colonnes)

	fonctionSwitch(&ja, &jb, plateau);	//Envoie de l'adresse des variables ja et jb (utilisation  de pionteur)

	puts("\n\n");
	return 0;
}


//BUGs : Attention ligne remplie d'un meme pion !
