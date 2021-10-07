#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef enum
{
    EASY=1, MEDIUM=2, HARD=3, APOCALYPTIC=4
}Level;

typedef struct
{
    int victory;
    int defeat;
    int ratio;
    int level;
    char name[100];
}Player;

typedef struct
{
    int color_Max;
    int play_Max;
    int taille_Max;
}Parameter;

void combinationIA(int const n, int const taille, int colorMax, int color[n][taille], int level);//Entre une combinaison aléatoirement suivant le niveau de l'IA
void chooseLevel(Player *joueur);//Choix du niveau de l'IA
void enterName(Player *joueur);//Entre le nom du joueur

#endif // PLAYER_H_INCLUDED
