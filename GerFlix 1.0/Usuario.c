
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
     int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]={"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,104,104,100,103};



    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}


void mostrarUsuario(eUsuario usuario )
{
    printf("\nId: %d", usuario.idUsuario);
    printf("\nNombre: %s", usuario.nombre);

}

void mostrarListaUsuarios(eUsuario listado[], int TAMUSUARIO)
{
    int i;
    for (i = 0; i <TAMUSUARIO; i++)
    {
        if(listado[i].estado == 1)
        {
        mostrarUsuario(listado[i]);
        }
    }
}

void mostrarUsuariosConSerie (eUsuario usuarios[], int cantidadUsuarios, eSerie serie[], int cantidadSeries)
{
    int i;
    int j;

    for(int i=0;i<cantidadUsuarios;i++) // usuario
    {
        if(usuarios[i].estado == 1)
        {
        printf("%3d %10s ", usuarios[i].idUsuario, usuarios[i].nombre); // muestro datos de usuario
        for(int j=0;j<cantidadSeries;j++) // serie
          {

            if(serie[j].estado == 1 && usuarios[i].idSerie == serie[j].idSerie) // verifico que estado de serie no sea 0, tenga datos
            {
                printf("%s", serie[j].nombre);
                break;//mostrar datos serie
            }
          }
          printf("\n");
        }
    }

}
