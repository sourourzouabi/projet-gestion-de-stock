#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<windows.h>

void afficherMenu(int *nbCat, int *nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[])
{
    int choix;
    do{
    printf("* veuillez choisir une option : \t\t\t *\n");
    printf("* 0- quittez le programme \t\t\t\t *\n");
    printf("* 1- Gestion de stock \t\t\t\t\t *\n");
    printf("* 2- Vente et Statistiques \t\t\t\t *\n");
    do{
    printf("* >>tapez votre choix : \t\t\t\t *");
    scanf("%d",&choix);
    }while(choix<0||choix>2);
    if (choix==1){
        afficherMenuGestionStock(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if (choix==2){
        afficherMenuVenteStat(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }

    }while(choix !=0);

}


void afficherMenuGestionStock(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choix;
    system("cls");
    do{
    printf("**********************************************************\n");
    printf("**********\t\tBIENVENU\t\t**********\n");
    printf("**********************************************************\n");
    printf("* veuillez choisir une option : \t\t\t *\n");
    printf("* 1- Gestion de Categories \t\t\t\t *\n");
    printf("* 2- Gestion des types \t\t\t\t\t *\n");
    printf("* 3- Gestion des produits \t\t\t\t *\n");
    printf("* 4- Affichage du stock \t\t\t\t *\n");
    printf("* 0- Retour Menu Principal \t\t\t\t *\n");

    do{
    printf("* >>tapez votre choix : \t\t\t\t * ");
    scanf("%d",&choix);
    }while(choix<0||choix>4);
    if (choix==0)
    {
        afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if (choix==1){
        afficherMenuGestionCat(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choix==2){
        afficherMenuGestionType(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choix==3){
        afficherMenuGestionProduit(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choix==4){
        afficherStock(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }


    }while(choix !=0);
}



void afficherMenuGestionCat(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choix;
    system("cls");
    do{
    printf("**********************************************************\n");
    printf("**********\t\tBIENVENU\t\t**********\n");
    printf("**********************************************************\n");
    printf("* veuillez choisir une option : \t\t\t *\n");
    printf("* 1- Ajout d'une nouvelle Categorie \t\t\t *\n");
    printf("* 2- Suppression d'une Categories \t\t\t *\n");
    printf("* 0- Retour Menu Principal \t\t\t\t *\n");

    do{
    printf("* >>tapez votre choix : \t\t\t\t *");
    scanf("%d",&choix);
    }while(choix<0 || choix>2);
    if (choix==0)
    {

        afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
    }
    if(choix==1){
        AjouterCat(nbCat,TabCat);
    }

    if(choix==2){
        SupprimerCat(nbCat, TabCat, nbType, TabType);
    }

    }while(choix != 0);
}



void afficherMenuGestionType(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choix;
system("cls");
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 1- Ajout d'un nouveau Type \t\t\t\t *\n");
        printf("* 2- Suppression d'un Type \t\t\t\t *\n");
        printf("* 0- Retour Menu Principal \t\t\t\t *\n");

            do{
                printf("* >>tapez votre choix : \t\t\t\t *");
                scanf("%d",&choix);
            }while(choix<0||choix>2);
        if (choix==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if (choix==1){
            AjouterTyp(nbType,nbCat, TabCat,TabType);
        }
        if (choix==2){
            SupprimerTyp(TabType, nbType, Stock, TabQte);
        }
    }while(choix !=0);
}



void afficherMenuGestionProduit(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
system("cls");
    int choix;
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 1- Ajout d'un nouveau Produit \t\t\t\t *\n");
        printf("* 2- Suppression dn Produit \t\t\t\t *\n");
        printf("* 0- Retour Menu Principal \t\t\t\t\t *\n");

        do{
            printf("* >>tapez votre choix : \t\t\t\t *");
            scanf("%d",&choix);
        }while(choix<0||choix>2);
        if (choix==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if (choix==1){
            AjouterPdt(Stock, TabType, TabQte, nbType);
        }
        if (choix ==2){
            SupprimerPdt(TabQte,nbType,Stock);
        }

    }while(choix !=0);
}



void afficherMenuVenteStat(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choix;
    system("cls");
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 1- Vente de produits \t\t\t\t\t *\n");
        printf("* 2- Statistique \t\t\t\t\t *\n");
        printf("* 0- Menu Principal \t\t\t\t\t *\n");

        do{
            printf("* >>tapez votre choix : \t\t\t\t *");
            scanf("%d",&choix);
        }while(choix<0||choix>2);

        if (choix==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
                if (choix==1){
            afficherMenuventePdt(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if (choix==2){
            afficherMenuStat(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }

    }while(choix !=0);
}

void afficherMenuventePdt(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choix;
    system("cls");
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t *\n");
        printf("* 1- Vente de produits \t\t\t\t\t *\n");
        printf("* 0- Menu Principal \t\t\t\t\t *\n");

        do{
            printf("* >>tapez votre choix : \t\t\t\t");
            scanf("%d",&choix);
        }while(choix<0||choix>2);

        if(choix==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if(choix==1){
        VendrePdt(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }

    }while(choix !=0);
}


void afficherMenuStat(int nbCat, int nbType, Produit Stock[100][50], Type TabType[], Categorie TabCat[], int TabQte[]){
    int choix;
    do{
        printf("**********************************************************\n");
        printf("**********\t\tBIENVENU\t\t**********\n");
        printf("**********************************************************\n");
        printf("* veuillez choisir une option : \t\t\t   *\n");
        printf("* 1- Statistique par mois \t\t\t\t\t     *\n");
        printf("* 2- Statistique par annees \t\t\t\t\t   *\n");
        printf("* 0- Menu Principal \t\t\t\t\t *\n");

        do{
            printf("* >>tapez votre choix : \t\t\t\t");
            scanf("%d",&choix);
        }while(choix<0||choix>2);

        if(choix==0){
            afficherMenu(nbCat, nbType, Stock, TabType, TabCat, TabQte);
        }
        if(choix==1){
            StatMois(TabCat);
        }
        if(choix==2){
            StatAnnee(TabCat);
        }

    }while(choix !=0);
}


#endif // MENU_H_INCLUDED
