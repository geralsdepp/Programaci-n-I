
typedef struct
{
    int anio;
    int mes;
    int dia;

}S_Fecha;

typedef struct
{
    char nombre[30];
    S_Fecha fecha_nacimiento;
    char pais[30];

}S_Director;

typedef struct
{
    char titulo[30];
    int anio;
    char nacionalidad[20];
    S_Director director;
    int id;
    int estado;
}S_Pelicula;

int menuOpcion(void);
void alta_Peliculas(S_Pelicula ficha[],int cant);
void baja_Peliculas(S_Pelicula ficha[]);
void modificar_pelicula(S_Pelicula ficha[]);
void nuevo_director(S_Director dir[],int cant);
void baja_director(S_Director dir[],int cant);
void inicializarArray(S_Pelicula ficha[],int cant);
int obtenerEspacioLibre(S_Pelicula ficha[],int cant);
