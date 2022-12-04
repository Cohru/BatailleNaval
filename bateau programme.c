 #include "grilleheader.h"
#include "bateauheader.h"
t_bateau newBateau( e_aligne alignement, e_type type,t_coord posi,size_t size, char lettre) {
    t_bateau new_bateau;
    new_bateau.alignement = alignement;
    new_bateau.size = size;
    new_bateau.type = type;
    new_bateau.lettre=lettre;
    new_bateau.pos= posi;
    new_bateau.cells_state = (bool*) malloc(sizeof(bool) * size);
    return new_bateau;
}

void freeBateau(t_bateau *bat) {
    free(bat->cells_state);

}
t_bateau Creationbat(e_type type) {
    e_aligne ligne = rand()%2;
    size_t size;
    char lettre;
    t_coord pos;
    pos.x = NULL;
    pos.y= NULL;
    switch(type){
        case PORTE_AVION:
            size=tporte_avion;
            lettre = 0x50;
            break;
        case CROISEUR:
            size=tcroiseur;
            lettre = 0x43;
            break;
        case DESTROYER:
            size=tdestroyer;
            lettre = 0x44;
            break;
        case SOUS_MARIN:
            size=tsousmarin;
            lettre = 0x53;
            break;
    }

    return  newBateau(ligne, type, pos,size,lettre);
}

t_bateau placementBateau(char tableau[16][16], t_bateau bat) {
    bool mal_placer = false;

    if(bat.alignement==VERTICAL) {//si c'est horizontal
        do {
            mal_placer = false; //retomber le flag
            //calcule des coordonnées
            bat.pos.x = rand() % (16 - bat.size) + 1;
            bat.pos.y = rand() % 16 + 1;
            for (int m = bat.pos.x; m < (bat.pos.x + bat.size); m++) {//verifie si les cases sont libres
                if (tableau[m][bat.pos.y] != NULL) {
                    mal_placer = true;
                    break;
                }
            }
        }while (mal_placer);
    }
    else if (bat.alignement==HORIZONTAL) {
        do {
            mal_placer = false;
            bat.pos.x = rand() % 16 + 1;
            bat.pos.y = rand() % (16 - bat.size) + 1;
            for (int m = bat.pos.y; m < (bat.pos.y + bat.size) ; m++) {//verifie si les cases sont libres
                if (tableau[bat.pos.x][m] != NULL) {
                    mal_placer = true;
                    break;
                }
            }
        } while (mal_placer);
    }
    if(bat.alignement) {
        for (int un = bat.pos.y; un < (bat.size + bat.pos.y); un++) {
            tableau[bat.pos.x][un] = bat.lettre;
        }
    }
    else if(!bat.alignement){
        for (int i = bat.pos.x; i < (bat.size+bat.pos.x); i++) {
            tableau[i][bat.pos.y] = bat.lettre;
        }
    }

    return newBateau(bat.alignement,bat.type,bat.pos,bat.size,bat.lettre);
}
void placementBateaux(int n_bateau, t_bateau *flotte, char tableau[16][16]){
    for (int i = 0; i < n_bateau; i++) {
        flotte[i]=placementBateau(tableau,flotte[i]);
    }
}

t_bateau * genererFlotte(int n_bateauP,int n_bateeauC,int n_bateauD,int n_bateauS,t_bateau *bateau){
    bateau = (t_bateau*) malloc(sizeof(t_bateau)*(n_bateauP+n_bateeauC+n_bateauD+n_bateauS));
    int compteur = 0;
    for (int i = 0; i < n_bateauP; i++) {
        bateau[i]= Creationbat(PORTE_AVION);
    }
    compteur+=n_bateauP;
    for (int j = compteur; j < (compteur+n_bateeauC);j++){
        bateau[j]= Creationbat(CROISEUR);
    }
    compteur+=n_bateeauC;
    for (int k = compteur; k <(compteur+n_bateauD);k++){
        bateau[k]= Creationbat(DESTROYER);
    }
    compteur += n_bateauD;
    for (int m = compteur;m < (compteur + n_bateauS);m++){
        bateau[m]= Creationbat(SOUS_MARIN);
    }
    return bateau;
}

void freeFlotte(int n_bateau, t_bateau *flotte)
{
    for (int i = 0 ; i < n_bateau ;i++){
        freeBateau(&flotte[i]);
    }
    free(flotte);
}
