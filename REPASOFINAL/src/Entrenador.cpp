#include "Entrenador.h"
#include "usuarios.h"
#include "AUTENTICACION.h"
#include "Bitacora.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;


void EntrenadorCrud::Crud() {
    string codigoPrograma="5001";
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
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION -      |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar "<<endl;
	cout<<"\t\t\t 2. Modificar "<<endl;
	cout<<"\t\t\t 3. Borrar "<<endl;
	cout<<"\t\t\t 4. Desplegar "<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        Ingresar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"IEN"); //CJO = Create Jornada
        system("Pause");
		break;
    case 2:
        system("Cls");
        Modificar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"MEN"); //CJO = Create Jornada
		system("Pause");
		break;
    case 3:
        system("Cls");
        Borrar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"BEN"); //CJO = Create Jornada
        system("Pause");
		break;
    case 4:
        Desplegar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"DEN"); //CJO = Create Jornada
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}
void EntrenadorCrud::Ingresar() {
    string codigoPrograma="3000";
   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Entrenador--------------------------------------------"<<endl;
    Entrenador entrena1;
    cout << "Ingrese el id del Entrenador: ";
    cin >> entrena1.id;
    cin.ignore();

    cout << "Ingrese el primer nombre del Entrenador: ";
    cin.getline(entrena1.nombre1, 50);
    cout << "Ingrese el Segundo nombre del Entrenador: ";
    cin.getline(entrena1.nombre2, 50);
    cout << "Ingrese el primer apellido del Entrenador: ";
    cin.getline(entrena1.apellido1, 50);
    cout << "Ingrese el segundo apellido del Entrenador: ";
    cin.getline(entrena1.apellido2, 50);
    cout<<"Ingrese la fecha de nacimiento: ";
    cin.getline(entrena1.fechanacimiento,50);

    ofstream archivo("Entrenadores.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&entrena1), sizeof(Entrenador));
    archivo.close();

    cout << "Pais agregado exitosamente!" << endl;
}
void EntrenadorCrud::Modificar() {
    string codigoPrograma="3000";
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Modificacion de Entrenadores--------------------------------------------"<<endl;
    int codigo;
    cout << "Ingrese el id del Entrenador a modificar: ";
    cin >> codigo;

    fstream archivo("Entrenadores.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Entrenadores registrados." << endl;
        return;
    }

    Entrenador entrena1;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&entrena1), sizeof(Entrenador))) {
        if (entrena1.id == codigo) {
            cout << "Ingrese el primer nombre del Entrenador: ";
            cin.getline(entrena1.nombre1, 50);
            cout << "Ingrese el Segundo nombre del Entrenador: ";
            cin.getline(entrena1.nombre2, 50);
            cout << "Ingrese el primer apellido del Entrenador: ";
            cin.getline(entrena1.apellido1, 50);
            cout << "Ingrese el segundo apellido del Entrenador: ";
            cin.getline(entrena1.apellido2, 50);
            cout<<"Ingrese la fecha de nacimiento: ";
            cin.getline(entrena1.fechanacimiento,50);

            archivo.seekp(-static_cast<int>(sizeof(Entrenador)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&entrena1), sizeof(Entrenador));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró Entrenador con el codigo ingresado." << endl;
    }
    else {
        cout << "Entrenador modificada exitosamente!" << endl;
    }

}
void EntrenadorCrud::Borrar() {
    string codigoPrograma="3000";
    int codigo;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Eliminar --------------------------------------------"<<endl;
    cout << "Ingrese el Id del Entrenador a eliminar: ";
    cin >> codigo;

    ifstream archivo("Entrenadores.dat", ios::binary);
    if (!archivo) {
        cout << "No hay Entrenadores registradas." << endl;

    }

    ofstream archivoTmp("paises_tmp.dat", ios::binary);
    Entrenador entrena1;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&entrena1), sizeof(Entrenador))) {
        if (entrena1.id != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&entrena1), sizeof(Entrenador)); //reescribe en otro archivo
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("Entrenadores.dat");
    rename("Entrenadores_tmp.dat", "Entrenadores.dat");

    if (eliminada) {
        cout << "Entrenador eliminado exitosamente!" << endl;

    } else {
        cout << "No se encontró el Entrenador con el codigo ingresado." << endl;
    }

}
void EntrenadorCrud::Desplegar() {
    system("cls");
    string codigoPrograma="3000";
    cout<<"-----------------Despliegue de Paises registradas---------------------"<<endl;
    ifstream archivo("Entrenadores.dat", ios::binary);
    if (!archivo) {
        cout << "No hay Entrenadores registrados." << endl;
        return;
    }
    Entrenador entrena1;

    while (archivo.read(reinterpret_cast<char*>(&entrena1), sizeof(Entrenador))) {
        cout << "ID: " << entrena1.id << endl;
        cout << "Primer Nombre: " << entrena1.nombre1 << endl;
        cout << "Segundo Nombre: " << entrena1.nombre2 << endl;
        cout << "Primer apellido: " << entrena1.apellido1<< endl;
        cout << "Segundo apellido: " << entrena1.apellido2 << endl;
        cout << "fecha de nacimiento: " << entrena1.fechanacimiento << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
