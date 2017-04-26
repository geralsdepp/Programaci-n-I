#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#define TURNOS 100
#define REGULAR 0
#define URGENTE 1
#define SIN_ATENDER -1
int main()
{
    int opcion;
    char seguir = 's';
    int i;
    Cliente turnoRegular[TURNOS];
    Cliente turnoUrgente[TURNOS];
    Cliente turno[TURNOS];

    //inicializo mis arrays en 0.

    for(i=0;i<TURNOS;i++)
    {
        turnoRegular[i].turno = 0;
        turnoRegular[i].estado = SIN_ATENDER;
    }

     for(i=0;i<TURNOS;i++)
    {
        turnoUrgente[i].turno = 0;
        turnoUrgente[i].estado = SIN_ATENDER;
    }
    for(i=0;i<TURNOS;i++)
    {
        turno[i].turno = 0;
        turno[i].estado = SIN_ATENDER;
    }
    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            turno_urgente(turnoUrgente,URGENTE,TURNOS);
            break;
        case 2:
            turno_regular(turnoRegular,REGULAR,TURNOS);
            break;
        case 3:
            proximo_cliente(turnoRegular,turnoUrgente,TURNOS);
            break;
        case 4:
            listar(turnoUrgente,turnoRegular);
            break;
        case 5:
            informar(turnoUrgente,turnoRegular,turno);
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }while(seguir == 's');
    return 0;
}
