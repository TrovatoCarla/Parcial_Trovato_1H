#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idInstrumento;
    char nombre[30];
    int tipo;

}Instrumento;

int inst_alta(Instrumento instrumentos[], int limite, int* contadorID);
int inst_baja(Instrumento instrumentos[], int limite);
int inst_Inicializar(Instrumento instrumentos[], int limite);
int inst_buscarLugarVacio(Instrumento instrumentos[], int limite, int* posicion);
int inst_buscarID(Instrumento instrumentos[], int limite, int valorBuscado, int* posicion);
int inst_listar(Instrumento instrumentos[], int limite);


#endif // INSTRUMENTO_H_INCLUDED
