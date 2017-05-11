#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#define USUARIOS 100
#define PRODUCTOS 200
#define CALIFICACIONES 200

int main()
{
    int opcion;
    char seguir = 's';
    S_Usuario ficha[USUARIOS];

    inicializarArray_usuario(ficha);
    inicializarArray_producto(ficha);
    inicializarArray_calificacion(ficha);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            alta_usuario(ficha,USUARIOS);
            break;
        case 2:
            modificar_usuario(ficha);
            break;
        case 3:
            baja_usuario(ficha);
            break;
        case 4:
            publicar_producto(ficha,PRODUCTOS);
            break;
        case 5:
            modificar_publicacion(ficha);
            break;
        case 6:
            cancelar_publicacion(ficha);
            break;
        case 7:
            comprar_producto(ficha,CALIFICACIONES);
            break;
        case 8:
            listar_public_usuario(ficha);
            break;
        case 9:
            listar_public(ficha);
            break;
        case 10:
            listar_usuario(ficha);
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("cls");
    }while(seguir == 's');
    return 0;
}
