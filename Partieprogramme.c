#include "Partieheader.h"

void Partie(){
    char ch;
    bool bateaualliee,bateauennemi;
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
    do{
        printf("Appuyez sur une touche pour continuer.\n");
        ch = getch();
        printf ("Vous avez appuyé sur la touche %c.\n", ch);

    }while(bateaualliee||bateauennemi);

}