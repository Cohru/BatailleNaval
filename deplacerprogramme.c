#include "Fdeplacerheader.h"
#include "bateauheader.h"
#include "grilleheader.h"

void Deplacer(char grille[16][16],t_bateau *flotte, int n_bateau){
    t_coord pos;
    printf("Sasir un bateau a la coordonnee en x\n");
    scanf("%d",&pos.y);
    printf("Sasir un bateau a la coordonnee en y\n");
    scanf("%d",&pos.x);
    t_bateau bateau= selectionBateau(flotte,pos,n_bateau);
    int direction;
    if (!bateau.alignement) {
        printf("Deplacer vers le haut saisir 0\n");
        printf("Deplacer vers le bas saisir 1\n");
        scanf("%d", &direction);
        if (direction == 0) {
            for (int i = bateau.pos.x; i < (bateau.size + bateau.pos.x); i++) {
                grille[i][bateau.pos.y] = NULL;
            }
            bateau.pos.x--;
            for (int i = bateau.pos.x; i < (bateau.size + bateau.pos.x); i++) {
                grille[i][bateau.pos.y] = bateau.lettre;
            }
        } else {
            for (int i = bateau.pos.x; i < (bateau.size + bateau.pos.x); i++) {
                grille[i][bateau.pos.y] = NULL;
            }
            bateau.pos.x++;
            for (int i = bateau.pos.x; i < (bateau.size + bateau.pos.x); i++) {
                grille[i][bateau.pos.y] = bateau.lettre;
            }
        }
    }
    else if (bateau.alignement){
        printf("Deplacer vers le gauche saisir 0\n");
        printf("Deplacer vers le droite saisir 1\n");
        scanf("%d",&direction);
        if (direction==0){
            for (int un = bateau.pos.y; un < (bateau.size + bateau.pos.y); un++) {
                grille[bateau.pos.x][un] = NULL;
            }
            bateau.pos.y--;
            for (int un = bateau.pos.y; un < (bateau.size + bateau.pos.y); un++) {
                grille[bateau.pos.x][un] = bateau.lettre;
            }
        }
        else{
            for (int un = bateau.pos.y; un < (bateau.size + bateau.pos.y); un++) {
                grille[bateau.pos.x][un] = NULL;
            }
            bateau.pos.y++;
            for (int un = bateau.pos.y; un < (bateau.size + bateau.pos.y); un++) {
                grille[bateau.pos.x][un] = bateau.lettre;
            }
        }
    }

}
t_bateau selectionBateau(t_bateau *bateau,t_coord ptpos, int n_bateau) {
    for (int i = 0; i < n_bateau; i++) {
        if (!bateau[i].alignement) {
            for (int m = bateau[i].pos.x; m < (bateau[i].pos.x + bateau[i].size); m++) {
                if ((m == ptpos.x) & (bateau[i].pos.y == ptpos.y)) {
                    return bateau[i];
                }
            }
        }
        else if (bateau[i].alignement) {
            for (int m = bateau[i].pos.y; m < (bateau[i].pos.y + bateau[i].size); m++) {
                if ((bateau[i].pos.x == ptpos.x) & ( m == ptpos.y)) {
                    return bateau[i];
                }
            }
        }
    }
}