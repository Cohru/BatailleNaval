//
// Created by nahue on 29/11/2022.

//
#include"menu.h"
void aide(){
    gotoligcol(20,45);
    printf("CARACTERISTIQUE DU JEU:\n");
    gotoligcol(22,0);
    printf("Chaque joueur (vous et l'ordinateur) dispose de deux grilles de  15x15 cases: \n");
    printf("- une premiere grille pour poser et visualiser ses propres navires\n");
    printf("- une deuxieme grille pour visualiser les degats causes a l'adversaire\n");
    printf("Chaque joueur possede une flotte de 10 navires:\n");
    printf("- 1 porte-avion (lettre P) et possedant une taille de 7 cases \n");
    printf("- 2 croiseurs (lettre C) et possedant une taille de 5 cases\n");
    printf("- 3 destroyers (lettre D) et possedant une taille de 3 cases\n");
    printf("- 4 sous-marins (lettre S) et possedant une taille de 1 case\n");
    printf("Ces navires sont places aleatoirement en debut de partie\n");
    printf("REGLES DU JEU:\n");
    printf("Chaque joueur joue a chaque tour de role, en choisissant a chaque tour une des trois actions:\n");
    printf("-Tirer: le joueur tire en choisissant les cordonnees, de 'a' a 'o' pour les lignes et de 0 a 15 pour les colonnes \n");
    printf("(  Si le tir tombe a l'eau, la lettre E apparait sur la grille 2)\n");
    printf("(  Si le tir touche un navire adverse, la lettre de T apparait sur la grille 2\n");
    printf("-Eclairer: Vous disposez de 4 fusee. Le tire d'une de ces fusees devoile un carre de 4x4 cases\n");
    printf("   Cette fusee ne revele que pendant quelques secondes la zone indiquee pendant votre tour\n");
    printf("-Deplacer: vous pouvez deplacer un de vos navire d'une seule case meme etant touche\n");
    printf("   Vous pouvez seulement vous deplacer de maniere horizontale et verticale pour cela il faut indiquer les coordonnees de destination\n");
    printf(" Le premier a couler tous les bateaux ennemis gagne !");
}