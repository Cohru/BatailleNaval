#include "Partieheader.h"

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
    do{
        printf("GRILLE JOUEUR\n");
        affichegrille(joueur);
        //gotolicol
        printf("GRILLE AFFICHAGE\n");
        affichegrille(affichage);

        printf("Appuyez sur une touche pour continuer.\n");
        printf("t pour tirer\n");
        printf("d pour deplacer\n");
        printf("e pour eclaire\n");
        printf("s pour sauvegarder\n");
        ch = getch();
        fflush(stdin);
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
        printf("\n");
        printf("TOUR DE L'IA\n");
        IAjoue(joueur,bateau,n_bateau);
        bateaualliee = etatBateaux(bateau,n_bateau,bateaualliee);
        Sleep(2000);
        clear();
    }while(!bateaualliee && !bateauennemi);
    freeFlotte(n_bateau,bateau);
    freeFlotte(n_bateau,bateauad);
}

bool etatBateaux(t_bateau *flotte, int n_bat,bool drapeau) {
    for (int j = 0; j < n_bat; j++) {
        for (int i = 0; i < flotte[j].size; i++) {
            if (flotte[j].cells_state[i] == false) {
                drapeau = true;
                return false;
            }
        }
    }
    if (drapeau == false) {
        printf("La partie est fini\n");
        return true;
    }
}

void ChargerPartie(){
    t_save recupdata;
    recupdata = Liredatasave();
    char joueur[16][16];
    char affichage[16][16];
    char adversaire[16][16];
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            adversaire[i][j]=recupdata.adversaire[i][j];
        }
    }
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            affichage[i][j]=recupdata.affichage[i][j];
        }
    }
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            joueur[i][j]=recupdata.joueur[i][j];
        }
    }
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
        //gotolicol
        printf("GRILLE AFFICHAGE\n");
        affichegrille(affichage);

        printf("Appuyez sur une touche pour continuer.\n");
        printf("t pour tirer\n");
        printf("d pour deplacer\n");
        printf("e pour eclaire\n");
        printf("s pour sauvegarder\n");
        ch = getch();
        fflush(stdin);
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
        printf("\n");
        printf("TOUR DE L'IA\n");
        IAjoue(joueur,bateau,n_bateau);
        bateaualliee = etatBateaux(bateau,n_bateau,bateaualliee);
        Sleep(2000);
        clear();
    }while(!bateaualliee && !bateauennemi);
    freeFlotte(n_bateau,bateau);
    freeFlotte(n_bateau,bateauad);

}