//
// Created by user on 07/10/2022.
//

#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include "TH.h"
#include "Pelicula.h"
#include <fstream>
using namespace std;
class Interfaz
{
public:

    void menu();
    void insertar();
    void eliminar();
    void consultar();
    void guardar();
    void cargar();

private:
    enum
    {
        OPC_INS=1,
        OPC_ELI,
        OPC_CONS,
        OPC_GUARDAR,
        OPC_CARGAR,
        OPC_SALIR
    };
    TablaHash<Pelicula> t;
};

void Interfaz::menu()
{
    int opc;
    do
    {
        cout<<"   Menu         "<<endl
            <<"[1] Insertar ."<<endl
            <<"[2] Eliminar."<<endl
            <<"[3] Consultar."<<endl
            <<"[4] Guardar."<<endl
            <<"[5] Cargar."<<endl
            <<"[6] Salir."<<endl
            <<"    opcion: "<<endl;
        cin>>opc;
        cin.ignore();
        switch (opc)
        {
            case OPC_INS: insertar();
                break;
            case OPC_CONS: consultar();
                break;
            case OPC_ELI: eliminar();
                break;
            case OPC_GUARDAR: guardar();
                break;
            case OPC_CARGAR:   cargar();
                break;
            case OPC_SALIR:
                cout<<"Saliendo de la aplicación."<<endl;
                break;
            default:
                cout <<"Opción no válida" <<endl;
                break;
        }

    } while (opc!=OPC_SALIR);
}

void Interfaz::insertar()
{
    string nombre,genero;
    int duracion;
    cout<<"--Insertar elemento--"<<endl
        <<"Nombre de la pelicula: "<<endl;
    getline(cin,nombre);
    cout<<"Genero: "<<endl;
    getline(cin, genero);
    cout<<"Duracion: "<<endl;
    cin>>duracion;

    Pelicula p(nombre,genero,duracion);
    Bucket<Pelicula> temp(p);
    t.insertar(temp.data);

}

void Interfaz::consultar()
{
    string nombre;
    cout<<"--Consultar elemento--"<<endl
    <<"nombre:"<<endl;
    getline(cin,nombre);
    t.consultar(nombre);

}

void Interfaz::eliminar()
{
    string nombre;
    cout<<"--Eliminar elemento--"<<endl
    <<"nombre:"<<endl;
    getline(cin,nombre);
    t.eliminarIndice(nombre);
}

void Interfaz::guardar()
{

    cout<<"--Guardando en archivo--"<<endl;
    fstream archivo;
    archivo.open("file01.txt",ios::app);
    if(!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        for (int i(0);i<t.capacity;++i)
        {
            //archivo.write((char *)&t.table[i].data, sizeof(Pelicula));
            if(!t.isBucketEmpty(i))
            {
                archivo<<t.table[i];
            }
        }
        archivo.close();
        cout<<"Archivo guardado con éxito"<<endl;
    }
}


void Interfaz::cargar()
{
    cout<<"--Cargando Archivo--"<<endl;
    fstream archivo;
    archivo.open("file01.txt",ios::in);
    if(!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        Bucket<Pelicula> b;
        while(archivo>>b)
        {
            t.insertar(b);
        }
        archivo.close();
        cout<<"Productos cargados con éxito."<<endl;
    }
}


#endif //interfaz.h