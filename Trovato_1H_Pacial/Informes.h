#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int inf_contadorTipoOrquesta(Orquesta* orquestas,int limite);
int inf_contadorTipoInstrumentos(Instrumento* instrumentos,int limite);
int inf_contadorMusicosPorOrquesta(Musico* musicos,Orquesta* orquestas,int limiteMusico,int limiteOrquesta);
int inf_cantidadMusicosPorOrquesta(Musico* musicos,Orquesta* orquestas, int limiteMusico, int limiteOrquesta) ;
int inf_ordenarApellidoNombre(Musico* musicos,int limite, int orderFirst, int orderSecond);
int inf_promedioEdades(Musico* musicos,int limiteMusico);
int Informes_listarPorCriterio(Musico* musicos, Instrumento* instrumentos, int limiteMusico, int limiteInstrumento, char* nombreIntrumento);

#endif // INFORMES_H_INCLUDED
