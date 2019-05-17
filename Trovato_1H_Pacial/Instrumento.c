#ifndef INSTRUMENTO_C_INCLUDED
#define INSTRUMENTO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Instrumento.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define MAX_CARACTER 50
#define MIN_CARACTER 1
#define MAX_INSTRUMENTOS 20
#define CUERDAS 1
#define VIENTO_MADERA 2
#define VIENTO_METAL 3
#define PERCUSION 4

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumentos Array instrumentos
* \param limite int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int inst_alta(Instrumento instrumentos[], int limite, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(instrumentos!=NULL && limite>0 && contadorID!=NULL)
    {
        if(inst_buscarLugarVacio(instrumentos,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            instrumentos[posicion].idInstrumento=*contadorID;
            instrumentos[posicion].isEmpty=0;
            getName("\nIngrese nombre del instrumento: ","\nNombre invalido",MAX_CARACTER,MIN_CARACTER,2,instrumentos[posicion].nombre);
            getInt("\nIngrese tipo de instrumentos: \n1- Cuerdas\n 2-Viento-madera\n 3- Viento-metal\n 4- Percusion\n","\nTipo invalido",sizeof(int),1,2,&instrumentos[posicion].tipo);

            printf("\n Posicion: %d\n ID: %d\n NOMBRE DEL INSTRUMENTO: %s\n Tipo: %d\n",
                   posicion, instrumentos[posicion].idInstrumento,instrumentos[posicion].nombre,instrumentos[posicion].tipo);

            retorno=0;
        }
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array instrumentos Array de instrumentos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int inst_modificar(Instrumento instrumentos[], int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if(instrumentos!=NULL && limite>0)
    {
        inst_listar(instrumentos,MAX_INSTRUMENTOS);
        getInt("\nIngrese ID a modificar: ","\nError",sizeof(int),1,2,&id);
        if(inst_buscarID(instrumentos,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n Tipo de instrumento: %d\n",
                  posicion, instrumentos[posicion].idInstrumento,instrumentos[posicion].nombre,instrumentos[posicion].tipo);

                getInt("\nModificar:\n 1) Edad\n 2) ID de Orquesta del musico\n 3) Salir)\n","\nError",sizeof(int),1,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        getName("\nIngrese nombre del musico: ","\nError",MAX_CARACTER,MIN_CARACTER,1,instrumentos[posicion].nombre);
                        break;
                    case 2:
                        getInt("\nIngrese tipo del instrumento: ","\nError",sizeof(int),1,2,&instrumentos[posicion].tipo);
                        break;
                    case 3:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=3);
            retorno=0;
        }
    }
    return retorno;
}
/** \brief  Inicializa todo el array en 1
* \param array instrumentos Array instrumentos
* \return int Retorna (-1) si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int inst_Inicializar(Instrumento instrumentos[], int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        instrumentos[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio en el array
* \param array instruemtnos Array instruemtnos
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/

int inst_buscarLugarVacio(Instrumento instrumentos[], int limite, int* posicion)
{
    int retorno=-1;
    int i;
    if(instrumentos!= NULL && limite>=0 && posicion!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(instrumentos[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array instrumentos Array instrumentos
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int inst_baja(Instrumento instrumentos[], int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    if(instrumentos!=NULL && limite>0)
    {
        inst_listar(instrumentos,MAX_INSTRUMENTOS);
        getInt("\nIngrese ID a cancelar: ","\nError",sizeof(int),1,2,&id);

        if(inst_buscarID(instrumentos,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            instrumentos[posicion].isEmpty=1;
            instrumentos[posicion].idInstrumento=0;
            instrumentos[posicion].tipo=0;
            strcpy(instrumentos[posicion].nombre,"");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Busca un ID en el array instrumentos y devuelve la posicion en que se encuentra
* \param array instrumentos Array instrumentos
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int inst_buscarID(Instrumento instrumentos[], int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(instrumentos!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(instrumentos[i].isEmpty==1)
                continue;
            else if(instrumentos[i].idInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Lista los elementos del array instrumentos
* \param array instrumentos Array de instrumentos
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int inst_listar(Instrumento instrumentos[], int limite)
{
    int retorno=-1;
    int i;
    if(instrumentos!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(instrumentos[i].isEmpty==1)
                continue;
            else
                 printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n TIPO: %d\n",
                   i, instrumentos[i].idInstrumento,instrumentos[i].nombre,instrumentos[i].tipo);
        }
        retorno=0;
    }
    return retorno;
}

#endif // INSTRUMENTO_C_INCLUDED
