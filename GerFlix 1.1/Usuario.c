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
/*void inicializarUsuariosHardCode(eUsuario usuarios[])
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
}*/


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



void mostrarUsuariosConSerie (eUsuario usuarios[], int cantidadUsuarios, eSerie serie[], int cantidadSeries, int usuarioIngresado, eUsuario_Serie usuarioSerie[], int cantidadUSerie)
{
    int i;
    int j;
    int auxUsuario;
    auxUsuario = usuarioIngresado;

    for(int i=0;i<cantidadUsuarios;i++) // usuario
    {
        if(usuarios[i].estado == 1)
        {

        for(int j=0;j<cantidadSeries;j++) // serie
          {

            if(serie[j].estado == 1 && usuarioSerie[i].idSerie == serie[j].idSerie) // verifico que estado de serie no sea 0, tenga datos
            {
                printf("%s", serie[j].nombre);
                break;//mostrar datos serie
            }
          }
          printf("\n");
        }
    }

}

void mostrarSerieConSuUsuario(eSerie serie[],int cantidadSeries, eUsuario usuario[], int cantidadUsuarios, int usuarioIngresado, eUsuario_Serie usuarioSerie[], int cantidadUSerie)
{
    int i;
    int j;
    int auxUsuario;
    auxUsuario = usuarioIngresado;

    for(i=0 ; i<cantidadSeries ; i++)
    {
        if(serie[i].estado == 1)
        {

            for(j=0 ; j<cantidadUsuarios ; j++)
            {
                if(usuario[j].estado == 1 && serie[i].estado == 1 &&
                   serie[i].idSerie == usuarioSerie[j].idSerie)
                {
                    printf("%10s " " %3s \n",serie[i].nombre, usuario[j].nombre);
                }
            }
        }
    }
}



/*void listarUsuariosSegunSerie (eSerie serie[],int cantidadSeries, eUsuario usuario[], int cantidadUsuarios, int IdSerieIngresado)

{
    int i;
    int j;
    int auxSerie;
    auxSerie = IdSerieIngresado;

    for(i=0 ; i<cantidadSeries ; i++)
    {
        if(serie[i].estado == 1)
        {

            for(j=0 ; j<cantidadUsuarios ; j++)
            {
                if(usuario[j].estado == 1 && serie[i].estado == 1 &&
                   serie[i].idSerie == auxSerie && usuario[j].idSerie == auxSerie)
                {
                    printf("%10s " " %3s \n",serie[i].nombre, usuario[j].nombre);
                }
            }
        }
    }
}

void mostarSerieMasPopular (eSerie serie[],int cantidadSeries, eUsuario usuario[], int cantidadUsuarios)
{





}*/

void altaUsuario(eUsuario usuario[], int cantidadUsuarios, eSerie series[], int cantidadSeries, eUsuario_Serie usuarioSerie[], int cantidadUsuarioSerie)
{
    int indexUsuarioSerie;
    int indexUsuario;
    int idNuevoUsuario;
    int i;


    //busco posición libre y la guardo en index
    for (i=0; i<cantidadUsuarios; i++)
    {
        if (usuario[i].estado==0)
        {
            indexUsuario=i;
            break;
        }
    }

    idNuevoUsuario = indexUsuario+1000;
    //le asigno un id
    usuario[indexUsuario].idUsuario=idNuevoUsuario;

    //pido el nombre
    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(usuario[indexUsuario].nombre);
    printf("\n");

    //le pregunto qué serie quiere ver
    for (i=0; i<cantidadSeries; i++)
    {
        if (series[i].estado==1)
        {
            printf("%d.%s\n",series[i].idSerie, series[i].nombre);
        }
    }
    printf("\n");
    printf("Ingrese el id de la serie que desea ver: ");

    // BUSCO UN LUGAR LIBRE EN LISTADO DE USUARIO_SERIE
     for (i=0; i<cantidadUsuarioSerie; i++)
    {
        if (usuarioSerie[i].estado==0)
        {
            indexUsuarioSerie=i;
            break;
        }
    }
    usuarioSerie[indexUsuarioSerie].idUsuario= idNuevoUsuario;
    scanf("%d" , &usuarioSerie[indexUsuarioSerie].idSerie);

    //pongo el estado en 1
    usuario[indexUsuario].estado=1;

    //aviso que el usuario se dio de alta
    printf("\nSe registro con exito. Su id es %d\n",usuarioSerie[indexUsuarioSerie].idUsuario);

}



