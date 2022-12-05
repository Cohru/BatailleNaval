#include "menu.h"
#include "grilleheader.h"
#include "bateauheader.h"
#include "Jouerheader.h"
#include "Fdeplacerheader.h"
#include "Eclairerheader.h"
#include "Partieheader.h"

void gotoligcol( int lig, int col )// fonction qui positionne le texte pcq + beau
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

int Menu()// la fonction menu
{
    int ChoixMode =0;
    Color(1, 0);
    gotoligcol(0,50);
    printf("-------------------BATAILLE NAVALE---------------------\n");


    do
    {
        Color(1, 0);
        gotoligcol(2,40);
        printf("1. Jouer une partie en local\n");
        gotoligcol(4,40);
        printf("2. Charger une partie\n");//choix du mode de jeu
        gotoligcol(6,40);
        printf("3. Aide \n");
        gotoligcol(8,40);
        printf("4. Quitter \n");
        gotoligcol(10,40);
        Color(12, 0);
        printf("Appuyer sur le numero correspondant !\n");



        fflush(stdin);
        scanf("%d", &ChoixMode);

    }


    while(ChoixMode<1 || ChoixMode>4);


    if (ChoixMode == 1)
    {
        clear();
        Partie();

    }
    else if (ChoixMode == 2)
    {
        clear();
        ChargerPartie();
    }
    else if (ChoixMode == 3)
    {
        clear();
        aide();


    }
    else if (ChoixMode == 4)
    {

        printf("A bientot!\n");
        exit (0);
    }


    return ChoixMode;

}