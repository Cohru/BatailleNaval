#include "Partieheader.h"

void Partie(){
    char ch;
    bool bateaualliee = false;
    bool bateauennemi = false;
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
    int n_fusee=4;
    do{
        affichegrille(joueur);
        //gotolicol
        affichegrille(affichage);

        printf("Appuyez sur une touche pour continuer.\n");
        ch = getch();
        fflush(stdin);
        if (ch == 't' ||ch== 'T'){
            tirer(affichage,adversaire,bateauad,n_bateau);
        }
        else if((ch== 'e' || ch == 'E')&& (n_fusee>0)){
            n_fusee--;
            //eclairer(adversaire);
        }
        else if (ch == 'd' || ch =='D'){
            Deplacer(joueur,bateau,n_bateau);
        }
        /*
        else if (ch=="s"||ch=="S"){
            //Sauvegarder
        }*/
        IAjoue(joueur,bateau,n_bateau);

    }while(!etatBateaux(bateau,n_bateau,bateaualliee) && !etatBateaux(bateau,n_bateau,bateauennemi));
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