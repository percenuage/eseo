#include "game.h"

int menulevel()//
{
    int level;
    setColour(MAGENTA_VIF,NOIR);
    titlecadre(50,2,7,3);
    gotoXY(52,4);
    setColour(BLANC_VIF,NOIR);
    printf("LEVEL\n\n\n\n\n");
    setColour(BLEU_VIF,NOIR);
    printf("\n\n\n\t\t1. Easy");
    setColour(CYAN_VIF,NOIR);
    printf("\n\n\n\t\t2. Medium");
    setColour(VERT_VIF,NOIR);
    printf("\n\n\n\t\t3. Hard");
    setColour(ROUGE_VIF,NOIR);
    printf("\n\n\n\t\t4. Ultimate");
    match(90,8,27);
    do
    {
        printf("\tChoose IA level : ");
        scanf("%d",&level);
        getchar();
    }while(level>4 || level<1);
    return level;
}
void nameplayer(char j1[], char j2[])//
{
    int choice;
    setColour(MAGENTA,NOIR);
    titlecadre(50,2,14,3);
    gotoXY(52,4);
    setColour(BLANC_VIF,NOIR);
    printf("NAME PLAYERS\n\n\n\n\n\n");
    purger();
    setColour(VERT,NOIR);
    printf("\n\n\n\t\tEnter name player 1 :\t");
    setColour(CYAN,NOIR);
    fgets(j1,50,stdin);
    clean(j1);
    setColour(VERT,NOIR);
    printf("\n\n\n\t\tEnter name player 2 :\t");
    setColour(CYAN,NOIR);
    fgets(j2,50,stdin);
    clean(j2);
    setColour(CYAN,NOIR);
    printf("\n\n\n\n\n\n\t\t\t\t%s",j1);
    setColour(ROUGE,NOIR);
    printf(" VS ");
    setColour(CYAN,NOIR);
    printf("%s\n\n\n",j2);
    setColour(BLANC_VIF,NOIR);
}
void rules()//
{
    setColour(VERT,NOIR);
    titlecadre(48,2,12,3);
    gotoXY(50,4);
    setColour(BLANC_VIF,NOIR);
    printf("GAME RULES\n\n\n\n\n");
    setColour(BLANC,NOIR);
    printf("\n\n\n\t=> The game is played with two players\n\n\n\t=> Between each player are placed 21 matches\n\n\n\t");
    printf("=> Players take it in turns to remove 1, 2 or 3 matches\n\n\n\t=> The player who removes the last match is the loser\n");
    match(90,8,27);
    setColour(BLANC_VIF,NOIR);
    printf("\tMenu Press Enter");
    getch();
}
void numbersOfMatches(char j1[], char j2[], int *valMatches)//
{
    int choice;
    int n=*valMatches;
    do
    {
        clrScr();
        setColour(CYAN,NOIR);
        titlecadre(48,2,9,3);
        gotoXY(50,4);
        setColour(BLANC_VIF,NOIR);
        printf("MATCHES\n\n\n\n\n");
        matches_21(3,10,1,n,5);
        printf("\n\n\n\t\t*There are %d matches on table*\n",n);
        printf("\n\n\n\tDo you want to change this number ?\n\n");
        printf("\n\n\t(0) No\n\n\t(1) Yes\n\n\t");
        scanf("%d",&choice);
        if(choice==1)
        {
            do
            {
                printf("\n\n\tHow many do want to put matches on table ? : ");
                setColour(JAUNE,NOIR);
                scanf("%d",&n);
                setColour(BLANC_VIF,NOIR);
                if(n<=5)
                    printf("\n\n\tNo Try again numbers of matches have to more higher than 5\n");
            }while(n<=5);
        }
    }while(choice==1);
    *valMatches=n;
}
void bonus(int n)//
{
    do
    {
        move(2,n);
        n=n+5;
        if(n==5)
        {
            letterE(20,10,5,NOIR,BLEU_VIF);
            usleep(500000);
        }
        if(n==10)
        {
            letterS(40,10,5,NOIR,BLEU_VIF);
            usleep(500000);
        }
        if(n==15)
        {
            letterE(60,10,5,NOIR,BLEU_VIF);
            usleep(500000);
        }
        if(n==20)
        {
            letterO(80,10,5,NOIR,BLEU_VIF);
            usleep(500000);
        }
        if(n==25)
        {
            ESEO(10,5,5,NOIR,BLEU_VIF);
            usleep(999999);
        }
    }while(n<25);
    usleep(999999);
    ESEO(10,5,5,BLANC_VIF,BLEU_VIF);
    usleep(999999);
    usleep(999999);
    clrScr();
    gotoXY(37,10);
    setColour(MAGENTA_VIF,NOIR);
    printf("CONGRATULATION - END OF GAME !!!\n\n\n");
    usleep(999999);
    usleep(999999);
    setColour(ROUGE,NOIR);
    titlecadre(37,17,32,10);
    gotoXY(40,20);
    setColour(BLANC_VIF,NOIR);
    printf("Programmer : ");
    gotoXY(53,20);
    setColour(CYAN_VIF,NOIR);
    printf("Axel Gendillard");
    gotoXY(40,25);
    setColour(BLANC_VIF,NOIR);
    printf("Web Site : ");
    gotoXY(52,25);
    setColour(CYAN_VIF,NOIR);
    printf("Antoine Delmas");
    usleep(999999);
    usleep(999999);
    setColour(BLANC_VIF,NOIR);
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tPress Enter :\t");
    getch();
    setColour(BLANC,NOIR);
}
void option(char j1[], char j2[], int *valMatches)//
{
    int p,i;
    char password[50]="";
    setColour(BLEU,NOIR);
    titlecadre(50,2,8,3);
    gotoXY(52,4);
    setColour(BLANC_VIF,NOIR);
    printf("OPTION\n\n\n\n\n");
    setColour(JAUNE_VIF,NOIR);
    printf("\n\n\n\t\t1. Name Players\n\n\n\t\t2. Numbers of Matches\n\n\n\t\t3. Bonus\n\n\n\n");
    setColour(GRIS,NOIR);
    printf("\t\t4. Menu");
    match(90,8,27);
    setColour(BLANC_VIF,NOIR);
    printf("\tChoose an option ? ");
    scanf("%d",&p);
    clrScr();
    if(p==1)
    {
        clrScr();
        nameplayer(j1,j2);
        printf("\n\n\n\tPress Enter\n");
        getch();
        clrScr();
        option(j1,j2,valMatches);

    }
    if(p==2)
    {
        clrScr();
        numbersOfMatches(j1,j2,valMatches);
        clrScr();
        option(j1,j2,valMatches);
    }
    if(p==3)
    {
        clrScr();
        {
            setColour(MAGENTA,NOIR);
            titlecadre(48,2,7,3);
            gotoXY(50,4);
            setColour(BLANC_VIF,NOIR);
            printf("BONUS\n\n\n\n\n");
            setColour(BLANC_VIF,NOIR);
            printf("\n\n\n\t\tEnter Password : ");
            setColour(CYAN_VIF,NOIR);
            scanf("%s",password);
            setColour(BLANC_VIF,NOIR);
            if(strcmp(password,"champion")==0)
            {
                printf("\n\n\t\tGood Password !!!\n\n");
                usleep(500000);
                for(i=5;i>=0;i--)
                {
                    setColour(ROUGE_VIF,NOIR);
                    printf("\a\n\n\t\t\t%d\n",i);
                    usleep(500000);
                }
                usleep(900000);
                bonus(0);
                clrScr();
                menu(j1,j2,valMatches);
            }
            else
            {

                printf("\n\n\tEPIC FAIL !!! Don't try to cheat, win the game against IA in Ultimate mode !!!\n\n\a");
                printf("\n\n\n Press Enter");
                getch();
                clrScr();
                menu(j1,j2,valMatches);
            }
        }
    }
    if(p==4)
    {
        clrScr();
        menu(j1,j2,valMatches);
    }
}
void menu(char j1[], char j2[], int *valMatches)//
{
    char win[100]="";
    char ia[50]="BlackPearl";
    int scorej1=0;
    int scorej2=0;
    int t,r;
    setColour(BLEU,NOIR);
    titlecadre(42,1,21,5);
    setColour(BLEU_VIF,NOIR);
    titlecadre(43,2,19,3);
    gotoXY(45,4);
    setColour(MAGENTA,NOIR);
    printf("GAME OF NIM MENU\n\n\n\n\n");
    setColour(CYAN_VIF,NOIR);
    printf("\n\n\n\t\t1. Play Game\n\n\n\t\t2. Competition Menu\n\n\n\t\t3. Rules\n\n\n\t\t4. Option\n\n\n\n");
    setColour(GRIS,NOIR);
    printf("\t\t5. Quit");
    match(90,8,27);
    setColour(BLANC_VIF,NOIR);
    printf("\tChoose an option ? : ");
    scanf("%d",&t);
    if(t==1)
    {
        do
        {
            clrScr();
            setColour(ROUGE,NOIR);
            titlecadre(49,2,11,3);
            gotoXY(51,4);
            setColour(BLANC_VIF,NOIR);
            printf("PLAY GAME\n\n\n\n\n");
            setColour(MAGENTA,NOIR);
            printf("\n\n\n\t\t1. Player vs Player");
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
            setColour(MAGENTA,NOIR);
            printf("\n\n\n\t\t2. Player vs IA");
            setColour(BLANC,NOIR);
            printf("\n\n\t\t\tPlayer 1 : ");
            setColour(CYAN,NOIR);
            printf("%s",j1);
            setColour(BLANC,NOIR);
            printf("\n\n\t\t\tPlayer 2 : ");
            setColour(CYAN,NOIR);
            printf("BlackPearl");
            setColour(BLANC,NOIR);
            printf("\n\n\t\t\tMatches  : ");
            setColour(JAUNE,NOIR);
            printf("%d\n\n\n",*valMatches);
            setColour(GRIS,NOIR);
            printf("\n\t\t3. Return");
            setColour(BLANC,NOIR);
            match(90,8,27);
            setColour(BLANC_VIF,NOIR);
            printf("\tChoose an option ? : ");
            scanf("%d",&t);
            if(t==1)
            {
                do
                {
                    clrScr();
                    play(win,j1,j2,valMatches);
                    printf("\n\n\tRestart ? (1)\n\n\tGame Menu ? (2)\n\n\tQuit ? (0)\n\n\t\t");
                    scanf("%d",&r);
                    getchar();
                }while(r==1);
            }
            if(t==2)
            {
                do
                {
                    clrScr();
                    playIA(j1,ia,win,valMatches);
                    printf("\n\n\tRestart ? (1)\n\n\tGame Menu ? (2)\n\n\tQuit ? (0)\n\n\t\t");
                    scanf("%d",&r);
                    getchar();
                }while(r==1);

            }
            if(t==3)
            {
                clrScr();
                menu(j1,j2,valMatches);
            }
        }while(r==2);
        exit(0);
    }
    if(t==2)
    {
        clrScr();
        competitionmenu(j1,j2,win,valMatches,&scorej1,&scorej2);
    }
    if(t==3)
    {
        clrScr();
        rules();
        clrScr();
        menu(j1,j2,valMatches);
    }
    if(t==4)
    {
        clrScr();
        option(j1,j2,valMatches);
    }
    if(t==5)
        exit(0);//Quite de programme.
}








