//
// Created by user on 28/10/2022.
//
#ifndef TH_H
#define TH_H
#include "lsl.h"

template<typename T>
struct Bucket{
    T data;
    LSL<T> sublist;
    Bucket(const T& elem):data(elem){}
    Bucket(){}

    friend ostream &operator <<(ostream & os, Bucket<T> & obj)
    {
        os<<obj.data;
        for(int i(0);i<obj.sublist.size();++i)
        {
            os<<"-"<<obj.sublist[i];
        }
        os<<endl;
        return os;
    }

    friend istream& operator >> (istream& is, Bucket<T>& obj)
    {
        string aux;
        getline(is,aux,'|');
        if(aux.size()>0)
        {
            obj.data.setNombre(aux);
            getline(is,aux,'|');
            obj.data.setGenero(aux);
            getline(is,aux,'-');
            obj.data.setDuracion(stoi(aux));
            for(int i(0);i<obj.sublist.size();++i)
            {
                getline(is,aux,'|');
                obj.sublist[i].setNombre(aux);
                getline(is,aux,'|');
                obj.sublist[i].setGenero(aux);
                getline(is,aux,'-');
                obj.sublist[i].setDuracion(stoi(aux));
            }
        }
        return is;
    }

};


template<typename T>
class TablaHash
{
public:
    const int capacity=99;
    //nos ayudara a saber si un bucket ya esta ocupado para manejo de colisiones
    bool isBucketEmpty(const int &value);
    //buscara un bucket en especifico
    void searchBucket(const string &value,const size_t &position);
    //generara a través del nombre del objeto un indice para insertar en la tabla
    int hash(const string &value);
    //insertara el dato recibido en el arreglo de buckets
    void insertar(const Bucket<T> elem);
    //eliminara el dato por indice dado por funcion hash
    void eliminarIndice(const string &value);
    //consultara elemento buscado
    void consultar(const string &value);


    Bucket<T> table[99];

private:

};

template<typename T>
int TablaHash<T>::hash(const std::string &value)
{
    int index=0;
    for(int i(0);i<value.size();++i)
    {
        int aux= int(value[i]);
        index+=aux;
    }
    if (index<700)
    {
        return index%10;
    }
    return index%100;
}

template<typename T>
bool TablaHash<T>::isBucketEmpty(const int &value)
{
    T t("","",0);
    Bucket<T> aux(t);
    if(table[value].data ==aux.data)
    {
        return true;
    }
    return false;
}


template<typename T>
void TablaHash<T>::insertar(const Bucket<T> elem)
{
    int index= hash(elem.data.getNombre());
    if(isBucketEmpty(index))
    {
        table[index]=elem;
        cout<<"Insertado con exito."<<endl;
    }
    else
    {
        //en caso de colision lo agrega a la sublista del indice
        table[index].sublist.push_back(elem.data);
        cout<<"Insertado con exito."<<endl;
    }
}

template<typename T>
void TablaHash<T>::consultar(const std::string &value)
{
    int index= hash(value);
    searchBucket(value,index);
}

template<typename T>
void TablaHash<T>::searchBucket(const string &value,const size_t &position) {
    T t(value, "", 0);
    Bucket<T> temp(t);
    //si el nombre es igual, encontramos nuestro valor con acceso directo
    if (temp.data == table[position].data)
    {
        cout << table[position].data<<endl;
        return;
    }
    //si no ,buscamos en sublista
    for(int i(0);i<table[position].sublist.size();++i)
    {
        if(temp.data==table[position].sublist[i])
        {
            cout<<table[position].sublist[i]<<endl;
            return;
        }
    }
    cout<<"No encontrado."<<endl;
}

template<typename T>
void TablaHash<T>::eliminarIndice(const string&value)
{
    int index=hash(value);
    T t(value,"",0);
    Bucket<T> temp(t);
   if(temp.data==table[index].data)
   {
       cout<<table[index].data;
       T t;
       table[index].data=t;
       cout<<"Eliminado con exito."<<endl;
       return;
   }
   for(int i(0);i<table[index].sublist.size();++i)
   {
       cout<<table[index].sublist[i];
       if(temp.data==table[index].sublist[i])
       {
           table[index].sublist.erase(i);
           cout<<"Eliminado con exito."<<endl;
           return;
       }
   }
   cout<<"No encontrado."<<endl;
}

#endif //PROG04_RAMIREZ_CORTES_IZCOATL_TH_H
