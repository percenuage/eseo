#include "game.h"

void password(int LEVEL,char j1[], char win[])//
{
    if(LEVEL==ULTIMATE)
    {
        if(strcmp(win,j1)==0)
        {
            usleep(1000000);
            clrScr();
            printf("\n\n\n\t\tCONGRATULATION !!! YOU ARE IMPECCABLE PLAYER !!!\n\n\n");
            printf("\n\t\t\tPassword is : 'champion'\n\n");
            printf("\n\n You can see the bonus of the game. Go in the game menu -> Option -> Bonus -> enter the password\n");
            printf("\n\n\n\t\t\tSURPRISE SURPRISE !!!\n\n");
        }
    }
}
int random(int LEVEL, int allumetteRestante)//
{
    int OneOrTwo;
    int matchesIA;
    int tpm;
    if(allumetteRestante%4==1)
    {
        LEVEL=EASY;
    }
    if(LEVEL==EASY)
    {
        matchesIA=(rand()%3)+1;
    }
    if(LEVEL==MEDIUM)
    {
        OneOrTwo=rand()%2;
        if(OneOrTwo==0)
        {
            matchesIA=(rand()%3)+1;
        }
        if(OneOrTwo==1)
            LEVEL=ULTIMATE;
    }
    if(LEVEL==HARD)
    {
        OneOrTwo=rand()%4;
        if(OneOrTwo==0)
        {
            matchesIA=(rand()%3)+1;
        }
        else
            LEVEL=ULTIMATE;

    }
    if(LEVEL==ULTIMATE)
    {
        do
        {
            tpm=allumetteRestante;
            matchesIA=(rand()%3)+1;
            tpm=allumetteRestante-matchesIA;
        }while(tpm%4!=1);
    }
    return matchesIA;
}
int game0(int allumetteRestante, char j1[])//
{
    int i;
    int allumetteJoue;
    setColour(CYAN,NOIR);
    printf("\n\n\n\n\t\t%s  ",j1);
    setColour(BLANC,NOIR);
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
    if(allumetteRestante!=1)
    {
        setColour(BLANC,NOIR);
        printf("\n\n\t\t\t\t\t\t  ");
        for(i=0;i<=2;i++)
        {
            usleep(500000);
            printf(" .");
        }
    }
    usleep(500000);
    return allumetteRestante;
}
int gameIA(int allumetteRestante, char ia[], int LEVEL)//
{
    int allumetteJoue;
    int i;
    do
    {
        allumetteJoue=random(LEVEL,allumetteRestante);
    }while(allumetteRestante<=allumetteJoue);
    allumetteRestante=allumetteRestante-allumetteJoue;
    clrScr();
    if(allumetteRestante<21)
        graphic_game(allumetteRestante,allumetteJoue,10);
    matches_21(X,Y,1,allumetteRestante,10);
    setColour(CYAN,NOIR);
    printf("\n\n\n\t\t%s  ",ia);
    setColour(BLANC,NOIR);
    printf("%c Removed",175);
    setColour(VERT,NOIR);
    printf(" %d ",allumetteJoue);
    setColour(BLANC,NOIR);
    printf("matches");
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
void playIA(char j1[], char ia[], char win[], int *valMatches)//
{
    int tpm;
    int val;
    int allumette=*valMatches;
    int LEVEL;
    LEVEL=menulevel();
    tpm=rand()%2;
    clrScr();
    matches_21(X,Y,1,allumette,10);
    printf("\n\n\n\t\t\t\t%s vs %s ... Ready ... Fight !!!  (Press Enter)",j1,ia);
    getch();
    clrScr();
    matches_21(X,Y,1,allumette,10);
    setColour(ROUGE_VIF,NOIR);
    printf("\n\n\n\n\n\t\t\t\t\t\t#");
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
        if(tpm==0)
        {
            strcpy(win,j1);
            allumette=game0(allumette,j1);
        }
        if(tpm==1)
        {
            strcpy(win,ia);
            allumette=gameIA(allumette,ia,LEVEL);
        }

        tpm=change(tpm);
    }while(allumette>1);
    setColour(BLANC,NOIR);
    printf("\n\n\n\t\t\t\t\t    The Game is Finished !!!\n");
    winner(win,allumette);
    password(LEVEL,j1,win);
}
