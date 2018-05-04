#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario_Serie.h"


void inicializarUsuariosSerieEstado(eUsuario_Serie usuarioSerie[], int cant)
{
     int i;

    for(i=0; i<cant; i++)
    {
        usuarioSerie[i].estado = 0;
    }
}
