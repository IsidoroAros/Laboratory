#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "funcionesTP.h"
#include "menus.h"
using namespace std;

bool validarFecha( int dia, int mes, int anio){

// Precondici�n: Se han de recibir tres par�metros, todos ellos de tipo entero.
// Poscondici�n: Se devolver� un 0/false o un 1/true.

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
//Si el a�o es bisiesto +1 d�a.
            if( ((anio%4 == 0)   &&   (anio%100 != 0)) ||   (anio%400 == 0) )
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

Usuario cargarUsuario(){

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
    cout << "�Tiene apto medico?\t";
    cin >> registro.aptoMedico;
    registro.estado = true;

    return registro;

}

void guardarUsuario(){

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

void modificarUsuario(){

    FILE *p;
    int posicion;
    Usuario regAux;
    bool guardo;
    int idUsuario;

    p = fopen("usuarios.dat","rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }

    cout << "Ingrese el ID:\t";
    cin >> idUsuario;

    posicion = buscarID(idUsuario);
    if(posicion<0)
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
    cout << "�Apto medico?\t";
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

int buscarID(int id){

    int contador=0;
    Usuario reg;
    FILE *p;

    p = fopen("usuarios.dat","rb");
    if(p==NULL)
    {
        return -1;///codigo de error de que no hall� el archivo.
    }

    while(fread(&reg, sizeof(Usuario),1, p)==1)
    {
        if(reg.id == id)
        {
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -2;///codigo de error de usuario inexistente.
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

void listarUsuarios(){

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
            cout<<"\n\nID: "<<reg.id<<endl;
            cout<<"Nombres: "<<reg.nombres<<endl;
            cout<<"Apellidos: "<<reg.apellidos<<endl;
            cout<<"Fecha de Nacimiento:"<<reg.fecha.dia<<"/"<<reg.fecha.mes<<"/"<<reg.fecha.anio<<endl;
            cout<<"Altura: "<<reg.altura<<endl;
            cout<<"Peso: "<<reg.peso<<endl;
            cout<<"Perfil: "<<reg.perfAct<<endl;
            cout<<"Apto: "<<reg.aptoMedico<<endl;
            if(reg.estado==true){
                cout<<"Estado: Activo"<<endl;
            }else{cout<<"Estado: Pasivo"<<endl;}
    }
    system("PAUSE");
    fclose(p);
}

void listarId(){
    int user;
    FILE *p;
    int idUsuario;
    Usuario reg;

    cout << "Ingrese el ID:\t";
    cin >> idUsuario;

    user=buscarID(idUsuario);
    cout<<"user: "<<user<<endl;
    system("PAUSE");

    if(user>=0){
        p = fopen("usuarios.dat","rb");
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
    else if(user==-2){
        cout<<"Id inexistente!\n";
        system("PAUSE");
    }else{
        cout << "Error al abrir el archivo \n";
        system("PAUSE");
        }
}

void mostrarReg(Usuario reg){
    if(reg.estado==true){
    cout<<"ID: "<<reg.id<<endl;
    cout<<"Nombres: "<<reg.nombres<<endl;
    cout<<"Apellidos: "<<reg.apellidos<<endl;
    cout<<"Fecha de Nacimiento:"<<reg.fecha.dia<<"/"<<reg.fecha.mes<<"/"<<reg.fecha.anio<<endl;
    cout<<"Altura: "<<reg.altura<<endl;
    cout<<"Peso: "<<reg.peso<<endl;
    cout<<"Perfil: "<<reg.perfAct<<endl;
    cout<<"Apto: "<<reg.aptoMedico<<endl;
    cout<<"Estado: "<<reg.estado<<endl;
    cout<<endl;
    }else{
        cout<<"\nusuario eliminado"<<endl<<endl;
        }
}

void eliminarUsuario(int posicion){

    FILE *p;
    Usuario regAux;
    bool guardo;
    int idUsuario;

    p = fopen("usuarios.dat","rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }

    cout << "ingrese el ID:\t";
    cin >> idUsuario;

    if(posicion<0)
    {
        cout << "\neliminacion fallida";
        fclose(p);
        system("pause");
        return;
    }
    regAux = leer_usuario(posicion);
    regAux.estado=false;

    fseek(p,sizeof(Usuario)*posicion,SEEK_SET);
    guardo = fwrite(&regAux,sizeof(Usuario),1,p);
    if(guardo==1)
    {
        cout << "\nusuario eliminado exitosamente";
        fclose(p);
        system("pause");
        return;
    }
    else
    {
        cout << "\neliminacion fallida";
        fclose(p);
        system("pause");
        return;
    }

}

