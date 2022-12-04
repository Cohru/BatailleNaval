#include "Sauvegardeheader.h"

void Ecriredatasave(t_save *partie){//ecrit les informations dans le fichier sauvegarde la structure avec toutes les informations
    char n_partie[]={"save.dat"};
    t_save partie_data;
    partie_data= *partie;
    FILE * fp=fopen(n_partie,"wb");// pointe l'adresse du fichier
    if(!fp){//fonction d'erreur
        printf("errreur d'ouverture du fichier\n");
    }
    fwrite(&partie_data,sizeof(t_save),1,fp);// ecrit la structure en binaire dans le fichier
    fclose(fp);
}

t_save Liredatasave(){//recupere la strucure sauvegarder dans le fichier
    t_save partie_data;
    FILE * fp;
    fp= fopen("save.dat","rb");
    if(!fp){
        printf("erreur d'ouverture du fichier\n");
    }
    while(1){
        fread(&partie_data,sizeof(t_save),1,fp);//lecture du fichier
        if(feof(fp)){
            break;
        }
    }
    return partie_data;
}

t_save remplissagestructure(char joueur[16][16],char affichage[16][16],char adversaire[16][16],t_bateau *bateau,t_bateau *bateauad,int n_fusee, int n_bat){
    t_save savegarde_data;//renvoie toutes les informations dans des variables adaptes
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            savegarde_data.affichage[i][j]=affichage[i][j];
        }
    }
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            savegarde_data.joueur[i][j]=joueur[i][j];
        }
    }
    for (int i =0;i<16;i++){
        for (int j = 0;j<16;j++){
            savegarde_data.adversaire[i][j]=adversaire[i][j];
        }
    }
    savegarde_data.bateau= malloc(sizeof(t_bateau)*n_bat);// realloue le nombre de bateaux
    savegarde_data.bateauad= malloc(sizeof(t_bateau)*n_bat);
    for (int k=0;k<n_bat;k++){
        savegarde_data.bateau[k]=bateau[k];
    }
    for (int m=0;m<n_bat;m++){
        savegarde_data.bateauad[m]=bateauad[m];
    }
    savegarde_data.n_fusee=n_fusee;

    return savegarde_data;
}

void sauvegarde(char joueur[16][16],char affichage[16][16],char adversaire[16][16],t_bateau *bateau,t_bateau *bateauad,int n_fusee, int n_bat){
    t_save data;// fonction sauvegarde pour appeler directement dans le jeu
    data = remplissagestructure(joueur,affichage,adversaire,bateau,bateauad,n_fusee,n_bat);
    Ecriredatasave(&data);
    printf("La partie est sauvegarder\n");
}