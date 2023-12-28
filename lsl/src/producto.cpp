#include "..\headers\producto.h"

Producto::Producto()
{
    nombre = "";
    existencia = 0;
    precio = 0.0;
}

string Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(const string &value)
{
    nombre = value;
}

int Producto::getExistencia() const
{
    return existencia;
}

void Producto::setExistencia(int value)
{
    existencia = value;
}

float Producto::getPrecio() const
{
    return precio;
}

void Producto::setPrecio(float value)
{
    precio = value;
}

ostream& operator << (ostream& os, const Producto& obj)
{
    os <<obj.getNombre() <<"|" <<obj.getExistencia() <<"|" <<obj.getPrecio() <<endl;
    return os;
}

istream& operator >> (istream& is, Producto& obj)
{
    string aux;
    getline(is, aux, '|');

    if (aux.size() > 0)
    {
        obj.setNombre(aux);
        getline(is, aux, '|');
        obj.setExistencia(stoi(aux)); //STOI : String TO Integer
        getline(is, aux);
        obj.setPrecio(stof(aux)); //STOF : String TO Float
    }
    return is;
}