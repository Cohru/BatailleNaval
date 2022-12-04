#include "bateauheader.h"
#include "grilleheader.h"

#ifndef PROJET_1_FDEPLACERHEADER_H
#define PROJET_1_FDEPLACERHEADER_H

void Deplacer(char grille[16][16],t_bateau *flotte, int n_bateau);
t_bateau selectionBateau(t_bateau *bateau,t_coord ptpos, int n_bateau);
#endif //PROJET_1_FDEPLACERHEADER_H
