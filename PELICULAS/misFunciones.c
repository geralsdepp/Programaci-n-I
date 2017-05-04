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

void inicializarArray_Peliculas(S_Pelicula ficha[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        ficha[i].estado = DISPONIBLE;
    }
}

void inicializarArray_Directores(S_Director dir[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        dir[i].estado = DISPONIBLE;
    }
}

int obtenerEspacioLibre_Peliculas(S_Pelicula ficha[],int cant)
{
    int retorno;

    for(cont_pelis=0; cont_pelis<cant; cont_pelis++)
    {
        if(ficha[cont_pelis].estado == DISPONIBLE)
        {
            retorno = cont_pelis;
            break;
        }
    }
    return retorno;
}

int obtenerEspacioLibre_Directores(S_Director dir[],int cant)
{
    int retorno;

    for(cont_direc = 0; cont_direc<cant; cont_direc++)
    {
        if(dir[cont_direc].estado == DISPONIBLE)
        {
            retorno = cont_direc;
            break;
        }
    }
    return retorno;
}

void alta_peliculas(S_Pelicula ficha[],int cant)
{
    int aux,flag = 0,i;
    char titulo[30], anio[10], nacionalidad[30], director[30];

    i = obtenerEspacioLibre_Peliculas(ficha,cant);

    printf("El primer espacio libre es: %d\n",i);

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

    strcpy(ficha[i].titulo,titulo);
    ficha[i].anio = aux;
    strcpy(ficha[i].nacionalidad,nacionalidad);
    strcpy(ficha[i].director.nombre,director);
    ficha[i].id = cont_pelis;
    ficha[i].estado = ALTA;
}

void modificar_pelicula(S_Pelicula ficha[])
{
    int i,flag = 0,id,anio;
    char id_str[5];
    char titulo[30], anio_str[10], nacionalidad[30], director[30];

    if(!getStringNumeros("Ingrese id a modificar: ",id_str))
    {
        printf("El id debe contener letras!!");
    }
    else
    {
        id = atoi(id_str);
        for(i=0; i<cont_pelis+1; i++)
        {
            if(id == ficha[i].id && ficha[i].estado == ALTA)
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
                    if(!getStringNumeros("Ingrese el anio: ",anio_str))
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

                anio = atoi(anio_str);

                strcpy(ficha[i].titulo,titulo);
                ficha[i].anio = anio;
                strcpy(ficha[i].nacionalidad,nacionalidad);
                strcpy(ficha[i].director.nombre,director);
                ficha[i].id = cont_pelis;
                ficha[i].estado = ALTA;
                break;
            }
            else
                printf("El id ingresado no existe o no esta dado de alta!! \n");
                break;
        }
    }
}

void baja_peliculas(S_Pelicula ficha[])
{
    int i;
    int id;

    printf("Ingrese el id a dar de baja: ");
    scanf("%d",&id);

    for(i=0; i<cont_pelis+1; i++)
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
    int flag = 0,dia,mes,anio,i,j;
    char director[30],dd[5],mm[5],aa[5],pais[20];

    i = obtenerEspacioLibre_Directores(dir,cant);

    while(flag == 0)
    {
        if(!getStringLetras("Ingrese Director: ",director))
        {
            printf("Reingrese!!\n");
        }
        else
        {
            for(j=0;j<cont_direc+1;j++)
            {
                if(director == dir[j].nombre)
                {
                    printf("Ya existe ese nombre!!");
                    break;
                }
                else
                    flag = 1;
            }
        }
    }
    flag = 0;
    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese el dia de nacimiento: ",dd))
        {
            printf("Reingrese!\n");
        }
        else
            flag = 1;
    }
    flag = 0;
    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese el mes de nacimiento: ",mm))
        {
            printf("Reingrese!\n");
        }
        else
            flag = 1;
    }
    flag = 0;
    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese el anio de nacimiento: ",aa))
        {
            printf("Reingrese!\n");
        }
        else
            flag = 1;
    }
    flag = 0;
    while(flag == 0)
    {
        if(!getStringLetras("Ingrese el pais de origen: ",pais))
        {
            printf("Reingrese!\n");
        }
        else
            flag = 1;
    }

    dia = atoi(dd);
    mes = atoi(mm);
    anio = atoi(aa);

    strcpy(dir[i].nombre,director);
    strcpy(dir[i].pais,pais);
    dir[i].fecha_nacimiento.dia = dia;
    dir[i].fecha_nacimiento.mes = mes;
    dir[i].fecha_nacimiento.anio = anio;
    dir[i].id = i;
    dir[i].estado = ALTA;
}

void eliminar_director(S_Director dir[])
{
    char nombre[20];
    int i;


    if(!getStringLetras("Ingrese nombre del director a eliminar: ",nombre))
    {
        printf("Reingrese!! El nombre debe contener letras!!\n");
    }
    else
    {
        for(i=0;i<cont_direc;i++)
        {
            if(strcmp(nombre,dir[i].nombre)==0)
            {
                dir[i].estado = BAJA;
                break;
            }
        }
        if(strcmp(nombre,dir[i].nombre)!=0)
            printf("El nombre ingresado no existe!!");
    }
}



