#include "Eclairerheader.h"

void eclairer(char adversaire[16][16]){
    t_coord cordo;
    do {
        printf("Saisir une case en x\n");
        scanf("%d", &cordo.y);
    }while(cordo.y >12);
    do {
        printf("Saisir une case en y\n");
        scanf("%d", &cordo.x);
    }while(cordo.x >12);
    char flash[16][16];
    creergrille(flash);
    for (int i = cordo.x; i<cordo.x+4 ;i++){
        for (int j = cordo.y;j<cordo.y+4;j++){
            flash[i][j]=adversaire[i][j];
        }
    }
    printf("Une fusee a ete utilise\n");
    affichegrille(flash);
    Sleep(5000);

}
