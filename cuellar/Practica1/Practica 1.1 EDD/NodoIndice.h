#ifndef NODOINDICE_H
#define NODOINDICE_H

#include <iostream>
using namespace std;
#include "NodoMenu.h"

class NodoIndice
{
public:
    int NRR;
    char CODIGO[8];
    size_t N_CODIGO;
    NodoIndice *NEXT;

    NodoIndice();
    void InsertarValores(NodoMenu *Nodo);
};

#endif
