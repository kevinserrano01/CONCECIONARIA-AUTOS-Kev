#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "TAD_Autos.h"
#define TMAXAUTOS 50 // CANTIDAD MAXIMA DE Autos 

//Creacion de un vector de registro de Autos
typedef Autos CantAutos[TMAXAUTOS];

//REgistro donde contiene la lista y el tamaño asociado a esa lista.
typedef struct{
	CantAutos Tlista; //1 vector
	int tam;		//Tamañao de la lista
}ListaAutos;	//registro


//void ordenar_lista(ListaAutos *aux);/* ORDENAR LISTA RECURSIVA POR QSHORT*/

int lista_vacia(ListaAutos aux); /* CONTROL SOBRE LISTA LLENA */
int lista_llena(ListaAutos aux); /* CONTROL SOBRE LISTA VACIA */
ListaAutos cargar_lista(); /* CARGA DEL VECTOR */ /* MODULO DESACTIVADO SI EXISTE UNA BASE DE DATOS */
void mostrar_inventario(ListaAutos aux); /* MOSTRAR EL INVENTARIO AL VENDEDOR */
void mostrar_catologo(ListaAutos aux); /* MOSTRAR EL CATALOGO PARA EL CLIENTE */
void agregar_auto(ListaAutos *aux); /* AGREGAR UN VEHICULO ORDENADO */
void eliminar_por_modelo(ListaAutos *aux); /* ELIMINA TANDA POR MODELO */
void eliminar_por_patente(ListaAutos *aux); /* ELIMINA UN ELEMENTO REGISTRO DEL VECTOR POR PATENTE */
void mostrar_por_modelo(ListaAutos aux); /* BUSCA Y MUESTRA POR MODELO */
void mostrar_por_marca(ListaAutos aux); /* BUSCA Y MUESTRA POR MARCA */
void comprar_auto(ListaAutos *aux); /* COMPRAR UN VEHICULO(SI EL STOCK ES MENOR O IGUAL A 1 SE ELIMINA TODO EL REGISTRO, SI NO SOLO SE RESTA 1 AL STOCK) */
void modificar_cuotas(ListaAutos *aux);/* MODIFICAR UN REGISTRO EN BASE A UNA POSICION */
void modificar_garantia(ListaAutos *aux); /* MODIFICAR UN REGISTRO EN BASE A UNA POSICION */
void modificar_precio(ListaAutos *aux);/* MODIFICAR UN REGISTRO EN BASE A UNA POSICION */
void modificar_stock(ListaAutos *aux);/* MODIFICAR UN REGISTRO EN BASE A UNA POSICION */

#endif
