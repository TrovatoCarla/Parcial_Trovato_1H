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
              if(!orq_baja(orquestas,musicos,MAX_ORQUESTAS,MAX_MUSICOS))
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
                if(!mus_modificar(musicos,MAX_MUSICOS))
                {
                    printf("\nMODIFICACION EXITOSA\n");
                }
                break;

            case 6:
                if(!mus_baja(musicos,MAX_MUSICOS))
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



