#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
struct Entrenador {
    int id;
    char nombre1[50];
    char nombre2[50];
    char apellido1[50];
    char apellido2[50];
    char fechanacimiento[50];

};

class EntrenadorCrud
{
    public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void Crud();
};

#endif // ENTRENADOR_H
