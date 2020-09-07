#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "usuario.h"
#include "rutinas.h"
#include "menu.h"

void menu()
{
    while(true)
    {
        cout<<"1 - PARTICIPANTES"<<endl;
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
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return;
            break;
        }



    }
}

void menuUsuarios()
{
    while(true)
    {

        cout<<"1 - NUEVO PARTICIPANTE "<<endl;
        cout<<"2 - EDITAR PARTICIPANTE "<<endl;
        cout<<"3 - LISTAR X ID "<<endl;
        cout<<"4 - LISTAR ACTIVOS"<<endl;
        cout<<"5 - LISTAR INACTIVOS"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"0 - VOLVER"<<endl;
        int opcion;
        cout<<"> ";
        cin>> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            Usuario reg;
            reg= cargarUsuario();
            if(guardarUsuario(reg))
            {
                cout<<"Usuario Registrado ok! "<<endl;
            }
            else
            {
                cout<<"ERROR!!! No se pudo registrar el Usuario. "<<endl;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4: listarUsuario(true); break;
        case 0:
            return;
            break;
        }
    }
}
