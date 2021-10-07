#include "jeu.h"


/* 
===================================================================================
	Fonction : affichePlateau(char plateau[6][7])

	Objet : Affiche le plateau de jeu

	Paramètres : Plateau

	Renvoie : Rien

	Commentaire : -
===================================================================================
*/

void affichePlateau(char plateau[6][7])
{
	int i,j;
	//séparations du début
	for(j=0;j<7;j++)
	{
		printf("+---");
	}
	printf("+\n");
	for(i=0;i<6;i++)
	{
		//séparations verticaux + caractèeres
		for(j=0;j<7;j++)
		{
			printf("| %c ",plateau[i][j]);
		}
		printf("|");
		//numéro de lignes
		printf(" %d",5-i);
		printf("\n");
		//séparations horizontaux
		for(j=0;j<7;j++)
		{
			printf("+---");
		}
		printf("+\n");
	}
	//numéro de colonnes
	for(j=0;j<7;j++)
	{
		printf("  %d ",j);
	}
}



/* 
===================================================================================
	Fonction : afficheResultat(Joueur ja, Joueur jb)

	Objet : Affiche le resultat de la partie

	Paramètres : Joueur ja et jb

	Renvoie : Rien

	Commentaire : -
===================================================================================
*/

void afficheResultat(Joueur ja, Joueur jb)
{
	ClrScr;
	moveto(25,2);
	printf(BOLD_UNDERLINED"##JEU##\n\n");
	printf(NORMAL"");
	puts("\n\t\t   < RÉCAPITULATIF >\n\n");

	printf("\t\tGAGNANT\t\tPERDANT");
	printf("\n");
	printf("\t\t=======\t\t=======");
	printf("\n\n");
	printf("Nom :\t\t%s  \t%s",ja.nom, jb.nom);
	printf("\n\n");
	printf("Pion :\t\t   %c  \t\t   %c",ja.caractereJoueur, jb.caractereJoueur);
	printf("\n\n");
	printf("Pion restant :\t   %d  \t\t   %d",ja.pionRestant, jb.pionRestant);	

	puts("\n\n\nContinuer ? Pressez \"Entrée\" ...");
}


/* 
===================================================================================
	Fonction : purger()

	Objet : Permet de corriger les erreurs de l'utilisateur lié à l'entrée
			de caractères non désirés

	Paramètres : Aucun

	Renvoie : Rien

	Commentaire : Fonction pris dans le Site du Zéro !
===================================================================================
*/

void purger()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}
