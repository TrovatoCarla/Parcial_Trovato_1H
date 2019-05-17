#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define TRUE 1
#define FALSE 0
#define MAX_CARACTER 50

int getInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *resultado)
{
    int auxiliar;
    int i;
    int retorno=-1;
        if(mensaje!=NULL &&
            mensajeError!=NULL &&
            maximo>minimo &&
            reintentos>=0 &&
            resultado!=NULL)

            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%d",&auxiliar);
                if(!isValidInt(auxiliar,maximo))
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                }
            }
    return retorno;
}

int getFloat(char *mensaje,char *mensajeError,int minSize, int maxSize,float maximo,float minimo,int reintentos,float *resultado)
{
    char buffer[maxSize];
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL&& minSize<maxSize && maximo>=minimo && reintentos>=0 && resultado!=NULL)
        {
             do
            {
                 __fpurge(stdin);
                if(!getString(mensaje,mensajeError,maxSize,minSize,reintentos,buffer)) ///==0 sin errores !0
                {
                    if(isValidFloat(buffer)==1)
                    {
                        *resultado=atof(buffer); /// atof array to float
                        retorno=0;
                        break;
                    }
                    else
                    {
                        printf("%s",mensajeError);
                        reintentos--;
                    }
                }
            }
        while(reintentos>=0);
        }
    return retorno;
}

int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    char buffer;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>0 && resultado!=NULL)
        {
           do
           {
               printf("%s",mensaje);
               __fpurge(stdin);
               scanf("%c",&buffer);
               if(isValidChar(buffer,maximo))
               {
                   *resultado=buffer;
                   retorno=0;
                   break;
               }
               else
                printf("%s",mensajeError);
           }while(reintentos>=0);
        }
    return retorno;
}

int getString(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{

      int retorno=-1;
    char bufferStr[maximo+10];

    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);   ///no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=minimo && strlen(bufferStr)<maximo)/// tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
            (reintentos)--;
        }
        while((reintentos)>=0);
    }
    return retorno;
 }
/*
    char buffer[MAX_CARACTER];
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1]= '\0';
            if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }*/


int getName(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    int retorno=-1;
    char buffer[MAX_CARACTER];

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        __fpurge(stdin);
       if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,buffer))
        {
            if(isValidNombre(buffer)==TRUE)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
             }
             else
                printf("%s",mensajeError);
        }
    }
    return retorno;
}

int getApellido(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    char buffer[MAX_CARACTER];
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
             __fpurge(stdin);
            if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,buffer))
            {
                if(isValidNombre(buffer)==1)
                {
                    strncpy(resultado,buffer,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
        return retorno;
}

int getSexo(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    int retorno=-1;
    char buffer;

    do
    {
        __fpurge(stdin);
        if(!getChar(mensaje,mensajeError,maximo,minimo,reintentos,&buffer))
        {
             if(isValidSexo(buffer))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
    }while(reintentos--);

    return retorno;
}

int getTelefono(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)///OK!!
{
    char bufferTelefono[MAX_CARACTER];
    int retorno=-1;

      if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>0 && resultado!=NULL)
      {
         do
        {   __fpurge(stdin);
            if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,bufferTelefono)) ///==0 sin errores !0
            {
                if(isValidTelefono(bufferTelefono)==1)
                {
                    strncpy(resultado,bufferTelefono,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
      }
    return retorno;
}

int getMail(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    char bufferMail[MAX_CARACTER];
    int retorno;

       if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>0 && resultado!=NULL)
       {
        do
        {
            __fpurge(stdin);
            if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,bufferMail)) ///==0 sin errores !0
            {
                if(isValidEmail(bufferMail)==1)
                {
                    strncpy(resultado,bufferMail,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getDNI(char* mensajes, char* mensajeError, int minimo, int maximo, int reintentos, char* resultado)
{
    maximo=11; ///con puntos
    minimo=8;  /// sin puntos
    int retorno=-1;
    char bufferDni[maximo];

    if(mensajes!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(mensajes,mensajeError,maximo,minimo,reintentos,bufferDni))
            {
                if(isValidDNI(bufferDni)==1)
                {
                    strncpy(resultado,bufferDni,maximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
