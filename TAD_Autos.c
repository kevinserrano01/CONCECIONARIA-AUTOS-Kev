#include <stdio.h>
#include <string.h>
#include "TAD_Autos.h"

void mostrarMetodo(Compra aux); /* MOSTRAR REGISTRO DE TIPO DE COMPRA */

Compra cargar_compra(){ /* MODULO CREADO POR SERRANO */
	Compra aux;
	printf("\nIngrese las cuotas: ");
	scanf("%d",&aux.Cuotas);
	printf("\nIngrese la garantia (en anios): ");
	scanf("%d",&aux.Garantia);
	return aux; //retorna un solo registro
}
Autos cargar_auto(int id){ /* MODULO CREADO POR SERRANO */
	Autos aux;
	strcpy(aux.Categoria, "AUTOS"); //asiganar automaticamente autos
	printf("\nIngrese la marca: ");	
	fflush(stdin);
	leeCad(aux.Marca,TMAXCAD);
	printf("\nIngrese el modelo: ");	
	fflush(stdin);
	leeCad(aux.Modelo,TMAXCAD);
	printf("\nIngrese el stock: ");
	scanf("%d",&aux.Stock);
	printf("\nIngrese la patente: ");
	fflush(stdin);
	leeCad(aux.Patente,TMAXCAD);
	printf("\nIngrese el precio: ");
	scanf("%f",&aux.Precio);
	printf("\nIngrese el color: ");	
	fflush(stdin);
	leeCad(aux.Color,TMAXCAD);
	fflush(stdin);
	aux.MetodoCompra = cargar_compra();
	aux.Identificador = id;
	return aux;
}

void mostrar_auto_del_inventario(Autos aux){ /* MODULO CREADO POR GÁLVEZ */
	printf("\n*************************************************************************");
	printf("\nCategoria: %s",aux.Categoria);	
	printf("\t\tMarca: %s",aux.Marca);	
	printf("\t\tModelo: %s",aux.Modelo);	
	printf("\nStock disponibles: %d",aux.Stock);
	printf("\t\tPatente: %s",aux.Patente);	
	printf("\nPrecio: $%.2f",aux.Precio);	
	printf("\t\tColor: %s",aux.Color);	
	mostrarMetodo(aux.MetodoCompra);
	printf("\nIdentificador: %d",aux.Identificador);
	printf("\n*************************************************************************\n");
}
	
void mostrar_auto_del_catalogo(Autos aux){ /* MODULO CREADO POR GÁLVEZ */
	printf("\n*************************************************************************");
	printf("\nMarca: %s",aux.Marca);	
	printf("\t\t\tModelo: %s",aux.Modelo);	
	printf("\nPrecio: $%.2f",aux.Precio);	
	printf("\t\tColor: %s",aux.Color);	
	mostrarMetodo(aux.MetodoCompra);
	printf("\nIdentificador: %d",aux.Identificador);
	printf("\n*************************************************************************\n");
}
void mostrarMetodo(Compra aux){ /* MODULO CREADO POR SERRANO */
	printf("\nCuotas disponibles: %d",aux.Cuotas);	
	if(aux.Garantia == 1) printf("\nGarantia: %d Anio",aux.Garantia);
	else printf("\nGarantias: %d Anios",aux.Garantia);
}	
void modificar_p(Autos *aux){/*MODULO CREADO POR ARAMAYO*/
	printf("\nIngrese el nuevo precio: ");
	scanf("%f",&aux->Precio);
}
void modificar_c(Autos *aux){/*MODULO CREADO POR GÁLVEZ*/
	printf("\nIngrese las nuevas cuotas: ");
	scanf("%d",&aux->MetodoCompra.Cuotas);
}
void modificar_s(Autos *aux){/*MODULO CREADO POR ARAMAYO*/
	printf("\nIngrese el nuevo stock: ");
	scanf("%d",&aux->Stock);
}
void modificar_g(Autos *aux){/*MODULO CREADO POR GÁLVEZ*/
	printf("\nIngrese la nueva garantia: ");
	scanf("%d",&aux->MetodoCompra.Garantia);
}
int retornar_identificador(Autos aux){ /* MODULO CREADO POR: ARAMAYO */
	return aux.Identificador;
}
int compara_identificador(Autos auto1, Autos auto2){ /* MODULO CREADO POR ARAMAYO */
	if(auto1.Identificador > auto2.Identificador){
		return 1;
	}else if(auto2.Identificador > auto1.Identificador){
		return -1;
	}else return 0;
}
int retornar_stock(Autos aux){ /* MODULO CREADO POR: ARAMAYO */
	return aux.Stock;
}
void restar_stock(Autos *aux, int nro){/* MODULO CREADO POR: SERRANO */
	aux->Stock -= nro;
}
int comparar_patente(Tcad cad1,Autos cad2){ /* MODULO CREADO POR: GÁLVEZ */ // retornara 1 si son iguales, 2 si no son iguales
	int resultado;
	resultado = strcmp(strupr(cad1),strupr(cad2.Patente));
	if(resultado == 0) return 1;
	else return 0;
}
int comparar_modelo(Tcad cad1,Autos cad2){/* MODULO CREADO POR: GÁLVEZ */ // retornara 1 si son iguales, 2 si no son iguales
	int resultado;
	resultado = strcmp(strupr(cad1),strupr(cad2.Modelo));
	if(resultado == 0) return 1;
	else return 0;
}
int comparar_marca(Tcad cad1,Autos cad2){/* MODULO CREADO POR: GÁLVEZ */ // retornara 1 si son iguales, 2 si no son iguales
	int resultado;
	resultado = strcmp(strupr(cad1),strupr(cad2.Marca));
	if(resultado == 0) return 1;
	else return 0;
}
