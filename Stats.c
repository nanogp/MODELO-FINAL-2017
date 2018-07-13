/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Stats.h"

/**************************** GETTERS ************************************************************/
int eStats_getId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eStats*)this)->idStats;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eStats_getName(void* this)
{
    char* returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eStats*)this)->name;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eStats_getGravedad(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eStats*)this)->gravedad;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eStats_getCantidad(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eStats*)this)->cantidad;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
/**************************** SETTERS ************************************************************/
int eStats_setId(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eStats*)this)->idStats = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eStats_setName(void* this, char* name)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        strcpy(((eStats*)this)->name,name);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eStats_setGravedad(void* this, int gravedad)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eStats*)this)->gravedad = gravedad;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eStats_setCantidad(void* this, int cantidad)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eStats*)this)->cantidad = cantidad;
        returnAux = OK;
    }
    return returnAux;
}
/**************************** CONSTRUCTORES ******************************************************/
void* eStats_new()
{
    void* entry;

    entry = malloc(sizeof(eStats));

    return entry;
}
//-----------------------------------------------------------------------------------------------//
void* eStats_newParam(int id, char* name, int gravedad, int cantidad)
{
    void* entry;

    entry = eStats_new();

    if(entry != NULL)
    {
        eStats_setId(entry, id);
        eStats_setName(entry, name);
        eStats_setGravedad(entry, gravedad);
        eStats_setCantidad(entry, cantidad);
    }
    return entry;
}
/**************************** LISTADO DE DATOS ***************************************************/
void eStats_mostrar(ArrayList* this, ArrayList* entries, ArrayList* services)
{
    void* entry;
    void* service;
    void* stat;
    int seMostroCabecera = 0;
    int crear;
    int menosTres;
    int tres;
    int cuatroSiete;
    int masSiete;

    while(this->len(this) > 0) //vaciar lista
    {
        stat = this->pop(this, 0);
        free(stat);
    }

    //pueblo array
    if(this != NULL && entries != NULL && services != NULL)
    {
        for(int i=0 ; i<entries->len(entries) ; i++)
        {
            entry = this->get(this, i);
            service = eGestion_buscarPorId(services, eService_getId, eEntry_getServiceId(entry));
            crear = 1;

            if(this->len(this) != 0)
            {
                for(int j=0 ; j<this->len(this) ; j++)
                {
                    stat = this->get(this, j);
                    if(strcmp(eStats_getName(stat), eService_getName(service)) == 0)//existe el servicio
                    {
                        if(eStats_getGravedad(stat) - eStats_getGravedad(stat) == 0)//existe gravedad
                        {
                            crear = 0;
                            eStats_setCantidad(stat, (eStats_getCantidad(stat)+1));
                            break;
                        }
                    }
                }
            }

            if(crear)
            {
                stat = eStats_newParam(eGestion_siguienteId(this, eStats_getId),
                                       eService_getName(service),
                                       eEntry_getGravedad(entry),
                                       1);
                this->add(this, stat);
            }
        }
    }
    else
    {
        imprimirEnPantalla("\n error de asignacion de punteros");
    }

    //ahora busco maximos
    for(int i=0 ; i<this->len(this) ; i++)
    {
        stat = this->get(this, i);

        if(i==0)
        {
            menosTres = eStats_getId(stat);
            tres = menosTres;
            cuatroSiete = menosTres;
            masSiete = menosTres;
        }
        else
        {
            if(eStats_getGravedad(stat) < 3)
            {

            }
        }

//Deberá indicar el servicio que más fallos tiene y la cantidad de fallos para los
//siguientes valores de gravedad:
//• Menores a 3
//• 3
//• 4 y 7 (inclusive)
//• Mayores a 7
    }

    pausa();
}
/**************************** ORDENAMIENTO *******************************************************/
int eStats_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eStats_getId);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
//int eStats_compararPorNombre(void* this, void* that)
//{
//    int returnAux;
//
//    if(this != NULL && that != NULL)
//    {
//        eGestion_compararPorString(this, that, eStats_getMsg)
//    }
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
//int eStats_ordenarPorNombre(ArrayList* this)
//{
//    int returnAux = CHECK_POINTER;
//
//    if(this != NULL)
//    {
//        returnAux = OK;
//        this->sort(this, eStats_compararPorNombre, ASC);
//    }
//    return returnAux;
//}
////-----------------------------------------------------------------------------------------------//
//int eStats_ordenarPorTarjeta(ArrayList* this)
//{
//    int returnAux = CHECK_POINTER;
//
//    if(this != NULL)
//    {
//        returnAux = OK;
//        this->sort(this, eStats_compararPorTarjeta, ASC);
//    }
//    return returnAux;
//}
//-----------------------------------------------------------------------------------------------//
