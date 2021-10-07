#include "jeu.h"

void calculLevel(Player *joueur)
{
    if(joueur->ratio==100)
        joueur->level=4;
    else if(joueur->ratio<100 && joueur->ratio>=75)
        joueur->level=3;
    else if(joueur->ratio<75 && joueur->ratio>=50)
        joueur->level=2;
    else if(joueur->ratio<50 && joueur->ratio>=25)
        joueur->level=1;
    else if(joueur->ratio<25 && joueur->ratio>=0)
        joueur->level=0;
}
void calculRatio(Player *joueur)
{
    if(joueur->victory==0 && joueur->defeat==0)
        joueur->ratio=0;//Impossible de divisé par 0
    else
        joueur->ratio=joueur->victory/(float)(joueur->defeat + joueur->victory)*100;
}
void resultScore(Player *joueur)
{
    calculRatio(joueur);//Calcule le ratio
    calculLevel(joueur);//Donne le niveau du joueur en fonction du ratio

    DEFAUT;
    gotoXY(30,5);
    printf("RECAPITULATIF DES SCORES DU JOUEUR");
    Sleep(1000);
    gotoXY(40,10);
    printf("VICTOIRE : %d",joueur->victory);
    gotoXY(40,12);
    printf("DEFAITE : %d",joueur->defeat);
    gotoXY(40,14);
    printf("RATIO : %d",joueur->ratio);
    puts(" %");
    gotoXY(40,16);
    printf("NIVEAU : *%d*",joueur->level);
    Sleep(1000);
}
void saveScore(Player *joueur)
{
    FILE *fichier=NULL;
    fichier = fopen("scores.txt", "a");//Mode d'ajout
    if (fichier != NULL)
    {
        fprintf(fichier,"%s  %d  %d  %d  %d\n",joueur->name,joueur->victory,joueur->defeat,joueur->ratio,joueur->level);
        fclose(fichier); //On ferme le fichier
    }
    else
        printf("IMPOSSIBLE!");//Message d'erreur
}
void getScore(char namePlayers[10][20], int scorePlayer[10][4])
{
    FILE*fichier=NULL;
    int i,j;

    fichier=fopen("scores.txt","r");//Mode de lecture
    if (fichier != NULL)
    {
        for(i=0;i<10;i++)
        {
            fscanf(fichier,"%s",namePlayers[i]);
            for(j=0;j<4;j++)
                fscanf(fichier,"%d",&scorePlayer[i][j]);
        }
    }
}
void viewScore(char namePlayers[10][20], int scorePlayer[10][4])
{
    int i,j;
    gotoXY(2,10);
    puts("Name\t\t    Victory   Defeat   Ratio(%)   *Level*");
    for(i=0;i<10;i++)
    {
        gotoXY(2,14+i*2);
        printf("%s",namePlayers[i]);
        for(j=0;j<4;j++)
        {
            gotoXY(22+j*10,14+i*2);
            printf("%d",scorePlayer[i][j]);
        }
        puts("\n");
    }
}

void permuteElement(int taille,int n, int p, char namePlayers[taille][20], int scorePlayer[taille][4])
{
    int k,t;
    char temp[20]="";
    for(k=0;k<4;k++)
    {
        t=scorePlayer[n][k];
        scorePlayer[n][k]=scorePlayer[p][k];
        scorePlayer[p][k]=t;
    }
    strcpy(temp,namePlayers[n]);
    strcpy(namePlayers[n],namePlayers[p]);
    strcpy(namePlayers[p],temp);
}
void triScoreAndName(int taille, int typeScore, char namePlayers[taille][20],int scorePlayer[taille][4])
{
    int i;
    int passe=TRUE;

    /*TRI PAR SCORES*/
    if(typeScore<4)
        while (passe==TRUE)//Remake de la fonction Tri_Bulles
        {
            passe=FALSE;
            for (i=0;i<taille-1;i++)
            {
                if(scorePlayer[i][typeScore]<scorePlayer[i+1][typeScore])
                {
                /*Permute toute les lignes ensembles (scores et noms)*/
                    permuteElement(10,i,i+1,namePlayers,scorePlayer);
                    passe=TRUE;
                }
                taille--;
            }
        }

    /*TRI PAR NOMS*/

    else
        while (passe==TRUE)//Remake de la fonction Tri_Bulles
        {
            passe=FALSE;
            for (i=0;i<taille-1;i++)
            {
                if(strcmp(namePlayers[i],namePlayers[i+1])>0)
                {
                /*Permute toute les lignes ensembles (scores et noms)*/
                    permuteElement(10,i,i+1,namePlayers,scorePlayer);
                    passe=TRUE;
                }
                taille--;
            }
        }
}



