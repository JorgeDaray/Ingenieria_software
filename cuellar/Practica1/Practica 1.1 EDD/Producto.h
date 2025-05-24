#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Producto
{
public:
    char NOMBRE[30];
    char DESCRIPCION[160];
    char ESPECIALIDAD[30];
    char CODIGO[8]; //FORMA CANONICA
    float PRECIO;
    size_t N_NOMBRE;
    size_t N_DESCRIPCION;
    size_t N_ESPECIALIDAD;
    size_t N_CODIGO;

    Producto();
    void Borrar_Campos();
    void Generar_CODIGO();
    friend ostream& operator <<(ostream &out, const Producto &p)
    {
        out << left;
        out << setw(32) << p.NOMBRE;
        out << setw(152) << p.DESCRIPCION;
        out << setw(32) << p.ESPECIALIDAD;
        out << setw(15) << p.CODIGO;
        out << setw(10) << p.PRECIO;
        return out;
    }
};

#endif
