#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>

using namespace std;

class Producto
{
public:
    Producto();

    string getNombre() const;
    void setNombre(const string &value);

    int getExistencia() const;
    void setExistencia(int value);

    float getPrecio() const;
    void setPrecio(float value);

    // Permite escribir al archivo
    friend ostream& operator << (ostream& os, const Producto& obj);
    // Permite leer del archivo
    friend istream& operator >> (istream& is, Producto& obj);
    //permite comparar
    bool operator < (const Producto& obj) const;
    bool operator > (const Producto& obj) const;
    bool operator == (const Producto& obj) const;

private:
    string nombre;
    int existencia;
    float precio;
};

#endif // PRODUCTO_H