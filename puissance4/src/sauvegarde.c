#include "jeu.h"


/* 
===================================================================================
	Fonction : sauvegardePlateau(char plateau[6][7])

	Objet : Sauvegarde dans un fichier auto_save le plateau de jeu

	Paramètres : Plateau

	Renvoie : Rien

	Commentaire : -
===================================================================================
*/

void sauvegardePlateau(char plateau[6][7])
{
	FILE* fichier = NULL;
 	int i,j;
    fichier = fopen("autosave_plateau.txt", "w");
 
    if (fichier != NULL)
    {
       	// Écriture des caractères 1 par 1
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				fputc(plateau[i][j],fichier);
			}
			fputc('\n',fichier);	//Retour à la ligne pour faire le plateau
		}
        fclose(fichier);
    }
}


/* 
===================================================================================
	Fonction : extractionPlateau(char plateau[6][7])

	Objet : Extrait le plateau depuis un fichier auto_save vers une matrice

	Paramètres : Plateau

	Renvoie : Rien

	Commentaire : J'ai inclus une variable tmp pour "supprimer" 
				  le retour à la ligne
===================================================================================
*/

void extractionPlateau(char plateau[6][7])
{
	FILE* fichier = NULL;
 	int i,j;
	char tmp;
    fichier = fopen("autosave_plateau.txt", "r");
 	
    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
		for(i=0;i<6;i++)
		{
			for(j=0;j<7;j++)
			{
				plateau[i][j]=fgetc(fichier);
			}
			tmp=fgetc(fichier);
		}
        fclose(fichier);
    }
}


/* 
===================================================================================
	Fonction : sauvegardeJoueur(Joueur ja, Joueur jb)

	Objet : Sauvegarde dans un fichier auto_save les paramètre des joueurs

	Paramètres : Joueur ja et jb

	Renvoie : Rien

	Commentaire : -
===================================================================================
*/

void sauvegardeJoueur(Joueur ja, Joueur jb)
{
	FILE* fichier = NULL;
    fichier = fopen("autosave_joueur.txt", "w");
 
    if (fichier != NULL)
    {
		fprintf(fichier,"%s %d %c",ja.nom, ja.pionRestant, ja.caractereJoueur);
		fprintf(fichier,"\n%s %d %c",jb.nom, jb.pionRestant, jb.caractereJoueur);

		fclose(fichier);
	}
}


/* 
===================================================================================
	Fonction : extractionJoueur(Joueur *ja, Joueur *jb)

	Objet : Extrait les paramètres des joueurs depuis un fichier auto_save 
			vers les joueurs ja et jb

	Paramètres : Joueur ja et jb

	Renvoie : Rien

	Commentaire : -
===================================================================================
*/

void extractionJoueur(Joueur *ja, Joueur *jb)
{
	FILE* fichier = NULL;
    fichier = fopen("autosave_joueur.txt", "r");
 	
    if (fichier != NULL)
    {
       	fscanf(fichier,"%s %d %c",ja->nom, &ja->pionRestant, &ja->caractereJoueur);
		fscanf(fichier,"\n%s %d %c",jb->nom, &jb->pionRestant, &jb->caractereJoueur);
	
		fclose(fichier);
    }
}





