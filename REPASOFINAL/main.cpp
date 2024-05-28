#include <iostream>
#include "AUTENTICACION.h"
#include "Usuarios.h"
#include "Pais.h"
#include "Entrenador.h"
#include "Bitacora.h"
#include "Equipo.h"


void menuGeneral();
void catalogos();
string codigoPrograma="1";
Bitacora Auditoria;
string user, contrasena;

using namespace std;

int main()
{
    AUTENTICACION ingreso(user, contrasena);

    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}
void menuGeneral()
{
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


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Procesos" << endl;
        cout << "\t\t\t 3. Informes" << endl;
        cout << "\t\t\t 4. Salir del Sistem" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
            //procesos();
            break;
        case 3:
            //reportes();
            break;
        case 4:
                Auditoria.ingresoBitacora(usuario1.usu,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 4);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Usuarios" << endl;
        cout << "\t\t\t 2. Paises" << endl;
        cout << "\t\t\t 3. Entrenador" << endl;
        cout << "\t\t\t 4. Puestos" << endl;
        cout << "\t\t\t 5. Equipo" << endl;
        cout << "\t\t\t 6. Jugadores" << endl;
        cout << "\t\t\t 7. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-7]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Usuarios usuario1;
            usuario1.menuUsuarios();

        }
            break;
        case 2:
        {
            PaisCrud pais1;
            pais1.Crud();
        }
            break;
        case 3:
        {
            EntrenadorCrud entrena;
            entrena.Crud();
            break;
        }
        case 4:

            break;
        case 5:
            EquipoCrud equipo;
            equipo.Crud();
            break;
        case 6:

            break;
        case 7:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 7);
}
