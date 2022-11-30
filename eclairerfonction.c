#include "Eclairerheader.h"

void eclairer(char **adversaire){
    t_coord cordo;
    printf("Saisir une case en x\n");
    scanf("%d",&cordo.y);
    printf("Saisir une case en y\n");
    scanf("%d",&cordo.x);
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
