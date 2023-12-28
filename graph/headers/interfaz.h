//
// Created by user on 07/10/2022.
//

#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include "grafo.h"
#include "ciudad.h"
#include <fstream>
using namespace std;
class Interfaz
{
public:
    void menu();
    void insertarVertice();
    void eliminarVertice();
    void insertarArista();
    void eliminarArista();
    void guardar();
    void cargar();

private:
    enum
    {
        OPC_INS_VERTEX=1,
        OPC_INS_ARISTA,
        OPC_ELIM_VERTEX,
        OPC_ELIM_ARISTA,
        OPC_RECORRER,
        OPC_GUARDAR,
        OPC_CARGAR,
        OPC_SALIR

    };
    Grafo<Ciudad> g;

};

void Interfaz::menu()
{
    int opc;
    do
    {
        cout<<"   Menu         "<<endl
            <<"[1] Insertar vertice."<<endl
            <<"[2] Insertar arista."<<endl
            <<"[3] Eliminar vertice."<<endl
            <<"[4] Eliminar arista."<<endl
            <<"[5] Recorrer Grafo."<<endl
            <<"[6] Guardar Grafo."<<endl
            <<"[7] Cargar Grafo."<<endl
            <<"[8] Salir."<<endl
            <<"    opcion: "<<endl;
        cin>>opc;
        cin.ignore();
        switch (opc)
        {
            case OPC_INS_VERTEX: insertarVertice();
                break;
            case OPC_INS_ARISTA: insertarArista();
                break;
            case OPC_ELIM_VERTEX: eliminarVertice();
                break;
            case OPC_ELIM_ARISTA: eliminarArista();
                break;
            case OPC_RECORRER: g.mostrar();
                break;
            case OPC_GUARDAR: guardar();
                break;
            case OPC_CARGAR: cargar();
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


void Interfaz::insertarVertice()
{
    string nombre,estado,pais;
    cout<<"--Insertar Vertice--"<<endl
    <<"Nombre de la ciudad: "<<endl;
    getline(cin,nombre);
    cout<<"Nombre del estado: "<<endl;
    getline(cin, estado);
    cout<<"Nombre del pais: "<<endl;
    getline(cin,pais);

    Ciudad c(nombre,estado,pais);
    NodeG<Ciudad> temp(c);

    g.insertarVertice(temp);
}

void Interfaz::eliminarVertice()
{
    string nombre;
    cout<<"--Eliminar vertice--"<<endl
    <<"Nombre de la ciudad: "<<endl;
    getline(cin,nombre);
    g.eliminarVertice(nombre);

}

void Interfaz::eliminarArista()
{
    string origen,destino;
    cout<<"--Eliminar Arista--"<<endl
    <<"Nombre del origen: "<<endl;
    getline(cin,origen);
    cout<<"Nombre del destino: "<<endl;
    getline(cin,destino);
    g.eliminarArista(origen,destino);

}

void Interfaz::insertarArista()
{
    string origen,destino;
    cout<<"--Insertar Arista--"<<endl
    <<"Nombre del origen: "<<endl;
    getline(cin,origen);
    cout<<"Nombre del destino: "<<endl;
    getline(cin,destino);
    g.insertarArista(origen,destino);

}


void Interfaz::guardar()
{
    cout<<"--Guardando Grafo--"<<endl;
    fstream archivo;
    archivo.open("file01.txt",ios::app);
    if(!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        for (int i(0);i<g.graph.size();++i)
        {
            archivo<<g.graph[i];
        }
        archivo.close();
        cout<<"Grafo guardado con éxito"<<endl;
    }
}

void Interfaz::cargar ()
{
    cout<<"--Cargando Grafo--"<<endl;
    fstream archivo;
    archivo.open("file01.txt",ios::in);
    if(!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        Ciudad c("","","");
        NodeG<Ciudad> p(c);
        while(archivo>>p)
        {
            g.graph.push_back(p);
        }
        archivo.close();
        cout<<"Productos cargados con éxito."<<endl;
    }

}


#endif //INTERFAZ_H
