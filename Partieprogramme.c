#include "Partieheader.h"
#include "menu.h"
void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void Partie(){
    char ch;

    //initialisation de la partie
    char joueur[16][16];
    char affichage[16][16];
    char adversaire[16][16];
    // création des grilles
    creergrille(joueur);
    creergrille(affichage);
    creergrille(adversaire);
    //creation des flottes
    t_bateau *bateau;
    t_bateau *bateauad;

    bateau = genererFlotte(n_porteavion,n_croisseur,n_destroyer,n_sousmarin,bateau);
    bateauad = genererFlotte(n_porteavion,n_croisseur,n_destroyer,n_sousmarin,bateau);

    placementBateaux(n_bateau,bateau,joueur);
    placementBateaux(n_bateau,bateauad,adversaire);
    bool bateaualliee = etatBateaux(bateau,n_bateau,bateaualliee);
    bool bateauennemi = etatBateaux(bateau,n_bateau,bateauennemi);
    int n_fusee=4;
    //la boucle de jeu
    do{
        printf("GRILLE JOUEUR\n");
        affichegrille(joueur);
        printf("\n");
        printf("GRILLE AFFICHAGE\n");
        affichegrille(affichage);
        gotoligcol(30,60);
        printf("Appuyez sur une touche pour continuer.\n");
        gotoligcol(31,60);
        printf("[T] pour tirer\n");
        gotoligcol(32,60);
        printf("[D] pour deplacer\n");
        gotoligcol(33,60);
        printf("[E] pour eclaire\n");
        gotoligcol(34,60);
        printf("[S] pour sauvegarder\n");
        gotoligcol(35,60);
        printf("[M] MENU\n");
        gotoligcol(36,60);
        printf("Nombre de fusee restant %d\n",n_fusee);
        gotoligcol(36,0);
        //recuperation de ce qu'il veut jouer
        do {
            ch = getch();
            fflush(stdin);
        }while(ch != 't' && ch!= 'T' && ch!= 'e' && ch != 'E' && ch != 'd' && ch !='D'&& ch != 's' && ch!='S'&& ch != 'm' && ch!='M'&& ch == 'v' && ch== 'V');
        // mode v
        if (ch == 'v' ||ch== 'V'){
            printf("\n");
            printf("GRILLE ADVERSAIRE\n");
            affichegrille(adversaire);
            printf("Rejouer\n");
            ch= getch();
            fflush(stdin);
        }//tirer
        if (ch == 't' ||ch== 'T'){
            tirer(affichage,adversaire,bateauad,n_bateau);
            bateauennemi = etatBateaux(bateau,n_bateau,bateauennemi);// si les bateaux ennemie sont detruit envoi sur le drapeau true
        }//eclairer s'il a encore des fussee
        else if((ch== 'e' || ch == 'E')&& (n_fusee>0)){
            n_fusee--;
            eclairer(adversaire);
        }//deplacer
        else if (ch == 'd' || ch =='D'){
            Deplacer(joueur,bateau,n_bateau);
        }
        //sauvegarder
        else if (ch=='s' || ch=='S'){

            sauvegarde(joueur,affichage,adversaire,bateau,bateauad,n_fusee,n_bateau);
        }
        // retour au menu
        else if(ch=='m' || ch=='M'){
            clear();
            break;
        }
        printf("\n");
        printf("TOUR DE L'IA\n");
        IAjoue(joueur,bateau,n_bateau);//l'ia tire
        bateaualliee = etatBateaux(bateau,n_bateau,bateaualliee);//si mes bateaux sont toujours en vie envoie sur le flag false
        Sleep(2000);
        clear();
    }while(!bateaualliee && !bateauennemi);
    freeFlotte(n_bateau,bateau);//libere les bateaux a la fin du jeu
    freeFlotte(n_bateau,bateauad);// libere les bateaux a la fin du jeu
    Menu();
}

bool etatBateaux(t_bateau *flotte, int n_bat,bool drapeau) {// fonction quui verifie l'etats de tous les bateaux
    for (int j = 0; j < n_bat; j++) {
        for (int i = 0; i < flotte[j].size; i++) {
            if (flotte[j].cells_state[i] == false) {//verifie si les bateaux sont toujours en vie
                drapeau = true;// les bateaux sont en vie
                return false;
            }
        }
    }
    if (drapeau == false) {// sinon la partie est fini
        printf("La partie est fini\n");
        return true;
    }
}

void ChargerPartie(){//la partie en sauvegarde
    t_save recupdata;// recupere la structure enregistrer
    recupdata = Liredatasave();
    char joueur[16][16];
    char affichage[16][16];
    char adversaire[16][16];
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            adversaire[i][j]=recupdata.adversaire[i][j];//Recupere toutes les valeurs du tableau ad
        }
    }
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            affichage[i][j]=recupdata.affichage[i][j];//pareil
        }
    }
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            joueur[i][j]=recupdata.joueur[i][j];// pareil
        }
    }
    // reinitialisation des bateua
    t_bateau *bateau;
    t_bateau *bateauad;
    bateau= &recupdata.bateau;
    bateauad = &recupdata.bateauad;
    bool bateaualliee = etatBateaux(bateau,n_bateau,bateaualliee);
    bool bateauennemi = etatBateaux(bateau,n_bateau,bateauennemi);
    int n_fusee=4;
    char ch;
    do{
        printf("GRILLE JOUEUR\n");
        affichegrille(joueur);
        printf("GRILLE AFFICHAGE\n");
        affichegrille(affichage);

        gotoligcol(30,60);
        printf("Appuyez sur une touche pour continuer.\n");
        gotoligcol(31,60);
        printf("[T] pour tirer\n");
        gotoligcol(32,60);
        printf("[D] pour deplacer\n");
        gotoligcol(33,60);
        printf("[E] pour eclaire\n");
        gotoligcol(34,60);
        printf("[S] pour sauvegarder\n");
        gotoligcol(35,60);
        printf("[M] MENU\n");
        gotoligcol(36,60);
        printf("Nombre de fusse restant %d\n",n_fusee);
        gotoligcol(36,0);
        do {
            ch = getch();
            fflush(stdin);
        }while(ch != 't' && ch!= 'T' && ch!= 'e' && ch != 'E' && ch != 'd' && ch !='D'&& ch != 's' && ch!='S'&& ch != 'm' && ch!='M'&& ch == 'v' && ch== 'V');

        if (ch == 'v' ||ch== 'V'){
            printf("\n");
            printf("GRILLE ADVERSAIRE\n");
            affichegrille(adversaire);
            printf("Rejouer\n");
            ch= getch();
            fflush(stdin);
        }
        if (ch == 't' ||ch== 'T'){
            tirer(affichage,adversaire,bateauad,n_bateau);
            bateauennemi = etatBateaux(bateau,n_bateau,bateauennemi);
        }
        else if((ch== 'e' || ch == 'E')&& (n_fusee>0)){
            n_fusee--;
            eclairer(adversaire);
        }
        else if (ch == 'd' || ch =='D'){
            Deplacer(joueur,bateau,n_bateau);
        }

        else if (ch=='s' || ch=='S'){

            sauvegarde(joueur,affichage,adversaire,bateau,bateauad,n_fusee,n_bateau);
        }
        else if(ch=='m' || ch=='M'){
            clear();
            break;
        }
        printf("\n");
        printf("TOUR DE L'IA\n");
        IAjoue(joueur,bateau,n_bateau);
        bateaualliee = etatBateaux(bateau,n_bateau,bateaualliee);
        Sleep(2000);
        clear();
    }while(!bateaualliee && !bateauennemi);
    freeFlotte(n_bateau,bateau);
    freeFlotte(n_bateau,bateauad);
    Menu();
}