#include "ListaMenu.h"

ListaMenu::ListaMenu()
{
    HEAD = nullptr;
    HEAD_INDICE = nullptr;
    ACTUAL = 0;
}
void ListaMenu::Insertar(const Producto &Producto)
{
    NodoMenu *N = new NodoMenu;
    N->PRODUCTO = Producto;
    N->NRR = ACTUAL;
    if(HEAD)
    {
        NodoMenu *act = HEAD;
        while (act->NEXT)
        {
            act = act->NEXT;
        }
        act->NEXT = N;
    }
    else
    {
        HEAD = N;
    }
    ACTUAL++;

    ofstream Archivo;
    Archivo.open("Menu.txt", ios::app);

    Archivo << left << setw(15) << N->PRODUCTO.CODIGO << '|' << setw(32) << N->PRODUCTO.NOMBRE << '|' << setw(152) << N->PRODUCTO.DESCRIPCION << '|' << setw(10) << N->PRODUCTO.PRECIO << '|' << setw(32) << N->PRODUCTO.ESPECIALIDAD << '\n';
    Archivo.close();

    NodoIndice *I = new NodoIndice;
    I->InsertarValores(N);
    if(HEAD_INDICE)
    {
        NodoIndice *current = HEAD_INDICE;
        while (current->NEXT)
        {
            current = current->NEXT;
        }
        current->NEXT = I;
    }
    else
    {
        HEAD_INDICE = I;
    }
    ofstream Indice;
    Indice.open("Indice.txt", ios::app);
    Indice << left << setw(9) << I->CODIGO << '|' << setw(5) << I->NRR << '\n';
    Indice.close();
}
void ListaMenu::Imprimir()
{
    NodoMenu *act = HEAD;
    if(!HEAD)
    {
        cout << "Lista Menu Vacia" << endl;
        return;
    }
    while(act)
    {
        cout << act->PRODUCTO << endl;
        cout << act->NRR << endl;
        act = act->NEXT;
    }
}
void ListaMenu::ImprimirIndice()
{
    NodoIndice *act = HEAD_INDICE;
    if(!HEAD_INDICE)
    {
        cout << "Lista Indice Vacia" << endl;
        return;
    }
    while(act)
    {
        cout << act->CODIGO << endl;
        cout << act->NRR << endl;
        act = act->NEXT;
    }
}


void ListaMenu::BuscarRegistro(char Codigo[])
{
    if(!HEAD_INDICE)
    {
        cout << "No hay registros disponibles" << endl;
        return;
    }
    NodoIndice *aux = HEAD_INDICE;
    bool band = false;
    while(aux and band == false)
    {
        band = true;
        for(int i = 0; i < aux->N_CODIGO-2; i++)
            if(Codigo[i] != aux->CODIGO[i] and band == true)
                band = false;
        if(band == false)
            aux = aux->NEXT;
        else
            break;
    }
    if(band == false)
    {
        cout << "No se encontro el registro" << endl;
        return;
    }
    int Cont = aux->NRR;
    NodoMenu *current = HEAD;
    for (int i = 0; i < Cont; i++)
    {
        current = current->NEXT;
    }
    cout << current->PRODUCTO << endl;
}


void ListaMenu::CargarDatos()
{
    fstream Menu;
    Menu.open("Menu.txt", ios::in);
    while(!Menu.eof())
    {
        NodoMenu M;
        char Caracter;
        for(int i = 0; i <= 15; i++)
        {
            Menu >> Caracter;
            if(i < 8)
                M.PRODUCTO.CODIGO[i] = Caracter;
        }
        for(int i = 0; i <= 32; i++)
        {
            Menu >> Caracter;
            if(i < 30)
                M.PRODUCTO.NOMBRE[i] = Caracter;
        }
        for(int i = 0; i <=152; i++)
        {
            Menu >> Caracter;
            if(i < 150)
                M.PRODUCTO.DESCRIPCION[i] = Caracter;
        }
        for(int i = 0; i < 8; i++)
            cout << M.PRODUCTO.CODIGO[i];
        cout << endl;
        for(int i = 0; i < 30; i++)
            cout << M.PRODUCTO.NOMBRE[i];
        cout << endl;
        for(int i = 0; i <=150; i++)
            cout << M.PRODUCTO.DESCRIPCION[i];
        cout << endl;
        break;
    }
    Menu.close();
//    ifstream  Indice("Indice.txt", ios::in);
//
//    Indice.close();

}


//while(aux)
//{
//for(int i = 0; i < aux->N_CODIGO-1; i++)
//cout << Codigo[i] << " <-> " << aux->CODIGO[i] << endl;
//cout << endl << "Registro: " << endl;
//aux = aux->NEXT;
//}



