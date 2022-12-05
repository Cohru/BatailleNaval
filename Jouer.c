#include "Jouerheader.h"
#include "bateauheader.h"
#include "grilleheader.h"
void tirer (char affichage[16][16], char adversaire[16][16], t_bateau *flotte, int n_bateau){
    t_coord pos;//demande au joueur ou tirer
    printf("\n");
    printf("Sasir une coordonnee en x\n");
    scanf("%d",&pos.y);
    printf("Sasir une coordonnee en y\n");
    scanf("%d",&pos.x);
    if (adversaire[pos.x][pos.y]!=NULL){//si la case contient un bateau
        affichage[pos.x][pos.y]=0x54;// le remplace par T
        trouverBateau(flotte,pos,n_bateau);//on retouve le bateau positionner sur la case cibler
        printf("Un bateau a ete touche\n");
    }
    else{
        affichage[pos.x][pos.y]=0x45;//sinon affiche E
    }
}

void trouverBateau(t_bateau *bateau,t_coord ptpos, int n_bateau) {
    int compteur=0;//on trouve le bateau positionner a la case
    for (int i = 0; i < n_bateau; i++) {
        if (!bateau[i].alignement) {
            for (int m = bateau[i].pos.x; m < (bateau[i].pos.x + bateau[i].size); m++) {//on avance par rapport a la postion du bateau et sa taille
                if ((m == ptpos.x) & (bateau[i].pos.y == ptpos.y)) {// si un bateau possede les coodonnee egale a la case
                    bateau[i].cells_state[compteur] = true;//change une case du bateau en true car il est touché
                    verifieBateau(bateau[i]);//verifie l'etat du bateau

                    break;
                }
                compteur++;//pour savoir quel case du bateau est touche
            }
        }
        else if (bateau[i].alignement) {
            for (int m = bateau[i].pos.y; m < (bateau[i].pos.y + bateau[i].size); m++) {
                if ((bateau[i].pos.x == ptpos.x) & ( m == ptpos.y)) {
                    bateau[i].cells_state[compteur] = true;
                    verifieBateau(bateau[i]);
                    break;
                }
                compteur++;
            }
        }
    compteur=0;
    }
}
void verifieBateau(t_bateau bateau) {
    bool coule = true;
    for (int i = 0; i < bateau.size; i++) {
        if (bateau.cells_state[i] == false) {// si le bateau a toujours une case non toucher
            coule = false;// le bateau n'est pas coule
        }
    }
    if (coule == true) {
        printf("le bateau est coule\n");
    }

}