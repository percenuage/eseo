#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1		//Je définis TRUE à 1
#define FALSE 0		//Je définis FALSE à 0
#define bool int	//En C, bool n'exixte pas (0 ou 1) donc je le définis (On comprend mieux une fonction avec son type)

/*
#define LIGNE 6
#define COLONNE 7
#define PION_VICTOIRE 10
#define PION_MAX LIGNE*COLONNE
*/

#define ClrScr system("clear")						//Effacer l'écran
#define moveto(x,y) printf("\033[%d;%dH",y,x)		//Placer le curseur dans le terminal
#define NORMAL "\E[0m"								//Sans attribut
#define BOLD_UNDERLINED "\E[1;4m"					//Gras et souligné
#define BOLD "\E[1m"								//Gras



//===========================STUCTURES=============================//

typedef struct
{
	int pionRestant;		//Nombre de pion restant dans la main du joueur
	char caractereJoueur;	//Le pion du joueur (X ou O)
	char nom[50];			//Le nom du joueur
}Joueur;


//============================PROTOTYPES============================//

//Menu

void menu();
void fonctionSwitch(Joueur *ja, Joueur *jb, char plateau[6][7]);
void initialisationPartie(Joueur *ja, Joueur *jb, char plateau[6][7]);
void nomDesJoueur(Joueur *ja, Joueur *jb);
void instructions();

//Affichage

void affichePlateau(char plateau[6][7]);
void afficheResultat(Joueur ja, Joueur jb);
void purger();

//Jeu

void jeu(Joueur *ja, Joueur *jb, char plateau[6][7]);
void phaseRemplissage(Joueur *ja, Joueur *jb, char plateau[6][7]);
void phaseEjection(Joueur *ja, Joueur *jb, char plateau[6][7]);
void copieJoueur(Joueur *j, Joueur copier);
void deplPion(char plateau[6][7], int colonne);
int choixColonne();
int changementJoueur(Joueur *j, Joueur *ja, Joueur *jb, int tour);
int retourneNumeroLigne(char plateau[6][7], int colonne);
int reinsertionPion(char plateau[6][7], int colonneEjecte);
bool verifLignePleine(char plateau[6][7], int ligne);
bool pionDuJoueur(Joueur j, char plateau[6][7], int colonne);

//Puissance4

bool verificationPuissance4(Joueur j, char plateau[6][7], int colonne);
bool verifPuissance4_V(Joueur j, char plateau[6][7], int colonne);
bool verifPuissance4_H(Joueur j, char plateau[6][7], int colonne);
bool verifPuissance4_D1(Joueur j, char plateau[6][7], int colonne);
bool verifPuissance4_D2(Joueur j, char plateau[6][7], int colonne);

//Sauvegarde

void sauvegardePlateau(char plateau[6][7]);
void extractionPlateau(char plateau[6][7]);
void sauvegardeJoueur(Joueur ja, Joueur jb);
void extractionJoueur(Joueur *ja, Joueur *jb);


#endif // STRUCTURE_H_INCLUDED
