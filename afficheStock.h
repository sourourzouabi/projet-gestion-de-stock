#ifndef AFFICHESTOCK_H_INCLUDED
#define AFFICHESTOCK_H_INCLUDED




void afficherStock(int *nbCat, int *nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
printf("**********************************************************\n");
printf("*Etat du stock:                                          *\n");
printf("*                                                        *\n");
printf("*Categorie\tType\tQte\tid-Pdt\tdate_exp\t *\n");
printf("*--------------------------------------------------------*\n");
for(int i=0;i<*nbCat;i++){
printf("*%s",TabCat[i].NomCat);
for(int j=0;j<*nbType;j++){
    if(strcmp(TabCat[i].NomCat,TabType[j].Cat.NomCat)==0&&TabCat[i].idCat == TabType[j].Cat.idCat){
        printf("\t%s\t%d ",TabType[j].Nomtype,TabQte[j]);
            for(int k=0;k<TabQte[j];k++){
                if(k>0){
                    printf("*\t\t\t ");
                }
                printf("\t%d\t%d/%d/%d\t *\n",Stock[j][k].id,Stock[j][k].dateexpiration.JJ,Stock[j][k].dateexpiration.MM,Stock[j][k].dateexpiration.AA);
            }
            if(TabQte[j]>1 &&TabQte[j]<=2){
                  printf("*\t");
              }
    }
}
}
printf("*--------------------------------------------------------*\n");
}

#endif // AFFICHESTOCK_H_INCLUDED
