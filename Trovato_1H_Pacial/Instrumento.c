#ifndef INSTRUMENTO_C_INCLUDED
#define INSTRUMENTO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Instrumento.h"

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
