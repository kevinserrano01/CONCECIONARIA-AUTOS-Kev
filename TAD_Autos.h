#ifndef TAD_AUTOS_H
#define TAD_AUTOS_H

#include "TAD_Cadenas.h"

//REgistro compra
typedef struct{
	int Cuotas; // de 3 a 36 cuotas con 10% de interes
	int Garantia; // de 1 año a 5 años
}Compra;


//Registro Autos
typedef struct{
	Tcad Categoria; // CATEGORIA DEL AUTO
	Tcad Marca; // MARCA DEL AUTO
	Tcad Modelo; // MODELO DEL AUTO
	int Stock; // CANTIDAD DE ESE AUTO
	Tcad Patente; // PATENTE UNICA DEL AUTO
	float Precio; // PRECIO DEL AUTO
	Tcad Color; // COLOR DEL AUTO
	Compra MetodoCompra;// METODO DE COMPRA -  REGISTRO ANIDADO
	int Identificador;// IDENTIFICADOR UNICO DE CADA AUTO
}Autos;


//Operaciones 
Autos cargar_auto(); /*CARGAR UN VEHICULO */
void mostrar_auto_del_inventario(Autos aux); /* MOSTRAR REGISTRO DE AUTO PARA EL VENDEDOR */
void mostrar_auto_del_catalogo(Autos aux); /* MOSTRAR REGISTRO DE AUTO PARA EL CLIENTE */
void modificar_c(Autos *aux); /* MODIFICAR CUOTAS */
void modificar_g(Autos *aux); /* MODIFICAR GARANTIA */
void modificar_p(Autos *aux); /* MODIFICAR PRECIO */
void modificar_s(Autos *aux); /* MODIFICAR STOCK*/
int compara_identificador(Autos auto1, Autos auto2);/* COMPARA LOS IDENTIFICADORES DE DOS AUTOS */
int retornar_identificador(Autos aux); /* RETORNAR IDENTIFICADOR */
int retornar_stock(Autos aux);/* RETORNAR STOCK */
void restar_stock(Autos *aux, int nro); /* ESTE MODULO LO USAMOS PARA QUE CUANDO EL USUARIO COMPRE UN AUTO, RESTEMOS 1 AL STOCK */
int comparar_patente(Tcad cad1,Autos cad2); /* COMPARAMOS UNA CADENA CON LA PATENTE */
int comparar_modelo(Tcad cad1,Autos cad2); /* COMPARAMOS UNA CADENA CON EL MODELO */
int comparar_marca(Tcad cad1,Autos cad2); /* COMPARAMOS UNA CADENA CON LA MARCA */
	
#endif
