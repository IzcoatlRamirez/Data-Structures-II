#include "..\headers\interfaz.h"

void Interfaz::insertar()
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
            tree.insert(p);
        }
    }
}

void Interfaz::eliminar()
{
    Producto p;
    string nombre;
    cout<<"Ingrese el nombre del producto a eliminar:"<<endl;
    getline(cin,nombre);
    p.setNombre(nombre);
    if (tree.find(p))
    {
        tree.erase(p);
    }
    else
    {
        cout<<"Producto no encontrado"<<endl;
    }

}

void Interfaz::encontrar()
{
    Producto p;
    string nombre;
    cout<<"Ingrese el nombre del producto a buscar:"<<endl;
    getline(cin,nombre);
    p.setNombre(nombre);
    if (tree.find(p))
    {
        cout<<*tree.find(p);
    }
    else
    {
        cout<<"Producto no encontrado"<<endl;
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
                tree.insert(p);
            }
            archivo.close();
            cout<<"Productos cargados con éxito."<<endl;

        }
}



void Interfaz::menu()
{
int opc;
do
{
    cout<<"   Menu         "<<endl
    <<"[1] Insertar."<<endl
    <<"[2] Encontrar."<<endl
    <<"[3] Eliminar."<<endl
    <<"[4] Cargar."<<endl
    <<"[5] Guardar."<<endl
    <<"[6] PreOrder."<<endl
    <<"[7] InOrder."<<endl
    <<"[8] PostOrder."<<endl
    <<"[9] Salir."<<endl
    <<"    opcion: "<<endl;
    cin>>opc;
    cin.ignore();
    switch (opc)
    {
    case OPC_INSERTAR: insertar();
    break;

    case OPC_ENCONTRAR: encontrar();
    break;

    case OPC_ELIMINAR: eliminar();
    break;

    case OPC_CARGAR: cargar();
    break;

    case OPC_GUARDAR: tree.guardar();
    break;

    case OPC_PREORDER: tree.preOrder();
    break;

    case OPC_INORDER: tree.inOrder();
    break;

    case OPC_POSTORDER: tree.postOrder();
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