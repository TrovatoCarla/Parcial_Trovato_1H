#ifndef MUSICO_C_INCLUDED
#define MUSICO_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "funcionesUTN.h"
#include "misValid.h"
#include "Orquesta.h"
#include "Musico.h"
#define MAX_CARACTER 50
#define MIN_CARACTER 1
#define MAX_MUSICOS 1000
#define MAX_ORQUESTAS 50
#define MAX_INSTRUMENTOS 20

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musicos Array musicos
* \param limite int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int mus_alta(Musico musicos[],Orquesta orquestas[],Instrumento instrumentos[], int limite, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int auxIdOrquesta;
    int auxIdInstrumento;
    int posicionOrquesta;
    int posicionInstrumento;

    if(musicos!=NULL && limite>0 && contadorID!=NULL)
    {
        if(mus_buscarLugarVacio(musicos,limite,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            musicos[posicion].idMusico=*contadorID;
            musicos[posicion].isEmpty=0;
            getName("\nIngrese nombre: ","\nNombre invalido",MAX_CARACTER,MIN_CARACTER,2,musicos[posicion].nombre);
            getApellido("\nIngrese apellido: ","\nLugar invalido",MAX_CARACTER,MIN_CARACTER,2,musicos[posicion].apellido);
            getInt("\nIngrese edad: ","\nEdad invalido",120,1,2,&musicos[posicion].edad);
            getInt("\nIngrese ID de la orquesta del musico: ","\nID invalido",sizeof(int),1,2,&auxIdOrquesta);
            if(!orq_buscarID(orquestas,MAX_ORQUESTAS,auxIdOrquesta,&posicionOrquesta))
            {
                musicos[posicion].idOrquesta=auxIdOrquesta;
            }
            getInt("\nIngrese ID del instrumento: ","\nID invalido",sizeof(int),1,2,&auxIdInstrumento);
            if(!inst_buscarID(instrumentos,MAX_INSTRUMENTOS,auxIdInstrumento,&posicionInstrumento))
            {
                musicos[posicion].idInstrumento=auxIdInstrumento;
            }

            printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n Tipo de instrumento: %d\n",
                   posicion, musicos[posicion].idMusico,musicos[posicion].nombre,musicos[posicion].apellido,musicos[posicion].tipoDeInstrumento);

            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array musicos Array musicos
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/

int mus_baja(Musico musicos[], int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    if(musicos!=NULL && limite>0)
    {
        mus_listar(musicos,MAX_MUSICOS);
        getInt("\nIngrese ID a cancelar: ","\nError",sizeof(int),1,2,&id);

        if(mus_buscarID(musicos,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            musicos[posicion].isEmpty=1;
            musicos[posicion].idMusico=0;
            musicos[posicion].edad=0;
            musicos[posicion].idOrquesta=0;
            musicos[posicion].idInstrumento=0;
            musicos[posicion].tipoDeInstrumento=0;
            strcpy(musicos[posicion].nombre,"");
            strcpy(musicos[posicion].apellido,"");
            strcpy(musicos[posicion].nombreInstrumento,"");
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
int mus_modificar(Musico* musicos, int limite)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if(musicos!=NULL && limite>0)
    {
        mus_listar(musicos,MAX_MUSICOS);
        getInt("\nIngrese ID a modificar: ","\nError",sizeof(int),1,2,&id);
        if(mus_buscarID(musicos,limite,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n Tipo de instrumento: %d\n",
                  posicion, musicos[posicion].idMusico,musicos[posicion].nombre,musicos[posicion].apellido,musicos[posicion].tipoDeInstrumento);

                getInt("\nModificar:\n 1) Edad\n 2) ID de Orquesta del musico\n 3) Salir)\n","\nError",sizeof(int),1,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        getInt("\nIngrese edad del musico: ","\nError",120,1,1,&musicos[posicion].edad);
                        break;
                    case 2:
                        getInt("\nINgrese ID de la orquesta del musico: ","\nError",sizeof(int),1,&musicos[posicion].idOrquesta);
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
* \param array musicos Array musicos
* \return int Retorna (-1) si hay error [Invalid length or NULL pointer] - (0) Si Ok
*
*/
int mus_Inicializar(Musico musicos[], int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        musicos[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


/** \brief Busca el primer lugar vacio en el array
* \param array musicos Array musicos
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int mus_buscarLugarVacio(Musico musicos[], int limite, int* posicion)
{
    int retorno=-1;
    int i;
    if(musicos!= NULL && limite>=0 && posicion!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(musicos[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en el array musicos y devuelve la posicion en que se encuentra
* \param array musicos Array musicos
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int mus_buscarID(Musico musicos[], int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(musicos!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(musicos[i].isEmpty==1)
                continue;
            else if(musicos[i].idMusico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Lista los elementos del array musicos
* \param array musicos Array de musicos
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*/
int mus_listar(Musico musicos[], int limite)
{
    int retorno=-1;
    int i;
    if(musicos!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(musicos[i].isEmpty==1)
                continue;
            else
                 printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n INSTRUMENTO: %s\n TIPO DE INSTRUMENTO: %d",
                   i, musicos[i].idMusico,musicos[i].nombre,musicos[i].apellido,musicos[i].nombreInstrumento,musicos[i].tipoDeInstrumento);
        }
        retorno=0;
    }
    return retorno;
}


#endif // MUSICO_C_INCLUDED
