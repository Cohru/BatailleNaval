//
// Created by nahue on 29/11/2022.
//

#include "menu.h"
void gotoligcol( int lig, int col )
{
// ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

int Menu()
{
    int ChoixMode =0;
    Color(1, 0);
    gotoligcol(1,35);
    printf("-------------------BATAILLE NAVALE---------------------\n");

    do
    {
        Color(1, 0);
        gotoligcol(5,40);
        printf("1. Jouer une partie en local\n");
        gotoligcol(7,40);
        printf("2. Charger une partie\n");//choix du mode de jeu
        gotoligcol(9,40);
        printf("3. Aide \n");
        gotoligcol(11,40);
        printf("4. Quitter \n");
        gotoligcol(13,40);
        Color(12, 0);
        printf("Appuyer sur le numero correspondant !\n");

        fflush(stdin);

        scanf("%d", &ChoixMode);
    }
    while(ChoixMode<1 || ChoixMode>4);

    if (ChoixMode == 1)
    {

        printf("Lancement de la partie \n");
    }
    else if (ChoixMode == 2)
    {
        printf("Vous reprenez votre derniere partie\n");
    }
    else if (ChoixMode == 3)
    {
        printf("Voici les regles du jeu !\n");
        aide();


    }
    else if (ChoixMode == 4)
    {
        printf("A bientot!\n");
        exit (0);
    }


    return ChoixMode;

}