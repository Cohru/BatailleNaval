#include "IAheader.h"

void IAjoue ( char joueur[16][16], t_bateau *flotte, int n_bateau){
    printf("L'IA joue\n");
    t_coord pos;
    pos.x= rand()%15+1;
    pos.y= rand()%15+1;
    if (joueur[pos.x][pos.y]!=NULL){
        printf("un bateau a ete toucher\n");
        printf("\n");
        trouverBateau(flotte,pos,n_bateau);
    }
    else{
        printf("L'IA n'a rien touche\n");
    }
    Sleep(1500);

}