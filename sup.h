#ifndef SUP_H_INCLUDED
#define SUP_H_INCLUDED


void SupprimerCat(int *nbCat,Categorie TabCat[20], int *nbType, Type TabType[20]){
    if(*nbCat ==0)
        printf("impossible de supprimer une categorie,table est vide\n");
    else{

        int position;
        printf( "choisissez parmi ces cat%cgories : \n",130);
        for(int i = 0; i<*nbCat;i++){
            printf( "id: %d | nom: %s | position: %d \n",TabCat[i].idCat, TabCat[i].NomCat,i);
        }
        do{
        printf("choisir position pour supprimer la categorie: ");
        scanf("%d",&position);
        }while(position<0 || position>=*nbCat);
        // le tableau type est vide
        if(*nbType==0){
            for (int j = position;j < *nbCat; j++)
                TabCat[j] = TabCat[j+1];
            *nbCat=*nbCat-1;
        }else{
            // le tableau type n'est pas vide
            bool existe =false;
            // le tableau TabType ne contient des types dont la catégorie est
            for(int l=0;l<*nbType;l++){
                if(strcmp(TabType[l].Cat.NomCat,TabCat[position].NomCat) == 0 && TabType[l].Cat.idCat == TabCat[position].idCat){
                    existe = true;
                    break;
                }
            }
            if(existe)
                printf("le tableau TabType contient des types dont la categorie est %s et id %d\n",TabCat[position].NomCat,TabCat[position].idCat);
            else{
                    for (int j = position; j < *nbCat; j++)
                        TabCat[j] = TabCat[j+1];
                *nbCat=*nbCat-1;
            }
        }
    }
}


void SupprimerTyp(Type TabType[20], int *nbType, Produit Stock[100][50], int TabQte[]){
    if(*nbType==0){
        printf("TabType est vide");
    }else{
        int position;
        for(int i=0;i<*nbType;i++){
            printf("id : %d | nom : %s | position : %d \n",TabType[i].idType,TabType[i].Nomtype,i);
        }
        do{
            printf("choisir position pour supprimer le type: ");
            scanf("%d",&position);
        }while(position<0 || position>=*nbType);

        if(TabQte[position]==0){
            for (int k = position; k < *nbType; k++)
            TabType[k] = TabType[k+1];
            *nbType=*nbType-1;
        }else{
           printf("la matrice Stock  contient  des produits dont le type est %s, la suppression ne peut pas  etre effectue\n",TabType[position].Nomtype);
        }
    }
}

void SupprimerPdt(int TabQte[50], int *nbType, Produit Stock[100][50]){

    bool v=false;
    for(int i=0;i<*nbType;i++){
            // v resultat peut etre supprimer ou non
        if(TabQte[i]>2){
                v= true;
            for(int j=0;j<TabQte[i];j++){
                printf("id : %d | nom : %s | Ligne :%d | Colonne : %d \n",Stock[i][j].id,Stock[i][j].nom, i,j);
            }
        }
    }
    if(v==false){
        printf("Il n'y a pas des produits du Type correspondant ont des quantites superieur a 2\n");
    }else{
        int l,c;
        do{
        printf("entrer Ligne :");
        scanf("%d",&l);
        }while((TabQte[l]>10)==false);
        printf("entrer colonne:");
        scanf("%d",&c);
        for(int k=c;k<50;k++)
            Stock[l][k]=Stock[l][k+1];
        *nbType=*nbType-1;
        TabQte[l]--;
    }
}

#endif // SUP_H_INCLUDED
