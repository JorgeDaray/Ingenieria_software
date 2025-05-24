#ifndef NODOMENU_H
#define NODOMENU_H

#include "Producto.h"

class NodoMenu
{
public:
    Producto PRODUCTO;
    int NRR;
    NodoMenu *NEXT;

    NodoMenu();
};

#endif
