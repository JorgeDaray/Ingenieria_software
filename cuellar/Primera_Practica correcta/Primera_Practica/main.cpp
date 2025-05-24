#include <vector>
#include <string.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime> //Para manejar tiempo
#define MAX 90000
//Estructura de datos ll
//Primera practica
//Miembros:
//Angel Liu Sanchez
//Barragan Gonzalez Carlos Ivan
//Diego Rafael Maldonado Mendoza

using namespace std;
using std::stoi;//libreria para poder usar la funcion stoi
string aux, aux2;

struct Menu
{ //estructura de menu, el cual llevara los campos de menu.
    int indice;
    char codigo[7];
    char especialidad[18];
    char nombre[25];
    char descripcion[180];
    char precio[9];

    void Ingresar();//funcion para ingresar datos en el archivo
    void Ordenamiento();//funcion para ordenar el indice
    void Buscar();//funcion para buscar
}me;

struct stIndicecodi
{ //estructura de indice, el cual llevara la llave primaria (codigo) y el nnr (indice).
    char codigo[7];
    int indice = 0;
}in;


string Rellenar(string dato, int t)
{ //funcion para rellenar espacios
    aux = "";
    aux2 = ""; //aux3 = "";
    for(int i=0; i < t; i++)
    { //ponemos en bucle el array
        if(i<dato.length())
        { // sacamos el tamaï¿½o de los datos
            aux.insert(i, dato.substr(i,1));//en un auxiliar mandamos lo que esta existente en el array para no perder el dato
        }
        else
        {
            aux.insert(i, " ");//rellena con espacios el resto de bits disponibles.
        }
    }
    return aux;// retorna el auxiliar con los espacios utilisados
    dato="";
    t=0;
}

void Menu::Ingresar()
{ //funcion para ingresar datos
    //indice method
    // indice+=1;
    string texto;
    int j=0;

    ifstream archivo;//abrirmos el archivo en modo lectura
    archivo.open("MENU.txt",std::ios::app);
    while(!archivo.eof())
    {
        getline(archivo,texto);
        j+=1;
    }
    archivo.close();//ceramos el archivo
    indice=j;//pasamos j a indice
    std::ofstream archivomenu;//abrimos el archivo en modo escritura
    archivomenu.open("MENU.txt",std::ios::app); //Abriendo y creando archivo
    archivomenu << indice << "|";//se escribe el indice
    char random[10]= {'0','1','2','3','4','5','6','7','8','9'};//cadena de numeros a tomar aleatoreamente para la llave canonica
    fflush(stdin);
    //Forma Canonica
    //Dos bits [0:1]
    srand ( time(NULL) ); // Tomar time como referencia para generar diferente NRG
    codigo[0] = random[rand()%10];//tomamos el cero byte del codigo y le aplicamos rand con nuestra cadeba ya hecha
    codigo[1] = random[rand()%10];//tomamos el primero byte del codigo y le aplicamos rand con nuestra cadena ya hecha
    //Dos bits [1:2|3]
    cout << "\tDame el nombre de la especialidad: " << endl;
    cin.getline(especialidad,18);//entra el nombre de la especialidad
    int i;
    for(i=0; i<=strlen(especialidad); i++)
    { // pone en mayusculas la especialidad
        if(especialidad[i]>=97 && especialidad[i]<=122)
        {
            especialidad[i]=especialidad[i]-32;
        }
    }
    aux2 = Rellenar(especialidad,18);//rellena con espacios, los espacios vacios
    strcpy(especialidad,aux2.c_str());//aux2 se escribe en especialidad
    archivomenu << especialidad << "|";// especialidad se escibe al archivo "MENU.txt"
    fflush(stdin); /////////////////
    if (aux2 == "PICAR Y COMPARTIR ")
    {//if para seguir la forma canonica
        codigo[2]=especialidad[0];//tomamos el cero byte de especialidad y lo insertamos en el codigo en el byte 2
        codigo[3]=especialidad[1];//tomamos el primer byte de especialidad y lo insertamos en el codigo en el byte 3
        fflush(stdin);
        memset(especialidad, 0, 18);//limpia para no unirlo con basura
        cout << "\tDame el nombre: " << endl;
        cin.getline(nombre,25);//recibe el nombre
        int i;
        for(i=0; i<=strlen(nombre); i++)
        { //pone en mayusculas el nombre
            if(nombre[i]>=97 && nombre[i]<=122)
            {
                nombre[i]=nombre[i]-32;
            }
        }
        aux2 = Rellenar(nombre,25);//rellena con espacios, los espacios vacios en nombre
        strcpy(nombre,aux2.c_str());//aux2 se escribe en nombre
        archivomenu << nombre << "|";//nombre se escribe en el archivo "MENU.txt"
        codigo[4] = nombre[0];//codigo toma el 4 bit de codigo y le asigna el primer bit de nombre siguiendo la forma canonica
        codigo[5] = nombre[1];//codigo toma el 5 bit de codigo y le asigna el segundo bit de nombre siguiendo la forma canonica
        codigo[6] = nombre[2];//codigo toma el 6 bit de codigo y le asigna el tercero bit de nombre siguiendo la forma canonica
        memset(nombre, 0, 25);//limpia para no unirlo con la basura
    }
    else
    {
        codigo[2]=especialidad[0];//codigo toma el 0 bit de especialida y le asigna el segundo bit siguiendo la forma canonica
        fflush(stdin);
        memset(especialidad, 0, 18);//limpia para no unirlo con basura
        cout << "\tDame el nombre: " << endl;
        cin.getline(nombre,25);//recibe el nombre
        int i;
        for(i=0; i<=strlen(nombre); i++)
        { //pone en mayusculas el nombre
            if(nombre[i]>=97 && nombre[i]<=122)
            {
                nombre[i]=nombre[i]-32;
            }
        }
        aux2 = Rellenar(nombre,25);//rellena con espacios, los espcacios vacios en nombre
        strcpy(nombre,aux2.c_str());// aux2 se escribe en nombre
        archivomenu << nombre << "|";//nombre se escribe en el archvo "MENU.txt"
        fflush(stdin); ///////
        codigo[3] = nombre[0];//codigo toma el 3 bit de codigo y le asigna el primer bit de nombre siguiendo la forma canonica
        codigo[4] = nombre[1];//codigo toma el 4 bit de codigo y le asigna el segundo bit de nombre siguiendo la forma canonica
        codigo[5] = nombre[2];//codigo toma el 5 bit de codigo y le asigna el tercero bit de nombre siguiendo la forma canonica
        memset(nombre, 0, 25);//limpia nombre para no unirlo con basura
    }
    fflush(stdin);
    cout << "\tDame la descripcion: " << endl;
    cin.getline(descripcion,180);//recibe descripcion
    for(i=0; i<=strlen(descripcion); i++)
    { //pone en mayusculas la descripcion
        if(descripcion[i]>=97 && descripcion[i]<=122)
        {
            descripcion[i]=descripcion[i]-32;
        }
    }
    aux2 = Rellenar(descripcion,180);//rellena de espacios, los espacios vacios de la descripcion
    strcpy(descripcion,aux2.c_str());//aux2 se escribe en descripcion
    archivomenu << descripcion << "|";//escribe el campo descripcion en el archivo "MENU,txt"
    aux2 = Rellenar(codigo,7);//rellena de espacios vacios codigo
    strcpy(codigo,aux2.c_str());//aux2 se escribe en codigo
    archivomenu << codigo << "|"; // escribe el codigo con la forma canonica descripcion en el archivo "MENU,txt"
    fflush(stdin); /////////////////////////
    memset(descripcion, 0, 180);
    //precio
    cout << "\tDame el precio: " << endl;
    cin.getline(precio,9);//recibe precio
    aux2 = Rellenar(precio,9);//rellena de espacios vacios precio
    strcpy(precio,aux2.c_str());//aux2 se escribe en precio
    archivomenu << precio << "|" << endl;//escribe el precio con la forma canonica descripcion en el archivo "MENU,txt"
    // cout<<"\nCodigo: "<< codigo << "|" << endl;//imprime el codigo
    fflush(stdin);
    archivomenu.close();//se cierra el archivo

    std::ofstream archivoindice;// se abre el archivo "INDICE.TXT" en modo escritura
    archivoindice.open("INDICE.txt",std::ios::app);
    in.indice=indice;//se mete indice en el indice del archivo "INIDICE.TXT" el cual va a ser el nrr
    strcpy(in.codigo,codigo);//se mete codigo a codgio del archivo "INDICE.TXT"
    archivoindice << in.codigo << "|"; //escribe codigo en el archivo "INDICE.TXT"
    archivoindice << in.indice << endl; //escribe indice o en este caso el nrr en el archivo "INDICE.TXT"
    archivoindice.close();// se cierrra el nrr

    memset(codigo, 0, 7);//se limpia el codigo para que no lo una con basura
    memset(descripcion, 0, 180);
    memset(nombre, 0, 25);
    memset(especialidad, 0, 18);//se limpian todos los datos para que no los una con basura
    }

void Menu::Ordenamiento()
{ //funcion que ordena el indice
    int i=0, r, j;
    string aux1;
    vector <string> v (MAX);
    ifstream archivo1 ("INDICE.txt");//se abre el archivo en modo de lectura
    if (archivo1.fail()) cout<<"El archivo no se abrio correctamente."<<endl;//en caso de el archivo no se abrio correctamente
    while (getline(archivo1, v[i]))
    { //Guardamos las lineas en vector
        // cout << v[i] << endl;
        i++;
    }
    archivo1.close();
    //Ordenamiento de Codigo
    for(int i=0; i<indice-1; i++)
    { //forma de ordenamiento de bubblesort
        for(int j=i+1; j<indice; j++)
        {
            if(v[i]>v[j])
            {
                aux1 = v[j];
                v[j] = v[i];
                v[i] = aux1;
            }
        }
    }
    // std::cout << "\nORDENADA: " << '\n';
    //Impresion de Ordenamiento
    std::ofstream archivo2;// se abre el archivo en escritura
    archivo2.open("INDICE.txt",std::ios::ate); // Abrir archivo en modo ios:ate para sobreescribir
    for (int i= 0 ; i < indice ; i++)
    {
        archivo2 << v[i] << endl;
    }
    archivo2.close();//se cierra el archivo

    // std::cout << "Funcion Ordenamiento" << '\n';
    // sleep (1);
}

void Menu::Buscar()
{ //funcion para buscar y recuperar el dato
    int i=0, r, j, size, ia=-1;
    string aux1, aux2;
    std::cout << "Dame el codigo a buscar: " << '\n';
    std::cin >> aux1;
    size=aux1.size();//saca el tamaño de aux1
    std::transform(aux1.begin(), aux1.end(), aux1.begin(), ::toupper);//pone todo en mayusculas
    vector <string> v (MAX);
    ifstream archivo1 ("INDICE.txt");//abre el archivo en modo lectura
    if (archivo1.fail()) cout<<"El archivo no se abrio correctamente."<<endl;// ver si el archivo falla
    while (getline(archivo1, v[i]))
    { //Guardamos las lineas en vector
        i++;
    }
    for (size_t j = 0; j < i; j++)
    {// for para comparar codigos
        if(v[j].substr(0,size) == aux1)
        {//compara el codigo con el auxiliar1
            ia = std::stoi(v[j].substr(8,2));//convierte a entero
        }
    }
    if (ia == -1)
    {
        std::cout << "No hay match :C" << '\n';// condicional por si no hay registro
    }
    else
    {
        i=0;
        vector <string> recuperarNRR (MAX);
        ifstream archi ("MENU.txt");//abre el archivo en forma de lectura
        if (archi.fail()) cout<<"El archivo no se abrio correctamente."<<endl;
        while (getline(archi, recuperarNRR[i]))
        { //Guardamos las lineas en vector
            i++;
        }
        archi.close();//cerrarmos el archivo
        std::cout << recuperarNRR[ia-1] << '\n';//mostramos a pantalla el registro buscado
    }
    archivo1.close();//ceramos el archivo
}

int main() {// Menu del programa
    int opc;

    do {
        // system("clear");
        cout << "\t\t\t -->|BIENVENIDO A TELEPIZZA|<-- \n\n";
        cout << "    Selecciona una de la siguientes opciones:\n\n";
        cout << "\t(1).-Insertar registro\n" << "\t(2).-Mostrar un registro por su Codigo\n" << "\t(3).-Salir\n\n" << "-->";
        cin >> opc;
        switch(opc)
        { //switch para entrar en cada uno de los casos del menu
            case 1:
                {
                    // std::cout << "Opcion 1" << '\n';
                    // sleep (1);
                    me.Ingresar();//manda a llamar la funcion ingresar
                    me.Ordenamiento();//manda a llamar la funcion ordenamiento
                    break;
                }
            case 2:
                {
                    // std::cout << "Opcion 2" << '\n';
                    me.Buscar();//manda a llamar la funcion de buscar
                    // sleep (1);
                    break;
                }
        }
    }
    while(opc != 3);
    return 0;
    }
