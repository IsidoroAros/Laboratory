#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cctype>
#include <algorithm>
#include "rutinas.h"
#include "funcionesTP.h"
#include "menus.h"
#include "fechas.h"
#include "ui.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;


void menu()
{

    while(true)
    {
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
        case 2:
            menuRutinas();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuUsuarios()
{

    while(true){

        system("cls");
        //title("MAIN MENU", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        //gotoxy(1, 5);
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
            eliminarUsuario();
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

void menuRutinas()
{
    system("cls");
    cout<<"MENÚ ENTRENAMIENTOS"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1) NUEVO ENTRENAMIENTO"<<endl;
    cout<<"2) MODIFICAR ENTRENAMIENTO"<<endl;
    cout<<"3) LISTAR ENTRENAMIENTO POR ID"<<endl;
    cout<<"4) LISTAR ENTRENAMIENTOS POR IDUSUARIO"<<endl;
    cout<<"4) LISTAR TODOS LOS ENTRENAMIENTOS"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
    int opcion;
    cout<<"> ";
    cin>> opcion;
    system("cls");
    switch(opcion)
    {
    case 1:
        nuevaRutina();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        return;
        break;
    default:
        break;
    }

}


