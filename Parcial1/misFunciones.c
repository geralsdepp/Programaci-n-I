#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "misValidaciones.h"
#define USUARIOS 100
#define PRODUCTOS 200
#define CALIFICACIONES 200

#define ALTA 1
#define BAJA -1
#define VACIO 0

int cont_usuario;
int cont_calificaciones;
int cont_producto;

/** \brief despliega un menu de opciones
 *
 * \return retorna la opcion ingresada
 *
 */

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.ALTA USUARIO.\n");
    printf("2.MODIFICAR DATOS DE USUARIO.\n");
    printf("3.BAJA DE USUARIO.\n");
    printf("4.PUBLICAR PRODUCTO\n");
    printf("5.MODIFICAR PUBLICACION\n");
    printf("6.CANCELAR PUBLICACION\n");
    printf("7.COMPRAR PRODUCTO\n");
    printf("8.LISTAR PUBLICACIONES DE USUARIO\n");
    printf("9.LISTAR PUBLICACIONES\n");
    printf("10.LISTAR USUARIOS\n");
    printf("11.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
/** \brief inicializa mi array de usuarios en 0
 *
 * \param ficha, array de usuarios
 * \return void
 *
 */

void inicializarArray_usuario(S_Usuario ficha[])
{
    int i;

    for(i=0; i<USUARIOS; i++)
    {
        ficha[i].estado = VACIO;
    }
}
/** \brief inicializa mi array de productos de cada usuario en 0
 *
 * \param ficha, array de usuarios
 * \return void
 *
 */

void inicializarArray_producto(S_Usuario ficha[])
{
    int i,j;

    for(i=0; i<USUARIOS; i++)
    {
        for(j=0; j< PRODUCTOS; j++)
        {
            ficha[i].producto[j].estado = VACIO;
        }
    }
}
/** \brief inicializa mi array de calificaciones de cada usuario en 0
 *
 * \param ficha, array de usuarios
 * \return void
 *
 */
void inicializarArray_calificacion(S_Usuario ficha[])
{
    int i,j;

    for(i=0; i<USUARIOS; i++)
      {
        for(j=0; j<CALIFICACIONES; j++)
        {
            ficha[i].puntuacion[j].estado = VACIO;
        }
    }
}

/** \brief busca el primer espacio libre
 *
 * \param ficha, array de usuarios
 * \param cant, cantidad maxima de usarios
 * \return primer espacio libre
 *
 */

int obtenerEspacioLibre_usuario(S_Usuario ficha[],int cant)
{
    int retorno;

    for(cont_usuario=0; cont_usuario<cant; cont_usuario++)
    {
        if(ficha[cont_usuario].estado == VACIO)
        {
            retorno = cont_usuario;
            break;
        }
        else if(ficha[cont_usuario].estado == ALTA)
        {
            retorno = -1;
            break;
        }
    }
    return retorno;
}

int obtenerEspacioLibre_producto(S_Usuario ficha[],int idU,int cant)
{
    int i,j;
    int retorno;

    for(i = 0;i<cont_usuario+1;i++)
    {
        if(ficha[i].idUsuario == idU)
        {
            for(j = 0; j<cant; j++)
            {
                if(ficha[i].estado == ALTA && ficha[i].producto[j].estado == VACIO)
                {
                    retorno = j;
                    break;
                }
                else if(ficha[i].estado == BAJA)
                {
                    retorno = -1;
                    break;
                }
            }
        }
    }
    return retorno;
}

int obtenerEspacioLibre_calificacion(S_Usuario ficha[],int cant)
{
    int retorno;

    for(cont_usuario = 0;cont_usuario<USUARIOS;cont_usuario++)
    {
        for(cont_calificaciones = 0; cont_calificaciones<PRODUCTOS; cont_calificaciones++)
        {
            if(ficha[cont_usuario].producto[cont_calificaciones].estado == VACIO)
            {
                retorno = cont_calificaciones;
                break;
            }
        }
    }
    return retorno;
}

void alta_usuario(S_Usuario ficha[],int cant)
{
    int flag = 0,i;
    char nombre[30], password[10];

    i = obtenerEspacioLibre_usuario(ficha,cant);

    if(i == -1)
    {
        printf("array lleno!!\n");
    }
    else
    {
        printf("El primer espacio libre es: %d\n",i);

        while(flag == 0)
        {
            if(!getStringLetras("Ingrese nombre: ",nombre))
            {
                printf("Reingrese!!\n");
            }
            else
                flag = 1;
        }
        flag = 0;
        while(flag == 0)
        {
            if(!getStringLetras("Ingrese password: ",password))
            {
                printf("Reingrese!!\n");
            }
            else
                flag = 1;
        }
        strcpy(ficha[i].nombre,nombre);
        strcpy(ficha[i].password,password);
        ficha[i].idUsuario = i;
        ficha[i].estado = ALTA;
    }
}

void modificar_usuario(S_Usuario ficha[])
{
    int i,flag = 0,idU;
    char id_str[5];
    char nombre[30], password[10];

    if(!getStringNumeros("Ingrese id a modificar: ",id_str))
    {
        printf("El id ser numerico!!");
    }
    else
    {
        idU = atoi(id_str);
        for(i=0; i<cont_usuario+1; i++)
        {
            if(idU == ficha[i].idUsuario && ficha[i].estado == ALTA)
            {
                while(flag == 0)
                {
                    if(!getStringLetras("Ingrese nombre: ",nombre))
                    {
                        printf("El nombre debe contener letras!!\n");
                    }
                    else
                        flag = 1;
                }
                flag = 0;
                while(flag == 0)
                {
                    getString("Ingrese password: ",password);
                    if(!alfanumerico(password))
                    {
                        printf("La password solo puede contener letras y numeros!!\n");
                    }
                    else
                    {
                        flag = 1;
                        strcpy(ficha[i].nombre,nombre);
                        strcpy(ficha[i].password,password);
                        break;
                    }
                }
            }
            else if(ficha[i].idUsuario != idU || ficha[i].estado != ALTA)
            {
                printf("El id ingresado no existe o no esta dado de alta!! \n");
                break;
            }
        }
    }
}

void baja_usuario(S_Usuario ficha[])
{
    int i,flag = 0;
    int idU;
    char id_str[5];

    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese el id de usuario a dar de baja: ",id_str))
        {
            printf("El id debe ser numerico!!");
        }
        else
        {
            flag = 1;
            idU = atoi(id_str);

            for(i=0; i<cont_usuario+1; i++)
            {
                if(idU == ficha[i].idUsuario && ficha[i].estado == ALTA)
                {
                    ficha[i].estado = BAJA;
                    printf("El id %d se ha dado de baja!!",idU);
                    system("pause");
                    break;
                }
                else if(idU != ficha[i].idUsuario || ficha[i].estado != ALTA)
                {
                    printf("El id ingresado no existe!!\n");
                    system("pause");
                    break;
                }
            }
        }
    }
}

void publicar_producto(S_Usuario ficha[],int cant)
{
    int flag = 0,i,j;
    int precio, stock,idU;
    char nombre[30],precio_str[5],stock_str[10],id_str[5];

    while(flag==0)
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe contener letras!!");
        }
        else
        {
            idU = atoi(id_str);

            i = obtenerEspacioLibre_producto(ficha,idU,cant);

            if(i == BAJA)
            {
                printf("El id ingresado se encuentra dado de baja!!\n");
            }
            else
            {
                printf("EL primer espacio libre es: %d\n",i);
                //recorro id
                for(j=0;j<cont_usuario+1;j++)
                {
                    for(cont_producto=0;cont_producto<cant;cont_producto++)
                    {
                        if(idU == ficha[j].idUsuario)
                        {
                            while(flag == 0)
                            {
                                if(!getStringLetras("Ingrese nombre de producto: ",nombre))
                                {
                                    printf("Reingrese!!\n");
                                }
                                else
                                    flag = 1;
                            }
                            flag = 0;
                            while(flag == 0)
                            {
                                if(!getStringNumeros("Ingrese precio: ",precio_str))
                                {
                                    printf("Reingrese!\n");
                                }
                                else
                                    flag = 1;
                            }
                            flag = 0;
                            while(flag == 0)
                            {
                                if(!getStringNumeros("Ingrese numero de stock: ",stock_str))
                                {
                                    printf("Reingrese!\n");
                                }
                                else
                                {
                                    flag = 1;
                                    precio = atoi(precio_str);
                                    stock = atoi(stock_str);
                                }
                            }
                            strcpy(ficha[j].producto[i].nombre,nombre);
                            ficha[j].producto[i].precio = precio;
                            ficha[j].producto[i].stock = stock;
                            ficha[j].producto[i].idProducto = cont_producto;
                            ficha[j].producto[i].estado = ALTA;
                           // ficha[j].producto[i].idUsuario = idU;
                            ficha[j].contProducto = i+1;
                            break;
                        }
                        else if(cont_usuario +1 == j)
                        {
                            printf("El id no existe!!");
                            break;
                        }
                    }
                }
            }
        }
    }
}

void modificar_publicacion(S_Usuario ficha[])
{
    int idP,idU,precio,stock;
    int i,j,flag = 0;
    char id_str[5],precio_str[5],stock_str[5];

    while(flag==0)
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idU = atoi(id_str);
                //recorro id de 100
            for(i=0;i<cont_usuario+1;i++)
            {
                for(j=0;j<cont_producto+1;j++)
                {
                    if(idU == ficha[i].idUsuario)
                    {
                        printf("Campos del producto:\n");
                        printf("id: %d\n",ficha[i].producto[j].idProducto);
                        printf("  Nombre: %s\n",ficha[i].producto[j].nombre);
                        printf("  Precio: %d\n",ficha[i].producto[j].precio);
                        printf("  Cantidad vendida: %d\n",ficha[i].producto[j].cantVendida);
                        printf("  Stock: %d\n",ficha[i].producto[j].stock);
                    }
                    else if(cont_usuario+1 == i)
                    printf("No se encuentra el id ingresado\n");
                }
            }
            flag = 0;

            //recorro id de 1000
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese id del producto: ",id_str))
                {
                    printf("El id debe ser numerico!!\n");
                }
                else
                {
                    flag = 1;
                    idP = atoi(id_str);

                    for(i=0;i<cont_usuario+1;i++)
                    {
                        for(j=0;j<cont_producto+1;j++)
                        {
                            if(idP == ficha[i].producto[j].idProducto)
                            {
                                 while(flag == 1)
                                 {
                                     if(!getStringNumeros("Ingrese nuevo precio: ",precio_str))
                                     {
                                        printf("Reingrese!\n");
                                     }
                                     else
                                        flag = 0;
                                 }
                                 flag = 1;
                                 while(flag == 1)
                                 {
                                     if(!getStringNumeros("Ingrese nuevo numero de stock: ",stock_str))
                                     {
                                         printf("Reingrese!\n");
                                     }
                                     else
                                     {
                                         flag = 0;
                                         precio = atoi(precio_str);
                                         stock = atoi(stock_str);

                                         ficha[i].producto[j].precio = precio;
                                         ficha[i].producto[j].stock = stock;
                                         break;
                                     }
                                 }
                            }
                            else if(cont_producto + 1 == i)
                            {
                                printf("El id no existe!!");
                            }
                        }
                    }
                }
            }
        }
    }
 }
void cancelar_publicacion(S_Usuario ficha[])
{
    char id_str[5];
    int i,j,idU,idP;
    int flag = 0;

    do
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idU = atoi(id_str);
            //recorro id de 100
            for(i=0;i<cont_usuario+1;i++)
            {
                for(j=0;j<cont_producto+1;j++)
                {
                    if(idU == ficha[i].idUsuario)
                    {
//                        if(idU == ficha[i].producto[j].idUsuario)
//                        {
                            printf("Campos del producto: \n");
                            printf("id: %d\n",ficha[i].producto[j].idProducto);
                            printf("  Nombre: %s\n",ficha[i].producto[j].nombre);
                            printf("  Precio: %d\n",ficha[i].producto[j].precio);
                            printf("  Cantidad vendida: %d\n",ficha[i].producto[j].cantVendida);
                            printf("  Stock: %d\n",ficha[i].producto[j].stock);
//                        }
                    }
                    else if(cont_usuario+1 == i)
                    {
                        printf("No se encuentra el id ingresado\n");
                    }
                }
            }
            flag = 0;
            //recorro id de 1000
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese id del producto que desea cancelar: ",id_str))
                {
                    printf("El id debe ser numerico!!\n");
                }
                else
                {
                    flag = 1;
                    idP = atoi(id_str);

                    for(i=0;i<cont_usuario+1;i++)
                    {
                        for(j=0;j<cont_producto+1;j++)
                        {
                            if(idP == ficha[i].producto[j].idProducto)
                            {
                                ficha[i].producto[j].estado = BAJA;
                                break;
                            }
                            else if(cont_producto + 1 == j)
                            {
                                printf("El id no existe!!");
                                break;
                            }
                        }
                    }
                }
            }
        }
    }while(flag == 0);
}

void comprar_producto(S_Usuario ficha[],int cant)
{
    char id_str[5],calificacion_str[5];
    int i,j,c,idP,calificacion,flag = 0;

    while(flag ==0)
    {
        if(!getStringNumeros("Ingrese id del producto que desea comprar: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idP = atoi(id_str);

            for(i=0;i<cont_usuario+1;i++)
            {
                for(j=0;j<cont_producto+1;j++)
                {
                    if(idP == ficha[i].producto[j].idProducto && ficha[i].producto[j].stock > 0)
                    {
                        while(flag == 1)
                        {
                            if(!getStringNumeros("Ingrese calificacion para el vendedor: ",calificacion_str))
                            {
                                printf("Debe ser numerico!!\n");
                            }
                            else
                            {
                                c = obtenerEspacioLibre_calificacion(ficha,CALIFICACIONES);
                                flag = 1;
                                calificacion = atoi(calificacion_str);
                                ficha[i].producto[j].cantVendida = j+1;//se realiza la compra
                                ficha[i].producto[j].stock = ficha[i].producto[j].stock - 1;
                                ficha[i].puntuacion[c].calif = calificacion;
                                break;
                            }
                        }
                    }
                    else if(cont_producto + 1 == j)
                    {
                        printf("El id no existe!!");
                        break;
                    }
                }
            }
        }
    }
}

void listar_public_usuario(S_Usuario ficha[])
{
    char id_str[5];
    int idU,i,j;
    int flag = 0;

    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idU = atoi(id_str);
            //recorro id de 100
            for(i=0;i<cont_usuario+1;i++)
            {
                for(j=0;j<ficha[i].contProducto;j++)
                {
                    if(idU == ficha[i].idUsuario)
                    {
                            printf("Campos del producto:\n\n");
                            printf("id: %d\n",ficha[i].producto[j].idProducto);
                            printf("  Nombre: %s\n",ficha[i].producto[j].nombre);
                            printf("  Precio: %d\n",ficha[i].producto[j].precio);
                            printf("  Cantidad vendida: %d\n",ficha[i].producto[j].cantVendida);
                            printf("  Stock: %d\n",ficha[i].producto[j].stock);
                    }
                    else if(cont_usuario + 1 == i)
                    {
                        printf("No se encuentra el id ingresado\n");
                        break;
                    }
                }
            }
            system("pause");
        }
    }
}

void listar_public(S_Usuario ficha[])
{
    int i,j;

    for(i=0;i<cont_usuario+1;i++)
    {
        for(j=0;j<PRODUCTOS;j++)
        {
            printf("ID: %d\n",ficha[i].producto[j].idProducto);
            printf("Nombre: %s\n",ficha[i].producto[j].nombre);
            printf("Precio: %d\n",ficha[i].producto[j].precio);
            printf("Cantidad Vendida: %d\n",ficha[i].producto[j].cantVendida);
            printf("Stock: %d\n",ficha[i].producto[j].stock);
            printf("Nombre de usuario: %s\n",ficha[i].nombre);
        }
    }
    system("pause");
}

void listar_usuario(S_Usuario ficha[])
{
    int i;
    float prom;

    for(i=0;i<cont_usuario+1;i++)
    {
        prom = promedio(ficha,i);
        printf("Usuario: %s --> Calificacion Promedio: %.2f",ficha[i].nombre,prom);
    }
}

float promedio(S_Usuario ficha[],int i)
{
    float retornoPromedio;
    int j,suma=0;

        for(j=0;j<cont_calificaciones+1;j++)
        {
            suma = suma + ficha[i].puntuacion[j].calif;
        }

        retornoPromedio=(float)suma/cont_calificaciones;

    return retornoPromedio;
}
