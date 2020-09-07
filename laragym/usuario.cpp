#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "usuario.h"
#include "rutinas.h"
#include "menu.h"
const char *USERS_FILE="Users.dat";
Usuario cargarUsuario()
{

    Usuario u, *aux;
    aux=&u;
    int codigo, pos;
    bool valido;
    do
    {
        cout<<"\nCodigo: ";
        cin>>codigo;

        if(!(codigo>=1000 && codigo<=9999))
        {
            cout<<"Codigo incorrecto.  Intente nuevamente: "<<endl;
            valido=false;
        }
        else if(buscarUsuario(codigo)>=0)
        {
            cout<<"EL codigo de usuario ingresado ya fue ingresado. "<<endl;
            valido=false;
        }
        else
        {
            valido=true;
        }
    }
    while(!valido);

    aux->id=codigo;
    cin.ignore();
    cout<<"\nApellido :";
    cin.getline(aux->apellido, 50);
    cout<<"\nNombre :";
    cin.getline(aux->nombre, 50);
    cout<<"\nGenero: ";
    cin>>aux->genero;
    while(aux->genero != 'M' && aux->genero != 'F' && aux->genero != 'X')
    {
        cout<<"\nGenero incorrecto!!!, ingrese otro: "<<endl;
        cin>>aux->genero;
    }
    cout<<"\nFecha de Nacimiento: ";

    cin>>aux->fechaNac.dia;
    cin>>aux->fechaNac.mes;
    cin>>aux->fechaNac.anio;
  /*     while(aux->fechaNac.anio <(ANIO_ACTUAL-13)){

       }*/
    aux->estado=true;

    return u;
}

bool guardarUsuario(Usuario reg)
{
    bool grabo;
    FILE *p;
    p= fopen(USERS_FILE, "ab");
    if(p==NULL)
    {
        return false;
    }
    grabo = fwrite(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return grabo;
}

int buscarUsuario(int codigo)
{
    Usuario reg;
    FILE *p;
    int pos=0;
    p=fopen(USERS_FILE, "rb");
    if(p==NULL)
    {
        return -2;
    }
    while(fread(&reg, sizeof(Usuario), 1, p))
    {
        if(codigo==reg.id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;

}
void  mostrarUsuario(Usuario reg, bool estado)
{
        cout<<"Codigo: "<<reg.id<<endl;
        cout<<"Apellidos: "<<reg.apellido<<endl;
        cout<<"Nombres:"<<reg.nombre<<endl;
        cout<<"Genero"<<reg.genero<<endl;
        cout<<"Fecha de Nacimiento:"<<reg.fechaNac.dia<<"/"<<reg.fechaNac.mes<<"/"<<reg.fechaNac.anio<<endl;
        cout<<"Estado: "<<reg.estado<<endl;

}
void  listarUsuario(bool estado)
{
    system("cls");
    cout<<"----- LISTADO DE USUARIOS"<<endl;
    int cant = cantidadUsuarios();
    for(int i= 0; i < cant; i++)
    {
        Usuario reg =leer_usuario(i);
        if(reg.estado==true)
        {
            mostrarUsuario(reg, true);
            cout<<endl;
        }
        else
        {
            mostrarUsuario(reg, false);
            cout<<endl;
        }
    }
}

int  cantidadUsuarios()
{
    FILE *p;
    p= fopen(USERS_FILE, "rb");
    if(p==NULL)
    {
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END);
    bytes=ftell(p);
    fclose(p);
    cant =bytes/sizeof(Usuario);
    return cant;
}
Usuario leer_usuario(int pos)
{
    Usuario reg;
    FILE *p;
    p= fopen(USERS_FILE, "rb");
    if(p==NULL)
    {
        reg.id=0;
        return reg;

    }
    fseek(p, pos*sizeof(Usuario), SEEK_SET);
    fread(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return reg;
}
