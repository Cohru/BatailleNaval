#include"menu.h"
void aide() {
    char ch;
    gotoligcol(0, 45);
    Color(15, 0);
    printf("CARACTERISTIQUE DU JEU:\n");
    printf("\n");

    printf("Chaque joueur (vous et l'ordinateur) dispose de deux grilles de  15x15 cases: \n");
    printf("- une premiere grille pour poser et visualiser ses propres navires\n");
    printf("- une deuxieme grille pour visualiser les degats causes a l'adversaire\n");

    printf("Chaque joueur possede une flotte de 10 navires:\n");
    printf("- 1 porte-avion (lettre P) et possedant une taille de 7 cases \n");
    printf("- 2 croiseurs (lettre C) et possedant une taille de 5 cases\n");
    printf("- 3 destroyers (lettre D) et possedant une taille de 3 cases\n");
    printf("- 4 sous-marins (lettre S) et possedant une taille de 1 case\n");
    printf("Ces navires sont places aleatoirement en debut de partie\n");
    gotoligcol(12, 45);
    printf("REGLES DU JEU:\n");
    printf("\n");
    printf("Chaque joueur joue a chaque tour de role, en choisissant a chaque tour une des trois actions:\n");
    printf("-Tirer (touche [T]): le joueur tire en choisissant les cordonnees, de 'a' a 'o' pour les lignes et de 0 a 15 pour les colonnes\n");
    printf(" Si le tir tombe a l'eau, la lettre E apparait sur la grille 2 et si le tir touche un navire adverse, la lettre T apparait\n");
    printf("-Eclairer (touche [E]): vous disposez de 4 fusee. Le tire d'une de ces fusees devoile un carre de 4x4 cases,cette fusee ne revele\n que pendant quelques secondes la zone indiquee pendant votre tour\n");
    printf("-Deplacer (touche [D]): vous pouvez deplacer un de vos navire d'une seule case meme en etant touche, vous pouvez seulement vous\n deplacer de maniere horizontale et verticale pour cela il faut indiquer les coordonnees de destination\n");
    printf("\n");
    printf("Vous pouvez sauvegarder votre partie a tout moment en appuyant sur [S]\n");
    printf("\n");
    printf("Le premier a couler tous les bateaux ennemis gagne !\n");

    gotoligcol(30, 90);
    Color(1, 0);
    printf("[M] MENU\n");
    ch = getch();
    if (ch == 'M') {
        clear();
        Menu();
    }
    else{
        clear();
        gotoligcol(31, 90);
        Color(12, 0);
        printf("Mauvaise touche");
        aide();

    }



}