#include "Eclairerheader.h"

void eclairer(char adversaire[16][16]){
    t_coord cordo;//creation des coodonnee
    do {
        printf("Saisir une case en x\n");
        scanf("%d", &cordo.y);//demande d'une case en ordonnée
    }while(cordo.y >12);
    do {
        printf("Saisir une case en y\n");
        scanf("%d", &cordo.x);//demande d'une case en abscisse
    }while(cordo.x >12);
    char flash[16][16];//creation d'une grille que l'on va afficher
    creergrille(flash);
    for (int i = cordo.x; i<cordo.x+4 ;i++){
        for (int j = cordo.y;j<cordo.y+4;j++){//boucle pour parcourir tout le tableau
            flash[i][j]=adversaire[i][j];//recupere l'information de toutes les cases
        }
    }
    printf("Une fusee a ete utilise\n");
    affichegrille(flash);
    Sleep(5000);//pause pour voir
}
