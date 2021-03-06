#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED


typedef struct
{
    int isEmpty;
    int idOrquesta;
    char nombre[30];
    char lugar[30];
    int tipo;

}Orquesta;

int orq_alta(Orquesta* orquestas, int limite, int* contadorID);
int orq_listar(Orquesta* orquestas, int limite);
int orq_Inicializar(Orquesta* orquestas, int limite);
int orq_buscarLugarVacio(Orquesta* orquestas, int limite, int* posicion);
int orq_buscarID(Orquesta* orquestas, int limite, int valorBuscado, int* posicion);

///int orq_baja(Orquesta* orquestas,Musico* musicos, int limiteOrquesta,int limiteMusico); SE PASO A MUSICO

#endif // ORQUESTA_H_INCLUDED
