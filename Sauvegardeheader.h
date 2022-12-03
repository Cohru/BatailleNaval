#include "grilleheader.h"
#include "bateauheader.h"
typedef struct{
    char joueur[16][16];
    char affichage[16][16];
    char adversaire[16][16];
    t_bateau *bateau;
    t_bateau *bateauad;
    int n_fusee;
}t_save;

#ifndef UPDATED_UPSTREAM_SAUVEGARDEHEADER_H
#define UPDATED_UPSTREAM_SAUVEGARDEHEADER_H
void Ecriredatasave(t_save *partie);
t_save Liredatasave();
t_save remplissagestructure(char joueur[16][16],char affichage[16][16],char adversaire[16][16],t_bateau *bateau,t_bateau *bateauad,int n_fusee, int n_bat);
void sauvegarde(char joueur[16][16],char affichage[16][16],char adversaire[16][16],t_bateau *bateau,t_bateau *bateauad,int n_fusee, int n_bat);
#endif //UPDATED_UPSTREAM_SAUVEGARDEHEADER_H
