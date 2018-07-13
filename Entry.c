/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Entry.h"

/**************************** GETTERS ************************************************************/
int eEntry_getId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eEntry*)this)->idEntry;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_getServiceId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eEntry*)this)->serviceId;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_getGravedad(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eEntry*)this)->gravedad;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eEntry_getDate(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eEntry*)this)->date;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eEntry_getTime(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eEntry*)this)->time;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eEntry_getMsg(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eEntry*)this)->msg;
    }
    return returnAux;
}
/**************************** SETTERS ************************************************************/
int eEntry_setId(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eEntry*)this)->idEntry = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_setServiceId(void* this, int serviceId)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eEntry*)this)->serviceId = serviceId;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_setGravedad(void* this, int gravedad)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eEntry*)this)->gravedad = gravedad;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_setDate(void* this, char* date)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && date != NULL)
    {
        strcpy(((eEntry*)this)->date, date);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_setTime(void* this, char* time)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && time != NULL)
    {
        strcpy(((eEntry*)this)->time, time);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eEntry_setMsg(void* this, char* msg)

{
    int returnAux = CHECK_POINTER;
    if(this != NULL && msg != NULL)
    {
        strcpy(((eEntry*)this)->msg, msg);
        returnAux = OK;
    }
    return returnAux;
}
/**************************** CONSTRUCTORES ******************************************************/
void* eEntry_new()
{
    void* entry;

    entry = malloc(sizeof(eEntry));

    return entry;
}
//-----------------------------------------------------------------------------------------------//
void* eEntry_newParam(int id, int serviceId, char* date, char* time, int gravedad, char* msg)
{
    void* entry;

    entry = eEntry_new();

    if(entry != NULL)
    {
        eEntry_setId(entry, id);
        eEntry_setServiceId(entry, serviceId);
        eEntry_setGravedad(entry, gravedad);
        eEntry_setDate(entry, date);
        eEntry_setTime(entry, time);
        eEntry_setMsg(entry, msg);
    }
    return entry;
}
/**************************** ENTRADA DE DATOS ***************************************************/
//char* eEntry_pedirNombre()
//{
//    return eString_newParam(ENTRY_MSJ_INGRESE_NOMBRE, ENTRY_MSJ_REINGRESE_NOMBRE, ENTRY_LARGO_NOMBRE);
//}
////-----------------------------------------------------------------------------------------------//
//char* eEntry_pedirDireccion()
//{
//    return eString_newParam(ENTRY_MSJ_INGRESE_DIRECCION, ENTRY_MSJ_REINGRESE_DIRECCION, ENTRY_LARGO_DIRECCION);
//}
////-----------------------------------------------------------------------------------------------//
//float eEntry_pedirTarjeta()
//{
//    return pedirFloatValido(ENTRY_MSJ_INGRESE_TARJETA, ENTRY_MSJ_REINGRESE_TARJETA, 0, ENTRY_LARGO_TARJETA);
//}
////-----------------------------------------------------------------------------------------------//
//void* eEntry_pedirEntry(ArrayList* this)
//{
//    void* entry;
//    char* nombre;
//    char* direccion;
//    float tarjeta;
//
//    if(this != NULL)
//    {
//        nombre = eEntry_pedirNombre();
//        direccion = eEntry_pedirDireccion();
//        tarjeta = eEntry_pedirTarjeta();
//
//        entry = eEntry_newParam(eGestion_siguienteId(this, eEntry_getId),
//                                            nombre,
//                                            direccion,
//                                            tarjeta);
//    }
//    return entry;
//}
/**************************** LISTADO DE DATOS ***************************************************/
void eEntry_mostrarUno(void* this)
{
    if(this != NULL)
    {
        printf(ENTRY_MOSTRAR_UNO_MASCARA,
               eEntry_getId(this),
               eEntry_getServiceId(this),
               eEntry_getDate(this),
               eEntry_getTime(this),
               eEntry_getGravedad(this),
               eEntry_getMsg(this));
    }
}
/**************************** GESTION DE DATOS ***************************************************/
//int eEntry_modificarUno(void* this)
//{
//    int returnAux = CHECK_POINTER;
//    eMenu menuModificar = {/*titulo del menu*/{"Que desea modificar?"},
//                           /*cantidad de opciones*/5,
//                           /*codigos*/{1,2,3,
//                                       9,0},
//                           /*descripciones*/"\n  1. Nombre"
//                                            "\n  2. Direccion"
//                                            "\n  3. Tarjeta"
//                                            "\n  9. FINALIZAR CAMBIOS"
//                                            "\n  0. CANCELAR"};
//    void* registro;
//    int opcion;
//    const int huboCambios = 1;
//    char finalizar = 'N';
//
//    if(this != NULL)
//    {
//        returnAux = OK;
//        registro = (eEntry*) this;
//        do
//        {
//            limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
//            imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
//
//            imprimirEnPantalla(ENTRY_MOSTRAR_UNO_CABECERA);
//            eEntry_mostrarUno(registro);
//            saltoDeLinea();
//
//            opcion = eMenu_pedirOpcion(&menuModificar);
//            switch(opcion)
//            {
//                case 1:
//                    eEntry_setNombre(registro, eEntry_pedirNombre());
//                    returnAux = huboCambios;
//                    break;
//                case 2:
//                    eEntry_setDireccion(registro, eEntry_pedirDireccion());
//                    returnAux = huboCambios;
//                    break;
//                case 3:
//                    eEntry_setTarjeta(registro, eEntry_pedirTarjeta());
//                    returnAux = huboCambios;
//                    break;
//                case 4:
//                    returnAux = huboCambios;
//                    break;
//                case 5:
//                    returnAux = huboCambios;
//                    break;
//                case 6:
//                    returnAux = huboCambios;
//                    break;
//                case 7:
//                    returnAux = huboCambios;
//                    break;
//                case 8:
//                    returnAux = huboCambios;
//                    break;
//                case 9:
//                    finalizar = 'S';
//                    break;
//                case 0:
//                    finalizar = 'S';
//                    returnAux = OK;
//                    break;
//            }
//        }
//        while(finalizar == 'N');
//    }
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
char* eEntry_parserATexto(void* this, int bufferSize)
{
    char* returnAux = NULL;
    void* entry;

    if(this != NULL)
    {
        returnAux = eString_new(bufferSize);

        if(returnAux != NULL)
        {
            entry = (eEntry*) this;
            strcpy(returnAux, "");
            strcat(returnAux, intToChar(eEntry_getId(entry)));
            strcat(returnAux, ";");
            strcat(returnAux, intToChar(eEntry_getId(entry)));
            strcat(returnAux, ";");
            strcat(returnAux, "\n");
        }
    }

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void* eEntry_parserAVoid(char* this, int bufferSize)
{
    void* returnAux = NULL;
    int serviceId, gravedad;
    char date[ENTRY_LARGO_DATE];
    char time[ENTRY_LARGO_TIME];
    char msg[ENTRY_LARGO_MSG];

    if(this != NULL)
    {
        sscanf(this, "%[^;];%[^;];%d;%d;%[^\n]\n", date, time, &serviceId, &gravedad, msg);
        returnAux = eEntry_newParam(0, serviceId, date, time, gravedad, msg);
        eEntry_mostrarUno(returnAux);pausa();
    }

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void eEntry_cargarTxt(ArrayList* this)
{
    eEntry* pElement;
    eGestion_cargarArchivoTexto(this,
                                eEntry_parserAVoid,
                                eEntry_compararPorId,
                                GESTION_CARGAR_ARCHIVO_TEXTO_TITULO,
                                2000);
    for(int i=0 ; i<this->len(this) ; i++)
    {
        pElement = (eEntry*)this->get(this, i);
        eEntry_setId(pElement, i+1);
    }
}
/**************************** ORDENAMIENTO *******************************************************/
int eEntry_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eEntry_getId);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
//int eEntry_compararPorNombre(void* this, void* that)
//{
//    int returnAux;
//
//    if(this != NULL && that != NULL)
//    {
//        eGestion_compararPorString(this, that, eEntry_getMsg)
//    }
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
//int eEntry_ordenarPorNombre(ArrayList* this)
//{
//    int returnAux = CHECK_POINTER;
//
//    if(this != NULL)
//    {
//        returnAux = OK;
//        this->sort(this, eEntry_compararPorNombre, ASC);
//    }
//    return returnAux;
//}
////-----------------------------------------------------------------------------------------------//
//int eEntry_ordenarPorTarjeta(ArrayList* this)
//{
//    int returnAux = CHECK_POINTER;
//
//    if(this != NULL)
//    {
//        returnAux = OK;
//        this->sort(this, eEntry_compararPorTarjeta, ASC);
//    }
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
