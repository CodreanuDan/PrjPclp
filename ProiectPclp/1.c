#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include <string.h>
#include"ProiectPclp.h"



Masini v[30];
void display()
{

	int i,j;
	char text[12];

	FILE *g;
	g=fopen("grafica.txt","r");

	int p[]={550,500,400,350,204,204,180,120,120,40};
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for(i = 0; i < 10; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(0.6f, i/10., 1.0f);
		glVertex2f(-0.81+i*0.17,-0.5);
		glVertex2f(-0.81+i*0.17+0.14, -0.5);
		glVertex2f(-0.81+i*0.17+0.14, -0.5+p[i]/550.0);
		glVertex2f(-0.81+i*0.17, -0.5+p[i]/550.0);
		glEnd();

		glRasterPos2f(-0.83+i*0.17+0.08,-0.5+p[i]/550.+0.05);
		sprintf(text,"%d CP",p[i]);
		for(j=0; j< 10; j++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,text[j]);

		fscanf(g,"%s",v[i].marca);
		glRasterPos2f(-0.83+i*0.17+0.08,-0.6);
		for(j=0 ;j< strlen(v[i].marca);j++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,v[i].marca[j]);
	    }

	}
	glFlush();
}


int main(int argc, char** argv)
{
    Masini v[30],ord[30];
    int i,n;
    int lim;
    int caz;
    int caz1;
    int tur;

    FILE *f;
    f=fopen("fiser_date.txt","r");

    if(!f)
	{
        printf("Eroare la deschidere fisier intrare!!!\n");
        return 1;
    }
    else
	{
        printf("Am deschis fisierul de intare!!!\n");
    }

    fscanf(f,"%d",&n);
    printf("%d marci\n",n);

    for(i=0;i<n;i++)
	{
    	fscanf(f,"%s%s%f%f%f%f",v[i].marca,v[i].model,&v[i].pret,&v[i].putereCP,&v[i].cuplu,&v[i].greutate);
    }

    printf("\no-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);
    printf("\no-o-o-o-o-o-o->INFORMATII_DESPRE_MASINI<-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);
    printf("\no-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);

    for(i=0;i<n;i++)
	{
    afiseazadate(v[i]);
	ord[i]=v[i];
    }

    printf("\no-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);
    printf("\no-o-o-o-o-o-o-o->ORDONARE_DUPA_PRET_CRESC<-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);
    printf("\no-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);

    OrdCrescPret(ord,10);
    for(i=0;i<n;i++)
	{
    	printf("%d",i+1);
    	afiseazadate(ord[i]);
    }

    printf("\no-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);
    printf("\no-o-o-o-o-o-o-o->ORDONARE_DUPA_PUTERE<o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);
    printf("\no-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o\n");
    fflush(stdout);

    OrdDescrPutere(ord,10);
    for(i=0;i<n;i++)
	{
		printf("%d",i+1);
		afiseazadate(ord[i]);
    }

    printf("\n_______________________________\n");
    fflush(stdout);
    printf("\n___________Raport_CP/T_________\n");
    fflush(stdout);
    printf("\n_______________________________\n");
    fflush(stdout);

    for(i=0;i<n;i++)
	{
    	printf("Modelul %s %s are raportul CP/t= %.2f CP/t",v[i].marca,v[i].model, v[i].putereCP/ (v[i].greutate/1000) );
    	printf("\n");
    }

    printf("\n");
    fflush(stdout);

    CPtBun(ord,n,0);

    printf("\n");
    fflush(stdout);

    printf("\n_______________________________\n");
    fflush(stdout);
    printf("\n_________PRETfaraTVA_________\n");
    fflush(stdout);
    printf("\n_______________________________\n");
    fflush(stdout);

    TVA(ord,n,i);

    printf("\n");
    fflush(stdout);

    printf("\n_______________________________\n");
        fflush(stdout);
        printf("\nORODNARE_PUTERE_DUPA_O_LIMITA_DE_CP\n");
        fflush(stdout);
        printf("\n_______________________________\n");
        fflush(stdout);

    printf("Introduceti limita de  CP peste care vom afisa masinile(40-550) \n");
    fflush(stdout);
    printf("\n");
    fflush(stdout);

    scanf("%d",&lim);

    printf("Introduceti 1 pentru afisare peste limita de CP si 2 pt afisarea sub limita de CP: \n ");
    fflush(stdout);
    printf("\n");
    fflush(stdout);

    scanf("%d",&caz);
    printf("\n");
    fflush(stdout);


    switch(caz)
	{

    case 1:
    		LimSup(ord,lim,n);
    		break;

    case 2:

    		LimInf(ord,lim,n);
    		break;

    default:

    		printf("Nu ati introdus bine!!!");
    		fflush(stdout);
    		printf("\n");
    }

    printf("\n");
    fflush(stdout);

    printf("\n_______________________________\n");
    fflush(stdout);
    printf("\n__PUTERE_FUNCTIE_DE_TURATIE_\n");
    fflush(stdout);
    printf("\n_______________________________\n");
    fflush(stdout);

    printf("Selectati masina:\n");
    fflush(stdout);
    printf("\n");
    fflush(stdout);
    printf("Tesla S: >tasta 0\n");
    fflush(stdout);
    printf("Mercedes EQC: >tasta 1<\n");
    fflush(stdout);
    printf("Jaguar I-Pace: >tasta 2<\n");
    fflush(stdout);
    printf("Tesla 3 :>tasta 3<\n");
    fflush(stdout);
    printf("Skoda Eniaq: >tasta 4<\n");
    fflush(stdout);
    printf("VW Id4: >tasta 5<\n");
    fflush(stdout);
    printf("Hyundai KonaElectric: >tasta 6<\n");
    fflush(stdout);
    printf("Renault Zoe: >tasta 7<\n");
    fflush(stdout);
    printf("Nissan LeafE: >tasta 8<\n");
    fflush(stdout);
    printf("Dacia Spring: >tasta 9<\n");
    fflush(stdout);
    printf("\n");
    fflush(stdout);

    scanf("%d",&caz1);
    printf("\n");
    fflush(stdout);

    printf("Am selectat %d:",caz1);
    printf("\n");
    fflush(stdout);

    printf("Alegeti turatia maxima(1000RPM-7000RPM)\n");
    printf("\n");
    fflush(stdout);

    scanf("%d",&tur);
    printf("\n");
    fflush(stdout);

    switch(caz1)
	{

    case 0:
    	 PutTur(ord,caz1,tur);
    	 break;

    case 1:
         PutTur(ord,caz1,tur);
         break;

    case 2:
         PutTur(ord,caz1,tur);
         break;

    case 3:
    	 PutTur(ord,caz1,tur);
       	 break;

    case 4:
         PutTur(ord,caz1,tur);
         break;

    case 5:
          PutTur(ord,caz1,tur);
          break;

    case 6:
          PutTur(ord,caz1,tur);
          break;

    case 7:
          PutTur(ord,caz1,tur);
          break;

    case 8:
           PutTur(ord,caz1,tur);
           break;

    case 9:
           PutTur(ord,caz1,tur);
            break;

    default:

		printf("Nu ati introdus bine!!!");
	    fflush(stdout);
	    printf("\n");
	    fflush(stdout);
    }

    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(" Graficul Puterilor ");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

