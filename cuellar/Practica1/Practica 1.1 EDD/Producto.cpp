#include "Producto.h"

Producto::Producto()
{
    N_NOMBRE = sizeof(NOMBRE) / sizeof(NOMBRE[0]);
    N_DESCRIPCION = sizeof(DESCRIPCION) / sizeof(DESCRIPCION[0]);
    N_ESPECIALIDAD = sizeof(ESPECIALIDAD) / sizeof(ESPECIALIDAD[0]);
    N_CODIGO = sizeof(CODIGO) / sizeof(CODIGO[0]);
    Borrar_Campos();
}
void Producto::Borrar_Campos()
{
    for(size_t i = 0; i < N_NOMBRE-1; i++)
    {
        NOMBRE[i] = ' ';
    }
    NOMBRE[N_NOMBRE-1] = '\0';
    for(size_t i = 0; i < N_DESCRIPCION-1; i++)
    {
        DESCRIPCION[i] = ' ';
    }
    DESCRIPCION[N_DESCRIPCION-1] = '\0';
    for(size_t i = 0; i < N_ESPECIALIDAD-1; i++)
    {
        ESPECIALIDAD[i] = ' ';
    }
    ESPECIALIDAD[N_ESPECIALIDAD-1] = '\0';
    for(size_t i = 0; i < N_CODIGO-1; i++)
    {
        CODIGO[i] = ' ';
    }
    CODIGO[N_CODIGO-1] = '\0';
    PRECIO = 0;
}
void Producto::Generar_CODIGO()
{
    srand(time(NULL));
    int N = rand() % 100;
    char Num[3];
    itoa(N, Num, 3);
    CODIGO[0] = Num[0];
    CODIGO[1] = Num[1];
    int cont=2;
    if(ESPECIALIDAD[2] == 'C' or ESPECIALIDAD[2] == 'c')
    {
        CODIGO[cont] = 'P';
        CODIGO[cont+1] = 'I';
        cont=4;
    }
    else
    {
        CODIGO[cont] = toupper(ESPECIALIDAD[0]);
        cont++;
    }
    for(int i = 0; i < 3; i++)
    {
        CODIGO[cont+i] = toupper(NOMBRE[i]);
    }
}
