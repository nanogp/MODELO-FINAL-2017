#pragma once
#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "ArrayList.h"
#include "Entry.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************** LIMITES ************************************************************/
#define STATS_CANT_MAX 10
#define STATS_LARGO_DATE 11
#define STATS_LARGO_TIME 6
#define STATS_LARGO_MSG 65
#define STATS_ID_MIN 1
#define STATS_ID_MAX 1000000

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    //------------id
    int idStats;
    //------------properties
    char name[SERVICE_LARGO_NAME];
    int gravedad;
    int cantidad;
}eStats;

/**************************** GETTERS ************************************************************/
int eStats_getId(void* this);
char* eStats_getName(void* this);
int eStats_getGravedad(void* this);
int eStats_getCantidad(void* this);

/**************************** SETTERS ************************************************************/
int eStats_setId(void* this, int id);
int eStats_setServiceId(void* this, char* name);
int eStats_setGravedad(void* this, int gravedad);
int eStats_setCantidad(void* this, int cantidad);

/**************************** CONSTRUCTORES ******************************************************/
void* eStats_new();
void* eStats_newParam(int id, char* name, int gravedad, int cantidad);

/**************************** ENTRADA DE DATOS ***************************************************/

/**************************** GESTION DE DATOS ***************************************************/
int eStats_modificarUno(void* this);
char* eStats_parserATexto(void* this, int bufferSize);
void* eStats_parserAVoid(char* this, int bufferSize);
void eStats_cargarTxt(ArrayList* this);
void eStats_mostrar(ArrayList* this, ArrayList* entries, ArrayList* services);

/**************************** LISTADO DE DATOS ***************************************************/
void eStats_mostrarUno(void* entry);

/**************************** ORDENAMIENTO *******************************************************/
int eStats_compararPorId(void* this, void* that);
int eStats_compararPorNombre(void* this, void* that);
int eStats_compararPorDireccion(void* this, void* that);
int eStats_compararPorTarjeta(void* this, void* that);
int eStats_ordenarPorNombre(ArrayList* this);
int eStats_ordenarPorTarjeta(ArrayList* this);

/**************************** TITULOS ************************************************************/
#define STATS_ALTA_TITULO "ALTA DE STATS"
#define STATS_MODIFICACION_TITULO "MODIFICACION DE STATS"
#define STATS_BAJA_TITULO "BAJA DE STATS"
#define STATS_LISTADO_TITULO "LISTADO DE STATSS"

/**************************** MENSAJES INPUT *****************************************************/
#define STATS_MSJ_INGRESE_ID "\n\nIngrese el ID de Stats: \0"
#define STATS_MSJ_INGRESE_NOMBRE "\nIngrese Nombre y Apellido: \0"
#define STATS_MSJ_INGRESE_DIRECCION "\nIngrese direccion: \0"
#define STATS_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"
#define STATS_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Stats?"

/**************************** MENSAJES ERROR *****************************************************/
#define STATS_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define STATS_MSJ_ID_NO_EXISTE "\nEl ID de Stats ingresado no existe"
#define STATS_MSJ_LISTA_VACIA "\n\nLa lista de Statss esta vacia"
#define STATS_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Stats"
#define STATS_MSJ_REINGRESE_NOMBRE "\nNombre muy largo. Reingrese por favor: \0"
#define STATS_MSJ_REINGRESE_DIRECCION "\nDireccion muy larga. Reingrese por favor: \0"
#define STATS_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define STATS_MSJ_ALTA_OK "\nEl Stats se dio de alta"
#define STATS_MSJ_BAJA_OK "\nEl Stats se dio de baja"
#define STATS_MSJ_MODIFICACION_OK "\nEl Stats se modifico"
#define STATS_MSJ_REGISTRO_ACTUAL "\n\nStats actual: "
#define STATS_MSJ_REGISTRO_MODIFICADO "\n\nStats modificado: "

/**************************** LISTADOS ***********************************************************/
#define STATS_MOSTRAR_UNO_MASCARA "\n%d \t %d \t\t %-10s \t\t %s \t %d  \t %s"
#define STATS_MOSTRAR_UNO_CABECERA "\nID \t ID SERVICIO \t DATE \t\t\t TIME \t GRAVEDAD \t MSG\n-- \t ----------- \t ---- \t\t\t ---- \t -------- \t ---"
#define STATS_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define STATS_ORDEN_NOMBRE "nombreAsc"
#define STATS_ORDEN_ID "idAsc"

#endif // STATS_H_INCLUDED
