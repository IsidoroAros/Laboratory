#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "funcionesTP.h"
#include "menus.h"
using namespace std;

void menu()
{

    while(true)
    {
        system("cls");
        cout<<"1 - USUARIOS"<<endl;
        cout<<"2 - ENTRENAMIENTOS"<<endl;
        cout<<"3 - REPORTES"<<endl;
        cout<<"4 - CONFIGURACION"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            menuUsuarios();
            break;
        case 0:
            return;
        default:
            cout << "OPCION INCORRECTA \n";
            break;
        }
    }
}

void menuUsuarios()
{

    while(true)
    {
        system("cls");
        cout<<"1 - NUEVO USUARIO "<<endl;
        cout<<"2 - MODIFICAR USUARIO "<<endl;
        cout<<"3 - LISTAR USUARIO POR ID "<<endl;
        cout<<"4 - LISTAR TODOS LOS USUARIOS"<<endl;
        cout<<"5 - ELIMINAR USUARIO "<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        int opcion;
        cout<<"> ";
        cin>> opcion;
        system("cls");
        switch(opcion)
        {

        case 1:
            guardarUsuario();
            break;
        case 2:
            modificarUsuario();
            break;
        case 3:
            listarId();
            break;
        case 4:
            listarUsuarios();
            break;
        case 5:
            int idBaja;
            cout<<"ingrese id del usuario a eliminar";
            cin>>idBaja;
            eliminarUsuario(buscarID(idBaja));
            break;
        case 0:
            return;
            break;
        }
    }
}
