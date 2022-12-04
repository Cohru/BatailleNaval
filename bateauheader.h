#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>



#ifndef PROJET_1_BATEAUHEADER_H
#define PROJET_1_BATEAUHEADER_H

#define tporte_avion 7
#define tcroiseur 5
#define tdestroyer 3
#define tsousmarin 1


typedef enum  {
    VERTICAL = 0,
    HORIZONTAL
}e_aligne;

typedef enum  {
    SOUS_MARIN = 0,
    CROISEUR,
    DESTROYER,
    PORTE_AVION
}e_type;

typedef struct  {
    unsigned int x;
    unsigned int y;
}t_coord;

typedef struct  {// toutes les informations qu'un bateau a besoin
    t_coord pos;// des coordonnées
    e_aligne alignement;// sa direction
    e_type type;//sont type
    size_t size;// sa taille
    char lettre;// la lette qu'elle represente
    bool *cells_state;// l'etat dans le quel il est
}t_bateau;

void freeBateau(t_bateau *bat);

t_bateau Creationbat(e_type type);

t_bateau placementBateau(char tableau[16][16], t_bateau bat);
t_bateau * genererFlotte(int n_bateauP,int n_bateeauC,int n_bateauD,int n_bateauS,t_bateau *bateau);
void placementBateaux(int n_bateau, t_bateau *flotte, char tableau[16][16]);

void freeFlotte(int n_bateau, t_bateau *flotte);//je n'arrive pas a le faire fonctionner



#endif //PROJET_1_BATEAUHEADER_H
