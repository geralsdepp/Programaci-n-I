#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "misValidaciones.h"
#define ALTA 1
#define BAJA -1
#define VACIO 0
#define DISPONIBLE 0
#define NO_DISPONIBLE 1

int cont_pelis;
int cont_direc;

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n1.ALTAS PELICULAS.\n2.MODIFICAR DATOS DE UNA PELICULA.\n3.BAJA DE PELICULA.\n4.NUEVO DIRECTOR\n5.ELIMINAR DIRECTOR\n6.INFORMAR\n7.LISTAR\n8.SALIR\nEliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void inicializarArray(S_Pelicula ficha[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        ficha[i].estado = DISPONIBLE;
    }
}

int obtenerEspacioLibre(S_Pelicula ficha[],int cant)
{
    int i;
    int retorno;

    for(i=0; i<cant; i++)
    {
        if(ficha[i].estado == DISPONIBLE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void alta_peliculas(S_Pelicula ficha[],int cant)
{
    int aux,flag = 0,i;
    char titulo[30], anio[10], nacionalidad[30], director[30];

    i = obtenerEspacioLibre(ficha,cant);

    printf("El primer espacio libre es: %d",i);

    for(cont_pelis=0; cont_pelis < cant; cont_pelis++)
    {
        while(flag == 0)
        {
            getString("Ingrese titulo: ",titulo);
            if(!alfanumerico(titulo))
            {
                printf("Reingrese!!\n");
            }
            else
                flag = 1;
        }
        flag = 0;
        while(flag == 0)
        {
            if(!getStringNumeros("Ingrese el anio: ",anio))
            {
                printf("Reingrese!\n");
            }
            else
                flag = 1;
        }
        flag = 0;
        while(flag == 0)
        {
            if(!getStringLetras("Ingrese Nacionalidad: ",nacionalidad))
            {
                printf("Reingrese!!\n");
            }
            else
                flag = 1;
        }
        flag = 0;
        while(flag == 0)
        {
            if(!getStringLetras("Ingrese Director: ",director))
            {
                printf("Reingrese!!\n");
            }
            else
                flag = 1;
        }

        aux = atoi(anio);

        strcpy(ficha[cont_pelis].titulo,titulo);
        ficha[cont_pelis].anio = aux;
        strcpy(ficha[cont_pelis].nacionalidad,nacionalidad);
        strcpy(ficha[cont_pelis].director.nombre,director);
        ficha[cont_pelis].id = cont_pelis;
        ficha[cont_pelis].estado = ALTA;
        break;
    }
}

void baja_peliculas(S_Pelicula ficha[])
{
    int i;
    int id;

    printf("Ingrese el id a dar de baja: ");
    scanf("%d",&id);

    for(i=0; i<cont_pelis; i++)
    {
        if(id == ficha[i].id && ficha[i].estado == ALTA)
        {
            ficha[i].estado = BAJA;
            break;
        }
        else
            printf("El id ingresado no existe!!\n");
            break;
    }
}

void nuevo_director(S_Director dir[],int cant)
{

}




