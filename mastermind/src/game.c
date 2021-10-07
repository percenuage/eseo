#include "jeu.h"

void gameMastermind(Player *joueur, Parameter *parametre)
{
    int taille=parametre->taille_Max;//Largeur du tableau (4 couleurs max)
    int longueurMax=parametre->play_Max;//Longueur du tableau (10 essais max)
    int colorMax=parametre->color_Max;//Nombre de couleurs au début du jeu (8 couleurs max)
    int compteur=0;//Compteur de tour
    int allCombinationPlay[PLAYMAX+1][TAILLE]={{0}};//Création d'un tabeau double entré (1 ligne = 1 combinaison + ligne n°0 : combinaison mystère)
    char screenReply[PLAYMAX+1][TAILLE]={{0}};//Création d'un tableau pour les caractères de corrections

    DEFAUT;
    clrScr();

/* ================================================
    1ER ETAPE : INITIALISATION COMBINAISON MYSTERE
   ================================================ */

    /*JOUEUR VS IA*/
    if(joueur->level==EASY)
    {
        colorMax=5;
        combinationIA(0,taille,colorMax,allCombinationPlay,EASY);//Voir fichier player.c
    }

    else if(joueur->level==MEDIUM)
    {
        combinationIA(0,taille,colorMax,allCombinationPlay,MEDIUM);
    }
    else if(joueur->level==HARD)
    {
        longueurMax=7;
        combinationIA(0,taille,colorMax,allCombinationPlay,HARD);
    }
    else if(joueur->level==APOCALYPTIC)
    {
        longueurMax=3;
        combinationIA(0,taille,colorMax,allCombinationPlay,APOCALYPTIC);
    }

    /*JOUEUR VS JOUEUR*/
    else
    {
        showAllColor(colorMax,2,1);//Voir fichier graphic.c

        printf("\n\n\n\n Choisir une combinaison de %d couleurs parmis %d : \n\n\n",taille,colorMax);
        enterColor(0,taille,colorMax,allCombinationPlay);//Entre la combinaison mystere (ligne : 0)
        printf("\n\n\n La combinaison est :");
        showCombination(0,taille,allCombinationPlay,3,28);//Affiche la combinaison mystère
        printf("\n\n\n\n\n\n\n (Press Enter)");
        getchar();
        clrScr();//Efface la combinaison mystère
    }

/* ============================================================
    2EME ETAPE : CHERCHEZ LA COMBINAISON MYSTERE ET CORRECTION
   ============================================================ */

    puts("\n\n\n");
    do
    {
        showAllColor(colorMax,2,1);
        printf("\n\n\n\n Entrer une combinaison de %d couleurs : \n\n\n",taille);
        compteur++;//Le compteur débute à 1 puis augmente de +1 à chaque passage
        enterColor(compteur,taille,colorMax,allCombinationPlay);//Entre une combinaison à la ligne "compteur"

        gameBoard(compteur,taille,allCombinationPlay,screenReply,60,-3);//Affiche le Jeu Mastermind + correction
        gotoXY(2,30);
        printf("Il reste %d essai(s)",longueurMax-compteur);
        getchar();
        clrScr();
        gameBoard(compteur,taille,allCombinationPlay,screenReply,60,-3);
    }while(compteur!=longueurMax && compareTable(compteur,taille,allCombinationPlay)==FALSE);//les 2 conditions doivent être réalisées.

/* ===========================================
    3EME ETAPE : CONCLURE + ANIMATION + SCORE
   =========================================== */

    DEFAUT;
    clrScr();
    gotoXY(33,3);
    printf("=========================");
    gotoXY(34,5);
    printf("YOU FINISH IN %d TURNS !",compteur);
    gotoXY(33,7);
    printf("=========================");
    Sleep(3000);//Fonction pause <unistd.h>

    /*ANIMATION DEFAITE*/
    if(compareTable(compteur,taille,allCombinationPlay)==FALSE)
    {
        (joueur->defeat)++;//Incrémentation +1 pour le score defeat
        gotoXY(35,14);
        printf("La combinaison etait :");
        showCombination(0,taille,allCombinationPlay,35,18);
        gotoXY(25,25);
        system("PAUSE");
        Defeat(10,5);//Voir fichier graphic.c
    }

    /*ANIMATION VICTOIRE*/
    else
    {
        (joueur->victory)++;//Incrémentation +1 pour le score victory
        Victory();//Voir fichier graphic.c
    }

    /*AFFICHAGE DES SCORES*/
    clrScr();
    resultScore(joueur);//Voir fichier score.c
    joueur->level=0;//Reinitialisation du level
}
void gameBoard(int const n, int const taille, int combinations[n][taille], char screenReply[n][taille], int X, int Y)
{
    /*CORRIGE LES COMBINAISONS*/
    correction(n,taille,combinations,screenReply);//Voir fichier game.c

    /*AFFICHE LES COMBINAISONS JOUEES*/
    showCombination(n,taille,combinations,X,Y);//Voir fichier graphic.c

    /*AFFICHE LES CORRECTIONS "C" ET "P"*/
    showCorrection(n,taille,screenReply,X+25,Y);//Voir fichier graphic.c
}
void enterColor(int const n, int const taille, int colorMax, int color[n][taille])
{
    int i;
    /*ENTRE LES COMBINAISONS*/
    for(i=0;i<taille;i++)
    {
        do
        {
            printf("\n Entrer la couleur %d : ",i+1);
            scanf("%d",&color[n][i]);
            fflush(stdin);//lettre interdite + vide le scanf
        }while(color[n][i]<1 || color[n][i]>colorMax);//verification du bon choix des valeurs
    }
}
int compareTable(int const n, int const taille, int combinations[n][taille])
{
    int i,temp=FALSE;
    for(i=0;i<taille;i++)
    {
        if(combinations[n][i]==combinations[0][i])//Comparaison entre la ligne n et ligne 0 (C.M)
            temp=TRUE;
        else
        {
            temp=FALSE;
            break;//Stop la boucle
        }
    }
    return temp;
}
void correction(int const n, int const taille, int combinations[n][taille], char screenReply[n][taille])
{
    int i,j;
    int c=0,p=0;

/* DETERMINE LE NOMBRE DE BONNE REPONSE */

    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            /*COMPARAISON "MEME COULEUR MEME PLACE"*/
            if(combinations[0][i]==combinations[n][i])
            {
                c++;
                break;//Stop la 2eme boucle
            }

            /*COMPARAISON "MEME COULEUR PLACE DIFFERENTE"*/
            else if(j!=i && combinations[0][i]==combinations[n][j])
            {
                p++;
                break;//Stop la 2eme boucle
            }
        }
    }

/* RENTRE LES REPONSES DANS UN TABLEAU */

    if(c+p<=taille)
    {
        for(i=0;i<c;i++)
            screenReply[n][i]='C';

        for(i=c;i<c+p;i++)
            screenReply[n][i]='P';

        for(i=c+p;i<taille;i++)
            screenReply[n][i]='*';
    }
    else
        printf("\n\tTOO MANY ARGUMENT !!!\n");//Message d'erreur
}

