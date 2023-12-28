//
// Created by user on 02/11/2022.
//
#include <iostream>
#include "criptografia.h"
using namespace std;
int main()
{

criptografia c;

string directorio="descifrado.txt";
//c.cifrar(directorio,5);
c.descifrar(directorio, 5);

    return 0;
}