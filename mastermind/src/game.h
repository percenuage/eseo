#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define COLORMAX 8 //Nombre de couleur maximum
#define PLAYMAX 10  //Nombre d'essaie maximum
#define TAILLE 4 //Nombre de couleur pour 1 combinaison

void gameMastermind(/*Player *joueur, Parameter *parametre*/);//Jouer au mastermind
void gameBoard(int const n, int const taille, int combinations[n][taille], char screenReply[n][taille], int X, int Y);//Affichage du jeu
void enterColor(int const n, int const taille, int colorMax, int color[n][taille]);//Entre les numéros des couleurs (combinaisons)
int compareTable(int const n, int const taille, int combinations[n][taille]);//Retourne TRUE (1) pour identique et FALSE (0) pour différent
void correction(int const n, int const taille, int combinations[n][taille], char screenReply[n][taille]);//Corrige les erreurs "C" et "P"

#endif // GAME_H_INCLUDED
