#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "producto.h"
#include "..\headers\abb.h"
#include <iostream>
#include <fstream>
using namespace std;

class Interfaz
{
public:
   void menu();
   void cargar();
   void insertar();
   void encontrar();
   void eliminar();

private:
    ABB<Producto> tree;
    enum opcInterfaz
    {
    OPC_INSERTAR=1,
    OPC_ENCONTRAR,
    OPC_ELIMINAR,
    OPC_CARGAR,
    OPC_GUARDAR,
    OPC_PREORDER,
    OPC_INORDER,
    OPC_POSTORDER,
    OPC_SALIR,
    };
};

#endif // HORARIO_H