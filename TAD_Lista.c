#include <stdio.h>
#include "TAD_Lista.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

void base_de_datos(ListaAutos *aux); /* BASE DE DATOS DE AUTO */ 
void quitar(ListaAutos *aux,int pos); /* ELIMINA UN ELEMENTO REGISTRO DE UN lista EN BASE A UNA POSICION */
void cargar_lista_rec(ListaAutos *aux,int i); /* CARGAR LISTA RECURSIVA */ 
int busqueda_binaria(ListaAutos aux,int);/* MODULO DE BUSQUEDA PARA EL IDENTIFICADOR */
int busqueda_binaria_rec(ListaAutos aux,int ini, int fin,int buscado); /* BUSQUEDA BINARIA RECURSIVA */
void corrimiento_carga_rec(ListaAutos *aux, int j,Autos res); /* CORRIMIENTO PARA LA CARGA ORDENADA */
void corrimiento_agrega_rec(ListaAutos *aux,Autos res, int i); /* CORRIMIENTO PARA EL AGREGAR ORDENADO */
void mostrar_inventario_rec(ListaAutos aux, int i); /* MUESTRA RECURSIVA DEL INVENTARIO */
void mostrar_catalogo_rec(ListaAutos aux, int i,int *b); /* MUESTRA RECURSIVA DEL CATALOGO */
Autos cargar_auto_rec(ListaAutos aux); /* CARGA Y VALIDACION DE UN AUTO */
int validar_rec(ListaAutos aux);/* VALIDA QUE EL IDENTIFICADOR INGRESADO EXISTA EN LA LISTA */
void validar_id_rec(ListaAutos aux,int *num); /* VALIDA QUE UN IDENTIFICADOR ALEATORIO NO EXISTA EN LA LISTA*/
void eliminacion_patente_rec(ListaAutos *aux,Tcad Patente,int *b,int i); /* ELIMINACION DE UNA PATENTE RECURSIVA */
void corrimiento_der(ListaAutos aux,Autos piv,int izq, int *der);/* PRIMER CORRIMIENTO */
void corrimiento_izq(ListaAutos aux,Autos piv,int *izq, int der);/* SEGUNDO CORRIMIENTO */
void corrimiento_grande(ListaAutos *aux,Autos piv,int *izq,int *der);/* CORRIMIENTO GENERAL */
void QSort_rec(ListaAutos *aux, int ini, int fin);/* ORDENAMIENTO EN BASE AL IDENTIFICADOR DE UNA LISTA POR QSHORT*/
void eliminacion_por_modelo_rec(ListaAutos *aux,Tcad Modelo, int i, int *b);

//
int lista_vacia(ListaAutos aux){/* MODULO IMPLEMENTADO POR SERRANO */
	if(aux.tam <= 0) return 0; //lista vacia
	else return 1;  			//lista no vacia
}
	
int lista_llena(ListaAutos aux){/* MODULO IMPLEMENTADO POR ARAMAYO */
	if(aux.tam >= TMAXAUTOS-1) return 0;
	else return 1;
}
	
//mascara
ListaAutos cargar_lista(){	/* MODULO CREADO POR SERRANO */
	ListaAutos aux;
	printf("\nIngrese una cantidad que desea agregar: ");
	scanf("%d",&aux.tam);
	cargar_lista_rec(&aux,1); //capa: cargar lista
	return aux;
}
	
Autos cargar_auto_rec(ListaAutos aux){/* MODULO IMPLEMENTADO POR SERRANO */
	Autos res;
	int num;
	num = rand()%(100-1+1)+1; //crear numero aleatorio
	validar_id_rec(aux,&num);
	res = cargar_auto(num);
	return res;
}
//
void validar_id_rec(ListaAutos aux,int *num){/* MODULO IMPLEMENTADO POR SERRANO*/
	if(busqueda_binaria(aux, *num) != 0){ //genera un num aleatorio y busca que no exista en la lista para agregarlo
		*num = rand()%(100-1+1)+1;
		validar_id_rec(aux,num);
	}  //valida que no esté repetido el id 
}
void cargar_lista_rec(ListaAutos *aux,int i){/* MODULO IMPLEMENTADO POR SERRANO */
	Autos res;
	int j;
	if(i<=aux->tam){ //caso base que no supere
		res = cargar_auto_rec(*aux);  //carga: validar el id ramdon repetido		
		aux->Tlista[0] = res;
		j = i-1;
		corrimiento_carga_rec(aux,j,res);
		cargar_lista_rec(aux,i+1);
	}
}

void corrimiento_carga_rec(ListaAutos *aux, int j, Autos res){/* MODULO IMPLEMENTADO POR SERRANO */
	if(compara_identificador(aux->Tlista[j],res) == 1){
		aux->Tlista[j+1] = aux->Tlista[j];
		corrimiento_carga_rec(aux,j-1,res);
	}else aux->Tlista[j+1] = res;
}
void mostrar_inventario(ListaAutos aux){	/* MODULO CREADO POR GÁLVEZ */
	mostrar_inventario_rec(aux,1);
}
void mostrar_inventario_rec(ListaAutos aux, int i){/* MODULO IMPLEMENTADO POR ARAMAYO */
	if(i<=aux.tam){
		mostrar_auto_del_inventario(aux.Tlista[i]);
		mostrar_inventario_rec(aux,i+1);
	}
}
void mostrar_catologo(ListaAutos aux){ /* MODULO CREADO POR GÁLVEZ */
	int b = 0;
	mostrar_catalogo_rec(aux,1,&b);
	if(b == 0) printf("\nCatalogo vacio");
}
void mostrar_catalogo_rec(ListaAutos aux, int i,int *b){/* MODULO IMPLEMENTADO POR ARAMAYO */
	if(i<=aux.tam){
		if(retornar_stock(aux.Tlista[i]) > 0){
			*b = 1;
			mostrar_auto_del_catalogo(aux.Tlista[i]);			
		}
		mostrar_catalogo_rec(aux,i+1,b);
	}
}

//
int busqueda_binaria_rec(ListaAutos aux,int ini, int fin,int buscado){ /* MODULO CREADO POR KEVIN SERRANO */
	int m;  //m = medio
	m = (ini+fin)/2;
	if((ini<=fin) && retornar_identificador(aux.Tlista[m])!=buscado){  //Caso base
		if(retornar_identificador(aux.Tlista[m])>buscado) 
			return(busqueda_binaria_rec(aux,ini,fin-1,buscado));
		else return(busqueda_binaria_rec(aux,ini+1,fin,buscado));
	}
	if(ini>fin)
	   return 0;
	else
		return m;
}

/*Es como una mascara para que el usuario  no se entere de lo recursivo*/
int busqueda_binaria(ListaAutos aux,int buscado){/* MODULO CREADO POR KEVIN SERRANO*/
	int fin;
	fin = aux.tam;
	return busqueda_binaria_rec(aux,1,fin,buscado);
}
	
//
void agregar_auto(ListaAutos *aux){ /* MODULO CREADO POR SERRANO */
	Autos res;
	int i;
	i = aux->tam;
	res = cargar_auto_rec(*aux);
	corrimiento_agrega_rec(aux,res,i);
	aux->tam = aux->tam+1;
}
void corrimiento_agrega_rec(ListaAutos *aux,Autos res, int i){/* MODULO IMPLEMENTADO POR SERRANO */
	if(i>0 && compara_identificador(aux->Tlista[i],res) == 1){
		aux->Tlista[i+1] = aux->Tlista[i];
		corrimiento_agrega_rec(aux,res,i-1);
	}else aux->Tlista[i+1] = res;
}
void quitar(ListaAutos *aux, int pos){ /* MODULO CREADO POR ARAMAYO */
	if(pos<aux->tam){
		aux->Tlista[pos]=aux->Tlista[pos+1];
		quitar(aux,pos+1);		
	}
}
void eliminacion_por_modelo_rec(ListaAutos *aux,Tcad Modelo, int i, int *b){ /* MODULO CREADO POR ARAMAYO */
	if(i<=aux->tam){
		if(comparar_modelo(Modelo,aux->Tlista[i]) == 1 && (retornar_stock(aux->Tlista[i]) >= 1)) {
			quitar(aux,i);
			aux->tam-=1;
			*b = 1;
			eliminacion_por_modelo_rec(aux,Modelo,i,b);
		}else eliminacion_por_modelo_rec(aux,Modelo,i+1,b);
	}
}
void eliminar_por_modelo(ListaAutos *aux){ /* MODULO CREADO POR ARAMAYO */
	Tcad Modelo;
	int i,b;
	i = 1, b = 0; //control para verificar si existe o no
	printf("\nIngrese el modelo a eliminar por tanda: ");
	fflush(stdin); 
	leeCad(Modelo,TMAXCAD);
	eliminacion_por_modelo_rec(aux,Modelo,i,&b);
	if(b == 0) printf("\nNo hay stock del modelo buscado");
}
void eliminacion_patente_rec(ListaAutos *aux,Tcad Patente,int *b,int i){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	if(i<=aux->tam && *b == 0){ //caso base
		if(comparar_patente(Patente,aux->Tlista[i]) == 1) {
			quitar(aux,i); //i es la posicion
			aux->tam-=1;
			*b = 1; //b = bandera por referencia para que perdure
		}else eliminacion_patente_rec(aux,Patente,b,i+1);  //si no encxuentra la patente sigue buscando
	}
}
void eliminar_por_patente(ListaAutos *aux){ /* MODULO CREADO POR GÁLVEZ */
	Tcad Patente;
	int b = 0;
	printf("\nIngrese la patente a eliminar: ");
	fflush(stdin); 
	leeCad(Patente,TMAXCAD);
	eliminacion_patente_rec(aux,Patente,&b,1);
	if(b == 0) printf("\nLa patente ingresada no existe");
}
void mostrar_por_modelo_rec(ListaAutos aux,int i,int *b,Tcad Modelo){ /* MODULO CREADO POR ARAMAYO */
	if(i<=aux.tam){
		if(comparar_modelo(Modelo,aux.Tlista[i]) == 1) {
			mostrar_auto_del_catalogo(aux.Tlista[i]);
			*b = 1;
		}
		mostrar_por_modelo_rec(aux,i+1,b,Modelo);
	}
}
void mostrar_por_modelo(ListaAutos aux){ /* MODULO CREADO POR ARAMAYO */
	Tcad Modelo;
	int b;
	printf("\nIngrese un modelo: ");
	fflush(stdin); 
	leeCad(Modelo,TMAXCAD);
	b = 0;
	mostrar_por_modelo_rec(aux,1,&b,Modelo);
	if(b == 0) printf("\nNo se encontraron Autos con ese modelo");
}
void mostrar_por_marca_rec(ListaAutos aux,int i,int *b,Tcad Marca){/* MODULO CREADO POR GÁLVEZ */
	if(i<=aux.tam){
		if(comparar_marca(Marca,aux.Tlista[i]) == 1) {
			mostrar_auto_del_catalogo(aux.Tlista[i]);
			*b = 1;
		}
		mostrar_por_marca_rec(aux,i+1,b,Marca);
	}
}
void mostrar_por_marca(ListaAutos aux){ /* MODULO CREADO POR GÁLVEZ */
	Tcad Marca;
	int b;
	printf("\nIngrese una marca: ");
	fflush(stdin); 
	leeCad(Marca,TMAXCAD);
	b = 0;
	mostrar_por_marca_rec(aux,1,&b,Marca);
	if(b == 0) printf("\nNo se encontraron Autos con esa marca");
}

void comprar_auto(ListaAutos *aux){ /*MODULO CREADO POR: SERRANO KEVIN */
	int id,pos;
	printf("\nIngrese el id del auto que desea comprar: ");
	scanf("%d",&id);
	pos = busqueda_binaria(*aux,id);
	if(pos != 0 && retornar_stock(aux->Tlista[pos]) >= 1){
		restar_stock(&aux->Tlista[pos],1);
		printf("\nFelicidades por su compra, Gracias vuelva prontos");
	}else printf("\nNo se encontro el auto con el id ingresado");
}	
int validar_rec(ListaAutos aux){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	int pos,identificador;		//busca el id exista para realizar la operacion
	printf("\nIngrese un identificador valido de un auto: ");
	scanf("%d",&identificador);
	pos = busqueda_binaria(aux,identificador);
	if(pos == 0){
		return validar_rec(aux);
	}else return pos;
}	
void modificar_cuotas(ListaAutos *aux){/* MODULO CREADO POR: GÁLVEZ */
	int pos;
	pos = validar_rec(*aux);
	modificar_c(&aux->Tlista[pos]);
}
void modificar_garantia(ListaAutos *aux){/* MODULO CREADO POR: GÁLVEZ */
	int pos;
	pos = validar_rec(*aux);
	modificar_g(&aux->Tlista[pos]);
}
void modificar_precio(ListaAutos *aux){/* MODULO CREADO POR: ARAMAYO */
	int pos;
	pos = validar_rec(*aux);
	modificar_p(&aux->Tlista[pos]);
}
void modificar_stock(ListaAutos *aux){/* MODULO CREADO POR: ARAMAYO */
	int pos;
	pos = validar_rec(*aux);
	modificar_s(&aux->Tlista[pos]);
}
	
void corrimiento_der(ListaAutos aux,Autos piv,int izq, int *der){ /* MODULO IMPLEMENTADO POR GÁLVEZ */
	if(*der>izq && (retornar_identificador(aux.Tlista[*der])>retornar_identificador(piv))) {
		*der = *der - 1;
		corrimiento_der(aux,piv,izq,der);
	}
}
void corrimiento_izq(ListaAutos aux,Autos piv,int *izq, int der){ /* MODULO IMPLEMENTADO POR GÁLVEZ */
	if(*izq<der && (retornar_identificador(aux.Tlista[*izq])<retornar_identificador(piv))) {
		*izq = *izq + 1;
		corrimiento_izq(aux,piv,izq,der);
	}
}
void corrimiento_grande(ListaAutos *aux,Autos piv,int *izq,int *der){ /* MODULO IMPLEMENTADO POR GÁLVEZ */
	if(*izq<*der){ 
		corrimiento_der(*aux,piv,*izq,der);
		if(*der>*izq) 
		{ 
			aux->Tlista[*izq]= aux->Tlista[*der]; 
			*izq = *izq+1; 
		}	
		corrimiento_izq(*aux,piv,izq,*der);
		if(*izq<*der) 
		{ 
			aux->Tlista[*der]= aux->Tlista[*izq]; 
			*der = *der -1; 
		} 
		corrimiento_grande(aux,piv,izq,der);
	} 
}	
void QSort_rec(ListaAutos *aux, int ini, int fin){ /* MODULO IMPLEMENTADO POR GÁLVEZ */
	Autos piv;
	int izq,der,med;
	if (ini<fin)
	{ 
		piv = aux->Tlista[ini];
		izq = ini; 
		der = fin; 
		corrimiento_grande(aux,piv,&izq,&der);
		aux->Tlista[der] = piv;
		med=der;
		QSort_rec(aux,ini, med-1); 
		QSort_rec(aux, med+1, fin); 
	}
}
void ordenar_lista(ListaAutos *aux){ /* MODULO IMPLEMENTADO POR GÁLVEZ */
	QSort_rec(aux,1,aux->tam);
}
