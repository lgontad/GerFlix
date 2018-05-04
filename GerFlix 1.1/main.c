#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 15
#define TAMUSERIE 300
// viernes Altas Bajas Modificaciones de Usuarios y Series
// alta de usuarios.. doy de alta usuario, muestro todas la series que hay y el usuario elige una -1 -2 -3

int main()
{
    int serieIngresada;
    int usuarioIngresado;

    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];
    eUsuario_Serie listaDeUsuarioSerie[TAMUSERIE];
    inicializarSeriesEstado(listaDeSeries, TAMSERIE);

    inicializarSeriesHardCode(listaDeSeries);
    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    //inicializarUsuariosHardCode(listaDeUsuarios);

    mostrarListaSeries(listaDeSeries,TAMSERIE);
    //mostrarListaUsuarios(listaDeUsuarios, TAMUSUARIO);
    altaUsuario (listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE, listaDeUsuarioSerie, TAMUSERIE);

    //mostrarUsuariosConSerie(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE, usuarioIngresado, listaDeUsuarioSerie, TAMUSERIE);
    mostrarSerieConSuUsuario(listaDeSeries, TAMSERIE, listaDeUsuarios, TAMUSUARIO, usuarioIngresado, listaDeUsuarioSerie, TAMUSERIE);


    /*printf("\nIngrese el id de una serie: ");
    scanf("%d", &serieIngresada);*/

   altaUsuario (listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE, listaDeUsuarioSerie, TAMUSERIE);




    //listarUsuariosSegunSerie(listaDeSeries, TAMSERIE, listaDeUsuarios, TAMUSUARIO, serieIngresada);


    //mostrarUsuarioConSerie(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);


    /*

    1. Mostrar el listado de series
    2. Mostrar el listado de usuarios
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.

    */

    return 0;
}
