#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <stdexcept>
#include <memory>
#include <fstream>

using namespace std;

template<typename T>
struct NodeAB
{
    T data;
    shared_ptr<NodeAB> left;
    shared_ptr<NodeAB> right;

    NodeAB(const T& element, shared_ptr<NodeAB> l = nullptr,
           shared_ptr<NodeAB> r = nullptr) : data(element), left(l), right(r)
    {}
};

template<typename T>
class ArbolBinario
{
protected:
    shared_ptr<NodeAB<T>> root;
    // Constructor que genera un árbol a partir de un nodo raíz
    ArbolBinario(shared_ptr<NodeAB<T>> newRoot) : root(newRoot)
    {}

public:
    // Constructor que genera un árbol nulo
    ArbolBinario()
    {
        root = nullptr;
    }
    //Constructor que genera un árbol con raiz e hijos a partir de arboles ya creados.
    ArbolBinario(const T& element,
                 const ArbolBinario<T>& leftChild = ArbolBinario(),
                 const ArbolBinario<T>& rightChild = ArbolBinario())
    {
        root = make_shared<NodeAB<T>> (element, leftChild.root, rightChild.root);
    }
    bool isNull() const;
    bool isLeaf() const;
    ArbolBinario<T> getLeftChild() const;
    ArbolBinario<T> getRightChild() const;
    const T& getValue() const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    void guardar() const;


};

template<typename T>
bool ArbolBinario<T>::isNull() const
{
    return root == nullptr;
}

template<typename T>
bool ArbolBinario<T>::isLeaf() const
{
    return root == nullptr || (root->left == nullptr && root->right == nullptr);
}

template<typename T>
ArbolBinario<T> ArbolBinario<T>::getLeftChild() const
{
    if (isNull())
    {
        throw runtime_error("Trying getLeftChild() from an empty tree.");
    }
    return ArbolBinario(root->left);
}

template<typename T>
ArbolBinario<T> ArbolBinario<T>::getRightChild() const
{
    if (isNull())
    {
        throw runtime_error("Trying getRightChild() from an empty tree.");
    }
    return ArbolBinario(root->right);
}

template<typename T>
const T& ArbolBinario<T>::getValue() const
{
    if (isNull())
    {
        throw runtime_error("Trying getValue() from an empty tree.");
    }
    return root->data;
}

template<typename T>
void ArbolBinario<T>::preOrder() const
{
    if (isNull())
    {
        return;
    }
    cout <<root->data <<" ";
    getLeftChild().preOrder();
    getRightChild().preOrder();
}

template<typename T>
void ArbolBinario<T>::guardar() const
{   fstream archivo;
    if (isNull())
    {
        return;
    }
    else
    {
        archivo.open("file01.txt",ios::app);
        if(!archivo.is_open())
        {
            cout<<"Error al abrir el archivo."<<endl;
        }
        archivo<<root->data;
        archivo.close();
        getLeftChild().guardar();
        getRightChild().guardar();
        cout<<"Guardado con éxito."<<endl;
    }

}


template<typename T>
void ArbolBinario<T>::inOrder() const
{
    if (isNull())
    {
        return;
    }
    getLeftChild().inOrder();
    cout <<root->data;
    getRightChild().inOrder();
}

template<typename T>
void ArbolBinario<T>::postOrder() const
{
    if (isNull())
    {
        return;
    }
    getLeftChild().postOrder();
    getRightChild().postOrder();
    cout <<root->data <<" ";
}
#endif // ARBOLBINARIO_H
