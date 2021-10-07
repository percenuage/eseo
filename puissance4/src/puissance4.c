#include "jeu.h"


/* 
===================================================================================
	Fonction : verificationPuissance4(Joueur j, char plateau[6][7], int colonne)

	Objet : Vérifie s'il y a un puissance 4 !

	Paramètres : Joueur j, plateau et colonne

	Renvoie : 1 ou 0 (booléen)

	Commentaire : Il est composé de 4 sous programme qui vérifie 
				  chacun une direction de puissance 4
===================================================================================
*/

bool verificationPuissance4(Joueur j, char plateau[6][7], int colonne)
{
	if(verifPuissance4_V(j,plateau,colonne) || verifPuissance4_H(j,plateau,colonne) || verifPuissance4_D1(j,plateau,colonne) || verifPuissance4_D2(j,plateau,colonne))
	{
		puts("\nPUISSANCE 4 !");
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}


/* 
===================================================================================
	Fonction : verificationPuissance4_V(Joueur j, char plateau[6][7], int colonne)

	Objet : Vérifie s'il y a un puissance 4 verticalement !

	Paramètres : Joueur j, plateau et colonne

	Renvoie : 1 ou 0 (booléen)

	Commentaire : -
===================================================================================
*/

bool verifPuissance4_V(Joueur j, char plateau[6][7], int colonne)
{
	int i;
	int n=0;

	for(i=5;i>=2;i--)
	{
		if(plateau[i][colonne]==j.caractereJoueur)
		{
			n++;	//compte le nombre de pion identique
		}
	}
	if(n==4)	//Puisance 4 !!!
	{
		return TRUE;	
	}
	else
	{
		return FALSE;
	}
}


/* 
===================================================================================
	Fonction : verificationPuissance4_H(Joueur j, char plateau[6][7], int colonne)

	Objet : Vérifie s'il y a un puissance 4 horizontalement !

	Paramètres : Joueur j, plateau et colonne

	Renvoie : 1 ou 0 (booléen)

	Commentaire : Difficile à concevoir !
===================================================================================
*/

bool verifPuissance4_H(Joueur j, char plateau[6][7], int colonne)
{
	int i;
	int n=0;
	bool pionJoueur=FALSE;

	for(i=0;i<7;i++)
	{
		if(plateau[5][i]==j.caractereJoueur)
		{
			n++;
			if(colonne==i)
			{
				pionJoueur=TRUE;
			}
		}
		else if(n<4 || pionJoueur==FALSE)
		{
			n=0;
			pionJoueur=FALSE;
		}
	}
	if(n>=4 && pionJoueur==TRUE)
	{
		return TRUE;	
	}
	else
	{
		return FALSE;
	}
}


/* 
===================================================================================
	Fonction : verificationPuissance4_D1(Joueur j, char plateau[6][7], int colonne)

	Objet : Vérifie s'il y a un puissance 4 diagonalement droite !

	Paramètres : Joueur j, plateau et colonne

	Renvoie : 1 ou 0 (booléen)

	Commentaire : -
===================================================================================
*/

bool verifPuissance4_D1(Joueur j, char plateau[6][7], int colonne)
{
	int i;
	int n=0;

	if(colonne>=0 && colonne<=3)
	{
		for(i=0;i<4;i++)
		{
			if(plateau[5-i][colonne+i]==j.caractereJoueur)
			{
				n++;
			}
		}
	}
	if(n==4)
	{
		return TRUE;
	}
	else
	{
		return FALSE; 
	}
}


/* 
===================================================================================
	Fonction : verificationPuissance4_D1(Joueur j, char plateau[6][7], int colonne)

	Objet : Vérifie s'il y a un puissance 4 diagonalement gauche !

	Paramètres : Joueur j, plateau et colonne

	Renvoie : 1 ou 0 (booléen)

	Commentaire : -
===================================================================================
*/

bool verifPuissance4_D2(Joueur j, char plateau[6][7], int colonne)
{
	int i;
	int n=0;

	if(colonne>=3 && colonne<=6)
	{
		for(i=0;i<4;i++)
		{
			if(plateau[5-i][colonne-i]==j.caractereJoueur)
			{
				n++;
			}
		}
	}
	if(n==4)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

