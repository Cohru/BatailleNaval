#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bateauheader.h"
#ifndef PROJET_1_JOUERHEADER_H
#define PROJET_1_JOUERHEADER_H

void tirer (char affichage[16][16], char adversaire[16][16], t_bateau *bateau, int n_bateau);
void verifieBateau(t_bateau bateau);
void trouverBateau(t_bateau *bateau,t_coord pos, int n_bateau);
#endif //PROJET_1_JOUERHEADER_H
