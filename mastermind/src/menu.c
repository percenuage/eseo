#include "jeu.h"

void menuMastermind(Player *joueur, Parameter *parametre)
{
    int i;
    char namePlayers[10][20]= {""};
    int scorePlayer[10][4]= {{0}};
    int choix=MenuInitialization();

    /*Initialisation Tableau Noms*/
    for(i=0; i<10; i++)
        strcpy(namePlayers[i],"EMPTY");

    switch(choix)
    {
    case 1:
        menuRules();//Voir fichier menu.c
        menuMastermind(joueur,parametre);//Voir fichier menu.c
        break;

    case 2:
        do
        {
            gameMastermind(joueur,parametre);//Voir fichier game.c
            gotoXY(10,22);
            printf("Do you want to restart ?  Yes(1) or No(0) : ");
            scanf("%d",&choix);
        }
        while(choix);
        gotoXY(10,26);
        printf("Do you want to save Score ?  Yes(1) or No(0) : ");
        scanf("%d",&choix);
        if(choix)
        {
            gotoXY(10,30);
            enterName(joueur);//Voir fichier player.c
            saveScore(joueur);//Voir fichier score.c
            puts("\n\n\n\n\t  *Score Saved* ! ... (Press Enter to Menu)");
            getchar();
        }
        menuMastermind(joueur,parametre);
        break;

    case 3:
        do
        {
            chooseLevel(joueur);//Voir fichier player.c
            gameMastermind(joueur,parametre);
            gotoXY(10,22);
            printf("Do you want to restart ?  Yes(1) or No(0) : ");
            scanf("%d",&choix);
        }
        while(choix);
        gotoXY(10,26);
        printf("Do you want to save Score ?  Yes(1) or No(0) : ");
        scanf("%d",&choix);
        if(choix)
        {
            gotoXY(10,30);
            enterName(joueur);
            saveScore(joueur);
            puts("\n\n\n\n\t  *Score Saved* ! ... (Press Enter to Menu)");
            getchar();
        }
        menuMastermind(joueur,parametre);
        break;

    case 4:
        menuScore(namePlayers,scorePlayer);//Voir fichier score.c
        menuMastermind(joueur,parametre);
        break;

    case 5:
        menuOptions(parametre);//Voir fichier menu.c
        menuMastermind(joueur,parametre);
        break;

    case 0:
        break;

    default:
        menuMastermind(joueur,parametre);
    }
}
int MenuInitialization()
{
    int positiony=14;
    int selection;
    setColour(NOIR,NOIR);
    clrScr();
    while(positiony>2)
    {
        setColour(NOIR,NOIR);
        gotoXY(32,positiony-1);
        printf("                                                             ");
        gotoXY(32,positiony);
        printf("                                                             ");
        gotoXY(32,positiony+1);
        printf("                                                             ");
        gotoXY(32,positiony+2);
        printf("                                                             ");
        gotoXY(32,positiony+3);
        printf("                                                             ");
        gotoXY(32,positiony+4);
        printf("                                                             ");
        gotoXY(32,positiony+5);
        printf("                                                             ");

        setColour(JAUNE_VIF,NOIR);
        gotoXY(32,positiony);
        printf("%c   %c %c%c%c %c%c %c%c%c %c%c%c %c%c  %c   %c %c %c   %c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,260,219,219,219,219);
        setColour(ROUGE_VIF,NOIR);
        gotoXY(32,positiony+1);
        printf("%c %c %c %c%c%c %c   %c  %c   %c %c %c %c %c %c %c%c  %c %c %c",219,31,219,219,22,219,219,219,219,219,219,219,31,219,219,219,219,219,219,219);
        setColour(MAGENTA,NOIR);
        gotoXY(32,positiony+2);
        printf("%c   %c %c %c %c%c  %c  %c%c  %c%c  %c   %c %c %c %c %c %c  %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        setColour(CYAN,NOIR);
        gotoXY(32,positiony+3);
        printf("%c   %c %c %c  %c  %c  %c   %c%c  %c   %c %c %c  %c%c %c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        setColour(BLEU_VIF,NOIR);
        gotoXY(32,positiony+4);
        printf("%c   %c %c %c %c%c  %c  %c%c%c %c %c %c   %c %c %c   %c %c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

        animation(100);
        positiony--;
    }

    setColour(MAGENTA,MAGENTA);
    bloc(25,79,9,30);
    setColour(ROUGE_VIF,NOIR);
    cadre(25,79,9,30);
    setColour(JAUNE_VIF,MAGENTA);
    gotoXY(49,11);
    printf("MENU");
    animation(1000);
    gotoXY(27,13);
    printf("%c 1. Read the instructions to play Mastermind ",4);
    gotoXY(27,15);
    animation(1000);
    printf("%c 2. Play against a friend ",4);
    gotoXY(27,17);
    animation(1000);
    printf("%c 3. Play against the Master of the game ",4);
    gotoXY(27,19);
    animation(1000);
    printf("%c 4. See Highscore board ",4);
    gotoXY(27,21);
    animation(1000);
    printf("%c 5. Options ",4);
    gotoXY(27,25);
    animation(1000);
    printf("> 0:QUIT <");
    gotoXY(27,27);
    animation(1000);

    printf("Your selection : ");
    scanf("%d", &selection);
//    setColour(NOIR,NOIR);
//    clrScr();
    return selection;
}
void menuRules()
{
    setColour(BLANC_VIF,NOIR);
    clrScr();
    setColour(BLANC_VIF,NOIR);
    gotoXY(35,2);
    printf("INSTRUCTIONS");
    setColour(CYAN,NOIR);
    printf(" FOR ");
    setColour(MAGENTA,NOIR);
    printf("THE ");
    setColour(ROUGE,NOIR);
    printf("GAME ");
    setColour(ROUGE_VIF,NOIR);
    printf("OF ");
    setColour(JAUNE,NOIR);
    printf("MASTERMIND");
    setColour(JAUNE_VIF,NOIR);
    gotoXY(20,5);
    printf("The game of Mastermind is a game basically played by two players.");
    gotoXY(32,7);
    printf("The master first define a secret combination");
    gotoXY(30,9);
    printf(" of four colours the player would have to find.");
    gotoXY(2,11);
    printf("The player will have a limited number of trials to find out what the combination the master has defined is.");
    gotoXY(19,13);
    printf("If the player finds the combination, he wins. If he doesn't, the master wins.");
    gotoXY(18,15);
    printf("When the player enters a combination, a hint appears on the right of the board.");
    gotoXY(20,17);
    printf("This hinter indicates <C> when the position AND the colour are BOTH correct.");
    gotoXY(20,19);
    printf("The hinter indicates <P> when the position is wrong BUT the colour is correct.");
    gotoXY(22,21);
    printf("It also writes <*> when the position nor the colour are correct. ");
    gotoXY(20,23);
    printf("ATTENTION: The hints are never in the right order in regards to the board.");
    gotoXY(35,25);
    fflush(stdin);
    getchar();
    DEFAUT;
    clrScr();
}
void menuOptions(Parameter *parametre)//N + commentaire
{
    int choix;
    DEFAUT;
    clrScr();
    do
    {
        setColour(MAGENTA,MAGENTA);
        bloc(46,62,1,7);
        setColour(ROUGE_VIF,NOIR);
        cadre(46,63,1,7);
        setColour(JAUNE_VIF,MAGENTA);
        gotoXY(47,2);
        printf("================");
        gotoXY(49,4);
        printf("MENU OPTIONS");
        gotoXY(47,6);
        printf("================");
        gotoXY(8,12);
        setColour(VERT_VIF,NOIR);
        printf("1. Changer Parametre du Mastermind");
        gotoXY(13,15);
        printf("@ Couleur Max : %d",parametre->color_Max);
        gotoXY(13,17);
        printf("@ Taille Max : %d",parametre->taille_Max);
        gotoXY(13,19);
        printf("@ Longueur Max : %d",parametre->play_Max);

        setColour(JAUNE_VIF,NOIR);
        gotoXY(65,12);
        printf("2. Jouer au jeu Bonus");
        setColour(BLEU_VIF,NOIR);
        gotoXY(65,20);
        printf("3. Animation Bonus");
        gotoXY(45,27);
        setColour(ROUGE_VIF,NOIR);
        printf("#  Quitter (0)");
        gotoXY(47,31);
        setColour(BLANC_VIF,NOIR);
        printf("Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1:
            do
            {
                printf("\nEntrer une valeur pour @ Couleur Max [1-8] : ");
                scanf("%d",&parametre->color_Max);
            }
            while(parametre->color_Max<1 || parametre->color_Max>8);
            do
            {
                printf("\nEntrer une valeur pour @ Taille Max [1-4] : ");
                scanf("%d",&parametre->taille_Max);
            }
            while(parametre->taille_Max<1 || parametre->taille_Max>4);
            do
            {
                printf("\nEntrer une valeur pour @ Longueur Max [1-10]: ");
                scanf("%d",&parametre->play_Max);
            }
            while(parametre->play_Max<1 || parametre->play_Max>10);
            clrScr();
            break;

        case 2: //jeu Bonus
            clrScr();
            gotoXY(30,17);
            printf("To play to the secret bonus game:");
            gotoXY(15,19);
            printf("Please launch DragonvsChickenSDL in the main file of the project and enjoy! ;)");
            gotoXY(25,21);
            system("PAUSE");
            clrScr();
            break;

        case 3: //Animation
            clrScr();
            ESEO(BLANC,BLEU,6,1,1);
            Sleep(2000);
            clrScr();
            animationBonusEnd();
            Sleep(2000);
            gotoXY(30,37);
            DEFAUT;
            system("PAUSE");
            clrScr();
            break;

        case 0:
            break;

        default:
            menuOptions(parametre);
        }
    }
    while(choix!=0);

}
void menuScore(char namePlayers[10][20], int scorePlayer[10][4])//N + commentaires
{
    int choix;
    DEFAUT;
    clrScr();

    getScore(namePlayers,scorePlayer);
    do
    {
        gotoXY(47,1);
        printf("==================");
        gotoXY(49,3);
        printf("TRI DES SCORES");
        gotoXY(47,5);
        printf("==================");

        viewScore(namePlayers,scorePlayer);
        gotoXY(70,15);
        printf("1. Trier par ordre alphabetique");
        gotoXY(70,17);
        printf("2. Trier par nombre de Victoire");
        gotoXY(70,19);
        printf("3. Trier par nombre de Defaite");
        gotoXY(70,21);
        printf("4. Trier par Ratio");
        gotoXY(70,23);
        printf("5. Trier par Level");
        gotoXY(70,27);
        printf("#  Quitter (0)");
        gotoXY(47,36);
        printf("Votre choix : ");
        scanf("%d",&choix);
        clrScr();

        switch(choix)
        {
        case 1:
            triScoreAndName(10,4,namePlayers,scorePlayer);
            viewScore(namePlayers,scorePlayer);
            break;

        case 2:
            triScoreAndName(10,0,namePlayers,scorePlayer);
            viewScore(namePlayers,scorePlayer);
            break;

        case 3:
            triScoreAndName(10,1,namePlayers,scorePlayer);
            viewScore(namePlayers,scorePlayer);
            break;

        case 4:
            triScoreAndName(10,2,namePlayers,scorePlayer);
            viewScore(namePlayers,scorePlayer);
            break;

        case 5:
            triScoreAndName(10,3,namePlayers,scorePlayer);
            viewScore(namePlayers,scorePlayer);
            break;

        case 0:
            break;

        default:
            menuScore(namePlayers,scorePlayer);
        }
    }
    while(choix!=0);
}




