#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define TRUE 1
#define FALSE 0

void menuMastermind(Player *joueur, Parameter *parametre);//Regroupe tous les menus et sous-menus
int MenuInitialization();//Animation du menu du Jeu Mastermind
void menuRules();//Menu des regles
void menuOptions(Parameter *parametre);//Menu des options
void menuScore(char namePlayers[10][20], int scorePlayer[10][4]);//Menu des scores

#endif // MENU_H_INCLUDED
