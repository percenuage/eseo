# include "jeu.h"


/* 
===================================================================================
	Fonction : menu()

	Objet : Affiche le menu du jeu

	Paramètres : Aucun

	Renvoie : Rien

	Commentaire : Il est composé de 4 choix [0-3] pour l'utilisateur
===================================================================================
*/

void menu()
{

	ClrScr;
	moveto(10,3);

	printf(BOLD_UNDERLINED"==Menu==\n");
	printf(NORMAL"\n\n1_ Lire les instructions\n");
	printf("2_ Jouer au jeu\n");
	printf("3_ Charger une partie\n");
	printf("0_ Quitter\n\n\n");
	printf("Votre choix: ");
}


/* 
===================================================================================
	Fonction : fonctionSwitch(Joueur *ja, Joueur *jb, char plateau[6][7])

	Objet : Elle lance les différentes fonctions choisis par l'utilisateur

	Paramètres : Joueur ja, jb et le plateau

	Renvoie : Rien

	Commentaire : Utilisation du switch et demande à l'utilisateur de rejouer
===================================================================================
*/

void fonctionSwitch(Joueur *ja, Joueur *jb, char plateau[6][7])
{
	int choix;

	menu(); //affiche le menu

	scanf("%d", &choix);
	purger();
	switch(choix)
	{
		case 1:
		{
			instructions();	//affiche les instructions
			fonctionSwitch(ja, jb, plateau);	//recommence la fonction switch
			break;
		}

		case 2:
		{	
			do
			{
				initialisationPartie(ja, jb, plateau);	//initialise les paramètres joueur et plateau par defaut
				nomDesJoueur(ja, jb);	//entre les noms des joueurs
				jeu(ja, jb, plateau);	//lance le jeu
				getchar();
				printf("\nVoulez-vous rejouer ? (1) Oui | (0) Non : ");
				scanf("%d",&choix);
				purger();
			}while(choix!=FALSE);	
			
			break;
		}

		case 3:
		{	
			extractionPlateau(plateau);	//extrait le plateau depuis un fichier auto_save
			extractionJoueur(ja, jb);	//extrait les joueurs depuis un fichier auto_save
			do
			{
				jeu(ja, jb, plateau);	//Il prendra les paramètre précédent (soit la sauvegarde soit l'initialisation)
				getchar();
				printf("\nVoulez-vous rejouer ? (1) Oui | (0) Non : ");
				scanf("%d",&choix);
				purger();
				if(choix==TRUE)
				{
					initialisationPartie(ja, jb, plateau);
					nomDesJoueur(ja, jb);
				}
			}while(choix!=FALSE);
			break;
		}
	
		case 0:
		{
			ClrScr;
			puts("\n\n\t\tMerci d'avoir joué au Puissance 4 signé ESEO");
			puts("\n\n\t\tProgrammeur : Axel Gendillard && Nicolas Launay");
			break;
		}
		
		default:
		{
			fonctionSwitch(ja, jb, plateau);	//Par defaut : recommenc ela fonction switch
			break;
		}	
	}
}



/* 
===================================================================================
	Fonction : instructions()

	Objet : Affiche les rêgles du jeu

	Paramètres : Aucun

	Renvoie : Rien

	Commentaire : Appuis sur entrée pour quitter
				  Utilisation de "puts("...");" qui affiche du texte (avec accent)
				  sans variable et permet un retour à la ligne automatique
===================================================================================
*/

void instructions()
{
	ClrScr;
	moveto(8,3);
	printf(BOLD_UNDERLINED"Bienvenue dans le jeu puissance 4 nouvelle version\n\n");
	printf(NORMAL"Ce nouveau mode de jeu se decompose en deux parties distinctes.\n\n");
	printf("Premiere partie:\n\tChaque joueur place ses pions de maniere a remplir chaque ligne de la grille.");
	printf("\n\tLes pions seront places en alignement de 4 pions.");
	printf("\n\tTant qu'une ligne n'est pas remplie,\n\taucun pion ne peut etre place dans la ligne du dessus.");
	printf("\n\tUne fois la grille ainsi remplie, la 2e partie du jeu commence.\n\n");
	printf("Deuxieme partie:\n\tChaque joueur retire un pion de la ligne du bas.");
	printf("\n\tSi le pion retire appartenait a un alignement de 4,\n\tle joueur le conserve dans sa main et le joueur rejoue.");
	printf("\n\tSinon il remet le pion en haut de la grille.");
	printf("\n\tLe premier joueur a avoir 10 pions dans sa main remporte la partie\n");
	
	puts("\n\n\n  Continuer ? Pressez \"Entrée\" ...");
	getchar();
}


/* 
===================================================================================
	Fonction : initialisationPartie(Joueur *ja, Joueur *jb, char plateau[6][7])

	Objet : Initialise les paramètres joueur et le plateau (case vide)

	Paramètres : Joueur ja, jb et le plateau

	Renvoie : Rien

	Commentaire : -
===================================================================================
*/

void initialisationPartie(Joueur *ja, Joueur *jb, char plateau[6][7])
{
	int i,j;
	//Initialisation du plateau de jeu
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			plateau[i][j]=' ';
		}
	}

	//Initialisation des pions des joueurs
	ja->pionRestant=21;
	jb->pionRestant=21;
}


/* 
===================================================================================
	Fonction : nomDesJoueur(Joueur *ja, Joueur *jb)

	Objet : Demande aux utilisateurs d'entrée leurs noms

	Paramètres : Joueur ja, jb

	Renvoie : Rien

	Commentaire : Double getchar pour certains problèmes liés aux scanf
===================================================================================
*/

void nomDesJoueur(Joueur *ja, Joueur *jb)
{

	//Joueur A
	printf("\n\nJoueur A, entrez votre nom : ");
	scanf("%s", ja->nom);
	printf("\n%s, votre pion est : %c",ja->nom, ja->caractereJoueur);

	//Joueur B
	printf("\n\nJoueur B, entrez votre nom : ");
	scanf("%s", jb->nom);
	printf("\n%s, votre pion est : %c",jb->nom, jb->caractereJoueur);

	puts("\n\n\nContinuer ? Pressez \"Entrée\" ...");

	getchar();
	getchar();	
}



