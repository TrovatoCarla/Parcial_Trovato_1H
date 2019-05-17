#ifndef ORQUESTA_C_INCLUDED
#define ORQUESTA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "funcionesUTN.h"
#include "misValid.h"
#include "Orquesta.h"
#define SINFONICA 1
#define FILARMONICA 2
#define CAMARA 3
#define MAX_CARACTER 50
#define MIN_CARACTER 1
#define MAX_ORQUESTAS 50

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquestas Array orquesta
* \param limite int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orq_alta(Orquesta orquestas[], int limite, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(orquestas!=NULL && limite>0 && contadorID!=NULL)
    {
        if(orq_buscarLugarVacio(orquestas,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            orquestas[posicion].idOrquesta=*contadorID;
            orquestas[posicion].isEmpty=0;
            getName("\nIngrese nombre de la orquesta: ","\nNombre invalido",MAX_CARACTER,MIN_CARACTER,2,orquestas[posicion].nombre);
            getName("\nIngrese lugar de la orquesta: ","\nLugar invalido",MAX_CARACTER,MIN_CARACTER,2,orquestas[posicion].lugar);
            getInt("\nIngrese tipo de orquesta: \n1-Sinfonica\n 2-Filarmonica\n 3- Camara\n","\nTipo invalido",sizeof(int),1,2,&orquestas[posicion].tipo);

            printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n LUGAR: %s\n Tipo: %d\n",
                   posicion, orquestas[posicion].idOrquesta,orquestas[posicion].nombre,orquestas[posicion].lugar,orquestas[posicion].tipo);

            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra un elemento del array por ID
* \param array orquestas Array orquestas
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orq_baja(Orquesta orquestas[], int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    if(orquestas!=NULL && limite>0)
    {
        orq_listar(orquestas,MAX_ORQUESTAS);
        getInt("\nIngrese ID a cancelar: ","\nError",sizeof(int),1,2,&id);

        if(orq_buscarID(orquestas,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            orquestas[posicion].isEmpty=1;
            orquestas[posicion].idOrquesta=0;
            orquestas[posicion].idMusico=0;
            orquestas[posicion].tipo=0;
            strcpy(orquestas[posicion].nombre,"");
            strcpy(orquestas[posicion].lugar,"");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int orq_modificar(Orquesta* orquestas, int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if(orquestas!=NULL && limite>0)
    {
        orq_listar(orquestas,MAX_ORQUESTAS);
        getInt("\nIngrese ID a modificar: ","\nError",sizeof(int),1,2,&id);
        if(orq_buscarID(orquestas,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n LUGAR: %s\n Tipo: %d\n",
                   posicion, orquestas[posicion].idOrquesta,orquestas[posicion].nombre,orquestas[posicion].lugar,orquestas[posicion].tipo);

                getInt("\nModificar:\n 1) NOMBRE\n 2) LUGAR \n 3) Tipo\n 4) Salir\n","\nError",sizeof(int),1,1,&opcion);
                switch(opcion)
                {
                    case 1:
                       if(!getName("\nIngrese nombre de la orquesta: ","\nNombre invalido",MAX_CARACTER,MIN_CARACTER,2,orquestas[posicion].nombre))
                       {
                        printf("\nNOMBRE MODIFICADO CORRECTAMENTE\n");
                       }
                        break;
                    case 2:
                        if(!getName("\nIngrese lugar de la orquesta: ","\nNombre invalido",MAX_CARACTER,MIN_CARACTER,2,orquestas[posicion].lugar))
                       {
                        printf("\nLUGAR MODIFICADO CORRECTAMENTE\n");
                       }
                        break;
                    case 3:
                        if(!getInt("\nIngrese tipo de orquesta: \n1-Sinfonica\n 2-Filarmonica\n 3- Camara\n","\nTipo invalido",sizeof(int),1,2,&orquestas[posicion].tipo))
                        {
                            printf("\nTIPO MOSIFICADO CORRECTAMENTE\n");
                        }
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=4);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief  Inicializa todo el array en 1
* \param array orquestas Array orquestas
* \return int Retorna (-1) si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int orq_Inicializar(Orquesta orquestas[], int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        orquestas[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio en el array
* \param array orquestas Array orquestas
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orq_buscarLugarVacio(Orquesta orquestas[], int limite, int* posicion)
{
    int retorno=-1;
    int i;
    if(orquestas!= NULL && limite>=0 && posicion!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(orquestas[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en el array orquestas y devuelve la posicion en que se encuentra
* \param array orquesta Array orquesta
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orq_buscarID(Orquesta orquestas[], int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(orquestas!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(orquestas[i].isEmpty==1)
                continue;
            else if(orquestas[i].idOrquesta==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Lista los elementos del array orquestas
* \param array orquestas Array de orquestas
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orq_listar(Orquesta orquestas[], int limite)
{
    int retorno=-1;
    int i;
    if(orquestas!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(orquestas[i].isEmpty==1)
                continue;
            else
                 printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n LUGAR: %s\n TIPO: %d\n",
                   i, orquestas[i].idOrquesta,orquestas[i].nombre,orquestas[i].lugar,orquestas[i].tipo);
        }
        retorno=0;
    }
    return retorno;
}

#endif // ORQUESTA_C_INCLUDED
