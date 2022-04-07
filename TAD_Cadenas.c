#include <stdio.h>
#include "TAD_Cadenas.h"
void leecad_rec1(Tcad cadena,char *c,int *j,int tam);
void leecad_rec2(char *c);

void leecad_rec1(Tcad cadena,char *c,int *j,int tam){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	if(*c!=EOF && *c!='\n' && *j<tam-1)
	{
		cadena[*j]=*c;
		*c=getchar();
		*j=*j+1;
		leecad_rec1(cadena,c,j,tam);
	}
}
void leecad_rec2(char *c){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	if(*c!=EOF && *c!='\n'){
		*c=getchar();
		leecad_rec2(c);
	}
}
/* CADENA */
void leeCad(Tcad cadena, int tam){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	int j;
	char c;
	j=0;
	c=getchar();
	leecad_rec1(cadena,&c,&j,tam);
	cadena[j]='\0';
	leecad_rec2(&c);
}
