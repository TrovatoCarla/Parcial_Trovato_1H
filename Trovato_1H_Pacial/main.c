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
#define MAX_ORQUESTAS 50
#define MAX_MUSICOS 1000
#define MAX_INSTRUMENTOS 20

int main()
{
    Orquesta orquestas[MAX_ORQUESTAS];
    Musico musicos[MAX_MUSICOS];
    Instrumento instrumentos[MAX_INSTRUMENTOS];

    int opcion;
    int contadorIdOrquestas=0;
    int contadorIdMusicos=0;
    int contadorIdInstrumentos=0;

    if((!orq_Inicializar(orquestas,MAX_ORQUESTAS)) && ((!mus_Inicializar(musicos,MAX_MUSICOS)) && (!inst_Inicializar(instrumentos,MAX_INSTRUMENTOS))))

    {
        printf("\nINICIALIZACIONES CORRECTAS\n");
    }
    /*
    orquestas[0].idOrquesta=1;
    orquestas[0].isEmpty=0;
    strcpy(orquestas[0].nombre,"Metallica");
    strcpy(orquestas[0].lugar,"San Francisco");
    orquestas[0].tipo = 1;
    contadorIdInstrumentos++;

    orquestas[1].idOrquesta=2;
    orquestas[1].isEmpty=0;
    strcpy(orquestas[1].nombre,"Grande");
    strcpy(orquestas[1].lugar,"Cordoba");
    orquestas[1].tipo = 2;
    contadorIdOrquestas++;

    orquestas[2].idOrquesta=3;
    orquestas[2].isEmpty=0;
    strcpy(orquestas[2].nombre,"Magnifica");
    strcpy(orquestas[2].lugar,"La Matanza");
    orquestas[2].tipo = 3;
    contadorIdOrquestas++;

    orquestas[3].idOrquesta=4;
    orquestas[3].isEmpty=0;
    strcpy(orquestas[3].nombre,"Callejera");
    strcpy(orquestas[3].lugar,"Boedo");
    orquestas[3].tipo = 1;
    contadorIdOrquestas++;

    instrumentos[0].idInstrumento=1;
    instrumentos[0].isEmpty=0;
    strcpy(instrumentos[0].nombre,"Guitarra");
    instrumentos[0].tipo = 1;
    contadorIdInstrumentos++;

    instrumentos[1].idInstrumento=2;
    instrumentos[1].isEmpty=0;
    strcpy(instrumentos[1].nombre,"Bateria");
    instrumentos[1].tipo = 4;
    contadorIdInstrumentos++;

    instrumentos[2].idInstrumento=3;
    instrumentos[2].isEmpty=0;
    strcpy(instrumentos[2].nombre,"Flauta traverza");
    instrumentos[2].tipo = 3;
    contadorIdInstrumentos++;

    instrumentos[3].idInstrumento=4;
    instrumentos[3].isEmpty=0;
    strcpy(instrumentos[3].nombre,"Violin");
    instrumentos[3].tipo = 1;
    contadorIdInstrumentos++;

    strcpy(musicos[0].nombre,"carla");
    strcpy(musicos[0].apellido,"Trovato");
    musicos[0].edad = 29;
    musicos[0].isEmpty = 0;
    musicos[0].idMusico = 1;
    musicos[0].idInstrumento=4;
    musicos[0].idOrquesta=2;


    strcpy(musicos[1].nombre,"karen");
    strcpy(musicos[1].apellido,"ramirez");
    musicos[1].edad = 26;
    musicos[1].isEmpty = 0;
    musicos[1].idMusico = 2;
    musicos[1].idInstrumento=3;
    musicos[1].idOrquesta=1;
    */



    do
    {
        getInt("\n\n1) Alta de Orquesta \n2) Eliminar Orquesta \n3) Listar Orquestas \n4) Agregar Musico \n5) Modificar Musico \n6) Eliminar Musico \n7) Listar Musico \n8) Agregar Instrumento \n9) Listar instrumentos\n",                   //cambiar
                      "\nError",sizeof(int),1,1,&opcion);
         system("clear");
        switch(opcion)
        {
            case 1:
                if(!orq_alta(orquestas,MAX_ORQUESTAS,&contadorIdOrquestas))
                {
                    printf("\nALTA EXITOSA\n");
                }
                break;

            case 2:
              if(!musYorq_baja(orquestas,musicos,MAX_ORQUESTAS,MAX_MUSICOS))
                {
                    printf("\nBAJA EXITOSA\n");
                }
                break;

            case 3:
                orq_listar(orquestas,MAX_ORQUESTAS);
                break;

           case 4:
                if(!mus_alta(musicos,orquestas,instrumentos,MAX_MUSICOS,&contadorIdMusicos))
                {
                    printf("\nALTA EXITOSA\n");
                }
                break;

            case 5:
                if(!mus_modificar(musicos,instrumentos,orquestas,MAX_MUSICOS,MAX_INSTRUMENTOS,MAX_ORQUESTAS))
                {
                    printf("\nMODIFICACION EXITOSA\n");
                }
                break;

            case 6:
                if(!mus_baja(musicos,instrumentos,MAX_MUSICOS,MAX_INSTRUMENTOS))
                {
                    printf("\nBAJA EXITOSA\n");
                }
                break;

            case 7:
                mus_listar(musicos,MAX_MUSICOS);
                break;

            case 8:
                if(!inst_alta(instrumentos,MAX_INSTRUMENTOS,&contadorIdInstrumentos))
                {
                    printf("\nALTA EXITOSA");
                }
                break;

            case 9:
                inst_listar(instrumentos,MAX_INSTRUMENTOS);
                break;
            default:
                printf("\nOpcion no valida\n");
        }
    }while(opcion!=9);

    return 0;
}



