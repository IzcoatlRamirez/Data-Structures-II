#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <stdexcept>
#include <memory>
#include "arbolbinario.h"

using namespace std;

template<typename T>
class ABB : public ArbolBinario<T>
{
public:
    ABB()
    {
        ArbolBinario<T>();
    }

    bool insert(const T& elem);
    bool erase(const T& elem);
    const T* find(const T& elem);

private:
    bool insert(shared_ptr<NodeAB<T>>& localRoot, const T& elem);
    bool erase(shared_ptr<NodeAB<T>>& localRoot, const T& elem);
    const T* find(shared_ptr<NodeAB<T>> localRoot, const T& elem);
    void replaceParent(shared_ptr<NodeAB<T>>& oldRoot, shared_ptr<NodeAB<T>>& localRoot);
};

template<typename T>
const T* ABB<T>::find(const T &elem)
{
    return find(this->root, elem);
}

template<typename T>
const T* ABB<T>::find(shared_ptr<NodeAB<T> > localRoot, const T &elem)
{
    if (localRoot == nullptr)
    {
        return nullptr;
    }
    else if (elem < localRoot->data)
    {
        return find(localRoot->left, elem);
    }
    else if (elem > localRoot->data)
    {
        return find(localRoot->right, elem);
    }
    else
    {
        return &(localRoot->data);
    }
}

template<typename T>
bool ABB<T>::insert(const T &elem)
{
    return insert(this->root, elem);
}

template<typename T>
bool ABB<T>::insert(shared_ptr<NodeAB<T> > &localRoot, const T &elem)
{
    if (localRoot == nullptr)
    {
        localRoot = make_shared<NodeAB<T>>(elem);
        return true;
    }
    else
    {
        if (elem< localRoot->data)
        {
            return insert(localRoot->left, elem);
        }
        else if (elem > localRoot->data)
        {
            return insert(localRoot->right, elem);
        }
        else
        {
            return false;
        }
    }
}

template<typename T>
bool ABB<T>::erase(const T &elem)
{
    return erase(this->root, elem);
}

template<typename T>
bool ABB<T>::erase(shared_ptr<NodeAB<T> > &localRoot, const T &elem)
{
    if (localRoot == nullptr)
    {
        return false;
    }
    else
    {
        if (elem < localRoot->data)
        {
            return erase(localRoot->left, elem);
        }
        else if (elem > localRoot->data)
        {
            return erase(localRoot->right, elem);
        }
        else
        {
            if (localRoot->left == nullptr)
            {
                localRoot = localRoot->right;
            }
            else if (localRoot->right == nullptr)
            {
                localRoot = localRoot->left;
            }
            else
            {
                shared_ptr<NodeAB<T>> oldRoot = localRoot;
                replaceParent(oldRoot, localRoot->left);
            }
            return true;
        }
    }
}

template<typename T>
void ABB<T>::replaceParent(shared_ptr<NodeAB<T> > &oldRoot, shared_ptr<NodeAB<T> > &localRoot)
{
    if (localRoot->right != nullptr)
    {
        replaceParent(oldRoot, localRoot->right);
    }
    else
    {
        oldRoot->data = localRoot->data;
        localRoot = localRoot->left;
    }
}
#endif // ABB_H

