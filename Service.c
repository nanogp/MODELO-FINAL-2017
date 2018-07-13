/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Service.h"

/**************************** GETTERS ************************************************************/
int eService_getId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eService*)this)->idService;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eService_getName(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eService*)this)->name;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eService_getEmail(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eService*)this)->email;
    }
    return returnAux;
}
/**************************** SETTERS ************************************************************/
int eService_setId(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eService*)this)->idService = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eService_setName(void* this, char* name)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && name != NULL)
    {
        strcpy(((eService*)this)->name, name);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eService_setEmail(void* this, char* email)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && email != NULL)
    {
        strcpy(((eService*)this)->email, email);
        returnAux = OK;
    }
    return returnAux;
}
/**************************** CONSTRUCTORES ******************************************************/
void* eService_new()
{
    void* service;

    service = malloc(sizeof(eService));

    return service;
}
//-----------------------------------------------------------------------------------------------//
void* eService_newParam(int id, char* name, char* email)
{
    void* service;

    service = eService_new();

    if(service != NULL)
    {
        eService_setId(service, id);
        eService_setName(service, name);
        eService_setEmail(service, email);
    }
    return service;
}
/**************************** ENTRADA DE DATOS ***************************************************/
//char* eService_pedirName()
//{
//    return eString_newParam(SERVICE_MSJ_INGRESE_NAME, SERVICE_MSJ_REINGRESE_NAME, SERVICE_LARGO_NAME);
//}
////-----------------------------------------------------------------------------------------------//
//char* eService_pedirEmail()
//{
//    return eString_newParam(SERVICE_MSJ_INGRESE_EMAIL, SERVICE_MSJ_REINGRESE_EMAIL, SERVICE_LARGO_EMAIL);
//}
////-----------------------------------------------------------------------------------------------//
//void* eService_pedirService(ArrayList* this)
//{
//    void* service;
//    char* name;
//    char* email;
//    float tarjeta;
//
//    if(this != NULL)
//    {
//        name = eService_pedirName();
//        email = eService_pedirEmail();
//        tarjeta = eService_pedirTarjeta();
//
//        service = eService_newParam(eGestion_siguienteId(this, eService_getId),
//                                            name,
//                                            email,
//                                            tarjeta);
//    }
//    return service;
//}
/**************************** LISTADO DE DATOS ***************************************************/
void eService_mostrarUno(void* this)
{
    if(this != NULL)
    {
        printf(SERVICE_MOSTRAR_UNO_MASCARA,
               eService_getId(this),
               eService_getName(this),
               eService_getEmail(this));
    }
}
/**************************** GESTION DE DATOS ***************************************************/
//int eService_modificarUno(void* this)
//{
//    int returnAux = CHECK_POINTER;
//    eMenu menuModificar = {/*titulo del menu*/{"Que desea modificar?"},
//                           /*cantidad de opciones*/5,
//                           /*codigos*/{1,2,3,
//                                       9,0},
//                           /*descripciones*/"\n  1. Name"
//                                            "\n  2. Email"
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
//        registro = (eService*) this;
//        do
//        {
//            limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
//            imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
//
//            imprimirEnPantalla(SERVICE_MOSTRAR_UNO_CABECERA);
//            eService_mostrarUno(registro);
//            saltoDeLinea();
//
//            opcion = eMenu_pedirOpcion(&menuModificar);
//            switch(opcion)
//            {
//                case 1:
//                    eService_setName(registro, eService_pedirName());
//                    returnAux = huboCambios;
//                    break;
//                case 2:
//                    eService_setEmail(registro, eService_pedirEmail());
//                    returnAux = huboCambios;
//                    break;
//                case 3:
//                    eService_setTarjeta(registro, eService_pedirTarjeta());
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
//char* eService_parserATexto(void* this, int bufferSize)
//{
//    char* returnAux = NULL;
//    void* service;
//
//    if(this != NULL)
//    {
//        returnAux = eString_new(bufferSize);
//
//        if(returnAux != NULL)
//        {
//            service = (eService*) this;
//            strcpy(returnAux, "");
//            strcat(returnAux, intToChar(eService_getId(service)));
//            strcat(returnAux, ",");
//            strcat(returnAux, eService_getName(service));
//            strcat(returnAux, ",");
//            strcat(returnAux, eService_getEmail(service));
//            strcat(returnAux, ",");
//            strcat(returnAux, floatToChar(eService_getTarjeta(service), 0));
//            strcat(returnAux, "\n");
//        }
//    }
//
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
void* eService_parserAVoid(char* this, int bufferSize)
{
    void* returnAux = NULL;
    int id;
    char name[SERVICE_LARGO_NAME];
    char email[SERVICE_LARGO_EMAIL];

    if(this != NULL)
    {
        sscanf(this, "%d;%[^;];%[^\n]\n", &id, name, email);
        returnAux = eService_newParam(id, name, email);
    }

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void eService_cargarTxt(ArrayList* this)
{
    eGestion_cargarArchivoTexto(this,
                                eService_parserAVoid,
                                eService_compararPorId,
                                "CARGAR ARCHIVO SERVICES",
                                2000);
}
/**************************** ORDENAMIENTO *******************************************************/
int eService_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eService_getId);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eService_compararPorName(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorString(this, that, eService_getName);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eService_ordenarPorName(ArrayList* this)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL)
    {
        returnAux = OK;
        this->sort(this, eService_compararPorName, ASC);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
