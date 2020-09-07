#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "funcionesTP.h"
#include "menus.h"
using namespace std;

bool validarFecha( int dia, int mes, int anio)
{

// Precondición: Se han de recibir tres parámetros, todos ellos de tipo entero.
// Poscondición: Se devolverá un 0/false o un 1/true.

    bool fec = 0;

    if( mes >= 1 && mes <= 12 )
    {

        switch( mes )
        {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if( dia >= 1 && dia <= 31 )
            {
                fec = true;
            }
            break;


        case 4:
        case 6:
        case 9:
        case 11:
            if( dia >= 1 && dia <= 30 )
            {
                fec = true;
            }
            break;


        case 2:
//Si el año es bisiesto +1 día.
            if( (anio%4 == 0)   &&   (anio%100 != 0)   ||   (anio%400 == 0) )
            {
                if( dia >= 1 && dia <= 29 )
                {
                    fec = true;
                }
            }
            else
            {
                if( dia >= 1 && dia <= 28 )
                {
                    fec = true;
                }
            }
            break;

        }

    }

    return fec;
}

Usuario cargarUsuario()
{

    int dia,mes,anio;
    Usuario registro;

    cout << "Ingrese ID:\t";
    cin >> registro.id;
    /// chequear si el usuario ya existe buscarRegistro();
    cin.ignore();
    cout << "Nombre:\t";
    cin.getline(registro.nombres,50,'\n');
    cout << "Apellido:\t";
    cin.getline(registro.apellidos,50,'\n');
    cout << "Ingrese fecha de nacimiento:\t";
    cin >> dia >> mes >> anio;
    /// agregar funcion de Eugenio de fechas
    while(validarFecha(dia,mes,anio)==0)
    {
        cout << "Fecha invalida, reingrese:\t";
        cin >> dia;
        cin >> mes;
        cin >> anio;
    }
    registro.fecha.dia = dia;
    registro.fecha.mes = mes;
    registro.fecha.anio = anio;

    cout << "Altura:\t";
    cin >> registro.altura;
    cout << "Peso:\t";
    cin >> registro.peso;
    cout << "Perfil de actividad:\t";
    cin >> registro.perfAct;
    cout << "¿Tiene apto medico?\t";
    cin >> registro.aptoMedico;
    registro.estado = true;

    return registro;

}

void guardarUsuario()
{

    FILE *p;
    bool chequeo;
    Usuario registro;

    registro = cargarUsuario(); /// recibo los datos de la funcion
    p = fopen("usuarios.dat","ab");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }
    chequeo = fwrite(&registro, sizeof(Usuario),1,p);
    if(chequeo==1)
    {
        cout << "El registro se guardo correctamente \n\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
    else
    {
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
}

void modificarUsuario()
{

    FILE *p;
    int posicion;
    Usuario regAux;
    bool guardo;

    p = fopen("usuarios.dat","rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }

    posicion = buscarID();
    if(posicion==-1)
    {
        cout << "Modificacion fallida\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
    regAux = leer_usuario(posicion);
    cout << "Nuevo peso:\t";
    cin >> regAux.peso;
    cout << "Nuevo perfil de actividad:\t";
    cin >> regAux.perfAct;
    cout << "¿Apto medico?\t";
    cin >> regAux.aptoMedico;

    fseek(p,sizeof(Usuario)*posicion,SEEK_SET);
    guardo = fwrite(&regAux,sizeof(Usuario),1,p);
    if(guardo==1)
    {
        cout << "Modificacion exitosa\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
    else
    {
        cout << "Modificacion fallida\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
}

int buscarID()
{

    int idUsuario, contador=0;
    Usuario reg;
    FILE *p;

    cout << "Ingrese el ID:\t";
    cin >> idUsuario;

    p = fopen("usuarios.dat","ab");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return -1;
    }

    while(fread(&reg, sizeof(Usuario),1, p)==1)
    {
        contador++;
        if(reg.id == idUsuario)
        {
            cout << "ID coincidente\n";
            fclose(p);
            return contador;
        }
    }
    fclose(p);
    return -1;
}

Usuario leer_usuario(int pos){
    Usuario reg;
    FILE *p = fopen("usuarios.dat", "rb");
    if (p == NULL)
    {
        reg.id = 0;
        return reg;
    }
    if(pos == -1)
    {
        cout << "Posicion incorrecta\n";

        reg.id = 0;
        system("pause");
        system("cls");
        return reg;
    }
    fseek(p, pos * sizeof(Usuario), SEEK_SET);
    fread(&reg, sizeof(Usuario), 1, p);
    fclose(p);
    return reg;
}

void listarUsuariosActivos(){

    FILE *p;
    Usuario reg;
    p = fopen("usuarios.dat","rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }

    while(fread(&reg,sizeof(Usuario),1,p)==1)
    {
        if(reg.estado==1)
        {
            cout<<"ID: "<<reg.id<<endl;
            cout<<"Nombres: "<<reg.nombres<<endl;
            cout<<"Apellidos: "<<reg.apellidos<<endl;
            cout<<"Fecha de Nacimiento:"<<reg.fecha.dia<<"/"<<reg.fecha.mes<<"/"<<reg.fecha.anio<<endl;
            cout<<"Altura: "<<reg.altura<<endl;
            cout<<"Peso: "<<reg.peso<<endl;
            cout<<"Perfil: "<<reg.perfAct<<endl;
            cout<<"Apto: "<<reg.aptoMedico<<endl;
            cout<<endl;
        }
    }
    system("PAUSE");
    fclose(p);
}

void listarId(){
    int user;
    FILE *p;
    Usuario reg;
    user=buscarID();
    if(user!=-1){
    p = fopen("usuarios.dat","rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }
    fseek(p,sizeof(Usuario)*user,SEEK_SET);
    fread(&reg,sizeof(Usuario),1,p);
    mostrarReg(reg);
    fclose(p);
    system("PAUSE");
    }
    else{
        cout<<"ID INEXISTENTE!"<<endl;
        system("PAUSE");
    }
}
void mostrarReg(Usuario reg){
    cout<<"ID: "<<reg.id<<endl;
    cout<<"Nombres: "<<reg.nombres<<endl;
    cout<<"Apellidos: "<<reg.apellidos<<endl;
    cout<<"Fecha de Nacimiento:"<<reg.fecha.dia<<"/"<<reg.fecha.mes<<"/"<<reg.fecha.anio<<endl;
    cout<<"Altura: "<<reg.altura<<endl;
    cout<<"Peso: "<<reg.peso<<endl;
    cout<<"Perfil: "<<reg.perfAct<<endl;
    cout<<"Apto: "<<reg.aptoMedico<<endl;
    cout<<endl;
}
