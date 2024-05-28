#ifndef PAIS_H
#define PAIS_H
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
//Elaborado por : Daniel Antonio Chacón Morataya  9959-22-1827
struct Pais {
    int id;
    char nombrePais[50];
};


class PaisCrud
{
    public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void Crud();
};

#endif // PAIS_H
