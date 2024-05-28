#ifndef EQUIPO_H
#define EQUIPO_H

#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
struct Equipo {
    int id;
    char nombre[50];

};

class EquipoCrud
{
    public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void Crud();
};


#endif // EQUIPO_H
