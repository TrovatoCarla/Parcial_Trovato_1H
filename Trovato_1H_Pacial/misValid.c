#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define TRUE 1
#define FALSE 0


int isValidStringInt(char cadena[])
{
    int i=0;
    while(cadena[i]!= '\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')

            return 0;
      i++;
    }
    return 1;
}
int isValidInt(int numero, int maximo)
{
    int i;
    int retorno=1;

   for(i=0;i<maximo;i++)
   {
        if(numero<'0' || numero>'9')
        {
            retorno=0;
        }
   }
    return retorno;
}

int isValidFloat(char* numero)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;numero[i]!='\0';i++)
    {
        if((numero[i]<'0' || numero[i]>'9') && (numero[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidChar(char aux,int maximo)
{
    int i;
    for(i=0;i<maximo;i++)
    {
       if((aux<'a' || aux>'z') && (aux<'A' || aux>'Z'))
       {
            return 0;
       }
    }
    return 1;
}

int isValidStringChar(char cadena[])
{
   int i;

   while(cadena[i]!='\0')
   {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))

            return 0;
    i++;
   }
   return 1;
}

int isValidNombre(char *cadena)
{
    int retorno=1;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if(cadena[i]<'A' || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidApellido(char* cadena)
{
    int retorno= TRUE;
    int i;

    for(i=0;cadena[i]!= '\0';i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A' || cadena[i]>'Z'))
        {
            if(cadena[i]<'0' &&  cadena[i]>'9')
            {
                retorno=FALSE;
            }
        }
    }
    return retorno;
}

int isValidTelefono(char cadena[])   ///OK!!!
{

    int retorno=1;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='-' && cadena[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidSexo(char cadena)
{
    int retorno=TRUE;

    if((cadena!='f') && (cadena!='F') && (cadena!='m') && (cadena!='M'))
    {
        retorno=FALSE;
    }
    return retorno;
}

int isValidEmail(char cadena[])
{
    int retorno=1;  /// para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'-' && cadena[i]!='+') || (cadena[i]>'9' && cadena[i]<'@') ||
           (cadena[i]>'Z' && cadena[i]!='_' && cadena[i]<'a')|| cadena[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidDNI(char* cadena)
{
    int retorno=1;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
