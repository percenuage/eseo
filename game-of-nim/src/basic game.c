#include "game.h"

int change(int tpm)//
{
    if(tpm==0)
    {
        tpm=1;
        return tpm;
    }
    if(tpm==1)
    {
        tpm=0;
        return tpm;
    }
}
void turn(int tpm, char win[], char j1[], char j2[])//
{
    if(tpm==0)
    {
        setColour(CYAN,NOIR);
        printf("\n\n\n\n\t\t%s  ",j1);
        setColour(BLANC,NOIR);
        strcpy(win,j1);
    }
    if(tpm==1)
    {
        setColour(CYAN,NOIR);
        printf("\n\n\n\n\t\t%s  ",j2);
        setColour(BLANC,NOIR);
        strcpy(win,j2);
    }
}
int warning(int matchesRemaining)//
{
    int matchesPlayed;
    setColour(VERT,NOIR);
    scanf("%d",&matchesPlayed);
    purger();
    setColour(BLANC,NOIR);
    while(matchesRemaining<=matchesPlayed || matchesPlayed>3 || matchesPlayed<=0)
    {
        printf("\n\tError Try Again : ");
        setColour(VERT,NOIR);
        scanf("%d",&matchesPlayed);
        purger();
        setColour(BLANC,NOIR);
    }
    return matchesPlayed;
}
void winner(char win[], int n)//
{
    if(n==1)
    {
        if(strcmp(win,"BlackPearl")==0)
        {
            printf("\n\n\n\t\t\tOh I'm so sorry ! You lose ! ");
            printf("BlackPearl is very strong, isn't it !\n\n");

        }
        else
        {
            printf("\n\n\t\t\t\t    Not bad %s ! You win this party !\n\n",win);
        }
    }
}
int game(int allumetteRestante, int tpm, char win[], char j1[], char j2[])//
{
    int allumetteJoue;
    int i;
    turn(tpm,win,j1,j2);
    printf("%c  Remove matches ? : ",175);
    allumetteJoue=warning(allumetteRestante);
    allumetteRestante=allumetteRestante-allumetteJoue;
    clrScr();
    if(allumetteRestante<21)
        graphic_game(allumetteRestante,allumetteJoue,10);
    matches_21(X,Y,1,allumetteRestante,10);
    setColour(ROUGE_VIF,NOIR);
    printf("\n\n\n\n\n\t\t\t\t\t#");
    setColour(BLANC,NOIR);
    printf(" There are");
    setColour(MAGENTA_VIF,NOIR);
    printf(" %d ",allumetteRestante);
    setColour(BLANC,NOIR);
    printf("matches on table ");
    setColour(ROUGE_VIF,NOIR);
    printf("#\n");
    setColour(BLANC,NOIR);
    return allumetteRestante;
}
void play(char win[], char j1[], char j2[],int *valMatches)//
{
    int tpm;
    int allumette=*valMatches;
    tpm=rand()%2; /*Randomly chooses the player who starts the game*/
    matches_21(X,Y,1,allumette,10);
    printf("\n\n\n\n\t\t\t\t%s vs %s ... Ready ... Fight !!!  (Press Enter)",j1,j2);
    getch();
    clrScr();
    matches_21(X,Y,1,allumette,10);
    setColour(ROUGE_VIF,NOIR);
    printf("\n\n\n\n\n\t\t\t\t\t#");
    setColour(BLANC,NOIR);
    printf(" There are");
    setColour(MAGENTA_VIF,NOIR);
    printf(" %d ",allumette);
    setColour(BLANC,NOIR);
    printf("matches on table ");
    setColour(ROUGE_VIF,NOIR);
    printf("#\n");
    setColour(BLANC,NOIR);
    do
    {
        allumette=game(allumette,tpm,win,j1,j2);
        tpm=change(tpm);
    }while(allumette>1);
    printf("\n\n\n\t\t\t\t\t    The Game is Finished !!!\n");
    winner(win,allumette);
}


