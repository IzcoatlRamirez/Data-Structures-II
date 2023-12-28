#ifndef LSL_H
#define LSL_H
#include <iostream>
#include <stdexcept>
#include <memory> // Permite utilizar apuntadores inteligentes

using namespace std;

template<typename T>
class LSL //Lista Simplemente Ligada
{
private:
    struct NodeLSL
    {
        T data;
        shared_ptr<NodeLSL> next; // NodeLSL* next;
        // Constructor del nodo
        NodeLSL(const T& element, shared_ptr<NodeLSL> n = nullptr) :
            data(element), next(n)
        {
            //data = element;
            //next = n;
        }
    };

    size_t listSize;
    shared_ptr<NodeLSL> listFront;
    shared_ptr<NodeLSL> listBack;




public:
    // Constructor de la lista. Inicialmente la lista tiene tamaño 0
    LSL()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }
    ~LSL()
    {
        clear();
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    void clear();
    void remove(const T& value);
    T& operator [] (size_t position);
    
};

template<typename T>
bool LSL<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t LSL<T>::size() const
{
    return listSize;
}

template<typename T>
void LSL<T>::push_front(const T& element)
{
    if (empty())
    {
        // listFront = new NodeLSL(element);
        listFront = make_shared<NodeLSL>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLSL> newNode = make_shared<NodeLSL>(element, listFront);
        listFront = newNode;
    }
    ++listSize;
}

template<typename T>
void LSL<T>::push_back(const T& element)
{
    if (empty())
    {
        listFront = make_shared<NodeLSL>(element);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodeLSL> newNode = make_shared<NodeLSL>(element);
        listBack->next = newNode;
        listBack = newNode;
    }
    ++listSize;
}

template<typename T>
const T& LSL<T>::front() const
{
    if (empty())
    {
        throw runtime_error("Trying front() from an empty list.");
    }
    return listFront->data;
}

template<typename T>
const T& LSL<T>::back() const
{
    if (empty())
    {
        throw runtime_error("Trying back() from an empty list.");
    }
    return listBack->data;
}

template<typename T>
void LSL<T>::pop_front()
{
    if (empty())
    {
        throw runtime_error("Trying pop_front() from an empty list.");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listFront = listFront->next;
    }
    --listSize;
}

template<typename T>
void LSL<T>::pop_back()
{
    if (empty())
    {
        throw runtime_error("Trying pop_back() from an empty list.");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        shared_ptr<NodeLSL> temp = listFront;
        while(temp->next != listBack)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        listBack = temp;
    }
    --listSize;
}

template<typename T>
void LSL<T>::insert(size_t position, const T& element)
{
    if (empty())
    {
        throw runtime_error("Trying insert() in an empty list.");
    }
    if (position > size())
    {
        throw runtime_error("Trying insert() in non valid position.");
    }
    if (position == 0)
    {
        push_front(element);
    }
    else if (position == size())
    {
        push_back(element);
    }
    else
    {
        shared_ptr<NodeLSL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        shared_ptr<NodeLSL> newNode = make_shared<NodeLSL>(element, temp->next);
        temp->next = newNode;
        ++listSize;
    }
}

template<typename T>
void LSL<T>::erase(size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying erase() from an empty list.");
    }
    if (position >= size())
    {
        throw runtime_error("Trying erase() from non valid position.");
    }
    if (position == 0)
    {
        pop_front();
    }
    else if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        shared_ptr<NodeLSL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        --listSize;
    }
}

template<typename T>
void LSL<T>::clear()
{
    listFront = nullptr;
    listBack = nullptr;
    listSize = 0;
    /*while(!empty())
    {
        pop_front();
    }*/
}

template<typename T>
void LSL<T>::remove(const T& value)
{
    if (empty())
    {
        throw runtime_error("Trying remove() from an empty list.");
    }
    T data;
    shared_ptr<NodeLSL> temp = listFront;
    for(size_t i(0); i < size(); ++i)
    {
        data = temp->data;
        temp = temp->next;
        if (data == value)
        {
            erase(i);
            --i;
        }
    }
}

template<typename T>
T& LSL<T>::operator[](size_t position)
{
    if (empty())
    {
        throw runtime_error("Trying [] from an empty list.");
    }
    shared_ptr<NodeLSL> temp = listFront;
    for (size_t i(0); i < position; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}


#endif // LSL_H
