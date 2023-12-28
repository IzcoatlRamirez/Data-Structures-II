#include "..\headers\interfaz.h"

void Interfaz::agregarFinal()
{
    Producto p;
    string nombre;
    int existencia;
    float precio;
    cout<<"Ingrese el nombre del producto:"<<endl;
    getline(cin,nombre);
    cout<<"Existencia en sucursal:"<<endl;
    cin>>existencia;
    if(existencia<=0)
    {
        cout<<"Existencia invalida."<<endl;
    }
    else
    {
        cout<<"Precio del producto:"<<endl;
        cin>>precio;
        if(precio<=0)
        {
            cout<<"Precio invalido."<<endl;
        }
        else
        {
            p.setNombre(nombre);
            p.setExistencia(existencia);
            p.setPrecio(precio);
            lista.push_back(p);
        }
    }


}

void Interfaz::agregarFrente()
{
    Producto p;
    string nombre;
    int existencia;
    float precio;
    cout<<"Ingrese el nombre del producto:"<<endl;
    getline(cin,nombre);
    cout<<"Existencia en sucursal:"<<endl;
    cin>>existencia;
    if(existencia<=0)
    {
        cout<<"Existencia invalida."<<endl;
    }
    else
    {
        cout<<"Precio del producto:"<<endl;
        cin>>precio;
        if(precio<=0)
        {
            cout<<"Precio invalido."<<endl;
        }
        else
        {
            p.setNombre(nombre);
            p.setExistencia(existencia);
            p.setPrecio(precio);
            lista.push_front(p);
        }
    }
}

void Interfaz::datoFrente()
{
    if(lista.empty())
    {
        cout<<"La lista esta vacia."<<endl;
    }
    else
    {
        cout<<lista.front()<<endl;
    }
}

void Interfaz::datoAtras()
{
    if(lista.empty())
    {
        cout << "La lista esta vacia." << endl;
    }
    else
    {
        cout<<lista.back()<<endl;
    }
}

void Interfaz::agregarEnPosicion()
{
    Producto p;
    string nombre;
    int existencia;
    float precio;
    size_t posicion;
    cout<<"Ingrese el nombre del producto:"<<endl;
    getline(cin,nombre);
    cout<<"Existencia en sucursal:"<<endl;
    cin>>existencia;
    if(existencia<=0)
    {
        cout<<"Existencia invalida."<<endl;
    }
    else
    {
        cout<<"Precio del producto:"<<endl;
        cin>>precio;
        if(precio<=0)
        {
            cout<<"Precio invalido."<<endl;
        }
        else
        {
            cout<<"Posicion:"<<endl;
            cin>>posicion;
            if (posicion<0)
            {
                cout<<"Invalido."<<endl;
            }
            else
            {
                p.setNombre(nombre);
                p.setExistencia(existencia);
                p.setPrecio(precio);
                lista.insert(posicion,p);
            }

        }
    }


}

void Interfaz::eliminarEnPosicion()
{
    size_t posicion;
    cout<<"Posicion:"<<endl;
    cin>>posicion;
    if(lista.empty())
    {
        cout<<"La lista esta vacia."<<endl;
    }
    if(posicion>=lista.size())
    {
        cout<<"Posicion invalida."<<endl;
    }
    else
    {
        lista.erase(posicion);
    }
}

void Interfaz::mostrarTodo()
{
    if (lista.empty())
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout<<"Productos en inventario:"<<endl;
        for(int i(0);i<lista.size();++i)
        {
            cout<<lista[i]<<endl;
        }
    }
}

void Interfaz::cargar()
{
    cout<<"--Cargando productos--"<<endl;
    fstream archivo;
    archivo.open("file01.txt",ios::in);
    if(!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        Producto p;
        while(archivo>>p)
        {
            lista.push_back(p);
        }
        archivo.close();
        cout<<"Productos cargados con éxito."<<endl;
    }
}

void Interfaz::guardar()
{
    cout<<"--Guardando productos en txt--"<<endl;
    fstream archivo;
    archivo.open("file01.txt",ios::app);
    if(!archivo.is_open())
    {
        cout<<"Error al abrir el archivo."<<endl;
    }
    else
    {
        for(size_t i(0);i<lista.size();i++)
        {
            archivo<<lista[i];
        }
        archivo.close();

        cout<<"Guardado con éxito."<<endl;
    }

}



void Interfaz::menu()
{
int opc;
do
{
    cout<<"   Menu         "<<endl
    <<"[1] Agregar al final."<<endl
    <<"[2] Agregar al inicio."<<endl
    <<"[3] Dato de el frente."<<endl
    <<"[4] Dato de atras."<<endl
    <<"[5] Agregar en posicion."<<endl
    <<"[6] Eliminar en posicion."<<endl
    <<"[7] Mostrar lista."<<endl
    <<"[8] Cargar archivo."<<endl
    <<"[9] Guardar archivo."<<endl
    <<"[10] Salir."
    <<"   opcion: "<<endl;
    cin>>opc;
    cin.ignore();
    switch (opc)
    {
    case OPC_ADD_BACK: agregarFinal();
    break;

    case OPC_ADD_FRONT: agregarFrente();
    break;

    case OPC_FRONT: datoFrente();
    break;

    case OPC_BACK: datoAtras();
    break;

    case OPC_INSERT: agregarEnPosicion();
    break;

    case OPC_ERASE: eliminarEnPosicion();
    break;

    case OPC_MOSTRAR: mostrarTodo();
    break;

    case OPC_CARGAR: cargar();
    break;

    case OPC_GUARDAR: guardar();
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