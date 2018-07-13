#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "Entry.h"
#include "Service.h"


int main()
{
    int returnAux;
    eMenu menuPrincipal = {/*titulo del menu*/{"ESTACIONAMIENTO"},
                           /*cantidad de opciones*/17,
                           /*codigos*/{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
                           0},
                           /*descripciones*/{"\n 1. Alta Service"
                                             "\n 2. Modificacion Service"
                                             "\n 3. Baja Service"
                                             "\n 4. Ingreso del Entry"
                                             "\n 5. Modificacion Entry"
                                             "\n 6. Egreso del Entry"
                                             "\n 7. Cargar Archivo Datos Services"
                                             "\n 8. Guardar Archivo Datos Services"
                                             "\n 9. Cargar Archivo CSV Services"
                                             "\n10. Guardar Archivo CSV Services"
                                             "\n11. Cargar Archivo Datos Entryes"
                                             "\n12. Guardar Archivo Datos Entryes"
                                             "\n13. Cargar Archivo CSV Entryes"
                                             "\n14. Guardar Archivo CSV Entryes"
                                             "\n15. Listar Entryes"
                                             "\n16. Listar Services"
                                             "\n 0. Salir del programa"}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ArrayList* listadoService = al_newArrayList();
    ArrayList* listadoEntry = al_newArrayList();

    if(listadoService == NULL || listadoEntry == NULL)
    {
        returnAux = CHECK_POINTER;
    }

    while(salirDelPrograma == 'N')
    {
        limpiarPantalla();
        opcion = eMenu_pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
//                eGestion_alta(listadoService,
//                              eService_pedirService,
//                              eService_mostrarUno,
//                              eService_compararPorId,
//                              SERVICE_ALTA_TITULO,
//                              SERVICE_MOSTRAR_UNO_CABECERA,
//                              SERVICE_MSJ_ALTA_OK);
                break;
            case 2:
//                eGestion_modificacion(listadoService,
//                                      eService_modificarUno,
//                                      eService_mostrarUno,
//                                      eService_getId,
//                                      eService_new,
//                                      eService_compararPorId,
//                                      sizeof(eService),
//                                      SERVICE_MODIFICACION_TITULO,
//                                      SERVICE_LISTADO_TITULO,
//                                      SERVICE_MOSTRAR_UNO_CABECERA,
//                                      SERVICE_MSJ_LISTA_VACIA,
//                                      SERVICE_MSJ_MODIFICACION_OK,
//                                      SERVICE_MSJ_INGRESE_ID,
//                                      SERVICE_MSJ_REINGRESE_ID,
//                                      SERVICE_ID_MIN,
//                                      SERVICE_ID_MAX,
//                                      SERVICE_MOSTRAR_UNO_PAGINADO);
              break;
            case 3:
//                eGestion_baja(listadoService,
//                              eService_mostrarUno,
//                              eService_getId,
//                              eService_compararPorId,
//                              sizeof(eService),
//                              SERVICE_BAJA_TITULO,
//                              SERVICE_LISTADO_TITULO,
//                              SERVICE_MOSTRAR_UNO_CABECERA,
//                              SERVICE_MSJ_LISTA_VACIA,
//                              SERVICE_MSJ_CONFIRMAR_BAJA,
//                              SERVICE_MSJ_BAJA_OK,
//                              SERVICE_MSJ_INGRESE_ID,
//                              SERVICE_MSJ_REINGRESE_ID,
//                              SERVICE_ID_MIN,
//                              SERVICE_ID_MAX,
//                              SERVICE_MOSTRAR_UNO_PAGINADO);

                break;
            case 4:
//                eGestion_altaForeign(listadoEntry,
//                                     listadoService,
//                                     eEntry_pedirEntry,
//                                     eEntry_mostrarUno,
//                                     eEntry_compararPorPatente,
//                                     ENTRY_ALTA_TITULO,
//                                     ENTRY_MOSTRAR_UNO_CABECERA,
//                                     SERVICE_MSJ_LISTA_VACIA,
//                                     ENTRY_MSJ_ALTA_OK);
                break;
            case 5:
//                eGestion_modificacion(listadoEntry,
//                                      eEntry_modificarUno,
//                                      eEntry_mostrarUno,
//                                      eEntry_getId,
//                                      eEntry_new,
//                                      eEntry_compararPorId,
//                                      sizeof(eEntry),
//                                      ENTRY_MODIFICACION_TITULO,
//                                      ENTRY_LISTADO_TITULO,
//                                      ENTRY_MOSTRAR_UNO_CABECERA,
//                                      ENTRY_MSJ_LISTA_VACIA,
//                                      ENTRY_MSJ_MODIFICACION_OK,
//                                      ENTRY_MSJ_INGRESE_ID,
//                                      ENTRY_MSJ_REINGRESE_ID,
//                                      ENTRY_ID_MIN,
//                                      ENTRY_ID_MAX,
//                                      ENTRY_MOSTRAR_UNO_PAGINADO);
                break;
            case 6:
//                eGestion_baja(listadoEntry,
//                              eEntry_mostrarUno,
//                              eEntry_getId,
//                              eEntry_compararPorId,
//                              sizeof(eEntry),
//                              ENTRY_BAJA_TITULO,
//                              ENTRY_LISTADO_TITULO,
//                              ENTRY_MOSTRAR_UNO_CABECERA,
//                              ENTRY_MSJ_LISTA_VACIA,AVoid
//                              ENTRY_MSJ_CONFIRMAR_BAJA,
//                              ENTRY_MSJ_BAJA_OK,
//                              ENTRY_MSJ_INGRESE_ID,
//                              ENTRY_MSJ_REINGRESE_ID,
//                              ENTRY_ID_MIN,
//                              ENTRY_ID_MAX,
//                              ENTRY_MOSTRAR_UNO_PAGINADO);

                break;
            case 7:
//                eGestion_cargarArchivoDatos(listadoService,
//                                            eService_compararPorId,
//                                            eService_new,
//                                            sizeof(eService),
//                                            GESTION_CARGAR_ARCHIVO_DATOS_TITULO);
                break;
            case 8:
//                eGestion_guardarArchivoDatos(listadoService,
//                                             sizeof(eService),
//                                             GESTION_GUARDAR_ARCHIVO_DATOS_TITULO,
//                                             SERVICE_MSJ_LISTA_VACIA);
                break;
            case 9:
//                eGestion_cargarArchivoTexto(listadoService,
//                                            eService_parserAVoid,
//                                            eService_compararPorId,
//                                            GESTION_CARGAR_ARCHIVO_TEXTO_TITULO,
//                                            2000);
                break;
            case 10:
//                eGestion_guardarArchivoTexto(listadoService,
//                                             eService_parserATexto,
//                                             GESTION_GUARDAR_ARCHIVO_TEXTO_TITULO,
//                                             SERVICE_MSJ_LISTA_VACIA,
//                                             2000);
                break;
            case 11:

                break;
            case 12:

                break;
            case 13:
                eEntry_cargarTxt(listadoEntry);
                break;
            case 14:

                break;
            case 15:
                eGestion_listado(listadoEntry,
                                 eEntry_mostrarUno,
                                 ENTRY_LISTADO_TITULO,
                                 ENTRY_MOSTRAR_UNO_CABECERA,
                                 ENTRY_MSJ_LISTA_VACIA,
                                 ENTRY_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 16:
//                eGestion_listado(listadoService,
//                                 eService_mostrarUno,
//                                 SERVICE_LISTADO_TITULO,
//                                 SERVICE_MOSTRAR_UNO_CABECERA,
//                                 SERVICE_MSJ_LISTA_VACIA,
//                                 SERVICE_MOSTRAR_UNO_PAGINADO);
//                                 pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                returnAux = OK;
                break;
        }

    }
    return returnAux;
}
