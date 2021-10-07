#include "game.h"


void menuscore(char j1[], char j2[], int *scoreA, int *scoreB)//
{
    setColour(VERT_VIF,NOIR);
    titlecadre(48,2,8,3);
    gotoXY(50,4);
    setColour(BLANC_VIF,NOIR);
    printf("SCORES\n\n\n\n\n");
    setColour(BLANC_VIF,NOIR);
    printf("\n\n\n\t\tPlayer ");
    setColour(CYAN,NOIR);
    printf("%s",j1);
    setColour(BLANC_VIF,NOIR);
    printf(" : ");
    setColour(ROUGE_VIF,NOIR);
    printf("%d",*scoreA);
    setColour(BLANC_VIF,NOIR);
    printf(" victory");
    printf("\n\n\n\t\tPlayer ");
    setColour(CYAN,NOIR);
    printf("%s",j2);
    setColour(BLANC_VIF,NOIR);
    printf(" : ");
    setColour(ROUGE_VIF,NOIR);
    printf("%d",*scoreB);
    setColour(BLANC_VIF,NOIR);
    printf(" victory\n\n\n");
}
void competitionrules()//
{
    setColour(VERT,NOIR);
    titlecadre(45,2,19,3);
    gotoXY(47,4);
    setColour(BLANC_VIF,NOIR);
    printf("COMPETITION RULES\n\n\n\n\n");
    setColour(BLANC,NOIR);
    printf("\n\n\n\n\n\n\t=> Rules of basic game\n\n");
    printf("\n\t=> To win the game you will need to be succesful in more than half of the games played");
    match(95,8,27);
    setColour(BLANC_VIF,NOIR);
    printf("\t Menu Press Enter ");
    getch();
}
int round()//
{
    int choice;
    setColour(JAUNE,NOIR);
    titlecadre(48,2,7,3);
    gotoXY(50,4);
    setColour(BLANC_VIF,NOIR);
    printf("ROUND\n\n\n\n\n");
    setColour(BLANC_VIF,NOIR);
    do
    {
        printf("\n\n\n\n\tChoose the number of winning race (3/5/7/+) : ");
        scanf("%d",&choice);
        getchar();
    }while(choice%2!=1 || choice==1);
    return choice;
}
void competitiongame(char j1[], char j2[], char win[], int *valMatches, int *scorej1, int *scorej2)//
{
    int point;
    int compteurj1=0;
    int compteurj2=0;
    point=round();
    clrScr();
    while(compteurj1<((point/2)+1) && compteurj2<((point/2)+1))
    {
        clrScr();
        play(win,j1,j2,valMatches);
        if(strcmp(win,j1)==0)
        {
            compteurj1++;
        }
        if(strcmp(win,j2)==0)
        {
            compteurj2++;
        }
        setColour(BLANC_VIF,NOIR);
        setColour(CYAN,NOIR);
        printf("\n\n\t%s",j1);
        setColour(BLANC_VIF,NOIR);
        printf(" has ");
        setColour(ROUGE,NOIR);
        printf("%d",compteurj1);
        setColour(BLANC_VIF,NOIR);
        printf(" victory on ");
        setColour(VERT,NOIR);
        printf("%d",point);
        setColour(CYAN,NOIR);
        printf("\n\n\t%s",j2);
        setColour(BLANC_VIF,NOIR);
        printf(" has ");
        setColour(ROUGE,NOIR);
        printf("%d",compteurj2);
        setColour(BLANC_VIF,NOIR);
        printf(" victory on ");
        setColour(VERT,NOIR);
        printf("%d",point);
        setColour(BLANC,NOIR);
        printf("\n\n\n Continue ? (Enter)");
        getch();
    }
    *scorej1+=compteurj1;
    *scorej2+=compteurj2;
    setColour(MAGENTA,NOIR);
    printf("\n\n\n\t\tCongratulation %s !! You win competition !!\n\n",win);
    setColour(BLANC,NOIR);
    printf("\n\n Competition Menu Press Enter ");
    getch();
}
void competitionmenu(char j1[], char j2[], char win[], int *valMatches, int *scorej1, int *scorej2)//
{
    int a;
    setColour(ROUGE,NOIR);
    titlecadre(43,2,19,3);
    gotoXY(45,4);
    setColour(BLANC_VIF,NOIR);
    printf("COMPETITION MENU\n\n\n\n\n");
    setColour(MAGENTA_VIF,NOIR);
    printf("\n\n\n\t\t1. Competition Game");
    setColour(BLANC,NOIR);
    printf("\n\n\t\t\tPlayer 1 : ");
    setColour(CYAN,NOIR);
    printf("%s",j1);
    setColour(BLANC,NOIR);
    printf("\n\n\t\t\tPlayer 2 : ");
    setColour(CYAN,NOIR);
    printf("%s",j2);
    setColour(BLANC,NOIR);
    printf("\n\n\t\t\tMatches  : ");
    setColour(JAUNE,NOIR);
    printf("%d",*valMatches);
    setColour(MAGENTA_VIF,NOIR);
    printf("\n\n\n\t\t2. Rules\n\n\n\t\t3. Score");
    setColour(GRIS,NOIR);
    printf("\n\n\n\n\t\t4. Return to menu");
    match(90,8,27);
    setColour(BLANC_VIF,NOIR);
    printf("\tChoose an option ? : ");
    scanf("%d",&a);
    if(a==1)
    {
        clrScr();
        competitiongame(j1,j2,win,valMatches,scorej1,scorej2);
        clrScr();
        competitionmenu(j1,j2,win,valMatches,scorej1,scorej2);
    }
    if(a==2)
    {
        clrScr();
        competitionrules();
        clrScr();
        competitionmenu(j1,j2,win,valMatches,scorej1,scorej2);
    }
    if(a==3)
    {
        clrScr();
        menuscore(j1,j2,scorej1,scorej2);
        printf("\n\n\tPress Enter\n");
        getch();
        clrScr();
        competitionmenu(j1,j2,win,valMatches,scorej1,scorej2);
    }
    if(a==4)
    {
        clrScr();
        menu(j1,j2,valMatches);
    }
}

