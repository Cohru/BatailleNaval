//
// Created by nahue on 29/11/2022.
//

#include "menu.h"
void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

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
    gotoligcol(0,35);
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

        printf("Lancement de la partie \n");

    }
    else if (ChoixMode == 2)
    {

        printf("Vous reprenez votre derniere partie\n");
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