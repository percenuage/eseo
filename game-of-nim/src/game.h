#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "colour.h"
#define X 5 /*Distance de séparation entre les allumettes suivant l'axe des abscisses (par defaut X=5)*/
#define Y 5 /*Position des allumettes suivant l'axe des ordonnées (par defaut Y=5)*/
#define VALMAX 21/*nombres d'allumettes par defaut dans le jeu*/
#define EASY 1
#define MEDIUM 2
#define HARD 3
#define ULTIMATE 4
#define case printf(" ")/*macro simple et rapide pour les fonctions graphiques*/

//Ne pas oublier, changer la taille de votre fenêtre (110,40).


///basic game
int change(int tpm);
void turn(int tpm, char win[], char j1[], char j2[]);
int warning(int allumetteRemaining);
void winner(char win[], int n);
int game(int allumetteRestante, int tpm, char win[], char j1[], char j2[]);
void play(char win[], char j1[], char j2[], int *valMatches);

///menu
int menulevel();
void nameplayer(char j1[], char j2[]);
void rules();
void numbersOfMatches(char j1[], char j2[], int *valMatches);
void bonus(int n);
void option(char j1[], char j2[], int *valMatches);
void menu(char j1[], char j2[], int *valMatches);

///competion
void competitionrules();
int round();
void menuscore(char j1[], char j2[], int *scoreA, int *scoreB);
void competitiongame(char j1[], char j2[], char win[], int *valMatches, int *scorej1, int *scorej2);
void competitionmenu(char j1[], char j2[], char win[], int *valMatches, int *scorej1, int *scorej2);

///graphic
void match(int x, int y, int size);
void matches_21(int x, int y, int m, int M, int size);
void graphic_game(int allumetteRestante, int allumetteJoue, int size);
void titlecadre(int x, int y, int L, int l);
void spacecraft(int x, int y);
void move(int x, int y);
void letterE(int x, int y, int n, char COLOR1[], char COLOR2[]);
void letterS(int x, int y, int n, char COLOR1[], char COLOR2[]);
void letterO(int x, int y, int n, char COLOR1[], char COLOR2[]);
void WaveRed(int x, int y, int n, char COLOR1[], char COLOR2[]);
void ESEO(int x, int y, int n, char COLOR1[], char COLOR2[]);

///IA
void password(int LEVEL,char j1[], char win[]);
int random(int LEVEL, int allumetteRestante);
int game0(int allumetteRestante, char j1[]);
int gameIA(int allumetteRestante, char ia[], int LEVEL);
void playIA(char j1[], char ia[], char win[], int *valMatches);

/*site du zero*/
void purger();
void clean (char *chaine);


//36 functions
//1205 lines

#endif // GAME_H_INCLUDED
