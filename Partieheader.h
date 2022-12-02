#include "grilleheader.h"
#include "bateauheader.h"
#include "Jouerheader.h"
#include "Eclairerheader.h"
#include "Fdeplacerheader.h"
#include "Sauvegardeheader.h"
#include "IAheader.h"

#include <conio.h>

#define n_porteavion 1
#define n_croisseur 2
#define n_destroyer 3
#define n_sousmarin 4
#define n_bateau  n_porteavion+n_croisseur+n_destroyer+n_sousmarin
#ifndef UPDATED_UPSTREAM_PARTIEHEADER_H
#define UPDATED_UPSTREAM_PARTIEHEADER_H
void Partie();

bool etatBateaux(t_bateau *flotte, int n_bat,bool drapeau);
#endif //UPDATED_UPSTREAM_PARTIEHEADER_H
