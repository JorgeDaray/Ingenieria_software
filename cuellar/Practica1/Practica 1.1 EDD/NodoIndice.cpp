#include "NodoIndice.h"

NodoIndice::NodoIndice()
{
    NRR = 0;
    N_CODIGO = sizeof(CODIGO) / sizeof(CODIGO[0]);
    NEXT = nullptr;
}
void NodoIndice::InsertarValores(NodoMenu *Nodo)
{
    NRR = Nodo->NRR;
    for(int i = 0; i < N_CODIGO; i++)
        CODIGO[i] = Nodo->PRODUCTO.CODIGO[i];
}
