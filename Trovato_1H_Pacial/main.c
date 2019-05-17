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

int main()
{
    Orquesta orquestas[MAX_ORQUESTAS];
    Musico musicos[MAX_MUSICOS];

    int opcion;
    int contadorIdOrquestas=0;
    int contadorIdMusicos=0;

    if((!orq_Inicializar(orquestas,MAX_ORQUESTAS)) && ((!mus_Inicializar(musicos,MAX_MUSICOS))))

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
              if(!orq_baja(orquestas,MAX_ORQUESTAS))
                {
                    printf("\nBAJA EXITOSA\n");
                }
                break;

            case 3:
                orq_listar(orquestas,MAX_ORQUESTAS);
                break;

           case 4:
                if(!mus_alta(musicos,orquestas,MAX_MUSICOS,&contadorIdMusicos))
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
            default:
                printf("\nOpcion no valida\n");
        }
    }while(opcion!=6);

    return 0;
}


