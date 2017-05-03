#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#define PELICULAS 200
#define DIRECTORES 100
#define ALTA 1
#define BAJA -1
#define VACIO 0

int main()
{
    char seguir = 's';
    int opcion;
    S_Pelicula ficha[PELICULAS];
    S_Director dir[DIRECTORES];

    inicializarArray(ficha,PELICULAS);
    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            alta_peliculas(ficha,PELICULAS);
            break;
        case 2:

            break;
        case 3:
            baja_peliculas(ficha);
            break;
        case 4:
            nuevo_director(dir,DIRECTORES);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            break;
        case 8:
            seguir = 'n';
            break;
        }
    }while(seguir == 's');


    return 0;
}
