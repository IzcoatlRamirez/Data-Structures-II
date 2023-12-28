//
// Created by user on 07/10/2022.
//

#ifndef CIUDAD_H
#define CIUDAD_H
#include <iostream>
using namespace std;
class Ciudad
{
public:
    //constructor ciudad
    Ciudad(const string& name,const string &estado,const string&pais):nombre(name),estado(estado),pais(pais){}

    string getNombre()const;
    void setNombre(const string &value);

    string getEstado()const;
    void setEstado(const string &value);

    string getPais()const;
    void setPais(const string &value);

    friend ostream & operator << (ostream& os, const Ciudad& obj);
    friend istream & operator >> (istream& is, const Ciudad& obj);
    bool operator == (const Ciudad & obj) const;


private:
    string nombre;
    string estado;
    string pais;

};
string Ciudad::getNombre() const
{
    return nombre;
}

void Ciudad::setNombre(const std::string &value)
{
    nombre=value;
}

string Ciudad::getEstado() const
{
    return estado;
}

void Ciudad::setEstado(const std::string &value)
{
    estado=value;
}

string Ciudad::getPais() const
{
    return pais;
}

void Ciudad::setPais(const std::string &value)
{
    pais=value;
}

ostream& operator << (ostream & os, Ciudad & obj)
{
    os<<obj.getNombre()<<"|"<<obj.getEstado()<<"|"<<obj.getPais();
    return os;
}

istream& operator >> (istream& is, Ciudad & obj)
{
    string aux;
    getline(is,aux,'|');
    if(aux.size()>0)
    {
        obj.setNombre(aux);
        getline(is,aux,'|');
        obj.setEstado(aux);
        getline(is,aux);
        obj.setPais(aux);
    }
    return is;
}

bool Ciudad::operator==(const Ciudad &obj) const
{
    return nombre==obj.nombre;
}


#endif //CIUDAD_H
