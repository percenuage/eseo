//#include <stdlib.h>
//#include <stdio.h>
//#include <SDL/SDL.h>
//#include <fmodex/fmod.h>
//#include "colour.h"
//#include <time.h>
//
////void pause()
////{
////    int continuer = 1;
////    SDL_Event event;
////
////    while (continuer)
////    {
////        SDL_WaitEvent(&event);
////        switch(event.type)
////        {
////        case SDL_QUIT:
////            continuer = 0;
////        }
////    }
////}
//
//void animation(unsigned long int n)
//{
//    /* boucle vide parcourue (n * 100000) fois*/
//    int i = 0;
//    unsigned long int max = n * 100000;
//    do
//    {
//        /* Faire qqch de stupide qui prend du temps */
//        i++;
//    }
//    while(i <= max);
//}
//
//
//void BonusGame(int argc, char *argv[])
//{
//    SDL_Surface *ecran = NULL, *imagedeFond = NULL, *Bouton = NULL, *Curseur = NULL, *Case = NULL, *Explosion = NULL, *fenetre=NULL, *fond=NULL;
//    SDL_Rect positionFond, positionBouton1, positionBouton2, positionBouton3, positionBouton4, positionCurseur, positionCase;
//    SDL_Event event;//J'ai créé un évenement appelé event
//    int continuer=1;
//    int time, i, j=1, k=1,hit=0,aleatpositionx,aleatpositiony,positionx,positiony;
//
//    FMOD_SYSTEM *system;
//
//    FMOD_CHANNEL *channel;
////    FMOD_CHANNELGROUP *group[3];
//    FMOD_SOUND *musique;
//    FMOD_SOUND *feu;
//    FMOD_SOUND *poulet;
//    FMOD_SOUND *intro;
//
//    FMOD_RESULT resultat;
//
//    FMOD_System_Create(&system);
//    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);
//    FMOD_System_CreateSound(system, "Horse race.mp3",FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
//
//    /* On active la répétition de la musique à l'infini */
//    FMOD_Sound_SetLoopCount(musique, -1);
//
//    positionFond.x = 0;
//    positionFond.y = 0;
//    positionBouton1.x = 5;
//    positionBouton1.y = 5;
//    positionBouton2.x = 745;
//    positionBouton2.y = 5;
//    positionBouton3.x = 5;
//    positionBouton3.y = 545;
//    positionBouton4.x = 745;
//    positionBouton4.y = 545;
//    positionCurseur.x = 400;
//    positionCurseur.y = 300;
//    positionCase.x = 100;
//    positionCase.y = 100;
//    //Démarrage de l'affichage vidéo de la SDL
//    SDL_Init(SDL_INIT_VIDEO);
//    /*Ouverture d'une fenêtre avec Longueur, hauteur, couleurs par pixels
//      qui sera gérée par la mémoire de la carte graphique(plus rapide)*/
//
//
//    fond = SDL_LoadBMP("Intro.bmp");
//    fenetre = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
//    SDL_WM_SetCaption("Dragon vs. Chikens", NULL);
//    SDL_BlitSurface(fond, NULL, fenetre, &positionFond);
//    SDL_ShowCursor(SDL_DISABLE);
//    SDL_Flip(fenetre);
//    resultat= FMOD_System_CreateSound(system, "Rugissement dragon2.wav", FMOD_CREATESAMPLE, 0, &intro);
//    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, intro, 0, NULL);
//    animation(10000);
//    SDL_FreeSurface(fond);
//    FMOD_Sound_Release(intro);
//
//
//    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
//    //Pour une fenêtre de taille modifiable:
//    //SDL_SetVideoMode(400, 300, 32, SDL_HWSURFACE | SDL_RESIZABLE);
//    //Titre de la fenêtre
//    SDL_WM_SetCaption("Dragon vs. Chikens", NULL);
//    //Mise d'une image en fond
//    imagedeFond = SDL_LoadBMP("fond.bmp");
//    //On donne un peu de transparence
////   SDL_SetAlpha(imagedeFond, SDL_SRCALPHA, 128);
//    //On fait en sorte de pouvoir mettre de choses par dessus plus tard
//    SDL_BlitSurface(imagedeFond, NULL, ecran, &positionFond);
//    //On charge le bouton sur le fond
//    Bouton = SDL_LoadBMP("Boutonyyang.bmp");
//    //J'enlève la couleur blanche autour du yingyang
//    SDL_SetColorKey(Bouton, SDL_SRCCOLORKEY, SDL_MapRGB(Bouton->format, 255, 255, 255));
//
//    Curseur = SDL_LoadBMP("curseur.bmp");
//    SDL_SetColorKey(Curseur, SDL_SRCCOLORKEY, SDL_MapRGB(Curseur->format, 255, 255, 255));
//
//    Case = SDL_LoadBMP("Case2.bmp");
//    SDL_SetColorKey(Case, SDL_SRCCOLORKEY, SDL_MapRGB(Case->format, 255, 255, 255));
//    SDL_BlitSurface(Case, NULL, ecran, &positionCase);
//
//    Explosion = SDL_LoadBMP("explosion1.bmp");
//    SDL_SetColorKey(Explosion, SDL_SRCCOLORKEY, SDL_MapRGB(Explosion->format, 0, 0, 0));
//    SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton1);
//    SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton2);
//    SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton3);
//    SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton4);
//    SDL_ShowCursor(SDL_DISABLE);//Masque le cursuer de la souris
//    //Possibilité de maintenir une touche enfoncée
//    //SDL_EnableKeyRepeat(10,10);
//
//    //Mise en pause du programme.
//
//    /* On joue la musique */
//    FMOD_System_GetChannel(system,9,&channel);
//    FMOD_System_PlaySound(system, (FMOD_CHANNELINDEX) 9, musique, 0, &channel);
//
//    //On lance la boucle des évenements
//    while (continuer)
//    {
//        i=0, time=0;
//        SDL_WaitEvent(&event);
//        if (hit==20) continuer=0;
//        switch(event.type)
//        {
//        case 0:
//            break;
//        case SDL_QUIT:
//            continuer=0;
//            break;
////            case SDL_MOUSEBUTTONUP:
////                if (event.button.button == SDL_BUTTON_RIGHT) /* On arrête le programme si on a fait un clic droit */
////                    i=1;
////                break;
//
//        case SDL_MOUSEMOTION:
//            positionCurseur.x = event.motion.x;
//            positionCurseur.y = event.motion.y;
//            positionx=positionCurseur.x;
//            positiony=positionCurseur.y;
//            break;
//
//        case SDL_KEYDOWN:
//            switch (event.key.keysym.sym)
//            {
//            case SDLK_ESCAPE:
//                continuer=0;
//                break;
//            case SDLK_SPACE:
//                resultat = FMOD_System_CreateSound(system, "Bouledefeu.wav",
//                                                   FMOD_CREATESAMPLE, 0, &feu);
//                if (resultat != FMOD_OK)
//                {
//                    fprintf(stderr, "Impossible de lire le son\n");
//                    exit(EXIT_FAILURE);
//                }
//                FMOD_System_PlaySound(system, (FMOD_CHANNELINDEX) 1, feu, 0, NULL);
//                time++;
//                i=1;
//                if(time>10) continuer=0;
//                break;
////                     case SDLK_UP:
////                          positionCurseur.y--;
////                          break;
////                     case SDLK_DOWN:
////                          positionCurseur.y++;
////                          break;
////                     case SDLK_RIGHT:
////                          positionCurseur.x++;
////                          break;
////                     case SDLK_LEFT:
////                          positionCurseur.x--;
////                          break;
//            }
//            if(positionx==aleatpositionx || positionx==aleatpositionx+1 || positionx==aleatpositionx+2 || positionx==aleatpositionx+3 || positionx==aleatpositionx+4 || positionx==aleatpositionx+5 || positionx==aleatpositionx+6 || positionx==aleatpositionx+7 || positionx==aleatpositionx+8 || positionx==aleatpositionx-1 || positionx==aleatpositionx-2 || positionx==aleatpositionx-3 || positionx==aleatpositionx-4 || positionx==aleatpositionx-5 || positionx==aleatpositionx-6 || positionx==aleatpositionx-7 || positionx==aleatpositionx-8) k=1;
//            if(positiony==aleatpositiony || positiony==aleatpositiony+1 || positiony==aleatpositiony+2 || positiony==aleatpositiony+3 || positiony==aleatpositiony+4 || positiony==aleatpositiony+5 || positiony==aleatpositiony+6 || positiony==aleatpositiony+7 || positiony==aleatpositiony+8 || positiony==aleatpositiony-1 || positiony==aleatpositiony-2 || positiony==aleatpositiony-3 || positiony==aleatpositiony-4 || positiony==aleatpositiony-5 || positiony==aleatpositiony-6 || positiony==aleatpositiony-7 || positiony==aleatpositiony-8) j=1;
//            if(k==1 && j==1)
//            {
//                aleatpositionx=(rand() % (700-100+1)) + 100;
//                aleatpositiony=(rand() % (500-100+1) + 100);
//                k=0;
//                j=0;
//
//                resultat = FMOD_System_CreateSound(system, "Chicken.wav",
//                                                   FMOD_CREATESAMPLE, 0, &poulet);
//
//                if (resultat != FMOD_OK)
//                {
//                    fprintf(stderr, "Impossible de lire le son\n");
//                    exit(EXIT_FAILURE);
//                }
//                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, poulet, 0, NULL);
//                hit++;
//            }
//            positionCase.x=aleatpositionx;
//            positionCase.y=aleatpositiony;
//            printf("Chickens blowed : %d",hit);
//            break;
//        }
//        SDL_BlitSurface(imagedeFond, NULL, ecran, &positionFond);
//        SDL_SetColorKey(Case, SDL_SRCCOLORKEY, SDL_MapRGB(Case->format, 255, 255, 255));
//        SDL_BlitSurface(Case, NULL, ecran, &positionCase);
//        SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton1);
//        SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton2);
//        SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton3);
//        SDL_BlitSurface(Bouton, NULL, ecran, &positionBouton4);
//        if(i==1)
//        {
//            SDL_SetColorKey(Explosion, SDL_SRCCOLORKEY, SDL_MapRGB(Explosion->format, 0, 0, 0));
//            SDL_BlitSurface(Explosion, NULL, ecran, &positionCurseur);
//        }
//        else
//        {
//            SDL_SetColorKey(Curseur, SDL_SRCCOLORKEY, SDL_MapRGB(Curseur->format, 255, 255, 255));
//            SDL_BlitSurface(Curseur, NULL, ecran, &positionCurseur);
//        }
//
//        SDL_Flip(ecran);
//    }
//
//    fond = SDL_LoadBMP("Fin.bmp");
//    fenetre = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
//    SDL_WM_SetCaption("Dragon vs. Chikens", NULL);
//    SDL_BlitSurface(fond, NULL, fenetre, &positionFond);
//    SDL_ShowCursor(SDL_DISABLE);
//    SDL_Flip(fenetre);
//    resultat= FMOD_System_CreateSound(system, "Rugissement dragon2.wav", FMOD_CREATESAMPLE, 0, &intro);
//    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, intro, 0, NULL);
//    animation(20000);
//    SDL_FreeSurface(fond);
//    FMOD_Sound_Release(intro);
//
//    //Ne pas oublier de relibérer la surface
//    SDL_FreeSurface(imagedeFond);
//    SDL_FreeSurface(Bouton);
//    SDL_FreeSurface(Curseur);
//    SDL_FreeSurface(Case);
//    SDL_FreeSurface(Explosion);
//    SDL_Quit();
//
//    //Et le son
//    FMOD_Sound_Release(musique);
//    FMOD_Sound_Release(feu);
//    FMOD_System_Close(system);
//    FMOD_System_Release(system);
//    //Arrêt de la SDL
//}
