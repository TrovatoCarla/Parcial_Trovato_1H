#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idInstrumento;
    char nombre[30];
    int tipo;

}Instrumento;

int inst_Inicializar(Instrumento instrumentos[], int limite);
int inst_buscarLugarVacio(Instrumento instrumentos[], int limite, int* posicion);
int inst_buscarID(Instrumento instrumentos[], int limite, int valorBuscado, int* posicion);


#endif // INSTRUMENTO_H_INCLUDED
