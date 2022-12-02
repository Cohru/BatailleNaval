#include "Sauvegardeheader.h"

void Ecriredatasave(t_save *partie){
    char n_partie[]={"save/save.dat"};
    t_save partie_data;
    partie_data= *partie;
    FILE * fp=fopen(n_partie,"wb");
    if(!fp){
        printf("errreur d'ouverture du fichier\n");
    }
    fwrite(&partie_data,sizeof(t_save),1,fp);
    fclose(fp);
}

t_save Liredatasave(char *n_partie){
    t_save partie_data;
    FILE * fp;
    fp= fopen(n_partie,"rb");
    if(!fp){
        printf("erreur d'ouverture du fichier\n");
    }
    while(1){
        fread(&partie_data,sizeof(t_save),1,fp);
        if(feof(fp)){
            break;
        }
    }
    return partie_data;
}