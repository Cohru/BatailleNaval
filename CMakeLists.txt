cmake_minimum_required(VERSION 3.23)
project(projet_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(projet_1 main.c grilleheader.h bateauheader.h grilleprogramme.c "bateau programme.c" Jouerheader.h Jouer.c Fdeplacerheader.h deplacerprogramme.c Eclairerheader.h eclairerfonction.c IAheader.h IAprogramme.c Partieheader.h Partieprogramme.c)
