#include "Usuarios.h"
//usuarios.cpp prueba
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iostream>
#define USER "usuario"
#define PASS "1234"
#include "Bitacora.h"

using namespace std;


void Usuarios::menuUsuarios(){
     string codigoPrograma="4001";
    Bitacora Auditoria;
//---------------Trae usuario --------------------------
    Usuario usuario1;
    fstream file;
    int total=0;
    file.open("bitaA.txt",ios::in);
    if(!file)
	{
		cout<<"\n\t\t\tNo hay usuarios registrados...";
		file.close();
	}
	else
	{
		file >> usuario1.usu;
		while(!file.eof())
		{
			total++;
			file >> usuario1.usu;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay usuarios...";
		}
	}
	file.close();

int choice;
    do {
    char x;
	system("cls");
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION DE SEGURIDAD - Catalogos Usuarios |"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Usuarios"<<endl;
	cout<<"\t\t\t 2. Consulta Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificacion Usuarios"<<endl;
	cout<<"\t\t\t 4. Eliminacion Usuarios"<<endl;
	cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"IUS"); //CJO = Create Jornada
    		cout<<"\n\t\t\t Agrega otra persona(s,n): ";
    		cin>>x;
		}while(x=='s'||x=='S');
		break;
	case 2:
		desplegar();
		Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"DUS"); //CJO = Create Jornada
		break;
	case 3:
		modificar();
		Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"MUS"); //CJO = Create Jornada
		break;
	case 4:
		borrar();
		Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"BUS"); //CJO = Create Jornada
		break;
	case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	cin.get();
	//getch();
    }while(choice!= 5);
}
bool Usuarios::buscar(string user, string passw)
{

	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		file >> id >> name >> pass;
		while(!file.eof())
		{
			if(user==id)
			{
			    if (passw == pass)
                {
                    found++;
                }
			}
			file >> id >> name >> pass;
		}
		if(found==0)
		{
			return false;
		}
		else
            return true;
		file.close();
	}
}
string Usuarios::getNombre()
{

    return name;
}
string Usuarios::setNombre(string nombre)
{
    name=nombre;
}

void Usuarios::insertar()
{
    system("cls");
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Usuario             |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    Usuario usuario;

    cout<<"       -> Ingrese el nombre del estudiante:  ";
    cin >> usuario.usu;

    cout<<"       -> Ingrese la contrasena del estudiante: ";
    cin >> usuario.contra;

    cout<<"+---------------------------------------------------------+"<< endl;

    ofstream archivo("Usuario.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(usuario));
    archivo.close();

}

void Usuarios::desplegar()
{
    system("cls");

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Usuario                        +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    ifstream archivo("Usuario.dat", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }
    Usuario usuario;
    while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(usuario))) {

        cout << "                        Mostrando -> ID del estudiante: " << usuario.usu << endl;
        cout << "                        Mostrando -> Nombre del estudiante: " << usuario.contra << endl;
        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void Usuarios::modificar()
{
	system("cls");
    fstream archivo;
    string idPersona;
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del estudiante                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    archivo.open("Usuario.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }

    cout << "Ingrese el ID de la persona que desea modificar: ";
    cin >> idPersona;

    Usuario usuario;
    while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario))) {
        if (usuario.usu == idPersona) {
            encontrado = true;
            cout << "Ingrese el nuevo nombre del usuario: ";
            cin >> usuario.usu;
            cout << "Ingrese la nueva contrasena del usuario: ";
            cin >> usuario.contra;

            archivo.seekp(-static_cast<int>(sizeof(Usuario)), ios::cur);


            archivo.write(reinterpret_cast<char*>(&usuario), sizeof(Usuario));
            break;
        }
    }
    archivo.close();

    if (!encontrado) {
        cout << "No se encontr� un usuario con el nombre proporcionado." << endl;
    }
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void Usuarios::borrar()
{
	system("cls");
	string idPersona;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar estudiante                                 +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

    ifstream archivo("Usuario.dat", ios::binary);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		return;
	}
	ofstream archivo2("Usuario2.dat", ios::binary);
	Usuario usuario;

    cout<<"-> Ingrese el nombre del usuario que desea eliminar: ";
    cin>>idPersona;
    bool resta = false;
    //cout<<"+---------------------------------------------------------------------------------+"<<endl;
		while(archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario)))
		{
			if(usuario.usu != idPersona)
			{
				archivo2.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuario));
			}
			else
			{
			    resta = true;
			}

		}

		archivo.close();
		archivo2.close();
		remove("Usuario.dat");
		rename("Usuario2.dat","Usuario.dat");

		if (resta)
        {
        cout << "Usuario eliminado con exito." << endl;
        }
        else
        {
        cout << "No se a podido encontrar el usuario" << endl;
        }
}

