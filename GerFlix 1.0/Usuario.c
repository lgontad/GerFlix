#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void mostrarSerieConSuUsuario(eSerie serie[],int cantidadSeries, eUsuario usuario[], int cantidadUsuarios)
{
    int i;
    int j;

    for(i=0 ; i<cantidadSeries ; i++)
    {
        if(serie[i].estado == 1)
        {

            for(j=0 ; j<cantidadUsuarios ; j++)
            {
                if(usuario[j].estado == 1 && serie[i].estado == 1 &&
                   serie[i].idSerie == usuario[j].idSerie)
                {
                    printf("%10s " " %3s \n",serie[i].nombre, usuario[j].nombre);
                }
            }
        }
    }
}




/*eUsuario altaDeUsuario()
{
    eUsuario retorno;
    do
    {
        printf("\nIngrese nombre del usuario: ");
        fflush(stdin);
        gets(retorno.nombre);
        if(strcmp(retorno.nombre, "") == 0)
        {
            printf("\nDebe ingresar el nombre del usuario");
        }
    } while(strcmp(retorno.nombre, "") == 0);
    do
        {
            mostrarListaSeries(listado[], TAMSERIE);
            printf("\nIngrese ID de la serie que ve el Usuario: ");
            scanf("%d", &listaDeUsuarios[posicionDeIngreso].idSerie);
            serieExistente = existeSerie(listaDeSeries, listaDeUsuarios[posicionDeIngreso].idSerie, TAMSERIE);
            if(serieExistente == 0)
            {
                printf("\nEl ID ingresado no existe. Por favor vuelva a ingresar el dato");
            }
        } while(serieExistente == 0);

    retorno.estado = 1;

    return retorno;
}
*/
