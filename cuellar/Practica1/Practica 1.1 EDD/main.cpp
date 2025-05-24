#include <iostream>
using namespace std;

#include "ListaMenu.h"

int main()
{
    int opc=0;
    ListaMenu *Lista = new ListaMenu();
    while(opc!=3)
    {

        cout<<"\n\t\t|TELEPIZZA|\n";
        cout<<"\n1. Insertar registro\n";
        cout<<"2. Mostrar registro por su codigo\n";
        cout<<"3. Salir\n";
        cout<<"Binvenido elija una opcion: ";
        cin >> opc;
        cout<<endl;
        if(opc == 1)
        {
            cin.ignore();
            Producto P;


            cout << "Dame el nombre del producto " << endl;
            cin.getline(P.NOMBRE, P.N_NOMBRE);
            cout << "Dame la descripcion del producto" << endl;
            cin.getline(P.DESCRIPCION, P.N_DESCRIPCION);
            cout << "Dame el precio del producto" << endl;
            cin >> P.PRECIO;
            char Basura[10];
            cin.getline(Basura, 10);
            cout << "Dame la especialidad del producto " << endl;
            cin.getline(P.ESPECIALIDAD, P.N_ESPECIALIDAD);
            P.Generar_CODIGO();
            Lista->Insertar(P);

        }
        else if(opc == 2)
        {
            cin.ignore();
            char Codigo[20];
            for(int i = 0; i < 20; i++)
                Codigo[i] = ' ';
            cout << "Ingrese el codigo del registro a buscar: ";
            cin.getline(Codigo, 20);
            char Basura[10];
            cin.getline(Basura, 10);
            for(int i = 0; i < 7; i++)
                Codigo[i] = toupper(Codigo[i]);
            Lista->BuscarRegistro(Codigo);
            opc = 0;
        }
        else if(opc == 3)
        {
            cout<<"sliendo..."<<endl;
            Lista->CargarDatos();

        }
        else
        {
            cout << "Ingrese una opcion valida" << endl;
        }
    }
    return 0;
}
