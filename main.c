#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include  "bib.h"
#include "ajout.h"
#include "sup.h"
#include "menu.h"
#include "afficheStock.h"

int main()
{
    system("color 4f");
    printf("**********************************************************\n");
    printf("**********\t\tBIENVENU\t\t**********\n");
    printf("**********************************************************\n");
    int nbCat=0, nbType=0;

    Categorie TabCat[20];
    Type TabType[50];
    Produit Stock[100][50];

    int TabQte[50]={2,11,1,1};

    Categorie c1,c2,c3;
    c1.idCat=1;
    strcpy(c1.NomCat,"conserve");
    c2.idCat=2;
    strcpy(c2.NomCat,"Boisson");
    c3.idCat=3;
    strcpy(c3.NomCat,"Epice");
    TabCat[0]=c1;
    TabCat[1]=c2;
    TabCat[2]=c3;

    nbCat=3;

    Type t1,t2,t3,t4;
    t1.idType=11;
    strcpy(t1.Nomtype,"tomate");
    t1.Cat=c1;

    t2.idType=12;
    strcpy(t2.Nomtype,"jus");
    t2.Cat=c2;

    t3.idType=10;
    strcpy(t3.Nomtype,"mais");
    t3.Cat=c1;

    t4.idType=45;
    strcpy(t4.Nomtype,"curcuma");
    t4.Cat=c3;


    TabType[0]=t1;
    TabType[1]=t2;
    TabType[2]=t3;
    TabType[3]=t4;

    nbType=4;


    Produit p1,p2,p3,p4,p5,p6,p7;
    Produit p8,p9,p10,p11,p12,p13,p14,p15;



    p1.id=50;
    strcpy(p1.nom,"pdt1");
    p1.type=t1;
    p1.dateexpiration.JJ=12;
    p1.dateexpiration.MM=12;
    p1.dateexpiration.AA=2021;

    p2.id=48;
    strcpy(p2.nom,"pdt2");
    p2.type=t2;
    p2.dateexpiration.JJ=14;
    p2.dateexpiration.MM=11;
    p2.dateexpiration.AA=2022;

    p3.id=27;
    strcpy(p3.nom,"pdt3");
    p3.type=t3;
    p3.dateexpiration.JJ=12;
    p3.dateexpiration.MM=12;
    p3.dateexpiration.AA=2021;

    p4.id=11;
    strcpy(p4.nom,"pdt4");
    p4.type=t4;
    p4.dateexpiration.JJ=25;
    p4.dateexpiration.MM=10;
    p4.dateexpiration.AA=2021;

    p5.id=48;
    strcpy(p5.nom,"pdt5");
    p5.type=t1;
    p5.dateexpiration.JJ=13;
    p5.dateexpiration.MM=12;
    p5.dateexpiration.AA=2020;


    p6.id=30;
    strcpy(p6.nom,"pdt6");
    p6.type=t2;
    p6.dateexpiration.JJ=10;
    p6.dateexpiration.MM=11;
    p6.dateexpiration.AA=2021;

    p7.id=60;
    strcpy(p7.nom,"pdt7");
    p7.type=t2;
    p7.dateexpiration.JJ=12;
    p7.dateexpiration.MM=12;
    p7.dateexpiration.AA=2021;

    p8.id=300;
    strcpy(p8.nom,"pdt8");
    p8.type=t2;
    p8.dateexpiration.JJ=12;
    p8.dateexpiration.MM=12;
    p8.dateexpiration.AA=2021;

    p9.id=59;
    strcpy(p9.nom,"pdt9");
    p9.type=t2;
    p9.dateexpiration.JJ=12;
    p9.dateexpiration.MM=12;
    p9.dateexpiration.AA=2021;

    p10.id=49;
    strcpy(p10.nom,"pdt10");
    p10.type=t2;
    p10.dateexpiration.JJ=12;
    p10.dateexpiration.MM=12;
    p10.dateexpiration.AA=2021;

    p11.id=79;
    strcpy(p11.nom,"pdt11");
    p11.type=t2;
    p11.dateexpiration.JJ=12;
    p11.dateexpiration.MM=12;
    p11.dateexpiration.AA=2021;

    p12.id=89;
    strcpy(p11.nom,"pdt12");
    p12.type=t2;
    p12.dateexpiration.JJ=20;
    p12.dateexpiration.MM=10;
    p12.dateexpiration.AA=2021;

    p13.id=99;
    strcpy(p11.nom,"pdt13");
    p13.type=t2;
    p13.dateexpiration.JJ=30;
    p13.dateexpiration.MM=12;
    p13.dateexpiration.AA=2021;

    p14.id=19;
    strcpy(p11.nom,"pdt14");
    p14.type=t2;
    p14.dateexpiration.JJ=11;
    p14.dateexpiration.MM=12;
    p14.dateexpiration.AA=2021;

    p15.id=24;
    strcpy(p11.nom,"pdt15");
    p15.type=t2;
    p15.dateexpiration.JJ=13;
    p15.dateexpiration.MM=12;
    p15.dateexpiration.AA=2021;



    Stock[0][0]=p1;
    Stock[0][1]=p5;

    Stock[1][0]=p2;
    Stock[1][1]=p6;
    Stock[1][2]=p7;

    Stock[1][3]=p8;
    Stock[1][4]=p9;
    Stock[1][5]=p10;
    Stock[1][6]=p11;
    Stock[1][7]=p12;
    Stock[1][8]=p13;
    Stock[1][9]=p14;
    Stock[1][10]=p15;

    Stock[2][0]=p3;

    Stock[3][0]=p4;

afficherMenu(&nbCat, &nbType, Stock, TabType, TabCat, TabQte);

    return 0;
}
