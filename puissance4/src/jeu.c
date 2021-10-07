#include "jeu.h"

/* 
===================================================================================
	Fonction : jeu(Joueur *ja, Joueur *jb, char plateau[6][7])

	Objet : Englobe toutes les phases du jeu !

	Paramètres : Joueurs ja, jb et Plateau

	Renvoie : Rien

	Commentaire : Utilisation de pionteur de structure pour changer
				  plusieurs variables dans des fonctions
===================================================================================
*/

void jeu(Joueur *ja, Joueur *jb, char plateau[6][7])
{
	ClrScr;

//Première phase de jeu
	phaseRemplissage(ja, jb, plateau);

//Deuxième phase de jeu
	phaseEjection(ja, jb, plateau);	

//Conclusion Récapitulatif
	if(ja->pionRestant>=10)
	{
		afficheResultat(*ja, *jb);
	}
	else if(jb->pionRestant>=10)
	{
		afficheResultat(*jb, *ja);
	}
}


/* 
===================================================================================
	Fonction : phaseRemplissage(Joueur *ja, Joueur *jb, char plateau[6][7])

	Objet : Joue la phase de remplissage

	Paramètres : Joueurs ja, jb et Plateau

	Renvoie : Rien

	Commentaire : Création d'un joueur j (fictif)
				  Phase 1 fonctionnelle
				  Sauvegarde fonctionnelle
				  Chargement non fonctionnel
===================================================================================
*/

void phaseRemplissage(Joueur *ja, Joueur *jb, char plateau[6][7])
{
	int colonne, ligne, tour=0;
	Joueur j={21,'.',"NONE"};	//Création d'un joueur fictif qui prendra les paramètres des "vrais" à tour de rôle

	do
	{
//affichage plateau
		ClrScr;
		moveto(12,2);
		printf(BOLD_UNDERLINED"##JEU##\n\n");
		printf(NORMAL"");
		puts("\n  < PHASE DE REMPLISSAGE >\n");
		affichePlateau(plateau);

//Sauvegarde
		sauvegardeJoueur(*ja, *jb);	
		sauvegardePlateau(plateau);	

//changement joueur
		tour=changementJoueur(&j, ja, jb, tour);

//insertion pion
		do
		{
			printf("\n\nJoueur \"%s\" à toi de jouer. Il te reste %d pion(s). \n",j.nom,j.pionRestant);
			colonne=choixColonne();//Entrer une colonne valide
			ligne=retourneNumeroLigne(plateau, colonne);//rangée précédente valide ?
		}while(verifLignePleine(plateau, ligne)!=TRUE && ligne!=6);
	
		//pion joué
		ligne--;//On joue la ligne précédente quand même !
		plateau[ligne][colonne]=j.caractereJoueur;
		(j.pionRestant)--;//décrémentation
	
	}while(ja->pionRestant!=0 && jb->pionRestant!=0);
}


/* 
===================================================================================
	Fonction : phaseEjection(Joueur *ja, Joueur *jb, char plateau[6][7])

	Objet : Joue la phase d'éjection

	Paramètres : Joueurs ja, jb et Plateau

	Renvoie : Rien

	Commentaire : Création d'un joueur j (fictif)
				  Phase 2 fonctionnelle
				  Sauvegarde fonctionnelle
				  Chargement non fonctionnel
===================================================================================
*/

void phaseEjection(Joueur *ja, Joueur *jb, char plateau[6][7])
{
	int colonne, ligne, tour=0;
	bool condition;
	Joueur j={0,'.',"NONE"};

	do
	{
//affichage plateau
		ClrScr;
		moveto(12,2);
		printf(BOLD_UNDERLINED"##JEU##\n\n");
		printf(NORMAL"");
		puts("\n    < PHASE D'EJECTION >\n");
		affichePlateau(plateau);

//sauvegarde
		sauvegardeJoueur(*ja, *jb);
		sauvegardePlateau(plateau);

//changement joueur
		tour=changementJoueur(&j, ja, jb, tour);

//ejection du pion
		do
		{
			//choix colonne valide
			printf("\n\nJoueur \"%s\" éjectez un pion. Tu as %d pion(s). \n",j.nom,j.pionRestant);
			colonne=choixColonne();

			//condition pour recommencer la boucle (puissance 4 ?)
			condition=verificationPuissance4(j, plateau, colonne);

			//sleep(1);	//pause de 1 second pour voir afficher le "puissance 4 !"

			//pion du bon joueur ?
			if(pionDuJoueur(j, plateau, colonne)==TRUE)
			{
				(j.pionRestant)++;
				plateau[5][colonne]=' ';//ejection faite
				deplPion(plateau,colonne);

				//affichage plateau
				ClrScr;
				moveto(12,2);
				printf(BOLD_UNDERLINED"##JEU##\n\n");
				printf(NORMAL"");
				puts("\n    < PHASE D'EJECTION >\n");
				affichePlateau(plateau);
			}
		}while(condition != FALSE && j.pionRestant<10);
		
//reinsertion pion
		if(j.pionRestant<10)//Si a ce moment là de la boucle il arrive a 10 ou + alors il ne reinsert pas de pion
		{
			//interdit meme colonne sauf exception
			printf("\n\nJoueur \"%s\" réinsérez un pion(s).\n",j.nom);
			colonne=reinsertionPion(plateau, colonne);
			ligne=retourneNumeroLigne(plateau, colonne);
	
			//pion joué
			ligne--;//On joue la ligne précédente quand même !
			plateau[ligne][colonne]=j.caractereJoueur;
			(j.pionRestant)--;//on décrémente ici !
			//printf("\n\n\"%s\" tu as maintenant %d pion(s). ",j.nom,j.pionRestant);
		}
		

//limite de pion atteint supérieur ou égale à 10 (ou + au cas où ! Même si ça n'arrivera pas)
	}while(j.pionRestant<10);

/*
Lorsque que l'un des joueurs a 10 pion, il n'y a plus de changement de joueur (et on quitte la boucle) 
et donc la variable pionRestant du joueur (ja ou jb) ne peux pas être changé.
Du coup, je dois rajouté ce else{} selon le tour
*/
	if(tour%2==0)
	{
		ja->pionRestant=j.pionRestant;
	}
	else
	{
		jb->pionRestant=j.pionRestant;
	}	
}


/* 
===================================================================================
	Fonction : changementJoueur(Joueur *j, Joueur *ja, Joueur *jb, int tour)

	Objet : Change de joueur et copie les paramètres du joueur (a ou b) dans j
			
	Paramètres : Joueur ja, jb, j et le tour actuel

	Renvoie : Le nombre de (tour + 1)

	Commentaire : Copie le nombre de pion restant de j vers le joueur qui 
				  avais joué puis j prend les paramètres du joueur suivant
===================================================================================
*/

int changementJoueur(Joueur *j, Joueur *ja, Joueur *jb, int tour)
{
	if(tour%2==0)
	{
		jb->pionRestant=j->pionRestant;	//Copie le nombre de pion qu'avais j dans jb
		copieJoueur(j,*ja);	//Copie tous les paramètres de ja vers j
	}
	else
	{
		ja->pionRestant=j->pionRestant;	//Copie le nombre de pion qu'avais j dans ja
		copieJoueur(j,*jb);	//Copie tous les paramètres de jb vers j
	}
	tour++;
	return tour;
}


/* 
===================================================================================
	Fonction : copieJoueur(Joueur *j, Joueur copier)

	Objet : Fonction qui copie les 3 paramètres de la structure d'un
			joueur vers un(e) autre
			
	Paramètres : Joueur j et Joueur copier

	Renvoie : Le nombre de (tour + 1)

	Commentaire : 'j' est un pointeur car il sera changé contrairement à 'copier'
===================================================================================
*/

void copieJoueur(Joueur *j, Joueur copier)
{
	j->pionRestant = copier.pionRestant;
	j->caractereJoueur = copier.caractereJoueur;
	strcpy(j->nom,copier.nom);
}


/* 
===================================================================================
	Fonction : retourneNumeroLigne(char plateau[6][7], int colonne)

	Objet : Fonction qui retourne le numéro de la ligne en fonction 
			de la colonne (et du plateau)
			
	Paramètres : Plateau et numéro de colonne

	Renvoie : Le numéro de ligne

	Commentaire : Retourne 6 si la colonne est vide sinon elle retournera de 0 - 5
===================================================================================
*/

int retourneNumeroLigne(char plateau[6][7], int colonne)
{
	int ligne=0;
	while(plateau[ligne][colonne]==' ' && ligne<=5)
	{
		ligne++;
	}
	return ligne;
}


/* 
===================================================================================
	Fonction : verifLignePleine(char plateau[6][7], int ligne)

	Objet : Fonction qui vérifie si une ligne est pleine
			
	Paramètres : Plateau et numéro de colonne

	Renvoie : Le numéro de ligne

	Commentaire : Retourne 6 si la colonne est vide sinon elle retournera de 0 - 5
				  Attention : risque de débordement avec la ligne 6 possible 
				  (toujours pas apparu !)
===================================================================================
*/

bool verifLignePleine(char plateau[6][7], int ligne)
{
	int j;
	bool tmp=TRUE;
	for(j=0;j<7;j++)
	{
		if(plateau[ligne][j]==' ')
		{
			tmp=FALSE;
		}
	}
	return tmp;
}


/* 
===================================================================================
	Fonction : choixColonne()

	Objet : Fonction qui fais demander à l'utilisateur d'entrer un numéro de colonne
			et qui empèche tout autre valeurs
			
	Paramètres : Aucun

	Renvoie : Le numéro de colonne

	Commentaire : Détecte les caractères ! 
===================================================================================
*/

int choixColonne()
{
	int colonne;
	do
	{
		printf("\nEntrer une colonne : ");
		scanf("%d",&colonne);
		purger();	//recommence l'entrée si detection de caractères
	}while(colonne<0 || colonne>7);
	return colonne;
}


/* 
===================================================================================
	Fonction : reinsertionPion(char plateau[6][7], int colonneEjecte)

	Objet : Fonction qui réinsert un pion et vérifie si s'est 
			la même colonne qu'éjecté précédement
			
	Paramètres : Plateau et numéro de colonne éjecté précédement

	Renvoie : Le numéro de colonne

	Commentaire : Le cas d'une seule colonne possible est pris en compte
				  Vérifie les cases vides (compteur)
				  Condition du while difficile (utilisation de Karnaugh !)
===================================================================================
*/

int reinsertionPion(char plateau[6][7], int colonneEjecte)
{
	int j, n=0, colonne;

	//verification ligne 0 d'avoir un seul vide et non +
	for(j=0;j<7;j++)
	{
		if(plateau[0][j]==' ')
		{
			n++;
		}
	}

	//verification de colonne différente
	do
	{
		colonne=choixColonne();
	}while(colonne==colonneEjecte && n!=1 ||  plateau[0][colonne]!=' ');	//S = e1 & e2 | e3 (cf logique)
	return colonne;	
}


/* 
===================================================================================
	Fonction : pionDuJoueur(Joueur j, char plateau[6][7], int colonne)

	Objet : Fonction qui vérifie si le pion choisis appartient au joueur j
			
	Paramètres : Joueur j, plateau et numéro de colonne

	Renvoie : 0 ou 1 (booléen)

	Commentaire : Il prend en compte les cases vide ! 
===================================================================================
*/

bool pionDuJoueur(Joueur j, char plateau[6][7], int colonne)
{
	if(plateau[5][colonne]==j.caractereJoueur)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/* 
===================================================================================
	Fonction : deplPion(char plateau[6][7], int colonne)

	Objet : Fonction qui déplace les pions du haut vers le bas
			
	Paramètres : Plateau et le numéro de colonne

	Renvoie : 0 ou 1 (booléen)

	Commentaire : -
===================================================================================
*/

void deplPion(char plateau[6][7], int colonne)
{
	int i;
	for(i=5;i>0;i--)
	{
		if(plateau[i][colonne]==' ')
		{
			plateau[i][colonne]=plateau[i-1][colonne];
			plateau[i-1][colonne]=' ';
		}		
	}
}

