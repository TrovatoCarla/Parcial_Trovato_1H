#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "Orquesta.h"
#include "Instrumento.h"

typedef struct
{
    int isEmpty;
    int idMusico;
    char nombre[30];
    char apellido[30];
    int edad;
    int idOrquesta;
    int idInstrumento;
    char nombreInstrumento[30];
    int tipoDeInstrumento;

}Musico;

int mus_alta(Musico* musicos,Orquesta* orquestas,Instrumento* instrumentos, int limite, int* contadorID);
int mus_baja(Musico* musicos,Instrumento* instrumentos, int limiteMusicos,int limiteInstrumetos);
int musYorq_baja(Orquesta* orquestas,Musico* musicos, int limiteOrquesta,int limiteMusico);
int mus_modificar(Musico* musicos,Instrumento* instrumentos,Orquesta* orquestas, int limiteMusicos,int limiteInstrumentos,int limiteOrquestas);
int mus_listar(Musico* musicos,int limiteMusicos);
int mus_Inicializar(Musico* musicos, int limite);
int mus_buscarLugarVacio(Musico* musicos, int limite, int* posicion);
int mus_buscarID(Musico* musicos, int limite, int valorBuscado, int* posicion);
int orq_baja(Orquesta* orquestas,Musico* musicos, int limiteOrquesta,int limiteMusico);

#endif // MUSICO_H_INCLUDED
