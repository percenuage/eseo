#include "jeu.h"

/*AXEL GRAPHIC*/

int returnColor(int number)
{
    if(number==1)
        return BLANC_VIF;
    else if(number==2)
        return ROUGE_VIF;
    else if(number==3)
        return VERT_VIF;
    else if(number==4)
        return JAUNE_VIF;
    else if(number==5)
        return BLEU_VIF;
    else if(number==6)
        return MAGENTA_VIF;
    else if(number==7)
        return CYAN_VIF;
    else if(number==8)
        return GRIS;
    else
        return BLANC;
}
void carre(int color, int X, int Y)
{
    setColour(BLANC,color);
    gotoXY(X,Y);
    CASE;
    gotoXY(X,Y);
    CASE;
    DEFAUT;
}
void showCombination(int const n, int const taille, int combinations[n][taille], int X, int Y)//affiche les 4 couleurs + numéro
{
    int i,j;
    int start=0;

    if(n!=0)
        start=1;

    for(i=start; i<=n; i++)
    {
        for(j=0; j<taille; j++)
        {
            carre(returnColor(combinations[i][j]),X+j*gapX,Y+i*gapY);
            gotoXY(X+j*gapX+1,Y+i*gapY+2);
            printf("%d",combinations[i][j]);
        }
    }
}
void showAllColor(int colorMax, int X, int Y)
{
    int i;
    for(i=0; i<colorMax; i++)
    {
        carre(returnColor(i+1),X+i*gapX,Y);
        gotoXY(X+i*gapX+1,Y+2);
        printf("%d",i+1);
    }
}
void showCorrection(int const n, int const taille, char tab[n][taille], int X, int Y)
{
    int i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<taille; j++)
        {
            gotoXY(X+j*2,Y+i*gapY);
            printf("%c",tab[i][j]);
        }
    }
}

/*NICOLAS GRAPHIC*/

void animation(unsigned long int n)
{
    /* boucle vide parcourue (n * 100000) fois*/
    int i = 0;
    unsigned long int max = n * 100000;
    do
    {
        /* Faire qqch de stupide qui prend du temps */
        i++;
    }
    while(i <= max);
}
void afficherTitreJeu()
{
    int i=1;
    setColour(NOIR,NOIR);
    clrScr();
    setColour(JAUNE_VIF,NOIR);
    gotoXY(32,14);
    printf("%c   %c %c%c%c %c%c %c%c%c %c%c%c %c%c  %c   %c %c %c   %c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,260,219,219,219,219);
    setColour(ROUGE_VIF,NOIR);
    gotoXY(32,15);
    printf("%c %c %c %c%c%c %c   %c  %c   %c %c %c %c %c %c %c%c  %c %c %c",219,31,219,219,22,219,219,219,219,219,219,219,31,219,219,219,219,219,219,219);
    setColour(MAGENTA,NOIR);
    gotoXY(32,16);
    printf("%c   %c %c %c %c%c  %c  %c%c  %c%c  %c   %c %c %c %c %c %c  %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    setColour(CYAN,NOIR);
    gotoXY(32,17);
    printf("%c   %c %c %c  %c  %c  %c   %c%c  %c   %c %c %c  %c%c %c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    setColour(BLEU_VIF,NOIR);
    gotoXY(32,18);
    printf("%c   %c %c %c %c%c  %c  %c%c%c %c %c %c   %c %c %c   %c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    animation(2000);
    while(i<=16)
    {
        DEFAUT;
        gotoXY(28,i);
        printf("%c",273);
        gotoXY(78,i);
        printf("%c",272);
        setColour(NOIR,NOIR);
        gotoXY(28,i-1);
        printf(" ");
        gotoXY(78,i-1);
        printf(" ");
        animation(100);
        i++;
    }
    i=1;
    while(i<=44)
    {
        setColour(BLANC_VIF,NOIR);
        gotoXY(i,21);
        printf("By Axel & Nicolas");
        setColour(NOIR,NOIR);
        gotoXY(i-1,21);
        printf(" ");
        animation(100);
        i++;
    }
    animation(2000);
}
void ligneHorizontale(int xdebut, int xfin, int y, int forme)
{
    while(xdebut<=xfin)
    {
        gotoXY(xdebut,y);
        printf("%c", forme);
        xdebut++;
    }
}
void ligneVerticale(int ydebut, int yfin, int x, int forme)
{
    while(ydebut<=yfin)
    {
        gotoXY(x,ydebut);
        printf("%c", forme);
        ydebut++;
    }
}
void bloc(int xdebut, int xfin, int ydebut, int yfin)
{
    while(xdebut<xfin)
    {
        ligneVerticale(ydebut+1,yfin-1,xdebut+1,219);
        xdebut++;
    }
}
void cadre (int xdebut,int xfin,int ydebut,int yfin)
{
    ligneHorizontale(xdebut+1,xfin-1,ydebut,30);
    ligneHorizontale(xdebut+1,xfin-1,yfin,31);
    ligneVerticale(ydebut+1,yfin-1,xdebut,17);
    ligneVerticale(ydebut+1,yfin-1,xfin,16);
}


void GeekHead(int positionx, int positiony)
{
    setColour(ROUGE_VIF,NOIR);
    gotoXY(positionx+3, positiony);
    printf("/|/|/|/|/|");
    gotoXY(positionx+2, positiony+1);
    printf("/ |/  |/  |");
    gotoXY(positionx+1, positiony+2);
    setColour(BLANC_VIF,NOIR);
    printf("/");
    gotoXY(positionx+3, positiony+2);
    setColour(BLEU_VIF,NOIR);
    printf("__     __ ");
    setColour(BLANC_VIF,NOIR);
    printf(" %c",92);
    gotoXY(positionx, positiony+3);
    printf("| ");
    setColour(BLEU_VIF,NOIR);
    printf("| | -- | |");
    setColour(BLANC_VIF,NOIR);
    printf("  |");
    gotoXY(positionx, positiony+4);
    printf("| ");
    setColour(BLEU_VIF,NOIR);
    printf(" %c      %c ",238,238);
    setColour(BLANC_VIF,NOIR);
    printf("  |");
    gotoXY(positionx, positiony+5);
    printf("|   ________  |");
    gotoXY(positionx, positiony+6);
    printf("%c  | ",92);
    setColour(JAUNE_VIF,NOIR);
    printf("[] [] ");
    setColour(BLANC_VIF,NOIR);
    printf("| |");
    gotoXY(positionx+1, positiony+7);
    printf("| |_______| |");
    gotoXY(positionx+2, positiony+8);
    printf("%c_________/",92);
}
void RedDogHead(int positionx, int positiony)
{
    gotoXY(positionx+1,positiony);
    setColour(ROUGE_VIF,NOIR);
    printf("|%c      /|",92);
    gotoXY(positionx+1,positiony+1);
    printf("| |    | |");
    gotoXY(positionx+1,positiony+2);
    printf("%c %c    / /",92,92);
    gotoXY(positionx+1,positiony+3);
    setColour(ROUGE_VIF,NOIR);
    printf("/%c%c%c%c%c%c%c%c%c\n",238,238,238,238,238,238,238,238,92);
    gotoXY(positionx,positiony+4);
    printf("|");
    gotoXY(positionx+2,positiony+4);
    setColour(JAUNE_VIF,NOIR);
    printf("|%c    /|",92);
    gotoXY(positionx+10,positiony+4);
    setColour(ROUGE_VIF,NOIR);
    printf(" |");
    gotoXY(positionx,positiony+5);
    printf("| ");
    gotoXY(positionx+2,positiony+5);
    setColour(JAUNE_VIF,NOIR);
    printf("%c_%c  /_/ ",92,92);
    gotoXY(positionx+11,positiony+5);
    setColour(ROUGE_VIF,NOIR);
    printf("|");
    gotoXY(positionx,positiony+6);
    printf("|          |");
    gotoXY(positionx,positiony+7);
    printf("|  ______  |");
    gotoXY(positionx,positiony+8);
    printf("| | %c/%c/ | |",92,92);
    gotoXY(positionx,positiony+9);
    printf("%c %c      / /",92,92);
    gotoXY(positionx+1,positiony+10);
    printf("| %c____/ |",92);
    gotoXY(positionx+2,positiony+11);
    printf("%c______/",92);
}
void RabbitHead(int positionx, int positiony)
{
    gotoXY(positionx,positiony);
    setColour(MAGENTA_VIF,NOIR);
    printf("          /|");
    gotoXY(positionx,positiony+1);
    printf("         / /");
    gotoXY(positionx,positiony+2);
    printf("   __ __| |");
    gotoXY(positionx,positiony+3);
    printf("  / /      %c",92);
    gotoXY(positionx,positiony+4);
    printf(" / /  ");
    setColour(ROUGE_VIF,NOIR);
    printf("%c  %c",259,259);
    setColour(MAGENTA_VIF,NOIR);
    printf("  ) ");
    gotoXY(positionx,positiony+5);
    printf("|/ %c _  %c _|",92,260);
    gotoXY(positionx,positiony+6);
    printf("    (_");
    setColour(BLANC_VIF,NOIR);
    printf(" %c%c ",254,254);
    setColour(MAGENTA_VIF,NOIR);
    printf("_)");
    gotoXY(positionx,positiony+7);
    printf("      |__|");
}
void MastersHead(int positionx, int positiony)
{
    gotoXY(positionx,positiony);
    printf("                          (");
    gotoXY(positionx,positiony+1);
    printf("              .           )         )");
    gotoXY(positionx,positiony+2);
    printf("                      (  (|              .");
    gotoXY(positionx,positiony+3);
    printf("                  )   )\\/ ( ( (");
    gotoXY(positionx,positiony+4);
    printf("          *   (  ((  /     ))\\))  (  )   )");
    gotoXY(positionx,positiony+5);
    printf("        (     \\   )\\(          |  ))( ) (|");
    gotoXY(positionx,positiony+6);
    printf("        >)     ))/   |          )/  \\(( ) \\");
    gotoXY(positionx,positiony+7);
    printf("        (     (      .        -.     V )/  )(    (");
    gotoXY(positionx,positiony+8);
    printf("         \\   /      .  \\            .      \\))   ))");
    gotoXY(positionx,positiony+9);
    printf("           )(       ( | |   )            .   (  /");
    gotoXY(positionx,positiony+10);
    printf("          )(     ,'))    \\ /          \\( `.   )");
    gotoXY(positionx,positiony+11);
    printf("          (\\>  ,'/__      ))            __`. /");
    gotoXY(positionx,positiony+12);
    printf("         ( \\   | /  ___   ( \\/     ___   \\ |( (");
    gotoXY(positionx,positiony+13);
    printf("          \\.)  |/  /   \\__      __/   \\   \\| ))");
    gotoXY(positionx,positiony+14);
    printf("         .  \\. |>  \\      | __ |      /   <|  /");
    gotoXY(positionx,positiony+15);
    printf("              )/    \\____/ :..: \\____/     \\ <");
    gotoXY(positionx,positiony+16);
    printf("      )    \\ (|__  .      / ;: \\          __| )  (");
    gotoXY(positionx,positiony+17);
    printf("     ((     )\\)  ~--_     --  --      _--~    /  ))");
    gotoXY(positionx,positiony+18);
    printf("      \\     (    |  ||               ||  |   (  /");
    gotoXY(positionx,positiony+19);
    printf("             \\.  |  ||_             _||  |  /");
    gotoXY(positionx,positiony+20);
    printf("               > :  |  ~V+-I_I_I-+V~  |  : (.");
    gotoXY(positionx,positiony+21);
    printf("              (  \\:  T\\   _     _   /T  : ./");
    gotoXY(positionx,positiony+22);
    printf("               \\  :    T^T T-+-T T^T    ;<");
    gotoXY(positionx,positiony+23);
    printf("                \\..`_       -+-       _'  )");
    gotoXY(positionx,positiony+24);
    printf("                    .`--=.._____..=--'. ./");
}
void Defeat(int positionx, int positiony)
{
    int i=0;
    setColour(NOIR,NOIR);
    clrScr();
    setColour(ROUGE_VIF,NOIR);
    gotoXY(50,3);
    printf("YOU");
    while(i<=6)
    {
        setColour(BLANC_VIF,NOIR);
        gotoXY(positionx,positiony);
        printf("\t\t                          (");
        gotoXY(positionx,positiony+1);
        printf("\t\t              .           )         )");
        gotoXY(positionx,positiony+2);
        printf("\t\t                      (  (|              .");
        gotoXY(positionx,positiony+3);
        printf("\t\t                  )   )\\/ ( ( (");
        gotoXY(positionx,positiony+4);
        printf("\t\t          *   (  ((  /     ))\\))  (  )   )");
        gotoXY(positionx,positiony+5);
        printf("\t\t        (     \\   )\\(          |  ))( ) (|");
        gotoXY(positionx,positiony+6);
        printf("\t\t        >)     ))/   |          )/  \\(( ) \\");
        gotoXY(positionx,positiony+7);
        printf("\t\t        (     (      .        -.     V )/  )(    (");
        gotoXY(positionx,positiony+8);
        printf("\t\t         \\   /      .  \\            .      \\))   ))");
        gotoXY(positionx,positiony+9);
        printf("\t\t           )(       ( | |   )            .   (  /");
        gotoXY(positionx,positiony+10);
        printf("\t\t          )(     ,'))    \\ /          \\( `.   )");
        gotoXY(positionx,positiony+11);
        printf("\t\t          (\\>  ,'/__      ))            __`. /");
        gotoXY(positionx,positiony+12);
        printf("\t\t         ( \\   | /  ___   ( \\/     ___   \\ |( (");
        gotoXY(positionx,positiony+13);
        printf("\t\t          \\.)  |/  /   \\__      __/   \\   \\| ))");
        gotoXY(positionx,positiony+14);
        printf("\t\t         .  \\. |>  \\      | __ |      /   <|  /");
        gotoXY(positionx,positiony+15);
        printf("\t\t              )/    \\____/ :..: \\____/     \\ <");
        gotoXY(positionx,positiony+16);
        printf("\t\t      )    \\ (|__  .      / ;: \\          __| )  (");
        gotoXY(positionx,positiony+17);
        printf("\t\t     ((     )\\)  ~--_     --  --      _--~    /  ))");
        gotoXY(positionx,positiony+18);
        printf("\t\t      \\     (    |  ||               ||  |   (  /");
        gotoXY(positionx,positiony+19);
        printf("\t\t             \\.  |  ||_             _||  |  /");
        gotoXY(positionx,positiony+20);
        printf("\t\t               > :  |  ~V+-I_I_I-+V~  |  : (.");
        gotoXY(positionx,positiony+21);
        printf("\t\t              (  \\:  T\\   _     _   /T  : ./");
        gotoXY(positionx,positiony+22);
        printf("\t\t               \\  :    T^T T-+-T T^T    ;<");
        gotoXY(positionx,positiony+23);
        printf("\t\t                \\..`_       -+-       _'  )");
        gotoXY(positionx,positiony+24);
        printf("\t\t                    .`--=.._____..=--'. ./");
        animation(800);

        gotoXY(positionx,positiony);
        printf("\t\t                          (");
        gotoXY(positionx,positiony+1);
        printf("\t\t              .           )         )");
        gotoXY(positionx,positiony+2);
        printf("\t\t                      (  (|              .");
        gotoXY(positionx,positiony+3);
        printf("\t\t                  )   )\\/ ( ( (");
        gotoXY(positionx,positiony+4);
        printf("\t\t          *   (  ((  /     ))\\))  (  )   )");
        gotoXY(positionx,positiony+5);
        printf("\t\t        (     \\   )\\(          |  ))( ) (|");
        gotoXY(positionx,positiony+6);
        printf("\t\t        >)     ))/   |          )/  \\(( ) \\");
        gotoXY(positionx,positiony+7);
        printf("\t\t        (     (      .        -.     V )/  )(    (");
        gotoXY(positionx,positiony+8);
        printf("\t\t         \\   /      .  \\            .      \\))   ))");
        gotoXY(positionx,positiony+9);
        printf("\t\t           )(       ( | |   )            .   (  /");
        gotoXY(positionx,positiony+10);
        printf("\t\t          )(     ,'))    \\ /          \\( `.   )");
        gotoXY(positionx,positiony+11);
        printf("\t\t          (\\>  ,'/__      ))            __`. /");
        gotoXY(positionx,positiony+12);
        printf("\t\t         ( \\   | /  ___   ( \\/     ___   \\ |( (");
        gotoXY(positionx,positiony+13);
        printf("\t\t          \\.)  |/  /   \\__      __/   \\   \\| ))");
        gotoXY(positionx,positiony+14);
        printf("\t\t         .  \\. |>  \\      | __ |      /   <|  /");
        gotoXY(positionx,positiony+15);
        printf("\t\t              )/    \\____/ :..: \\____/     \\ <");
        gotoXY(positionx,positiony+16);
        printf("\t\t      )    \\ (|__  .      / ;: \\          __| )  (");
        gotoXY(positionx,positiony+17);
        printf("\t\t     ((     )\\)  ~--_     --  --      _--~    /  ))");
        gotoXY(positionx,positiony+18);
        printf("\t\t      \\     (    |  ||               ||  |   (  /");
        gotoXY(positionx,positiony+19);
        printf("\t\t             \\.  |  ||_             _||  |  /");
        gotoXY(positionx,positiony+20);
        printf("\t\t               > :  |  ~V+-I_I_I-+V~  |  : (.");
        gotoXY(positionx,positiony+21);
        printf("\t\t               \\  :    T^T T-+-T T^T    ;<");
        gotoXY(positionx,positiony+22);
        printf("\t\t                \\..`_       -+-       _'  )");
        gotoXY(positionx,positiony+23);
        printf("\t\t                    .`--=.._____..=--'. ./");
        gotoXY(positionx+35+(2*i),positiony+28);
        setColour(ROUGE_VIF,NOIR);
        printf("HA");
        animation(500);
        i++;
    }
    setColour(JAUNE_VIF,NOIR);
    //affichage de la lettre L
    ligneVerticale(10,20,3,219);
    ligneHorizontale(4,10,20,219);
    setColour(BLEU_VIF,NOIR);
    animation(800);
    //affichage de la lettre O
    ligneVerticale(11,19,12,219);
    ligneHorizontale(13,20,20,219);
    ligneHorizontale(13,20,10,219);
    ligneVerticale(11,19,21,219);
    setColour(MAGENTA,NOIR);
    animation(800);
    //affichage de la lettre S
    ligneVerticale(11,14,80,219);
    ligneHorizontale(81,86,10,219);
    ligneHorizontale(81,86,15,219);
    ligneVerticale(16,19,87,219);
    ligneHorizontale(80,86,20,219);
    setColour(CYAN_VIF,NOIR);
    animation(800);
    //affichage de la lettre E
    ligneVerticale(10,20,89,219);
    ligneHorizontale(90,99,10,219);
    ligneHorizontale(90,94,15,219);
    ligneHorizontale(90,99,20,219);
    animation(5000);
//    getchar();
//    setColour(BLANC_VIF,NOIR);
//    gotoXY(39,15);
//    printf("Back to Menu?");
//    getchar();
}
void Victory()
{
    int i=1;
    setColour(NOIR,NOIR);
    clrScr();
    //affichage des smileys tout autour
    setColour(BLANC_VIF,NOIR);
    gotoXY(10,10);
    printf("%c",258);
    gotoXY(10,25);
    printf("%c",258);
    gotoXY(30,30);
    printf("%c",258);
    gotoXY(30,5);
    printf("%c",258);
    gotoXY(70,30);
    printf("%c",258);
    gotoXY(70,5);
    printf("%c",258);
    gotoXY(90,25);
    printf("%c",258);
    gotoXY(90,10);
    printf("%c",258);
    //affichage de well done et animation des flammes
    while(i<14)
    {
        setColour(ROUGE_VIF,NOIR);
        gotoXY(25,13);
        printf("                 (     (     (         )      )");
        gotoXY(25,14);
        printf(" (  (            )\\ )  )\\ )  )\\ )   ( /(   ( /( ");
        gotoXY(25,15);
        printf(" )\\))(    ' (   (()/( (()/( (()/(   )\\())  )\\())  ( ");
        gotoXY(25,16);
        printf(" ((_)()\\ )  )\\   /(_)) /(_)) /(_)) ((_)\\  ((_)\\   )\\ ");
        gotoXY(25,17);
        printf(" _(())\\_)()((_) (_))  (_))  (_))_    ((_)  _((_) ((_) ");
        setColour(JAUNE_VIF,NOIR);
        gotoXY(25,18);
        printf(" \\ \\((_)/ /| __|| |   | |    |   \\  / _ \\ | \\| || __| ");
        gotoXY(25,19);
        printf("  \\ \\/\\/ / | _| | |__ | |__  | |) || (_) || .` || _| ");
        gotoXY(25,20);
        printf("   \\_/\\_/  |___||____||____| |___/  \\___/ |_|\\_||___| ");
        animation(800);

        setColour(ROUGE_VIF,NOIR);
        gotoXY(25,13);
        printf("               (     (     (         )      )");
        gotoXY(25,14);
        printf("   (            )\\ )  )\\ )  )\\ )   ( /(   ( /( ");
        gotoXY(25,15);
        printf(" \\))(     (   (()/( (()/( (()/(   )\\())  )\\())  ( ");
        gotoXY(25,16);
        printf(" (_)()\\ )  )\\   /(_)) /(_)) /(_)) ((_)\\  ((_)\\   )\\(");
        gotoXY(25,17);
        printf(" _(())\\_)()((_) (_))  (_))  (_))_    ((_)  _((_) ((_) ");
        setColour(JAUNE_VIF,NOIR);
        gotoXY(25,18);
        printf(" \\ \\((_)/ /| __|| |   | |    |   \\  / _ \\ | \\| || __| ");
        gotoXY(25,19);
        printf("  \\ \\/\\/ / | _| | |__ | |__  | |) || (_) || .` || _| ");
        gotoXY(25,20);
        printf("   \\_/\\_/  |___||____||____| |___/  \\___/ |_|\\_||___| ");
        animation(800);

        //appartition des feux d'artifice à la place des smileys
        if((i%2)==0)
        {
            //on efface les restes éventuels d'un feu d'artifice antérieur
            setColour(NOIR,NOIR);
            gotoXY(8,8);
            printf("%c | /",92);
            gotoXY(8,10);
            printf("-   -");
            gotoXY(8,12);
            printf("/ | %c",92);
            gotoXY(8,23);
            printf("%c | /",92);
            gotoXY(8,25);
            printf("-   -");
            gotoXY(8,27);
            printf("/ | %c",92);
            gotoXY(28,28);
            printf("%c | /",92);
            gotoXY(28,30);
            printf("-   -");
            gotoXY(28,32);
            printf("/ | %c",92);
            gotoXY(28,3);
            printf("%c | /",92);
            gotoXY(28,5);
            printf("-   -");
            gotoXY(28,7);
            printf("/ | %c",92);
            gotoXY(68,28);
            printf("%c | /",92);
            gotoXY(68,30);
            printf("-   -");
            gotoXY(68,32);
            printf("/ | %c",92);
            gotoXY(68,3);
            printf("%c | /",92);
            gotoXY(68,5);
            printf("-   -");
            gotoXY(68,7);
            printf("/ | %c",92);
            gotoXY(88,23);
            printf("%c | /",92);
            gotoXY(88,25);
            printf("-   -");
            gotoXY(88,27);
            printf("/ | %c",92);
            gotoXY(88,8);
            printf("%c | /",92);
            gotoXY(88,10);
            printf("-   -");
            gotoXY(88,12);
            printf("/ | %c",92);
            //on peut commencer le feu d'artifice
            setColour(MAGENTA_VIF,NOIR);
            gotoXY(10,10);
            printf(" ");
            gotoXY(9,9);
            printf("%c /",92);
            gotoXY(9,11);
            printf("/ %c",92);
            gotoXY(10,25);
            printf(" ");
            gotoXY(9,24);
            printf("%c /",92);
            gotoXY(9,26);
            printf("/ %c",92);
            gotoXY(30,30);
            printf(" ");
            gotoXY(29,29);
            printf("%c /",92);
            gotoXY(29,31);
            printf("/ %c",92);
            gotoXY(30,5);
            printf(" ");
            gotoXY(29,4);
            printf("%c /",92);
            gotoXY(29,6);
            printf("/ %c",92);
            gotoXY(70,30);
            printf(" ");
            gotoXY(69,29);
            printf("%c /",92);
            gotoXY(69,31);
            printf("/ %c",92);
            gotoXY(70,5);
            printf(" ");
            gotoXY(69,4);
            printf("%c /",92);
            gotoXY(69,6);
            printf("/ %c",92);
            gotoXY(90,25);
            printf(" ");
            gotoXY(89,24);
            printf("%c /",92);
            gotoXY(89,26);
            printf("/ %c",92);
            gotoXY(90,10);
            printf(" ");
            gotoXY(89,9);
            printf("%c /",92);
            gotoXY(89,11);
            printf("/ %c",92);
        }
        if((i%3)==0)
        {
            setColour(NOIR,NOIR);
            gotoXY(10,10);
            printf(" ");
            gotoXY(9,9);
            printf("%c /",92);
            gotoXY(9,11);
            printf("/ %c",92);
            gotoXY(10,25);
            printf(" ");
            gotoXY(9,24);
            printf("%c /",92);
            gotoXY(9,26);
            printf("/ %c",92);
            gotoXY(30,30);
            printf(" ");
            gotoXY(29,29);
            printf("%c /",92);
            gotoXY(29,31);
            printf("/ %c",92);
            gotoXY(30,5);
            printf(" ");
            gotoXY(29,4);
            printf("%c /",92);
            gotoXY(29,6);
            printf("/ %c",92);
            gotoXY(70,30);
            printf(" ");
            gotoXY(69,29);
            printf("%c /",92);
            gotoXY(69,31);
            printf("/ %c",92);
            gotoXY(70,5);
            printf(" ");
            gotoXY(69,4);
            printf("%c /",92);
            gotoXY(69,6);
            printf("/ %c",92);
            gotoXY(90,25);
            printf(" ");
            gotoXY(89,24);
            printf("%c /",92);
            gotoXY(89,26);
            printf("/ %c",92);
            gotoXY(90,10);
            printf(" ");
            gotoXY(89,9);
            printf("%c /",92);
            gotoXY(89,11);
            printf("/ %c",92);

            //on termine le feu d'artifice
            setColour(CYAN_VIF,NOIR);
            gotoXY(8,8);
            printf("%c | /",92);
            gotoXY(8,10);
            printf("-   -");
            gotoXY(8,12);
            printf("/ | %c",92);
            gotoXY(8,23);
            printf("%c | /",92);
            gotoXY(8,25);
            printf("-   -");
            gotoXY(8,27);
            printf("/ | %c",92);
            gotoXY(28,28);
            printf("%c | /",92);
            gotoXY(28,30);
            printf("-   -");
            gotoXY(28,32);
            printf("/ | %c",92);
            gotoXY(28,3);
            printf("%c | /",92);
            gotoXY(28,5);
            printf("-   -");
            gotoXY(28,7);
            printf("/ | %c",92);
            gotoXY(68,28);
            printf("%c | /",92);
            gotoXY(68,30);
            printf("-   -");
            gotoXY(68,32);
            printf("/ | %c",92);
            gotoXY(68,3);
            printf("%c | /",92);
            gotoXY(68,5);
            printf("-   -");
            gotoXY(68,7);
            printf("/ | %c",92);
            gotoXY(88,23);
            printf("%c | /",92);
            gotoXY(88,25);
            printf("-   -");
            gotoXY(88,27);
            printf("/ | %c",92);
            gotoXY(88,8);
            printf("%c | /",92);
            gotoXY(88,10);
            printf("-   -");
            gotoXY(88,12);
            printf("/ | %c",92);
        }
        i++;
    }
    setColour(BLANC_VIF,NOIR);
    clrScr();
}


/*AXEL ANIMATION\OPTION*/

void letterE(int COLOR1, int COLOR2, int n, int x, int y)
{
    int i;
    for(i=0;i<=2*n;i++)
    {
        gotoXY(x+i,y);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+i,y+4*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
    for(i=0;i<=4*n;i++)
    {
        gotoXY(x,y+i);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
    for(i=0;i<=n;i++)
    {
        gotoXY(x+i,y+2*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
}
void letterS(int COLOR1, int COLOR2, int n, int x, int y)
{
    int i;
    for(i=0;i<=2*n;i++)
    {
        gotoXY(x,y+i);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+2*n,y+i+2*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+i,y);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+i,y+4*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+i,y+2*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
    for(i=0;i<=n;i++)
    {
        gotoXY(x+2*n,y+i);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x,y+i+3*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
}
void letterO(int COLOR1, int COLOR2, int n, int x, int y)
{
    int i;
    for(i=0;i<=4*n;i++)
    {
        gotoXY(x,y+i);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+2*n,y+i);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
    for(i=0;i<=2*n;i++)
    {
        gotoXY(x+i,y);
        setColour(COLOR1,COLOR2);
        printf(" ");
        gotoXY(x+i,y+4*n);
        setColour(COLOR1,COLOR2);
        printf(" ");
    }
}
void WaveRed(int COLOR1, int COLOR2, int n, int x, int y)
{
    gotoXY(x,y+4*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+2*n,y+3*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+3*n,y+2*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+4*n,y+n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+6*n,y+n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+8*n,y+2*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+10*n,y+3*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+11*n,y+3*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+12*n,y+2*n);
    setColour(COLOR1,COLOR2);
    printf(" ");
    gotoXY(x+16*n,y);
    setColour(COLOR1,COLOR2);
    printf(" ");
}
void ESEO(int COLOR1, int COLOR2, int n, int x, int y)
{
    int i,j;
    for(j=0;j<=6*n;j++)
    {
        for(i=0;i<=16*n;i++)
        {
            gotoXY(x+i+n,y+j);
            setColour(COLOR1,COLOR1);
            printf(" ");
        }
    }
    Sleep(300);
    letterE(COLOR1,COLOR2,n,x+2*n,y+n);
    Sleep(800);
    letterS(COLOR1,COLOR2,n,x+6*n,y+n);
    Sleep(1500);
    letterE(COLOR1,COLOR2,n,x+10*n,y+n);
    Sleep(800);
    letterO(COLOR1,COLOR2,n,x+14*n,y+n);
    Sleep(800);
    WaveRed(COLOR1,ROUGE_VIF,n,x+n,y+n);
    setColour(BLANC,NOIR);
}
void titlecadre(int x, int y, int L, int l)
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
void animationBonusEnd()
{
    gotoXY(37,8);
    setColour(MAGENTA_VIF,NOIR);
    printf("CONGRATULATION - END OF GAME !!!\n\n\n");
    Sleep(1000);
    setColour(ROUGE,NOIR);
    titlecadre(36,17,32,10);
    gotoXY(38,20);
    setColour(BLANC_VIF,NOIR);
    printf("Programmer : ");
    gotoXY(51,20);
    setColour(CYAN_VIF,NOIR);
    printf("Axel Gendillard");
    gotoXY(38,25);
    setColour(BLANC_VIF,NOIR);
    printf("Designer : ");
    gotoXY(50,25);
    setColour(CYAN_VIF,NOIR);
    printf("Nicolas Launay");
}


