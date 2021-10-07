#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#define CASE printf("   ")//Case de couleur
#define DEFAUT setColour(BLANC,NOIR)//Couleur par defaut
#define gapX 6//Distance entre les carres de couleurs suivant X
#define gapY 4//Distance entre les carres de couleurs suivant Y

/*ENVIRONNEMENT GRAPHIQUE DU JEU*/
int returnColor(int number);//Retourne une lettre pour un chiffre données
void carre(int color, int X, int Y);//Carré de couleur
void showCombination(int const n, int const taille, int combinations[n][taille], int X, int Y);//Affiche les couleurs de la combinaison
void showAllColor(int colorMax, int X, int Y);//Affiche les couleurs max qui peuvent être jouées
void showCorrection(int const n, int const taille, char tab[n][taille], int X, int Y);//Affiche la correction des "C" et "P"

/*PACKAGE D'UTILITAIRE POUR LES ANIMATIONS*/
void animation(unsigned long int n);//Fonction pause comme Sleep et usleep
void ligneHorizontale(int xdebut, int xfin, int y, int forme);
void ligneVerticale(int ydebut, int yfin, int x, int forme);
void bloc(int xdebut, int xfin, int ydebut, int yfin);
void cadre (int xdebut,int xfin,int ydebut,int yfin);

void Defeat(int positionx, int positiony);//Tête de mort_defeat
void Victory();//Well Done : Victoire
void afficherTitreJeu();//Animation d'affichage de "Mastermind" au lancement du jeu
void GeekHead(int positionx, int positiony);//Affichage d'une tête de geek
void RedDogHead(int positionx, int positiony);//Affichage d'une tête de chien
void RabbitHead(int positionx, int positiony);//Affichage d'une tête de lapin
void MastersHead(int positionx, int positiony);//Affichage d'une tête de mort

void letterE(int COLOR1, int COLOR2, int n, int x, int y);
void letterS(int COLOR1, int COLOR2, int n, int x, int y);
void letterO(int COLOR1, int COLOR2, int n, int x, int y);
void WaveRed(int COLOR1, int COLOR2, int n, int x, int y);
void ESEO(int COLOR1, int COLOR2, int n, int x, int y);
void titlecadre(int x, int y, int L, int l);
void animationBonusEnd();
#endif // GRAPHIC_H_INCLUDED
