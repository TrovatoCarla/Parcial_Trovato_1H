#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "funcionesUTN.h"
#include "misValid.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "Informes.h"
#define MAX_CARACTER 50
#define MIN_CARACTER 1
#define MAX_ORQUESTAS 50
#define MAX_MUSICOS 1000
#define MAX_INSTRUMENTOS 20
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    Orquesta orquestas[MAX_ORQUESTAS];
    Musico musicos[MAX_MUSICOS];
    Instrumento instrumentos[MAX_INSTRUMENTOS];

    int opcion;
    int opcion2;
    int contadorIdOrquestas=0;
    int contadorIdMusicos=0;
    int contadorIdInstrumentos=0;

    if((!orq_Inicializar(orquestas,MAX_ORQUESTAS)) && ((!mus_Inicializar(musicos,MAX_MUSICOS)) && (!inst_Inicializar(instrumentos,MAX_INSTRUMENTOS))))

    {
        printf("\nINICIALIZACIONES CORRECTAS\n");
    }

    instrumentos[0].idInstrumento=1;
    instrumentos[0].isEmpty=0;
    strcpy(instrumentos[0].nombre,"Inst1");
    instrumentos[0].tipo = 1;
    contadorIdInstrumentos++;

    instrumentos[1].idInstrumento=2;
    instrumentos[1].isEmpty=1;
    strcpy(instrumentos[1].nombre,"Inst2");
    instrumentos[1].tipo = 2;
    contadorIdInstrumentos++;

    instrumentos[3].idInstrumento=3;
    instrumentos[3].isEmpty=3;
    strcpy(instrumentos[3].nombre,"Inst3");
    instrumentos[3].tipo = 2;
    contadorIdInstrumentos++;

    instrumentos[4].idInstrumento=4;
    instrumentos[4].isEmpty=3;
    strcpy(instrumentos[4].nombre,"Inst4");
    instrumentos[4].tipo = 3;
    contadorIdInstrumentos++;

    instrumentos[5].idInstrumento=5;
    instrumentos[5].isEmpty=3;
    strcpy(instrumentos[5].nombre,"Inst5");
    instrumentos[5].tipo = 4;
    contadorIdInstrumentos++;

    orquestas[0].idOrquesta=1;
    orquestas[1].isEmpty=0;
    strcpy(orquestas[0].nombre,"Orquesta1");
    strcpy(orquestas[0].lugar,"Lugar1");
    orquestas[0].tipo = 1;
    contadorIdOrquestas++;

    orquestas[1].idOrquesta=2;
    orquestas[1].isEmpty=0;
    strcpy(orquestas[1].nombre,"Orquesta2");
    strcpy(orquestas[1].lugar,"Lugar1");
    orquestas[1].tipo = 2;
    contadorIdOrquestas++;


    orquestas[2].idOrquesta=3;
    orquestas[2].isEmpty=0;
    strcpy(orquestas[2].nombre,"Orquesta3");
    strcpy(orquestas[2].lugar,"Lugar2");
    orquestas[2].tipo = 3;
    contadorIdOrquestas++;

    orquestas[3].idOrquesta=4;
    orquestas[3].isEmpty=0;
    strcpy(orquestas[3].nombre,"Orquesta4");
    strcpy(orquestas[3].lugar,"Lugar3");
    orquestas[3].tipo = 2;
    contadorIdOrquestas++;

    musicos[0].idMusico = 1;
    strcpy(musicos[0].nombre,"Mus1");
    strcpy(musicos[0].apellido,"AMus1");
    musicos[0].edad = 30;
    musicos[0].idOrquesta=1;
    musicos[0].idInstrumento=2;
    musicos[0].isEmpty = 0;

    musicos[0].idMusico = 2;
    strcpy(musicos[0].nombre,"Mus2");
    strcpy(musicos[0].apellido,"AMus2");
    musicos[0].edad = 20;
    musicos[0].idOrquesta=2;
    musicos[0].idInstrumento=5;
    musicos[0].isEmpty = 0;

    musicos[0].idMusico = 3;
    strcpy(musicos[0].nombre,"Mus3");
    strcpy(musicos[0].apellido,"AMus3");
    musicos[0].edad = 25;
    musicos[0].idOrquesta=4;
    musicos[0].idInstrumento=2;
    musicos[0].isEmpty = 0;

    musicos[0].idMusico = 4;
    strcpy(musicos[0].nombre,"Mus4");
    strcpy(musicos[0].apellido,"AMus4");
    musicos[0].edad = 27;
    musicos[0].idOrquesta=4;
    musicos[0].idInstrumento=1;
    musicos[0].isEmpty = 0;

    musicos[0].idMusico = 5;
    strcpy(musicos[0].nombre,"Mus5");
    strcpy(musicos[0].apellido,"AMus5");
    musicos[0].edad = 22;
    musicos[0].idOrquesta=1;
    musicos[0].idInstrumento=3;
    musicos[0].isEmpty = 0;

    musicos[0].idMusico = 6;
    strcpy(musicos[0].nombre,"Mus6");
    strcpy(musicos[0].apellido,"AMus6");
    musicos[0].edad = 35;
    musicos[0].idOrquesta=3;
    musicos[0].idInstrumento=4;
    musicos[0].isEmpty = 0;



    mus_listar(musicos,MAX_MUSICOS);

    do
    {
        getInt("\n\n1) Alta de Orquesta \n2) Eliminar Orquesta \n3) Listar Orquestas \n4) Agregar Musico \n5) Modificar Musico \n6) Eliminar Musico \n7) Listar Musico \n8) Agregar Instrumento \n9) Listar instrumentos \n10) INFORMES\n\n ",                   //cambiar
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
              if((contadorIdOrquestas>0) && (contadorIdMusicos>0))
                {
                    musYorq_baja(orquestas,musicos,MAX_ORQUESTAS,MAX_MUSICOS);
                    printf("\nBAJA EXITOSA\n");
                }
                else
                    printf("\nNO HAY ORQUESTAS Y MUSICOS DADOS DE ALTA\n");
                break;

            case 3:
                if(contadorIdOrquestas>0)
                {
                    orq_listar(orquestas,MAX_ORQUESTAS);
                }
                else
                    printf("\nNO HAY ORQUESTAS DADAS DE ALTA\n");
                break;

           case 4:
                if(!mus_alta(musicos,orquestas,instrumentos,MAX_MUSICOS,MAX_ORQUESTAS,MAX_INSTRUMENTOS,&contadorIdMusicos))
                {
                    printf("\nALTA EXITOSA\n");
                }
                break;

            case 5:
                if(contadorIdMusicos>0)
                {
                    mus_modificar(musicos,instrumentos,orquestas,MAX_MUSICOS,MAX_INSTRUMENTOS,MAX_ORQUESTAS);
                    printf("\nMODIFICACION EXITOSA\n");
                }
                else
                    printf("\nNO HAY MUSICOS DADOS DE ALTA\n");
                break;

            case 6:
                if(contadorIdMusicos>0)
                {
                    mus_baja(musicos,instrumentos,MAX_MUSICOS,MAX_INSTRUMENTOS);
                    printf("\nBAJA EXITOSA\n");
                }
                else
                    printf("\nNO HAY MUSICOS DADOS DE ALTA\n");
                break;

            case 7:
                if(contadorIdMusicos>0)
                {
                    mus_listar(musicos,MAX_MUSICOS);
                }
                else
                    printf("\nNO HAY MUSICOS DADOS DE ALTA PARA LISTAR\n");
                break;

            case 8:
                if(!inst_alta(instrumentos,MAX_INSTRUMENTOS,&contadorIdInstrumentos))
                {
                    printf("\nALTA EXITOSA");
                }
                break;

            case 9:
                if(contadorIdInstrumentos>0)
                {
                    inst_listar(instrumentos,MAX_INSTRUMENTOS);
                }
                else
                    printf("\nNO HAY INSTRUMENTOS DADOS DE ALTA PARA LISTAR\n");
                break;

            case 10:
                getInt("\n\n1) Listar orquesta segun lugar \n2) Lista musicos menores 25 años \n3) Listar Orquestas \n4) Listar instrumentos de orquesta X \n5) Orquesta completa \n6) Eliminar Musico \n7) Listar Musico \n8) Agregar Instrumento \n9) Listar instrumentos \n10) INFORMES\n\n ",                   //cambiar
                      "\nError",sizeof(int),1,1,&opcion2);
                    system("clear");
                    switch(opcion2)
                        {
                            case 1:
                                inf_listaOrquestaSegunLugar(orquestas,MAX_ORQUESTAS);
                                break;
                            case 2:
                                inf_listaMusicosMenores(musicos,MAX_MUSICOS);
                                break;
                            case 3:
                                inf_cantidadMusicosPorOrquesta(musicos,orquestas,MAX_MUSICOS,MAX_ORQUESTAS);
                                break;
                            case 4:
                                inf_listarInstrumentosDeOrquesta(orquestas,musicos,instrumentos,MAX_INSTRUMENTOS,MAX_ORQUESTAS,MAX_MUSICOS);
                                break;
                            case 5:
                                inf_contadorTipoInstrumentos(instrumentos,orquestas,MAX_INSTRUMENTOS,MAX_ORQUESTAS);
                             break;
                            case 7:
                                inf_listarMusicosNoViento(musicos,MAX_MUSICOS,SORT_DOWN,SORT_DOWN);
                                break;

                        }


                break;
            default:
                printf("\nOpcion no valida\n");
        }
    }while(opcion!=10);

    return 0;
}



