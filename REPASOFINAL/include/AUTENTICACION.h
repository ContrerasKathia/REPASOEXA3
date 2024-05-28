#ifndef AUTENTICACION_H
#define AUTENTICACION_H
#include<iostream>
#include<fstream>
#include<string>

 using namespace std;



class AUTENTICACION
{
 public:
        AUTENTICACION(string usuarios,string contrasena);

        string setUser(string usuarios);
        string getUser();

        string setContrasena(string contrasena);
        string getContrasena();


        bool VerificarUsuario();


    private:
        string usuarios,contrasena;

};

#endif // AUTENTICACION_H
