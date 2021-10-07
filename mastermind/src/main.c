#include "jeu.h"

/* Probleme couleur.h + Mettre couleur scoreMenu() + resolution probleme TRI*/

int main ()
{
    system("MODE CON LINES=40 COLS=110");
    Parameter parametre= {COLORMAX,PLAYMAX,TAILLE};
    Player joueur= {0,0,0,0,""};
    srand(time(NULL));

    afficherTitreJeu();
    menuMastermind(&joueur,&parametre);

    HWND hwnd=GetForegroundWindow(); // ferme la fenètre immédiatement
    SendMessage(hwnd,WM_CLOSE,0,0);
    setColour(NOIR,NOIR);
    return 0;
}

/*  _ _ _ _
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|
   |_|_|_|_|

   */


