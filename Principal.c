/*
CONCESIONARIA DE autoS USADOS ENUNCIADO
Un concesionario de autos usados solicita un programa que permita guardar los siguientes datos:

*La categoría del vehiculo(auto).
*La marca del auto.
*El modelo del auto.
*La patente del auto.
*El color del auto.
*El precio del auto.
*El método de pago del auto:
---	La cantidad de cuotas (en caso de estar disponibles).
--- La garantía (de 1 a 5 años). 
*El stock del auto (cantidad de unidades disponibles).
*Un identificador ( cada auto debe tener un unico identificador ).
Se pide que el programa conste de dos partes:
1° Entrar como vendedor:
->Ver el inventario (MOSTRAR TODOS LOS DATOS DE LOS autoS).
->Agregar algún auto nuevo de forma ordenada de acuerdo al numero de identificador.
->Eliminar algún auto dada su patente.
->Eliminar una tanda completa dado su modelo.
2° Entrar como cliente:
->Buscar un auto por su modelo.
->Buscar un auto por su marca.
->Buscar un auto por su categoría (Camioneta o Auto).
->Ver el catalogo (Mostrar solo datos que sean relevantes).
->Comprar un auto ( el cliente debe elegir un identificador y si el stock de ese identificador es igual a 1, se debe eliminar todo el registro de ese auto).
***************************************************************************************************************************************************************************************/
/***INTEGRANTE 1: --> SERRANO KEVIN***/
/***INTEGRANTE 2: --> ARAMAYO DIEGO***/
/***INTEGRANTE 1: --> GÁLVEZ JOEL***/

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "TAD_Cadenas.h"
#include "TAD_Autos.h"
#include "TAD_Lista.h"

int menu_principal(void); /*MENU PRINCIPAL */
int menu_vendedor(void); /* MENU VISTA VENDEDOR */
int menu_comprador(void); /* MENU VISTA CLIENTE */
int menu_modificar(void); /* MENU VISTA VENDEDOR: MODIFICAR ATRIBUTOS */
void menu_rec_principal(ListaAutos *aux); /* MENU RECUSRIVO PRINCIPAL */ 
void menu_rec_vendedor(ListaAutos *aux); /* MENU RECUSRIVO VENDEDOR */ 
void menu_rec_modificar(ListaAutos *aux); /* MENU RECUSRIVO MODIFICAR*/ 
void menu_rec_comprador(ListaAutos *aux); /* MENU RECUSRIVO COMPRADOR*/ 

int main() {
	ListaAutos autos;	srand(time(NULL)); /* CADA VEZ QUE SE EJECUTE EL PROGRAMA, SE USA UNA SEMILLA	DE ACUERDO AL RELOJ DE LA PC */
	autos = cargar_lista();
	menu_rec_principal(&autos);
	return 0;
}

void limpiar_pantalla(){/* MODULO IMPLEMENTADO POR GÁLVEZ*/
	fflush(stdin);
	printf("\nPresione ENTER para mostrar opciones de Menu");
	getchar();
	system("cls");
}
void menu_rec_principal(ListaAutos *aux){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	int op;
	limpiar_pantalla();
	op = menu_principal();
	switch(op){
		case 1:{
			menu_rec_vendedor(aux);
			menu_rec_principal(aux);
			break;
		}
		case 2:{
			menu_rec_comprador(aux);
			menu_rec_principal(aux);
			break;
		}
		/* ELIMINAMOS EL ORDENAMIENTO SOLO DEL MENU POR QUE NO SE REQUIERE EN NUESTRO TRABAJO INTEGRADOR
			case 3:{
			if(lista_vacia(*aux)) ordenar_lista(aux);
			else printf("\nLa lista esta vacia"); 
			menu_rec_principal(aux);
		}
		*/
		case 0: printf("\nGracias por elegirnos."); break;	
		default: printf("\nOpcion incorrecta"); menu_rec_principal(aux); break;
	}
}

void menu_rec_vendedor(ListaAutos *aux){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	int op;
	limpiar_pantalla();
	op = menu_vendedor();
	switch(op){ /* ACCEDEMOS COMO VENDEDOR */
		case 1:{/* AGREGAR UN VEHICULO */
			if(lista_llena(*aux)) agregar_auto(aux); 
			else printf("\nMAXIMO ALCANZADO"); 
			menu_rec_vendedor(aux);
			break;
		}
		case 2:{/* ELIMINAR TANDA POR MODELO */
			if(lista_vacia(*aux)) eliminar_por_modelo(aux); 
			else printf("\nLa lista esta vacia"); 
			menu_rec_vendedor(aux);
			break;
		}
		case 3:{/* ELIMINAR POR PATENTE */
			if(lista_vacia(*aux)) eliminar_por_patente(aux); 
			else printf("\nLa lista esta vacia"); 
			menu_rec_vendedor(aux);
			break;
		}
		case 4:{ /* MODIFICAR */
			if(lista_vacia(*aux)){
				menu_rec_modificar(aux);
			}else printf("\nLa lista esta vacia\n");
			menu_rec_vendedor(aux);
			break;
		}
		case 5:{/* MOSTRAR INVENTARIO [ mostrar todo ]*/	
			if(lista_vacia(*aux)) mostrar_inventario(*aux); 
			else printf("\nLa lista esta vacia\n");
			menu_rec_vendedor(aux);
			break;
		}
		case 0: break;
	default: printf("\nOpcion incorrecta"); menu_rec_vendedor(aux); break; 
	}
}
void menu_rec_modificar(ListaAutos *aux){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	int op;
	limpiar_pantalla();
	op = menu_modificar();
	switch(op){
		case 1:{
			modificar_precio(aux);
			menu_rec_modificar(aux);
			break;
		}
		case 2:{
			modificar_cuotas(aux);
			menu_rec_modificar(aux);
			break;
		}
		case 3:{
			modificar_stock(aux);
			menu_rec_modificar(aux);
			break;
		}
		case 4:{
			modificar_garantia(aux);
			menu_rec_modificar(aux);
			break;
		}
		case 0: break;
	default: printf("\nOpcion incorrecta"); menu_rec_modificar(aux); break;
	}
}
void menu_rec_comprador(ListaAutos *aux){/* MODULO IMPLEMENTADO POR GÁLVEZ */
	int op;
	limpiar_pantalla();
	op = menu_comprador();
	switch(op){ /* ACCEDEMOS COMO COMPRADOR */
		case 1:{/* MOSTRAR CATOLOGO [mostrar: Modelo,Marca,Precio,Color,Cuotas]*/
			if(lista_vacia(*aux)) mostrar_catologo(*aux); 
			else printf("\nCatalogo vacio\n"); 
			menu_rec_comprador(aux);
			break;
		}
		case 2:{
			if(lista_vacia(*aux)) mostrar_por_modelo(*aux);
			else printf("\nCatalogo vacio\n"); 
			menu_rec_comprador(aux);
			break;
		}
		case 3:{
			if(lista_vacia(*aux)) mostrar_por_marca(*aux);
			else printf("\nCatalogo vacio\n"); 
			menu_rec_comprador(aux);
			break;
		}
		case 4:{
			if(lista_vacia(*aux)) comprar_auto(aux);
			else printf("\nCatalogo vacio\n"); 
			menu_rec_comprador(aux);
			break;
		}
		case 0: break;
	default: printf("\nOpcion incorrecta"); menu_rec_comprador(aux); break;
	}
}

int menu_principal(){ /* MODULO CREADO POR SERRANO */
	int opc;
	printf("\nComo desea ejecutar el programa?\n");
	printf("\n1. Como vendedor"); 
	printf("\n2. Como cliente"); 
	//printf("\n3. Ordenar lista ( solo funciona sin el agrega ordenado y sin el carga ordenado ) "); 
	printf("\n0. Salir");
	printf("\n\nSeleccione una opcion: ");
	scanf("%d",&opc);
	return opc;
}	
int menu_vendedor(){ /* MODULO CREADO POR SERRANO */
	int opc;
	printf("\nVista: como vendedor\n");
	printf("\n1. Agregar un auto"); 
	printf("\n2. Eliminar tanda por modelo"); 
	printf("\n3. Eliminar por patente"); 
	printf("\n4. Modificar caracteristicas de un auto"); 
	printf("\n5. Mostrar Inventario"); 
	printf("\n0. Volver al menu anterior");
	printf("\n\nSeleccione una opcion: ");
	scanf("%d",&opc);
	return opc;
}	
int menu_comprador(){ /* MODULO CREADO POR SERRANO */
	int opc;
	printf("\nVista: como cliente\n");
	printf("\n1. Mostrar catalogo");  
	printf("\n2. Buscar por modelo"); 
	printf("\n3. Buscar por marca"); 
	printf("\n4. Comprar un auto"); 
	printf("\n0. Volver al menu anterior ");
	printf("\n\nSeleccione una opcion: ");
	scanf("%d",&opc);
	return opc;
}		
int menu_modificar(){/* MODULO CREADO POR: SERRANO */
	int opc;
	printf("\nVista: como vendedor\n");
	printf("\n1. Modificar precio"); 
	printf("\n2. Modificar cuotas"); 
	printf("\n3. Modificar stock"); 
	printf("\n4. Modificar garantia"); 
	printf("\n0. Volver al menu anterior ");
	printf("\n\nSeleccione una opcion: ");
	scanf("%d",&opc);
	return opc;
}

