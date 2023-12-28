//
// Created by user on 02/11/2022.
//

#ifndef PROG05_RAMIREZ_CORTES_IZCOATL_CRIPTOGRAFIA_H
#define PROG05_RAMIREZ_CORTES_IZCOATL_CRIPTOGRAFIA_H
#include <iostream>
#include <algorithm>
#include <fstream>
class criptografia
{
public:
    void cifrar(std::string& fich,const int &clave);
    void descifrar(std::string &fich,const int &clave);
private:
    std::string cifrarCaesar(std::string &value, const int clave);
    std::string descifrarCaesar(std::string &text,const int clave);
    std::string cifrarXOR(std::string & text,const int clave);
    std::string descifrarXOR(std::string&text,const int clave);
    std::string leer(std::string& fich);
    void escribir(std::string &text,std::string &fich);
};

std::string criptografia::cifrarCaesar(std::string &value, const int clave)
{

    std::transform(value.begin(),value.end(),value.begin(), toupper);
    std::string texto="";
    for(auto p: value)
    {
        if(isalpha(p))
        {
            p+=clave;
            if(p > 'Z'){p-=26;}
            if(p <'A'){p+=26;}

        }
        texto+=p;
    }
    return texto;
}

std::string criptografia::descifrarCaesar(std::string &text, const int clave)
{
    return cifrarCaesar(text,-clave);
}

std::string criptografia::leer(std::string &fich)
{
    std::ifstream archivo;
    std::string  aux;
    std::string texto="";
    archivo.open(fich,std::ios::in);
    if(archivo.fail())
    {
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
    else
    {
        while(!archivo.eof())
        {
            getline(archivo,aux);
            texto+=aux;
        }
        archivo.close();
    }

    return texto;
}

void criptografia::escribir(std::string &text, std::string &fich)
{
    std::ofstream archivo;
    archivo.open(fich,std::ios::out); //reemplazo
    if(!archivo.is_open())
    {
        std::cout<<"Error al abrir el archivo."<<std::endl;
    }
    else
    {
        archivo<<text;
        archivo.close();
    }
}

void criptografia::cifrar(std::string &fich,const int &clave)
{
    std::string texto= leer(fich);
    std::string aux=cifrarCaesar(texto,clave);
    std::string cifrado= cifrarXOR(aux,clave);
    escribir(cifrado,fich);
}

void criptografia::descifrar(std::string &fich,const int &clave)
{
    std::string texto=leer(fich);
    std::string aux= descifrarXOR(texto,clave);
    std::string descifrado= descifrarCaesar(aux,clave);
    escribir(descifrado,fich);
}

std::string criptografia::cifrarXOR(std::string &text, const int clave)
{
    std::string texto="";
    for(int i(0);i<text.size();++i)
    {
        char aux=char(text[i]^clave);
        texto+=aux;
    }
    return texto;
}

std::string criptografia::descifrarXOR(std::string &text, const int clave)
{
    return cifrarXOR(text,clave);
}


#endif //PROG05_RAMIREZ_CORTES_IZCOATL_CRIPTOGRAFIA_H
