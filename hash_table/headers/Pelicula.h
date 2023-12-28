//
// Created by user on 28/10/2022.
//

#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
using namespace std;
class Pelicula
{
public:
    Pelicula();
    Pelicula(const string& n,const string &g,const int &d):nombre(n),genero(g),duracion(d){}
    string getNombre()const;
    void setNombre(const string &value);
    string getGenero()const;
    void setGenero(const string &value);
    int getDuracion() const;
    void setDuracion(const int &value);
    bool operator == (const Pelicula & obj) const;
    bool operator != (const Pelicula & obj) const;
    friend ostream & operator << (ostream& os, const Pelicula& obj);
    friend istream & operator >> (istream& is, const Pelicula& obj);

private:
    string nombre;
    string genero;
    int duracion;

};

string Pelicula::getNombre() const
{
    return nombre;
}

void Pelicula::setNombre(const std::string &value)
{
    nombre=value;
}

string Pelicula::getGenero() const
{
    return genero;
}

void Pelicula::setGenero(const std::string &value)
{
    genero=value;
}

int Pelicula::getDuracion() const
{
    return duracion;
}

void Pelicula::setDuracion(const int &value)
{
    duracion=value;
}
bool Pelicula::operator==(const Pelicula &obj) const
{
    return nombre==obj.nombre;
}
bool Pelicula::operator!=(const Pelicula &obj) const
{
    return nombre!=obj.nombre;
}

Pelicula::Pelicula()
{
nombre="";
genero="";
duracion=0;
}

ostream& operator << (ostream & os, Pelicula & obj)
{
    os<<obj.getNombre()<<"|"<<obj.getGenero()<<"|"<<obj.getDuracion();
    return os;
}

istream& operator >> (istream& is, Pelicula & obj)
{
    string aux;
    getline(is,aux,'|');
    if(aux.size()>0)
    {
        obj.setNombre(aux);
        getline(is,aux,'|');
        obj.setGenero(aux);
        getline(is,aux);
        obj.setDuracion(stoi(aux));
    }
    return is;
}




#endif //PELICULA_H
