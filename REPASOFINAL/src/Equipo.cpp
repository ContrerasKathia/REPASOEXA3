#include "Equipo.h"

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

void EquipoCrud::Crud() {
    string codigoPrograma="7001";
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
	cout<<"\t\t\t|   SISTEMA DE GESTION - Pais     |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Pais"<<endl;
	cout<<"\t\t\t 2. Modificar Pais"<<endl;
	cout<<"\t\t\t 3. Borrar Pais"<<endl;
	cout<<"\t\t\t 4. Desplegar Pais"<<endl;
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
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"IEQ"); //CJO = Create Jornada
        system("Pause");
		break;
    case 2:
        system("Cls");
        Modificar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"MEQ"); //CJO = Create Jornada
		system("Pause");
		break;
    case 3:
        system("Cls");
        Borrar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"BEQ"); //CJO = Create Jornada
        system("Pause");
		break;
    case 4:
        Desplegar();
        Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"DEQ"); //CJO = Create Jornada
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}
// aqui se agregan carreras que son almacenadas
void EquipoCrud::Ingresar() {
    string codigoPrograma="3000";
   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Pais--------------------------------------------"<<endl;
    Equipo equipo1;
    cout << "Ingrese el id del Pais: ";
    cin >> equipo1.id;
    cin.ignore();

    cout << "Ingrese el nombre del Pais: ";
    cin.getline(equipo1.nombre, 50);

    ofstream archivo("Paises.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&equipo1), sizeof(Equipo));
    archivo.close();


    cout << "Pais agregado exitosamente!" << endl;
}
// modificar carreras
void EquipoCrud::Modificar() {
    string codigoPrograma="3000";
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Modificacion de Paises--------------------------------------------"<<endl;
    int codigo;
    cout << "Ingrese el id del pais a modificar: ";
    cin >> codigo;

    fstream archivo("Equipos.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Paises registrados." << endl;
        return;
    }

    Equipo equipo1;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&equipo1), sizeof(Equipo))) {
        if (equipo1.id == codigo) {
            cout << "Ingrese el nuevo nombre del Pais: ";
            cin.ignore();
            cin.getline(equipo1.nombre, 50);

            archivo.seekp(-static_cast<int>(sizeof(Equipo)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&equipo1), sizeof(Equipo));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró Pais con el codigo ingresado." << endl;
    }
    else {
        cout << "Pais modificada exitosamente!" << endl;
    }

}
// elimina carreras que ya no deseamos que estan registradas
void EquipoCrud::Borrar() {
    string codigoPrograma="3000";
    int codigo;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Eliminar Pais--------------------------------------------"<<endl;
    cout << "Ingrese el Id del Pais a eliminar: ";
    cin >> codigo;

    ifstream archivo("Equipos.dat", ios::binary);
    if (!archivo) {
        cout << "No hay paises registradas." << endl;

    }

    ofstream archivoTmp("Equipos_tmp.dat", ios::binary);
    Equipo equipo1;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&equipo1), sizeof(Equipo))) {
        if (equipo1.id != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&equipo1), sizeof(Equipo)); //reescribe en otro archivo
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("Equipos.dat");
    rename("Equipos_tmp.dat", "Equipos.dat");

    if (eliminada) {
        cout << "Pais eliminado exitosamente!" << endl;

    } else {
        cout << "No se encontró el Pais con el codigo ingresado." << endl;
    }

}
// Nos muestra las carreras registradas
void EquipoCrud::Desplegar() {
    system("cls");
    string codigoPrograma="3000";
    cout<<"-----------------Despliegue de Paises registradas---------------------"<<endl;
    ifstream archivo("Equipos.dat", ios::binary);
    if (!archivo) {
        cout << "No hay Paises registrados." << endl;
        return;
    }
    Equipo equipo1;
    while (archivo.read(reinterpret_cast<char*>(&equipo1), sizeof(Equipo))) {
        cout << "ID: " << equipo1.id << endl;
        cout << "Nombre: " << equipo1.nombre << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
