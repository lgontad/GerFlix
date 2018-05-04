#include "Serie.h"
#include "Usuario_Serie.h"

typedef struct
{
    int idUsuario;
    char nombre[50];
    int estado;
}eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarListaUsuarios(eUsuario[], int);
void mostrarUsuario (eUsuario usuario);
void mostrarUsuariosConSerie (eUsuario[], int, eSerie[], int, int, eUsuario_Serie[], int );
void mostrarSerieConSuUsuario(eSerie[], int, eUsuario[], int, int, eUsuario_Serie[], int );
void listarUsuariosSegunSerie(eSerie[],int, eUsuario [], int, int);
void altaUsuario (eUsuario[],int,eSerie[], int, eUsuario_Serie[], int);
