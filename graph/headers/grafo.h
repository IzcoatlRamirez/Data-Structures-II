//
// Created by user on 07/10/2022.
//
#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include "lsl.h"

using namespace std;

template<typename T>
struct NodeG
{
    T data;
    LSL<T> l_arista;
    NodeG(const T& elem):data(elem){}
    //sobrecarga
    friend ostream &operator <<(ostream & os, NodeG<T> & obj)
    {
        os<<obj.data;
        for(int i(0);i<obj.l_arista.size();++i)
        {
            os<<"-"<<obj.l_arista[i];
        }
        os<<endl;
        return os;
    }


    friend istream& operator >> (istream& is, NodeG<T>& obj)
    {
        string aux;
        getline(is,aux,'|');
        if(aux.size()>0)
        {
            obj.data.setNombre(aux);
            getline(is,aux,'|');
            obj.data.setEstado(aux);
            getline(is,aux);
            obj.data.setPais(aux);
        }

        return is;
    }

};

template<typename T>
class Grafo
{
private:

public:

    LSL<NodeG<T>> graph;
    void insertarVertice(const NodeG<T> & elem);
    void eliminarVertice(const string &nombre);
    void insertarArista(const string& origen,const string& destino);
    void eliminarArista(const string& origen,const string& destino);
    int buscarNodeG(const string & elem);
    int buscarNodeGenArista(const string & elem, size_t nodo);
    void mostrar();

};

template<typename T>
void Grafo<T>::insertarVertice(const NodeG<T> & elem)
{
    graph.push_back(elem);
}

template<typename T>
void Grafo<T>::eliminarVertice(const string &elem)
{
    int posicion= buscarNodeG(elem);
    if(posicion!=-1)
    {
        graph.erase(posicion);
        cout<<"Eliminado con éxito."<<endl;
    }
    else
    {
        cout<<"No se encontro el vertice."<<endl;
    }

}

template<typename T>
void Grafo<T>::eliminarArista(const std::string &origen, const std::string &destino)
{
    if(graph.empty())
    {
        cout<<"Aún no hay nodos."<<endl;
    }
    else
    {
        int org= buscarNodeG(origen);
        if(org!=-1)
        {
            int des= buscarNodeGenArista(destino,org);
            if(des!=-1)
            {
                //elimina de l_arista del nodo origen el dato del nodo destino
                graph[org].l_arista.erase(des);
            }
            else
            {
                cout<<"No se encontro el destino."<<endl;
            }
        }
        else
        {
            cout<<"No se encontro el origen."<<endl;
        }
    }
}

template<typename T>
int Grafo<T>::buscarNodeG(const std::string &elem)
{

    T t(elem," "," ");
    NodeG<T> temp(t); //se crea un nodo temporal con elem para poder realizar la busqueda
    bool encontrado= false;
    int i=0;
    while(i<graph.size()&&(encontrado==false))
    {
        if(temp.data==graph[i].data)
        {
            encontrado= true;
            return i;
        }
        ++i;
    }
    return -1;
}
template<typename T>
int Grafo<T>::buscarNodeGenArista(const std::string &elem, size_t nodoOrigen)
{

    T t(elem," "," ");
    NodeG<T> temp(t); //se crea un nodo temporal con elem para poder realizar la busqueda
    bool encontrado= false;
    int i=0;
    while(i<graph[nodoOrigen].l_arista.size()&&(encontrado==false)) //busqueda dentro de la lista de aristas
    {
        if(temp.data==graph[nodoOrigen].l_arista[i])
        {
            encontrado= true;
            return i;
        }
        ++i;
    }
    return -1;
}





template<typename T>
void Grafo<T>::insertarArista(const string &origen,const string &destino)
{
    if(graph.empty())
    {
        cout<<"Aún no hay nodos."<<endl;
    }
    else
    {
        int org= buscarNodeG(origen);
        if(org!=-1)
        {
            int des= buscarNodeG(destino);
            if(des!=-1)
            {
                //añade a l_arista del nodo origen el dato del nodo destino
                graph[org].l_arista.push_back(graph[des].data);
            }
            else
            {
                cout<<"No se encontro el destino."<<endl;
            }
        }
        else
        {
            cout<<"No se encontro el origen."<<endl;
        }
    }

}

template<typename T>
void Grafo<T>::mostrar()
{
    cout<<"Formato:"<<endl
    <<"Nodo - "<<"Aristas adyacentes"<<endl;
    for(int i(0);i<graph.size();++i)
    {
        cout<<graph[i];
    }
}

#endif // GRAFO_H
