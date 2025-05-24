#ifndef LISTAMENU_H
#define LISTAMENU_H

#include "NodoMenu.h"
#include "NodoIndice.h"
#include <fstream>

class ListaMenu
{
public:
    NodoMenu *HEAD;
    NodoIndice *HEAD_INDICE;
    int ACTUAL;

    ListaMenu();
    void Insertar(const Producto &Producto);
    void Imprimir();
    void ImprimirIndice();
    void CargarDatos();
    void BuscarRegistro(char Codigo[]);
};

#endif
