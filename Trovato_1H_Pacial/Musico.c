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
#include "Instrumento.h"
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
int mus_alta(Musico* musicos,Orquesta* orquestas,Instrumento* instrumentos, int limiteMusico,int limiteOrquesta,int limiteInstrumento, int* contadorID)
{
    int retorno=-1;
    int posicion;
    int auxIdOrquesta;
    int auxIdInstrumento;
    int posicionOrquesta;
    int posicionInstrumento;


    if(musicos!=NULL && orquestas!=NULL && instrumentos!=NULL && limiteMusico>=0 && limiteOrquesta>=0 && limiteInstrumento>=0 && contadorID!=NULL)
    {
        if(mus_buscarLugarVacio(musicos,limiteMusico,&posicion)==-1)
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

            orq_listar(orquestas,MAX_ORQUESTAS);
            getInt("\nIngrese ID de la orquesta del musico: ","\nID invalido",sizeof(int),1,2,&auxIdOrquesta);
            if(!orq_buscarID(orquestas,MAX_ORQUESTAS,auxIdOrquesta,&posicionOrquesta))
            {
                musicos[posicion].idOrquesta=auxIdOrquesta;
            }

            inst_listar(instrumentos,MAX_INSTRUMENTOS);
            getInt("\nIngrese ID del instrumento: ","\nID invalido",sizeof(int),1,2,&auxIdInstrumento);
            if(!inst_buscarID(instrumentos,MAX_INSTRUMENTOS,auxIdInstrumento,&posicionInstrumento))
            {
                musicos[posicion].idInstrumento=auxIdInstrumento;
                strncpy(musicos[posicion].nombreInstrumento,instrumentos[posicionInstrumento].nombre,MAX_CARACTER);
                musicos[posicion].tipoDeInstrumento=instrumentos[posicionInstrumento].tipo;
            }
            mus_listar(musicos,MAX_MUSICOS);

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

int mus_baja(Musico* musicos,Instrumento* instrumentos, int limiteMusicos,int limiteInstrumetos)
{
    int retorno=-1;
    int posicion;
    int id;
    if(musicos!=NULL && instrumentos!=NULL && limiteMusicos>0 && limiteInstrumetos>0)
    {
        mus_listar(musicos,MAX_MUSICOS);
        getInt("\nIngrese ID a cancelar: ","\nError",sizeof(int),1,2,&id);

        if(mus_buscarID(musicos,limiteMusicos,id,&posicion)==-1)
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
int mus_modificar(Musico* musicos,Instrumento* instrumentos,Orquesta* orquestas, int limiteMusicos,int limiteInstrumentos,int limiteOrquestas)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    int auxIdnuevo;

    if(musicos!=NULL && instrumentos!=NULL && orquestas!=NULL && limiteMusicos>0 && limiteInstrumentos>0 && limiteOrquestas>0)
    {
        mus_listar(musicos,MAX_MUSICOS);

        getInt("\nIngrese ID a modificar: ","\nError",sizeof(int),1,2,&id);
        if(mus_buscarID(musicos,limiteMusicos,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                 mus_listar(musicos,MAX_MUSICOS);

                getInt("\nModificar:\n 1) Edad\n 2) ID de Orquesta del musico\n 3) Salir)\n","\nError",sizeof(int),1,1,&opcion);
                system("clear");
                switch(opcion)
                {
                    case 1:
                        if(!getInt("\nIngrese edad del musico: ","\nError",120,1,1,&musicos[posicion].edad))
                        {
                            printf("\n EDAD MODIFICADA CORRECTAMENTE\n\n");
                        }
                        break;
                    case 2:
                        if(!getInt("\nINgrese el nuevo ID de la orquesta: ","\nError",sizeof(int),1,2,&auxIdnuevo))
                        {
                            if(!orq_buscarID(orquestas,MAX_ORQUESTAS,auxIdnuevo,&posicion))
                            {
                                printf("\n ID ENCONTRADO\n\n");
                                musicos[posicion].idOrquesta=auxIdnuevo;
                                printf("\nID ORQUESTA MODIFICADO CORRECTAMENTE\n\n");
                            }
                            else
                                printf("\nID INEXISTENTE\n\n");

                        }
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
int mus_Inicializar(Musico* musicos, int limite)
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
int mus_buscarLugarVacio(Musico* musicos, int limite, int* posicion)
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
int mus_buscarID(Musico* musicos, int limite, int valorBuscado, int* posicion)
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
int mus_listar(Musico* musicos,int limiteMusicos)
{
    int retorno=-1;
    int i;
    if(musicos!=NULL && limiteMusicos>=0)
    {
        for(i=0;i<limiteMusicos;i++)
        {
            if(musicos[i].isEmpty==1)
                continue;
            else
             {
                printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n INSTRUMENTO: %s\n",
                   i, musicos[i].idMusico,musicos[i].nombre,musicos[i].apellido,musicos[i].nombreInstrumento);

                    switch(musicos[i].tipoDeInstrumento)
                    {
                        case 1:
                            printf(" TIPO DE INSTRUMENTO: Cuerdas\n");
                            break;
                        case 2:
                            printf(" TIPO DE INSTRUMENTO: Viento-madera\n");
                            break;

                        case 3:
                            printf(" TIPO DE INSTRUMENTO: Viento-metal\n");
                            break;
                        case 4:
                            printf(" TIPO DE INSTRUMENTO: Percusion\n");
                            break;
                    }
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Borra un elemento del array por ID
* \param array orquestas Array orquestas
* \param limite int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musYorq_baja(Orquesta* orquestas,Musico* musicos, int limiteOrquesta,int limiteMusico)
{
    int retorno=-1;
    int posicionOrquesta;
    int id;
    int i;

    orq_listar(orquestas,MAX_ORQUESTAS);
    if(orquestas!=NULL && musicos!=NULL && limiteOrquesta>0 && limiteMusico>0)
    {
        getInt("\nIngrese ID a cancelar: ","\nError",sizeof(int),1,2,&id);

        if(orq_buscarID(orquestas,MAX_ORQUESTAS,id,&posicionOrquesta)== -1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
                for(i=0;i<limiteMusico;i++)
                {
                    if(musicos[i].idOrquesta==orquestas[posicionOrquesta].idOrquesta)
                    {
                        musicos[i].isEmpty= 1;
                    }

                }
            orquestas[posicionOrquesta].isEmpty= 2;
            orquestas[posicionOrquesta].idOrquesta=0;
            orquestas[posicionOrquesta].tipo=0;
            strcpy(orquestas[posicionOrquesta].nombre,"");
            strcpy(orquestas[posicionOrquesta].lugar,"");
            retorno=0;
        }
    }
    return retorno;
}
#endif // MUSICO_C_INCLUDED
