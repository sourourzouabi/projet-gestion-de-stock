#ifndef AJOUT_H_INCLUDED
#define AJOUT_H_INCLUDED

void AjouterCat(int *nbCat,Categorie TabCat[20]){
    if(*nbCat<20){
        Categorie cat;
        InitCat(&cat);
        bool verif =false;
        for(int i=0;i<*nbCat;i++){
                // strcmp pour la comparaison entre deux chaines de caractere
            if(strcmp(TabCat[i].NomCat , cat.NomCat) == 0 || TabCat[i].idCat == cat.idCat){
                verif= true;
                break;
            }
        }
        if(verif == true){
            printf( "La categorie existe deja! \n");
        }else{
            TabCat[*nbCat]= cat;
            printf("ajouter avec succes \n");
            *nbCat=*nbCat+1;
        }
    }else{
        printf("impossible d'ajouter une categorie, espace plein \n");
    }
}



void AjouterTyp(int *nbType,int *nbCat, Categorie TabCat[20],Type TAbType[20]){

    if(*nbType <50){
        printf( "choisissez parmi ces categories : \n");
        //afficher id et nom des categories
        for(int i = 0; i<*nbCat;i++){
            printf( "id: %d | nom: %s \n",TabCat[i].idCat, TabCat[i].NomCat);
        }

        Type type;
        InitType(&type);
        // chercher l'absence de type
        bool verifType =false;

        for(int i=0;i<*nbType;i++){
        if(strcmp(TAbType[i].Nomtype,type.Nomtype) == 0 && TAbType[i].idType == type.idType){
            verifType= true;
        }
        }
        if(verifType){
            printf( "Le type existe deja! \n");
        }else{
            bool existeCat=false;
            //chercher l'existance categorie
            for(int j=0;j<*nbCat;j++){
                if(strcmp(TabCat[j].NomCat,type.Cat.NomCat) == 0 && TabCat[j].idCat == type.Cat.idCat){
                existeCat = true;
                break;
                }
            }
            if(existeCat){
                    TAbType[*nbType] = type;
                printf("ajouter avec succecs \n");

                *nbType=*nbType+1;
            }else{
                printf("La catecgorie n'existe pas \n");
            }
    }
}else{
        printf("impossible d'ajouter un type, espace sature \n");

        }
}


void AjouterPdt(Produit Stock[100][50], Type TabType[20], int TabQte[50], int *nbType){
    Produit pdt;
    //affichage type et cat de type
    for (int i=0; i<*nbType; i++){
        printf("id type :%d | nomtype : %s |id categorie : %d | nom categorie : %s \n",TabType[i].idType,TabType[i].Nomtype,TabType[i].Cat.idCat,TabType[i].Cat.NomCat);
    }
    InitPdt(&pdt);
    bool existeType =false;
    // verifier l'existance de type
    int position;
    for(int i=0;i<*nbType;i++){
        if((strcmp(TabType[i].Nomtype , pdt.type.Nomtype) == 0 )&&(TabType[i].idType == pdt.type.idType)){
            existeType = true;
            position=i;
            break;
        }
    }
    if(existeType ==true){
        bool existeProduit =false;
        //verifier l'existance de produit
        for(int c=0; c<TabQte[position];c++){
            if(Stock[position][c].id == pdt.id &&strcmp(Stock[position][c].nom,pdt.nom)==0 &&Stock[position][c].dateexpiration.AA==pdt.dateexpiration.AA &&
                 Stock[position][c].dateexpiration.JJ==pdt.dateexpiration.JJ &&Stock[position][c].dateexpiration.MM==pdt.dateexpiration.MM ){
                existeProduit=true;
                break;
            }
        }
        if(existeProduit==false){
            int indice=TabQte[position];
            Stock[position][indice]=pdt;
            TabQte[position]++;
        }else{
            printf("Le produit existe \n");
        }
    }else{
        printf("Veuillez creer le type d'abord !\n");
    }
}


// Définir les fonctions de vente et statistiques
void VendrePdt(int *nbCat, int *nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]) {
    // Ajoutez le code pour vendre un produit ici
    printf("Saisir l'identifiant du produit à vendre : ");
    int indiceProduitAVendre;
    scanf("%d", &indiceProduitAVendre);
    printf("Saisir l'identifiant du type du produit à vendre : ");
    int idTypeAVendre;
    scanf("%d", &idTypeAVendre);
    int i,j,s1,s2,a,b;
    s1=s2=0;
    for(i=0;i<50;i++)
    {
        if(idTypeAVendre==TabType[i].idType)
        {
            s1=1;
            i=50;
        }
    }
    if(s1==1)
    {
        for(i=0;i<100;i++)
        {
            for(j=0;j<50;j++)
            {
                if(Stock[i][j].id==indiceProduitAVendre && Stock[i][j].type.idType==idTypeAVendre)
                {
                    s2=1;
                    a=i;
                    b=j;
                    i=100;
                    j=50;
                }
            }
        }
        if(s2==1)
        {
             Stock[a][b].id = 0;
        TabQte[idTypeAVendre]--;
        printf("Le produit a été vendu avec succès.\n");
        MaDate dte;
        time_t now;
        time(&now);
        struct tm *localTime = localtime(&now);
        printf("entrez la date de vente");
        scanf("%d %d %d",&dte.JJ,&dte.MM,&dte.AA);
        FILE*f=fopen("trace.txt","a");
        fprintf(f,"%4d\t%s\t%2d\t%s\t%2d\t%s\t%2d\t%2d\t%4d\n",Stock[a][b].id,Stock[a][b].nom, Stock[a][b].type.idType, Stock[a][b].type.Nomtype, Stock[a][b].type.Cat.idCat, Stock[a][b].type.Cat.NomCat,localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
        fclose(f);
        }
        else
        {
            printf("le produit n'existe pas");
        }
    }
    else
    {
        printf("le type n'existe pas");
    }
}


void StatMois(Categorie TabCat[20]) {
    int mois, annee;
    Produit p;
    MaDate dte;
    char c;
    // Demander à l'utilisateur le mois et l'année pour les statistiques
    printf("Saisir le mois (MM) : ");
    scanf("%d", &mois);

    printf("Saisir l'année (AAAA) : ");
    scanf("%d", &annee);

    // Initialiser les compteurs de statistiques
    int nombreTotalVentes = 0;
    int nombreVentesParCategorie[20] = {0};
    int nombreVentesParAnnee,i = 0;
    FILE*f=fopen("trace.txt","r");
    // Parcourir trace pour calculer les statistiques
    while(c!='*')
    {
        fscanf(f,"%4d\t%s\t%2d\t%s\t%2d\t%s\t%2d\t%2d\t%4d\n",&p.id,p.nom, &p.type.idType, p.type.Nomtype,&p.type.Cat.idCat, p.type.Cat.NomCat,&dte.JJ,&dte.MM,&dte.AA);
        fscanf(f,"%c",&c);
        fseek(f,-1,SEEK_CUR);
        if( dte.MM==mois && dte.AA==annee)
        {
            nombreTotalVentes++;
            for(i=0;i<20;i++)
            {
                if(strcmp(p.type.Cat.NomCat,TabCat[i].NomCat)==0)
                {
                    nombreVentesParCategorie[i]++;
                }
            }
        }
    }
    fclose(f);
    // Afficher les statistiques par mois
    printf("Statistiques pour le mois %d de l'année %d :\n", mois, annee);
    printf("Nombre total de ventes : %d\n", nombreTotalVentes);

    // Afficher le nombre de ventes par catégorie
    printf("Nombre de ventes par catégorie :\n");
    for (int i = 0; i < 20; i++) {
        printf("%s : %d\n", TabCat[i].NomCat, nombreVentesParCategorie[i]);
    }

    }



void StatAnnee(Categorie TabCat[20]) {
    int mois, annee;
    Produit p;
    MaDate dte;
    char c;
    printf("Saisir l'année (AAAA) : ");
    scanf("%d", &annee);

    // Initialiser les compteurs de statistiques
    int nombreTotalVentes = 0;
    int nombreVentesParCategorie[20] = {0};
    int nombreVentesParAnnee,i = 0;
    FILE*f=fopen("trace.txt","r");
    // Parcourir trace pour calculer les statistiques
    while(c!='*')
    {
        fscanf(f,"%4d\t%s\t%2d\t%s\t%2d\t%s\t%2d\t%2d\t%4d\n",&p.id,p.nom, &p.type.idType, p.type.Nomtype,&p.type.Cat.idCat, p.type.Cat.NomCat,&dte.JJ,&dte.MM,&dte.AA);
        fscanf(f,"%c",&c);
        fseek(f,-1,SEEK_CUR);
        if( dte.AA==annee)
        {
            nombreTotalVentes++;
            for(i=0;i<20;i++)
            {
                if(strcmp(p.type.Cat.NomCat,TabCat[i].NomCat)==0)
                {
                    nombreVentesParCategorie[i]++;
                }
            }
        }
    }
    fclose(f);
    // Afficher les statistiques par mois
    printf("Statistiques pour le mois %d de l'année %d :\n", mois, annee);
    printf("Nombre total de ventes : %d\n", nombreTotalVentes);

    // Afficher le nombre de ventes par catégorie
    printf("Nombre de ventes par catégorie :\n");
    for (int i = 0; i < 20; i++) {
        printf("%s : %d\n", TabCat[i].NomCat, nombreVentesParCategorie[i]);
    }
    }


#endif // AJOUT_H_INCLUDED
