#include "AUTENTICACION.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include"Usuarios.h"
//#include "Bitacora.h"


using namespace std;

//CONSTRUCTOR
AUTENTICACION::AUTENTICACION(string usuario, string contrasena)//parametros de la clase
{
    this -> usuarios=usuarios;
    this -> contrasena=contrasena;
}

string AUTENTICACION::setUser(string usuarios)
{
    this -> usuarios=usuarios;
}

string AUTENTICACION::getUser()
{
    return this->usuarios;
}

string AUTENTICACION::setContrasena(string contrasena)
{
    this -> contrasena=contrasena;
}

string AUTENTICACION::getContrasena()
{
    return this->contrasena;
}

//primer despliegue de pantalla
bool AUTENTICACION::VerificarUsuario()
{
    string usuario,contrasena;
    int contador= 0; // contador de intentos
    bool encontrado =false; // indica si encontro user y contra

    //el ciclo se repite mientras el numero de intentos sea menor a 3 o no se encuentre user valido
    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|       LOGIN                       |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|Solo tienes permitido 3 intentos   |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\tIngrese el nombre de usuario: ";
    cin >> usuario;
    cout <<"\t\t\tIngrese la contrasena: ";
    char caracter;
    caracter = getch();

    // ocultar a la hora de escribir la contraseña
    contrasena="";
        while (caracter!=13)//ascci enter
        {
        if(caracter !=8)//ascci backs pace
            {
                contrasena.push_back(caracter);
                cout<<"*";
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b";
                    contrasena=contrasena.substr(0,contrasena.length()-1);
                }
            }
            caracter=getch();
        }

    //abrira el archivo de User y contraseñas--------------------------
    ifstream fileU_P("Usuario.dat", ios::binary | ios::app);



    //verificar si se abrio el archivo---------------------------
    if (!fileU_P)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }
    string codigoPrograma="1000";
    //Bitacora Auditoria;

    //busca el usuario en el archivo---------------------------------

    Usuario usuario1;
    while (fileU_P.read(reinterpret_cast<char*>(&usuario1), sizeof(Usuario))) {

       if (usuario==usuario1.usu && contrasena==usuario1.contra)
        {
            //Auditoria.ingresoBitacora(user,codigoPrograma,"LGI");
            encontrado=true;
            break;
        }
    }
     fileU_P.close();

    //si no encuentra user y pass , el contador incrementara------------------------
    if(!encontrado)
    {
        cout << "\n\n\t\t\tUSUARIO Y/O CONTRASEÑA INCORRECTOS" << endl;
        cout << "\n\n\t\t\tPerdio un intento, Intente de nuevo\n" << endl;
        contador++;
        system("pause");
    }
}

    //Si encuentra a user y pass , se retornara un true
   if (encontrado)
    {
    	         system("cls");

    cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
     system("pause");
    return true;
    }
   else
    {
	system("cls");
    cout << "\n\n\t\t\tPERDIO LOS 3 INTENTOS" << endl;
     system("pause");
     exit(0);

    return false;
    }





}
