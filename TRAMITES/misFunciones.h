typedef struct
{
    char dni[10];
    int turno;
    int tramite;
    int estado;
}Cliente;

int menuOpcion(void);
int cargar_dni(Cliente turno[],int tramite,int cant);
int turno_urgente(Cliente turnoUrgente[],int tramite,int cant);
int turno_regular(Cliente turnoRegular[],int tramite,int cant);
void proximo_cliente(Cliente turnoRegular[],Cliente turnoUrgente[],int cant);
void listar(Cliente turnoUrgente[],Cliente turnoRegular[]);
void informar(Cliente turnoUrgente[],Cliente turnoRegular[],Cliente turno[]);
void ordenar(Cliente turno[]);
