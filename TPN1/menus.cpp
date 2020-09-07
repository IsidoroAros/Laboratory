#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "funcionesTP.h"
#include "menus.h"
using namespace std;

void menu(){

    while(true){
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
        switch(opcion){
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

void menuUsuarios(){

    while(true){

        cout<<"1 - NUEVO USUARIO "<<endl;
        cout<<"2 - EDITAR USUARIO "<<endl;
        cout<<"3 - LISTAR X ID "<<endl;
        cout<<"4 - LISTAR USUARIOS ACTIVOS"<<endl;
        cout<<"5 - LISTAR USUARIOS INACTIVOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0 - VOLVER"<<endl;
        int opcion;
        cout<<"> ";
        cin>> opcion;
        system("cls");
        switch(opcion){

        case 1:
            guardarUsuario();
            break;
        case 2:
            modificarUsuario();
            break;
        case 3:
            break;
        case 4:
        listarUsuariosActivos();
            break;
        case 0:
            return;
            break;
        }
    }
}
