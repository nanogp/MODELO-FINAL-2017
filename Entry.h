#pragma once
#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "ArrayList.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************** LIMITES ************************************************************/
#define ENTRY_CANT_MAX 10
#define ENTRY_LARGO_DATE 11
#define ENTRY_LARGO_TIME 6
#define ENTRY_LARGO_MSG 65
#define ENTRY_ID_MIN 1
#define ENTRY_ID_MAX 1000000

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    //------------id
    int idEntry;
    int serviceId;
    //------------properties
    char date[ENTRY_LARGO_DATE];
    char time[ENTRY_LARGO_TIME];
    int gravedad;
    char msg[ENTRY_LARGO_MSG];
}eEntry;


/**************************** GETTERS ************************************************************/
int eEntry_getId(void* this);
int eEntry_getServiceId(void* this);
int eEntry_getGravedad(void* this);
char* eEntry_getDate(void* this);
char* eEntry_getTime(void* this);
char* eEntry_getMsg(void* this);

/**************************** SETTERS ************************************************************/
int eEntry_setId(void* this, int id);
int eEntry_setServiceId(void* this, int serviceId);
int eEntry_setGravedad(void* this, int gravedad);
int eEntry_setDate(void* this, char* date);
int eEntry_setTime(void* this, char* time);
int eEntry_setMsg(void* this, char* msg);

/**************************** CONSTRUCTORES ******************************************************/
void* eEntry_new();
void* eEntry_newParam(int id, int serviceId, char* date, char* time, int gravedad, char* msg);

/**************************** ENTRADA DE DATOS ***************************************************/
int eEntry_pedirServiceId();
char* eEntry_pedirDate();
char* eEntry_pedirTime();
int eEntry_pedirGravedad(ArrayList* this);
char* eEntry_pedirMsg(ArrayList* this);

/**************************** GESTION DE DATOS ***************************************************/
int eEntry_modificarUno(void* this);
char* eEntry_parserATexto(void* this, int bufferSize);
void* eEntry_parserAVoid(char* this, int bufferSize);
void eEntry_cargarTxt(ArrayList* this);

/**************************** LISTADO DE DATOS ***************************************************/
void eEntry_mostrarUno(void* entry);

/**************************** ORDENAMIENTO *******************************************************/
int eEntry_compararPorId(void* this, void* that);
int eEntry_compararPorNombre(void* this, void* that);
int eEntry_compararPorDireccion(void* this, void* that);
int eEntry_compararPorTarjeta(void* this, void* that);
int eEntry_ordenarPorNombre(ArrayList* this);
int eEntry_ordenarPorTarjeta(ArrayList* this);

/**************************** TITULOS ************************************************************/
#define ENTRY_ALTA_TITULO "ALTA DE ENTRY"
#define ENTRY_MODIFICACION_TITULO "MODIFICACION DE ENTRY"
#define ENTRY_BAJA_TITULO "BAJA DE ENTRY"
#define ENTRY_LISTADO_TITULO "LISTADO DE ENTRYS"

/**************************** MENSAJES INPUT *****************************************************/
#define ENTRY_MSJ_INGRESE_ID "\n\nIngrese el ID de Entry: \0"
#define ENTRY_MSJ_INGRESE_NOMBRE "\nIngrese Nombre y Apellido: \0"
#define ENTRY_MSJ_INGRESE_DIRECCION "\nIngrese direccion: \0"
#define ENTRY_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"
#define ENTRY_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Entry?"

/**************************** MENSAJES ERROR *****************************************************/
#define ENTRY_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define ENTRY_MSJ_ID_NO_EXISTE "\nEl ID de Entry ingresado no existe"
#define ENTRY_MSJ_LISTA_VACIA "\n\nLa lista de Entrys esta vacia"
#define ENTRY_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Entry"
#define ENTRY_MSJ_REINGRESE_NOMBRE "\nNombre muy largo. Reingrese por favor: \0"
#define ENTRY_MSJ_REINGRESE_DIRECCION "\nDireccion muy larga. Reingrese por favor: \0"
#define ENTRY_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define ENTRY_MSJ_ALTA_OK "\nEl Entry se dio de alta"
#define ENTRY_MSJ_BAJA_OK "\nEl Entry se dio de baja"
#define ENTRY_MSJ_MODIFICACION_OK "\nEl Entry se modifico"
#define ENTRY_MSJ_REGISTRO_ACTUAL "\n\nEntry actual: "
#define ENTRY_MSJ_REGISTRO_MODIFICADO "\n\nEntry modificado: "

/**************************** LISTADOS ***********************************************************/
#define ENTRY_MOSTRAR_UNO_MASCARA "\n%d \t %d \t %-10s \t %-20s \t %d  \t %-20s"
#define ENTRY_MOSTRAR_UNO_CABECERA "\nID \t ID SERVICIO \t DATE \t\t TIME \t GRAVEDAD \t MSG\n-- \t ----------- \t ---- \t ---- \t -------- \t ---"
#define ENTRY_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define ENTRY_ORDEN_NOMBRE "nombreAsc"
#define ENTRY_ORDEN_ID "idAsc"

#endif // ENTRY_H_INCLUDED
