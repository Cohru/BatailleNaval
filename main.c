#include "grilleheader.h vvvvlllll"
#include "bateauheader.h"
#include "Jouerheader.h"
#include "Fdeplacerheader.h"
#include "Eclairerheader.h"
int main() {
    srand(time(NULL));
    char joueur[16][16];
    char affichage[16][16];
    char adversaire[16][16];

    creergrille(joueur);
    creergrille(affichage);
    creergrille(adversaire);

    t_bateau *bateau;
    t_bateau *bateauad;

    bateau = genererFlotte(1,2,3,4,bateau);
    bateauad = genererFlotte(1,2,3,4,bateau);

    placementBateaux(10,bateau,joueur);
    placementBateaux(10,bateauad,adversaire);


    //affichegrille(&joueur);

    affichegrille(adversaire);


    eclairer(&adversaire);
    //tirer(affichage,adversaire,bateauad,10);
    //Deplacer(joueur,bateau,10);

    //affichegrille(affichage);
    affichegrille(&joueur);

    freeFlotte(10, bateau);
    //freeFlotte(10,bateauad);
    return 0;
}
