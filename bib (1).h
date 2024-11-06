#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED


typedef struct  Categorie
 {
  int idCat;
  char NomCat[30];
 }Categorie ;

 typedef struct Type
{
    int idType;
    char Nomtype[30];
    Categorie Cat;
}Type;

 typedef struct MaDate
{
   int JJ;
   int MM;
   int AA;
} MaDate;

typedef struct Produit
{
    int id;
    char nom[30];
    Type type;
    MaDate dateexpiration;
}Produit;



void InitCat(Categorie* categorie){
    printf("donner l'id de la categorie: ");
    scanf("%d",&categorie->idCat);
    printf("donner le nom de la categorie: ");
    scanf("%s",categorie->NomCat);

}
void InitType(Type* type){
    Categorie cat;
    printf("donner l'id de type: ");
    scanf("%d",&type->idType);
    printf("donner le nom de type: ");
    scanf("%s",type->Nomtype);
    InitCat(&cat);
    type->Cat = cat;

}

void InitDate(MaDate* date){
   do{
    printf("donner le jour: ");
    scanf("%d",&date->JJ);
   } while((date->JJ<1)|| (date->JJ>31));
   do{
    printf("donner le mois: ");
    scanf("%d",&date->MM);
   } while((date->MM<1)||(date->MM>12));
   do{
    printf("donner l'annee: ");
    scanf("%d",&date->AA);
   } while((date->AA<1000)||(date->AA>9999));
}

void InitPdt (Produit* produit){
    Type type;
    MaDate date;
    printf("donner l'id de produit: ");
    scanf("%d",&produit->id);
    printf("donner le nom de produit: ");
    scanf("%s",produit->nom);
    InitType(&type);
    InitDate(&date);
    produit->type=type;
    produit->dateexpiration =date;
}

#endif // BIB_H_INCLUDED
