#include <iostream>
#include "AUTENTICACION.h"
#include "Usuarios.h"

//#include "Bitacora.h"

void menuGeneral();
void catalogos();
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
                //Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
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

        }
            break;
        case 3:
        {

            break;
        }
        case 4:
            // Implementación para Carreras
            break;
        case 5:
            // Implementación para Facultades
            break;
        case 6:
            // Implementación para Cursos
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
