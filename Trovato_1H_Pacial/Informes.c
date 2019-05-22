#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "funcionesUTN.h"
#define MAX_ORQUESTAS 50
#define MAX_CARACTER 50
#define MIN_CARACTER 1
#define MAX_MUSICOS 1000
#define SORT_UP 1
#define SORT_DOWN 0

/** \brief Cuenta cantidad de orquestas segun su tipo
* \param Orquesta orquestas array orquestas
* \param limite tamaño del array
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/
int inf_listaOrquestaSegunLugar(Orquesta* orquestas,int limite)
{
    int i;
    int retorno=-1;
    char auxLugar[50];


   if(orquestas!=NULL && limite>0)
   {
        if(!getName("\nIngrese el lugar de orquestas a listar\n","\nError\n",MAX_CARACTER,MIN_CARACTER,2,auxLugar))
        {

            for(i=0;i<limite;i++)
            {
                if(orquestas[i].isEmpty==0)
                {
                    if(strncmp(orquestas[i].nombre,auxLugar,MAX_CARACTER)==0)
                    {
                        switch(orquestas[i].tipo)
                        {
                        case 1:
                            printf(" TIPO DE ORQUESTA: Sinfonica\n");
                            break;
                        case 2:
                            printf(" TIPO DE ORQUESTA: Filarmonica\n");
                            break;
                        case 3:
                            printf(" TIPO DE ORQUESTA: Camara\n");
                            break;
                        default:
                            break;
                        printf("\nID ORQUESTA: %d\n NOMBRE: %s\n LUGAR: %s\n",orquestas[i].idOrquesta,
                                orquestas[i].nombre,orquestas[i].lugar);
                        }
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Lista musicos menores de 25 años
* \param Musico musicos , array de musicos
* \param limiteMusico tamaño del array musicos
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/
int inf_listaMusicosMenores(Musico* musicos,int limiteMusico)///ok
{
    int i;

        if(musicos!=NULL && limiteMusico>0)
        {
            for(i=0;i<limiteMusico;i++)
            {
                if(musicos[i].isEmpty==0)
                {
                    if(musicos[i].edad<25)
                    {
                        printf("\nID MUSICO: %d\n NOMBRE: %s\n APELLIDO: %s\n EDAD: %d\n NOMBRE INSTRUMENTO: %s\n NOMBRE ORQUESTA: %s",
                                musicos[i].idMusico,musicos[i].nombre,musicos[i].apellido,musicos[i].edad,musicos[i].nombreInstrumento,musicos[i].nombreOrquesta);
                    }

                }
            }
        }

    return 0;
}


/** \brief Cuenta cantidad de musicos por orquesta
* \param Musico musicos , array de musicos
* \param Orquesta orquestas, array de orquestas
* \param limiteMusico tamaño del array musicos
* \param limiteOrquesta tamaño del array orquesta
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/
int inf_cantidadMusicosPorOrquesta(Musico* musicos,Orquesta* orquestas, int limiteMusico, int limiteOrquesta)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;


    if(musicos!=NULL && limiteMusico>=0 && orquestas!=NULL && limiteOrquesta>=0)
    {
        printf("\nCANTIDAD DE MUSICOS POR ORQUESTAS\n");
        for(i=0;i<limiteMusico;i++)
        {
            mus_buscarID(musicos,limiteMusico,musicos[i].idOrquesta,&auxPosicion);
            if(musicos[i].isEmpty==1 && auxPosicion!=-1)
                continue;
            else
            {
                for(k=i,contador=0;k<limiteMusico;k++)
                {
                    if(musicos[k].isEmpty!=1 && (musicos[k].idOrquesta==musicos[i].idOrquesta))
                    {
                        orq_buscarID(orquestas,limiteOrquesta,musicos[k].idOrquesta,&j);
                        contador++;
                    }

                }
                    if(contador<6)
                    {
                        printf("\nID Orquesta: %d\n Cantidad Musicos: %d",orquestas[j].idOrquesta,contador);
                    }

            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un elemento por ID y modifica sus campos
* \param array musicos Array de musicos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int inf_listarInstrumentosDeOrquesta(Orquesta* orquestas,Musico* musicos,Instrumento* instrumentos,int limiteInstrumento, int limiteOrquesta,int limiteMusico)
{
    int retorno=-1;
    int i;
    int auxPosicion;
    int idAbuscar;


    if(musicos!=NULL && limiteMusico>0 && orquestas!=NULL && limiteOrquesta>0 && instrumentos!=NULL && limiteInstrumento>0)
    {
        if(!getInt("\nIngrese ID a listar\n","Error\n",MAX_MUSICOS,1,2,&idAbuscar))
        {
            if(!orq_buscarID(orquestas,limiteOrquesta,idAbuscar,&auxPosicion))
            {
                for(i=0;i<limiteMusico;i++)
                {
                    if(musicos[i].idOrquesta==idAbuscar)
                    {

                        printf("\nID Orquesta: %d\n nombre instrumento: %s\n Nombre musico: %s\n",orquestas[auxPosicion].idOrquesta,musicos[i].nombreInstrumento,musicos[i].nombre);
                        switch(instrumentos[i].tipo)
                        {
                            case 1:
                                printf(" Tipo: Cuerdas\n");
                                break;
                            case 2:
                                printf(" Tipo: Viento-madera\n");
                                break;
                            case 3:
                                printf(" Tipo: Viento-metal\n");
                                break;
                            case 4:
                                printf(" Tipo: Percusion\n");
                                break;
                        }
                    }

                }
                retorno=0;
            }

        }

    }

    return retorno;
}

/** \brief Cuenta cantidad de instrumentos segun su tipo
* \param  Instrumento instrumentos array de instrumentos
* \param limite tamaño del array
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/
int inf_contadorTipoInstrumentos(Instrumento* instrumentos,Orquesta* orquestas,int limiteInstrumento,int limiteOrquesta)
{
    int i;
    int retorno=-1;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

   if(instrumentos!=NULL && limiteInstrumento>0 && orquestas!=NULL && limiteOrquesta>0)
   {
        for(i=0;i<limiteInstrumento;i++)
        {
            if(instrumentos[i].isEmpty==0)
            {
                switch(instrumentos[i].tipo)
                {
                    case 1:
                        contadorCuerdas++;
                        break;
                    case 2:
                        contadorVientoMadera++;
                        break;
                    case 3:
                        contadorVientoMetal++;
                        break;
                    case 4:
                        contadorPercusion++;
                        break;
                }
                retorno=0;
            }
        }

        if((contadorCuerdas>=4) && (contadorVientoMadera+contadorVientoMetal>=4) && (contadorPercusion>=1))
        {
            printf("\n Posicion: %d\n ID DE LA ORQUESTA: %d\n NOMBRE ORQUESTA: %s\n LUGAR ORQUESTA: %s\n",
                   i, orquestas[i].idOrquesta,orquestas[i].nombre,orquestas[i].lugar);

                    switch(orquestas[i].tipo)
                    {
                        case 1:
                            printf(" TIPO DE ORQUESTA: Sinfonica\n");
                            break;
                        case 2:
                            printf(" TIPO DE ORQUESTA: Filarmonica\n");
                            break;
                        case 3:
                            printf(" TIPO DE ORQUESTA: Camara\n");
                            break;
                        default:
                            break;
                            retorno=0;
                    }
        }
        else
            printf("\nNO HAY ORQUESTAS COMPLETAS\n");

}
    return retorno;
}

int inf_listarMusicosNoViento(Musico* musicos,int limite, int orderFirst, int orderSecond)///Sort Down Sort Down a-->z                              //cambiar fantasma
{
    int retorno=-1;
    int k;


    if(musicos!=NULL && limite>=0)
    {
       for(k=0;k<limite;k++)
       {
            if((musicos[k].tipoDeInstrumento!=2) && (musicos[k].tipoDeInstrumento!=3))
            {
                if(!inf_ordenarApellidoNombre(musicos,MAX_MUSICOS,SORT_DOWN,SORT_DOWN))
                {
                                printf("\n Posicion: %d\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n EDAD: %d\n INSTRUMENTO: %s\n",
                   k, musicos[k].idMusico,musicos[k].nombre,musicos[k].apellido,musicos[k].edad,musicos[k].nombreInstrumento);

                    switch(musicos[k].tipoDeInstrumento)
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
       }

        retorno=0;
    }
    return retorno;
}









































///-------------------------------------------------------------------------------------------
/** \brief Cuenta cantidad de orquestas segun su tipo
* \param Orquesta orquestas array orquestas
* \param limite tamaño del array
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/
int inf_contadorTipoOrquesta(Orquesta* orquestas,int limite)
{
    int i;
    int retorno=-1;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

   if(orquestas!=NULL && limite>0)
   {
        for(i=0;i<limite;i++)
        {
            if(orquestas[i].isEmpty==0)
            {
                switch(orquestas[i].tipo)
                {
                    case 1:
                        contadorSinfonica++;
                        break;
                    case 2:
                        contadorFilarmonica++;
                        break;
                    case 3:
                        contadorCamara++;
                        break;
                }
                retorno=0;
            }
        }
        printf("\ncantidad de orquestas SINFONICAS: %d",contadorSinfonica);
        printf("\ncantidad de orquestas FILARMONICAS: %d",contadorFilarmonica);
        printf("\ncantidad de orquestas CAMARAS: %d\n\n",contadorCamara);
    }
    return retorno;
}

/** \brief Cuenta cantidad de instrumentos segun su tipo
* \param  Instrumento instrumentos array de instrumentos
* \param limite tamaño del array
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/


/** \brief Ordena el array de musicos por apellido y nombre
* \param Musico* musicos  Array de musicos
* \param limite int Tamaño del array musicos
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int inf_ordenarApellidoNombre(Musico* musicos,int limite, int orderFirst, int orderSecond)///Sort Down Sort Down a-->z                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(musicos!=NULL && limite>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 0; i < limite-1; i++)
            {
                if( ((strcmp(musicos[i].apellido,musicos[i+1].apellido) < 0) && orderFirst) ||
                    ((strcmp(musicos[i].apellido,musicos[i+1].apellido) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = musicos[i];
                    musicos[i] = musicos[i+1];
                    musicos[i+1] = buffer;
                }
                else if(strcmp(musicos[i].apellido,musicos[i+1].apellido) == 0)
                {
                    if( ((strcmp(musicos[i].nombre,musicos[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(musicos[i].nombre,musicos[i+1].nombre) > 0) && !orderFirst) )
                    {
                        flagSwap=1;
                        buffer = musicos[i];
                        musicos[i] = musicos[i+1];
                        musicos[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

/** \brief Calcula promedio de edad de los musicos
* \param Musico musicos , array de musicos
* \param limiteMusico tamaño del array musicos
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*/
int inf_promedioEdades(Musico* musicos,int limiteMusico)
{
    int i;
    int acumuladorEdades=0;
    int contadorEdades=0;
    float promedioEdades;

        if(musicos!=NULL && limiteMusico>=0)
        {
            for(i=0;i<limiteMusico;i++)
            {
                if(musicos[i].isEmpty==0)
                {
                    acumuladorEdades=acumuladorEdades+musicos[i].edad;
                    contadorEdades++;
                }
            }
            promedioEdades=acumuladorEdades/contadorEdades;
        }
        printf("\nEl promedio de edades de los musicos es: %.2f\n\n",promedioEdades);

    return 0;
}


#endif // INFORMES_C_INCLUDED
