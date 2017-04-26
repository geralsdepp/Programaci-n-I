#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#define ATENDIDO 1
#define EN_ESPERA 0
#define REGULAR 0
#define URGENTE 1
#define SIN_ATENDER -1

int cont_urgentes;
int cont_regulares;

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n1.TRAMITE URGENTE.\n2.TRAMITE REGULAR.\n3.PROXIMO CLIENTE.\n4.LISTAR\n5.INFORMAR\n6.SALIR\nEliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int cargar_dni_urgente(Cliente turno[],int tramite,int cant)
{
    int retorno;
    char buffer[10];

    if(tramite == URGENTE)
    {
        for(cont_urgentes=1;cont_urgentes < cant;
         cont_urgentes++)
        {
            if(turno[cont_urgentes].turno == 0)
            {
                printf("Ingrese su DNI: \n");
                scanf("%s",buffer);
                strncpy(turno[cont_urgentes].dni,buffer,10);
                turno[cont_urgentes].tramite = tramite;
                turno[cont_urgentes].turno = cont_urgentes;
                turno[cont_urgentes].estado = EN_ESPERA;
                retorno = turno[cont_urgentes].turno;
                break;
            }
        }
    }
    return retorno;
}

int cargar_dni_regular(Cliente turno[],int tramite,int cant)
{
    int retorno;
    char buffer[10];

    if(tramite == REGULAR)
    {
        for(cont_regulares=1;cont_regulares<cant;cont_regulares++)
        {
            if(turno[cont_regulares].turno == 0)
            {
                printf("Ingrese su DNI: \n");
                scanf("%s",buffer);
                strncpy(turno[cont_regulares].dni,buffer,10);
                turno[cont_regulares].tramite = tramite;
                turno[cont_regulares].turno = cont_regulares;
                turno[cont_regulares].estado = EN_ESPERA;
                retorno = turno[cont_regulares].turno;
                break;
            }
        }
    }
    return retorno;
}

int turno_regular(Cliente turnoRegular[],int tramite, int cant)
{
    int numero_turno;

    numero_turno = cargar_dni_regular(turnoRegular,tramite,cant);

    printf("Turno: %d\n",numero_turno);

    return numero_turno;
}

int turno_urgente(Cliente turnoUrgente[],int tramite,int cant)
{
    int numeroTurno;

    numeroTurno = cargar_dni_urgente(turnoUrgente,tramite,cant);

    printf("\nTurno: %d \n",numeroTurno);

    return numeroTurno;
}

void proximo_cliente(Cliente turnoRegular[], Cliente turnoUrgente[], int cant)
{
    int i;
    int band = 0;

    //Recorro los clientes urgentes
    for(i=1;i<cant;i++)
    {
        if (turnoUrgente[i].estado == EN_ESPERA && turnoUrgente[i].turno != 0)
        {
            printf("Proximo cliente Urgente: %d\n",i);
            turnoUrgente[i].estado = ATENDIDO;
            band = 1;
            break;
        }
    }
    //Recorro los clientes regulares
    for(i=1;i<cant;i++)
    {
        if (turnoRegular[i].estado == EN_ESPERA && band == 0 && turnoRegular[i].turno != 0)
        {
            printf("Proximo cliente REGULAR: %d\n",i);
            turnoRegular[i].estado = ATENDIDO;
            break;
        }
    }
}

void listar(Cliente turnoUrgente[],Cliente turnoRegular[])
{
    int i;

    for(i=1;i<cont_urgentes+1;i++)
    {
        if(turnoUrgente[i].estado == EN_ESPERA)
        {
            printf("Turnos Urgentes sin atender:\nTURNO: %d --- DNI: %s --> EN ESPERA\n",turnoUrgente[i].turno,turnoUrgente[i].dni);
        }
    }
    for(i=1;i<cont_regulares+1;i++)
    {
        if(turnoRegular[i].estado == EN_ESPERA)
        {
            printf("Turnos Regulares sin atender:\nTURNO: %d --- DNI: %s --> EN ESPERA\n",turnoRegular[i].turno,turnoRegular[i].dni);
        }
    }
}

void informar(Cliente turnoUrgente[],Cliente turnoRegular[],Cliente turno[])
{
    int i,j;

    //Copio las dos listas en una nueva llamada turno[].
    for(i=1; i<cont_urgentes+1;i++)
    {
        turno[i] = turnoUrgente[i];
    }
    for(i=i,j=1;j<cont_regulares+1;i++,j++)
    {
        turno[i] = turnoRegular[j];
    }
    ordenar(turno);
}

void ordenar(Cliente turno[])
{
    int i,j;
    char aux[10];
    int suma;

    suma = cont_regulares + cont_urgentes;

    for(i=1; i<suma+1;i++)
    {
        for(j=i+1;j<suma+1;j++)
        {
            if(strcmp(turno[i].dni,turno[j].dni) < 0)
            {
                strcpy(aux,turno[i].dni);
                strcpy(turno[i].dni,turno[j].dni);
                strcpy(turno[j].dni,aux);
            }
        }
    }
    for(i=1;i<suma+1;i++)
    {
        printf("DNI: %s\n", turno[i].dni);
    }
}
