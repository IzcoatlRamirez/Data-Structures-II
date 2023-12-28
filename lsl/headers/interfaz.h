#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "lsl.h"
#include "producto.h"
#include <iostream>
#include <fstream>
using namespace std;

class Interfaz
{
public:
    void agregarFinal();
    void agregarFrente();
    void datoFrente();
    void datoAtras();
    void agregarEnPosicion();
    void eliminarEnPosicion();
    void mostrarTodo();
    void cargar();
    void guardar();
    void menu();


private:
    LSL <Producto> lista;
    enum opcInterfaz
    {
    OPC_ADD_BACK=1,
    OPC_ADD_FRONT,
    OPC_FRONT,
    OPC_BACK,
    OPC_INSERT,
    OPC_ERASE,
    OPC_MOSTRAR,
    OPC_CARGAR,
    OPC_GUARDAR,
    OPC_SALIR,
    };
};

#endif // HORARIO_H