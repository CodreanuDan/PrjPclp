
#ifndef PROIECTPCLP_H_
#define PROIECTPCLP_H_


struct masini{
    char marca[30];
    char model[30];
    float pret;
    float cuplu;
    float greutate;
    float putereCP;
    float pretTVA;
};
typedef struct  masini Masini;


void OrdCrescPret(Masini v[30],int n);


void OrdDescrPutere( Masini v[30],int n);


void CPtBun(Masini v[30],int n,int imax);


void afiseazadate(Masini marca);


void TVA(Masini v[30],int n,int i);



void LimSup(Masini v[30],int lim,int n);


void LimInf(Masini v[30],int lim,int n);


void PutTur(Masini v[30],int nrmasina,int m);


#endif /* PROIECTPCLP_H_ */

