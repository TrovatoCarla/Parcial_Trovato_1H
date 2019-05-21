#ifndef INFORMES_C_INCLUDED
#define INFORMES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#define MAX_ORQUESTAS 50



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
int inf_contadorTipoInstrumentos(Instrumento* instrumentos,int limite)
{
    int i;
    int retorno=-1;
    int contadorCuerdas=0;
    int contadorVientoMadera=0;
    int contadorVientoMetal=0;
    int contadorPercusion=0;

   if(instrumentos!=NULL && limite>0)
   {
        for(i=0;i<limite;i++)
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
        printf("\nCantidad de instrumentos de CUERDAS: %d",contadorCuerdas);
        printf("\nCantidad de instrumentos de VIENTO-MADERA: %d",contadorVientoMadera);
        printf("\nCantidad de instrumentos de VIENTO-METAL: %d\n",contadorVientoMetal);
        printf("\nCantidad de instrumentos de PERCUSION: %d\n\n",contadorPercusion);
    }
    return retorno;
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
        for(i=0;i<limiteMusico;i++)
        {
            mus_buscarID(musicos,limiteMusico,musicos[i].idOrquesta,&auxPosicion);
            if(musicos[i].isEmpty==1 && auxPosicion!=-1)
                continue;
            else
            {
                printf("\nCANTIDAD DE MUSICOS POR ORQUESTAS\n");
                for(k=i,contador=0;k<limiteMusico;k++)
                {
                    if(musicos[k].isEmpty!=1 && (musicos[k].idOrquesta==musicos[i].idOrquesta))
                    {
                        orq_buscarID(orquestas,limiteOrquesta,musicos[k].idOrquesta,&j);

                        contador++;
                    }
                }
                printf("\nID Orquesta: %d\n Cantidad Musicos: %d",orquestas[j].idOrquesta,contador);
            }
        }
        retorno=0;
    }
    return retorno;
}

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
