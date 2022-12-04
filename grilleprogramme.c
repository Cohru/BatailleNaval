#include "grilleheader.h"
#include "bateauheader.h"


void creergrille(char grille[16][16]){
    for (int i=0;i<16;i++) {
            for (int j = 0; j < 16; j++) {
                if (i == 0) {
                    grille[i][j] = j;//ca let la premiere ligne
                } else if (i>0&&j==0){
                    grille[i][j]=96+i;//Ca ca fait les lettres
                }else{
                    grille[i][j] = NULL;//Ca ca remplie les cases par "?" avec 0x3F mettre NULL si tu veux vide
                }
            }
    }
    grille[0][0]=NULL;
}
void affichegrille(char grille[16][16]){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    for (int j=0;j<16;j++){
        if (j>9){
            printf("%i",grille[0][j]);// affiche la valeur de la grille dans la case
            if (j!=15) {
                printf("%c", 0xB3);// affiche un trait
            }
        }else if (j!=0){
            printf(" %i",grille[0][j]);//affiche les nombres des coordonnées
            printf("%c", 0xB3);
        }else{
            printf("  ");
            printf("%c", 0xB3);//trace la barre vertical entre les nombres

        }
    }
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4);
    for (int i=1;i<16;i++){
        for(int j=0;j<16;j++){
            if (j>0){
                SetConsoleTextAttribute(H,9*16+0);// couleur
            }
            printf(" %c",grille[i][j]);//affiche la valeur de la case
            if (j!=16) {
                printf("%c", 0xB3);//trace la barre vertical pour separer les cases
            }
        }
        SetConsoleTextAttribute(H,0*16+15);// couleur
        printf("\n");
    }
}