
#include<stdio.h>
#include"ProiectPclp.h"



void OrdCrescPret(Masini v[30],int n){
	int i;
	int j;
	Masini aux;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(v[j].pret>v[j+1].pret){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}



void OrdDescrPutere( Masini v[30],int n){
	int i;
	int j;
	Masini aux;
	for (i=0;i<n;i++){
		for (j=0;j<n-1;j++){
			if(v[j].putereCP<v[j+1].putereCP){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}



void CPtBun(Masini v[30],int n,int imax){
	int i;
	float max;
	for(i=0;i<n;i++){
		max=(v[0].putereCP/ (v[0].greutate/1000));
		if((v[i].putereCP/ (v[i].greutate/1000))>max){
				max=(v[i].putereCP/(v[i].greutate/1000));
				i=imax;
		}
	}
	 printf("Masina cu cel mai bun raport cp/tona este %s %s.", v[imax].marca,v[imax].model);
}



void afiseazadate(Masini marca){
    printf("\n___________________\n");
    fflush(stdout);
    printf("Marca:%s\n",marca.marca);
    printf("Informatii despre modelul %s:\n pret:%.2f € \n putere:%.2f(CP) \n cuplu:%.2f(Nm) \n greutate:%.2f(kg)"
           ,marca.model,marca.pret,marca.putereCP
           ,marca.cuplu,marca.greutate);
    printf("\n___________________\n");
    fflush(stdout);
}



void TVA(Masini v[30],int n,int i){
	float ftva;
	for(i=0;i<n;i++){
		ftva=v[i].pret-(float)(v[i].pret*24/100);
		printf(" %d %s %s are pret fara TVA %.2f € fata de  %.2f € cu TVA, TVA=24 la suta. \n",i+1, v[i].marca,v[i].model,ftva,v[i].pret );
	}
}



void LimSup(Masini v[30],int lim,int n){
	int i;
	for(i=0;i<n;i++){
		if(v[i].putereCP >lim)
		printf(" %d.%s %s cu puterea de %.2f CP. \n",i+1,v[i].marca,v[i].model,v[i].putereCP);
	}
}



void LimInf(Masini v[30],int lim,int n){
	int i;
	for(i=0;i<n;i++){
		if(v[i].putereCP <lim)
		printf(" %d.%s %s cu puterea de %.2f CP. \n",i+1,v[i].marca,v[i].model,v[i].putereCP);
	}
}



void PutTur(Masini v[30],int nrmasina,int m){
	float f[10];
	int i;
	printf("Masina selectata este %s %s cu putere maxima %.2f si cuplu maxim %.2f \n",v[nrmasina].marca,v[nrmasina].model,v[nrmasina].putereCP,v[nrmasina].cuplu);
	fflush(stdout);
	for(i=0;i<=m/1000;i++){
	 f[i]=(float)((v[nrmasina].cuplu*i*1000)/10000);
	 printf(" %d RPM -->%.2f CP \n",i*1000,f[i]);
	 fflush(stdout);
	}
}

