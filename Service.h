#pragma once
#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

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
#define SERVICE_CANT_MAX 10
#define SERVICE_LARGO_NAME 33
#define SERVICE_LARGO_EMAIL 65
#define SERVICE_ID_MIN 1
#define SERVICE_ID_MAX 1000000

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    //------------id
    int idService;
    //------------properties
    char name[SERVICE_LARGO_NAME];
    char email[SERVICE_LARGO_EMAIL];
}eService;


/**************************** GETTERS ************************************************************/
int eService_getId(void* this);
char* eService_getName(void* this);
char* eService_getEmail(void* this);

/**************************** SETTERS ************************************************************/
int eService_setId(void* this, int id);
int eService_setName(void* this, char* name);
int eService_setEmail(void* this, char* email);

/**************************** CONSTRUCTORES ******************************************************/
void* eService_new();
void* eService_newParam(int id, char* name, char* email);

/**************************** ENTRADA DE DATOS ***************************************************/
//char* eService_pedirName();
//char* eService_pedirEmail();
//float eService_pedirTarjeta();
//void* eService_pedirService(ArrayList* this);

/**************************** GESTION DE DATOS ***************************************************/
int eService_modificarUno(void* this);
char* eService_parserATexto(void* this, int bufferSize);
void* eService_parserAVoid(char* this, int bufferSize);
void eService_cargarTxt(ArrayList* this);

/**************************** LISTADO DE DATOS ***************************************************/
void eService_mostrarUno(void* service);

/**************************** ORDENAMIENTO *******************************************************/
int eService_compararPorId(void* this, void* that);
int eService_compararPorName(void* this, void* that);
int eService_compararPorEmail(void* this, void* that);
int eService_ordenarPorName(ArrayList* this);

/**************************** TITULOS ************************************************************/
#define SERVICE_ALTA_TITULO "ALTA DE SERVICE"
#define SERVICE_MODIFICACION_TITULO "MODIFICACION DE SERVICE"
#define SERVICE_BAJA_TITULO "BAJA DE SERVICE"
#define SERVICE_LISTADO_TITULO "LISTADO DE SERVICES"

/**************************** MENSAJES INPUT *****************************************************/
#define SERVICE_MSJ_INGRESE_ID "\n\nIngrese el ID de Service: \0"
#define SERVICE_MSJ_INGRESE_NAME "\nIngrese Name y Apellido: \0"
#define SERVICE_MSJ_INGRESE_EMAIL "\nIngrese email: \0"
#define SERVICE_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"
#define SERVICE_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Service?"

/**************************** MENSAJES ERROR *****************************************************/
#define SERVICE_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define SERVICE_MSJ_ID_NO_EXISTE "\nEl ID de Service ingresado no existe"
#define SERVICE_MSJ_LISTA_VACIA "\n\nLa lista de Services esta vacia"
#define SERVICE_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Service"
#define SERVICE_MSJ_REINGRESE_NAME "\nName muy largo. Reingrese por favor: \0"
#define SERVICE_MSJ_REINGRESE_EMAIL "\nEmail muy larga. Reingrese por favor: \0"
#define SERVICE_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define SERVICE_MSJ_ALTA_OK "\nEl Service se dio de alta"
#define SERVICE_MSJ_BAJA_OK "\nEl Service se dio de baja"
#define SERVICE_MSJ_MODIFICACION_OK "\nEl Service se modifico"
#define SERVICE_MSJ_REGISTRO_ACTUAL "\n\nService actual: "
#define SERVICE_MSJ_REGISTRO_MODIFICADO "\n\nService modificado: "

/**************************** LISTADOS ***********************************************************/
#define SERVICE_MOSTRAR_UNO_MASCARA "\n%d \t %-10s \t %-20s"
#define SERVICE_MOSTRAR_UNO_CABECERA "\nID \t NAME \t\t EMAIL\n-- \t ---- \t\t -----"
#define SERVICE_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define SERVICE_ORDEN_NAME "nameAsc"
#define SERVICE_ORDEN_ID "idAsc"

#endif // SERVICE_H_INCLUDED
