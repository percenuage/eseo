#include "jeu.h"

void combinationIA(int const n, int const taille, int colorMax, int color[n][taille], int level)
{
    int i,j,temp;

/* RANDOM SANS REMISE */
    if(level==EASY || level==MEDIUM)
    {
        for(i=0;i<taille;i++)
        {
            temp=(rand()%colorMax)+1;//Donne une valeur à "temp" aléatoirement
            for(j=0;j<taille;j++)//Boucle qui compare les valeurs du tableau avec "temp"
            {
                if(color[n][j]==temp)//Comparaison : égalité
                {
                    temp=(rand()%colorMax)+1;//Redonne une valeur à "temp"
                    j=-1;//On veux recomencer la boucle de comparaison : remettre j à 0
                }
            }
            color[n][i]=temp;//Après que l'on soit assurer de l'unicité de "temp", on l'incrémente à color
        }
    }

/* RANDOM AVEC REMISE */
    else
        for(i=0;i<taille;i++)
            color[n][i]=(rand()%colorMax)+1;//1-8
}
void chooseLevel(Player *joueur)
{
    DEFAUT;
    clrScr();
    setColour(JAUNE_VIF,NOIR);
    gotoXY(38,3);
    printf("%c  %c%c %c %c %c%c %c   %c  %c",219,219,219,219,219,219,219,219,219,219);
    setColour(BLEU_VIF,NOIR);
    gotoXY(38,4);
    printf("%c  %c%c %c %c %c%c %c   %c %c%c%c",219,219,254,219,219,219,254,219,219,219,254,219);
    setColour(ROUGE_VIF,NOIR);
    gotoXY(38,5);
    printf("%c%c %c%c  %c  %c%c %c%c  %c %c %c",219,219,219,219,219,219,219,219,219,219,219,219);
    gotoXY(5,10);
    setColour(MAGENTA_VIF,NOIR);
    puts("EASY (1)");
    RabbitHead(16,5);
    gotoXY(5,20);
    setColour(BLEU_VIF,NOIR);
    puts("MEDIUM (2)");
    GeekHead(16,15);
    gotoXY(5,30);
    setColour(ROUGE_VIF,NOIR);
    puts("HARD (3)");
    RedDogHead(16,25);
    gotoXY(79,10);
    setColour(BLANC_VIF,NOIR);
    puts("APOCALYPTIC (4)");
    MastersHead(58,11);
    gotoXY(39,22);
    printf("Which level ? : ");
    scanf("%d",&joueur->level);
}
void enterName(Player *joueur)
{
    printf("Entrer votre nom : ");
    scanf("%s",joueur->name);
    fflush(stdin);
}


