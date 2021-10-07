#include "game.h"

void match(int x, int y, int size)//
{
    int i;
    gotoXY(x,y-1);
    setColour(NOIR,ROUGE);
    printf("%c\n",177);
    setColour(BLANC,JAUNE);
    for(i=0;i<=size;i++)
    {
        gotoXY(x,y+i);
        printf(" \n");
    }
    setColour(BLANC,NOIR);
}
void matches_21(int x, int y, int m, int M, int size)//
{
    int i,j,t;
    if(M>35)
    {
        j=0;
        t=0;
        x=3;
        size=5;
        while(j<=M)
        {
            for(i=m;i<=35;i++)
            {
                if(j+i!=M+1)
                {
                    match(x*i,y+t,size);
                    gotoXY(x*i,y+size+2+t);
                    setColour(BLANC,NOIR);
                    printf("%d",j+i);
                }
                else break;
            }
            j=j+35;
            t=t+size+5;
        }
    }
    else
    {
        if(M>21)
        {
            x=3;
            size=5;
        }
        for(i=m;i<=M;i++)
        {
            match(x*i,y,size);
            gotoXY(x*i,y+size+2);
            setColour(BLANC,NOIR);
            printf("%d",i);
        }
    }
}
void graphic_game(int allumetteRestante, int allumetteJoue, int size)//
{
    int i;
    for(i=size;i<=2*size;i=i+size)
    {
        matches_21(X,Y,1,allumetteRestante,size);
        matches_21(X,Y+i,allumetteRestante+1,allumetteRestante+allumetteJoue,size);
        usleep(300000);
        clrScr();
    }
    for(i=size/2;i<=size;i=i+size/2)
    {
        matches_21(X,Y,1,allumetteRestante,size);
        matches_21(X,Y+2*size,allumetteRestante+1,allumetteRestante+allumetteJoue,size-i);
        usleep(200000);//PAUSE
        clrScr();
    }
}
void spacecraft(int x, int y)//
{
    int i;
    gotoXY(x-1,y+1);
    printf("%c",177);
    gotoXY(x-1,y+3);
    printf("%c",177);
    setColour(BLEU,MAGENTA);
    for(i=0;i<=4;i++)
    {
        gotoXY(x,y+i);
        printf("%c\n",177);
    }
    setColour(NOIR,MAGENTA_VIF);
    for(i=0;i<=2;i++)
    {
        gotoXY(x+1,y+1+i);
        printf("%c\n",177);
    }
    setColour(BLANC,JAUNE);
    for(i=0;i<=3;i++)
    {
        gotoXY(x+2+i,y+2);
        printf(" ");
    }
    setColour(BLANC,ROUGE);
    gotoXY(x+6,y+2);
    printf(" ");
    setColour(BLANC_VIF,NOIR);
}
void move(int x, int y)//
{
    int i;
    for(i=0;i<=100;i++)
    {
        spacecraft(x+i,y+1);
        usleep(20000);
        clrScr();
    }
}
void titlecadre(int x, int y, int L, int l)//
{
    int i,j;
    gotoXY(x,y);
    printf("%c",201);
    for(i=1;i<=L;i++)
    {
        for(j=1;j<=l;j++)
        {
            gotoXY(x,y+j);
            printf("%c",186);
            gotoXY(x+L+1,y+j);
            printf("%c",186);
            gotoXY(x,y+l+1);
            printf("%c",200);
            gotoXY(x+i,y);
            printf("%c",205);
            gotoXY(x+i,y+l+1);
            printf("%c",205);
            gotoXY(x+L+1,y);
            printf("%c",187);
            gotoXY(x+L+1,y+l+1);
            printf("%c",188);
        }
    }
}
void letterE(int x, int y, int n, char COLOR1[], char COLOR2[])//
{
    int i;
    for(i=0;i<=2*n;i++)
    {
        gotoXY(x+i,y);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+i,y+4*n);
        setColour(COLOR1,COLOR2);
        case;
    }
    for(i=0;i<=4*n;i++)
    {
        gotoXY(x,y+i);
        setColour(COLOR1,COLOR2);
        case;
    }
    for(i=0;i<=n;i++)
    {
        gotoXY(x+i,y+2*n);
        setColour(COLOR1,COLOR2);
        case;
    }
}
void letterS(int x, int y, int n, char COLOR1[], char COLOR2[])//
{
    int i;
    for(i=0;i<=2*n;i++)
    {
        gotoXY(x,y+i);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+2*n,y+i+2*n);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+i,y);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+i,y+4*n);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+i,y+2*n);
        setColour(COLOR1,COLOR2);
        case;
    }
    for(i=0;i<=n;i++)
    {
        gotoXY(x+2*n,y+i);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x,y+i+3*n);
        setColour(COLOR1,COLOR2);
        case;
    }
}
void letterO(int x, int y, int n, char COLOR1[], char COLOR2[])//
{
    int i;
    for(i=0;i<=4*n;i++)
    {
        gotoXY(x,y+i);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+2*n,y+i);
        setColour(COLOR1,COLOR2);
        case;
    }
    for(i=0;i<=2*n;i++)
    {
        gotoXY(x+i,y);
        setColour(COLOR1,COLOR2);
        case;
        gotoXY(x+i,y+4*n);
        setColour(COLOR1,COLOR2);
        case;
    }
}
void WaveRed(int x, int y, int n, char COLOR1[], char COLOR2[])//
{
    gotoXY(x,y+4*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+2*n,y+3*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+3*n,y+2*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+4*n,y+n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+6*n,y+n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+8*n,y+2*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+10*n,y+3*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+11*n,y+3*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+12*n,y+2*n);
    setColour(COLOR1,COLOR2);
    case;
    gotoXY(x+16*n,y);
    setColour(COLOR1,COLOR2);
    case;
}
void ESEO(int x, int y, int n, char COLOR1[], char COLOR2[])//
{
    int i,j;
    for(j=0;j<=6*n;j++)
    {
        for(i=0;i<=16*n;i++)
        {
            gotoXY(x+i+n,y+j);
            setColour(COLOR1,COLOR1);
            case;
        }
    }
    letterE(x+2*n,y+n,n,COLOR1,COLOR2);
    letterS(x+6*n,y+n,n,COLOR1,COLOR2);
    letterE(x+10*n,y+n,n,COLOR1,COLOR2);
    letterO(x+14*n,y+n,n,COLOR1,COLOR2);
    WaveRed(x+n,y+n,n,COLOR1,ROUGE_VIF);
    setColour(BLANC,NOIR);
}
void purger()//
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}
void clean (char *chaine)//
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}













