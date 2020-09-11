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

const char *FILE_USUARIOS = "archivos/usuarios.dat";

Usuario cargarUsuario(){

    int dia,mes,anio;
    Usuario registro;
    char perf, nombre[50], apellido[50];
    locate(1,2);cout << "Ingrese ID:\t";
    cin >> registro.id;
    while(buscarID(registro.id)!=-2 || (registro.id<0 || registro.id>9999)){
        msj("ID erroneo",WHITE,RED,29,TEXT_LEFT);
        ///locate(1,29);cout << "\nID erroneo\t";

        cls();
        title("NUEVO USUARIO");
        gotoxy(1,2);cout << "Ingrese otro ID:\t";
        cin >> registro.id;
    } /// validacion id

    cin.ignore();
    cout << "Nombre:\t";
    cin.getline(nombre,50,'\n');
        while(validarNombresApellidos(nombre,50)==false){
                msj("Nombre erroneo",WHITE,RED,29,TEXT_LEFT);
                cls();
                title("NUEVO USUARIO");
                locate(1,2);cout << "Nuevo nombre:\t";
                cin.getline(nombre,50,'\n');
        } /// validacion nombre
    strcpy(registro.nombres,nombre);
    getch();

    cout << "Apellido:\t";
    cin.getline(apellido,50,'\n');
        while(validarNombresApellidos(apellido,50)==false){
                msj("Apellido erroneo",WHITE,RED,29,TEXT_LEFT);
                cls();
                title("NUEVO USUARIO");
                locate(1,2);cout << "Nuevo apellido:\t";
                cin.getline(apellido,50,'\n');
        } /// validacion apellido
    strcpy(registro.apellidos,apellido);

    cout << "Ingrese fecha de nacimiento:\t";
    cin >> dia >> mes >> anio;

    while(validarEdad(dia,mes,anio)==false){
                msj("Fecha erronea",WHITE,RED,29,TEXT_LEFT);
                cls();
                title("NUEVO USUARIO");
                locate(1,5);cout << "Nueva fecha:\t";
                cin >> dia;
                cin >> mes;
                cin >> anio;

    } /// validacion fecha
    registro.fecha.dia = dia;
    registro.fecha.mes = mes;
    registro.fecha.anio = anio;

    cout << "Altura:\t";
    cin >> registro.altura;
        while(registro.altura<=0){
                    msj("Altura erronea",WHITE,RED,29,TEXT_LEFT);
                    cls();
                    title("NUEVO USUARIO");
                    locate(1,5);cout << "Nueva altura:\t";
                    cin >> registro.altura;
        }
    cout << "Peso:\t";
    cin >> registro.peso;
        while(registro.peso<=0){
                    cls();
                    msj("Peso erroneo",WHITE,RED,130,TEXT_LEFT);
                    cls();
                    title("NUEVO USUARIO");
                    locate(1,5);cout << "Nuevo peso:\t";
                    cin >> registro.peso;
        }
    cout << "Perfil de actividad:\t";
    cin >> perf;
        while(!(perf == 'A' || perf == 'a'
                || perf == 'B' || perf == 'b'
                || perf == 'C' || perf == 'c') ){
                    cls();
                    msj("Perfil erroneo",WHITE,RED,130,TEXT_LEFT);
                    gotoxy(1,5);
                fflush(stdin);
            cout << "Nuevo perfil de actividad:\t";
            cin >>perf;
        }/// validacion perfil de actividad

        registro.perfAct=perf;
    /*cout << "¿Tiene apto medico?\t";
    cin >> apto;
        while(apto != 'S' || apto != 's' || apto != 'N' || apto != 'n'){
                fflush(stdin);
                    cls();
                    msj("Apto erroneo",WHITE,RED,130,TEXT_LEFT);
                    gotoxy(1,5);
            cout << "Tiene apto medico?\t";
            cin >> apto;
        }*//// validacion apto medico
    registro.estado = true;

    system("cls");
    title("NUEVO USUARIO");
    locate(1,2);mostrarReg(registro);
    locate(1,29);system("pause");
    system("cls");

    return registro;
}

void guardarUsuario(){
    cls();
    title("NUEVO USUARIO");
    FILE *p;
    bool chequeo;
    Usuario registro;

    registro = cargarUsuario();
    p = fopen(FILE_USUARIOS,"ab");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }
    chequeo = fwrite(&registro, sizeof(Usuario),1,p);
    if(chequeo==1)
    {

        msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
        fclose(p);
        system("pause");
        cls();
        return;
    }
    else
    {
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        cls();
        return;
    }
}

void modificarUsuario(){///PROBLEMA CON ESTA FUNCION: SE CUELGA AL SALIR! ENVIA LOS DOS CARTELES PERO GUARDA

    FILE *p;
    int posicion;
    Usuario regAux;
    bool guardo;
    int idUsuario;

    cls();
    title("MODIFICAR USUARIO");

    p = fopen(FILE_USUARIOS,"rb+");
    if(p==NULL){
        cout << "Error al abrir el archivo \n";
        return;
    }

    locate(1,2);cout << "Ingrese el ID:\t";
    cin >> idUsuario;

    posicion = buscarID(idUsuario);
    if(posicion<0){
        msj("Modificacion fallida",WHITE,RED,130,TEXT_LEFT);;
        fclose(p);
        return;
    }
    regAux = leerUsuario(posicion);
    locate(1,3);cout << "Nuevo peso:\t";
    cin >> regAux.peso;
    while(regAux.peso<=0){
                    cls();
                    msj("Peso erroneo",WHITE,RED,130,TEXT_LEFT);
                    cls();
                    title("MODIFICAR USUARIO");
                    locate(1,2);cout << "Nuevo peso:\t";
                    cin >> regAux.peso;
        }
    cout << "Nuevo perfil de actividad:\t";
    cin >> regAux.perfAct;
        while(!(regAux.perfAct == 'A' || regAux.perfAct == 'a'
                    || regAux.perfAct == 'B' || regAux.perfAct == 'b'
                    || regAux.perfAct == 'C' || regAux.perfAct == 'c') ){
                        msj("Perfil erroneo",WHITE,RED,130,TEXT_LEFT);

                        cls();
                        title("MODIFICAR USUARIO");

                        fflush(stdin);
                        locate(1,2);cout << "Nuevo perfil de actividad:\t";
                        cin >>regAux.perfAct;
            }

    cout << "¿Apto medico?\t";
    cin >> regAux.aptoMedico;

    fseek(p,sizeof(Usuario)*posicion,SEEK_SET);
    guardo = fwrite(&regAux,sizeof(Usuario),1,p);
    cout<<"--------- "<<guardo;
    getch();
    if(guardo==1){
        msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
        fclose(p);
        return;
    }
    else if(guardo!=1){
        msj("Modificacion fallida",WHITE,RED,130,TEXT_LEFT);
        fclose(p);
        return;
    }
}

bool rangoId(int id){

    if(id<=0 || id >= 9999){
    return false;
    }else{
    return true;
    }
}

int buscarID(int id){

    int contador=0;
    Usuario reg;
    FILE *p;

    p = fopen(FILE_USUARIOS,"rb");

    if(p==NULL){
        return -1;///codigo de error de que no halló el archivo.
    }

    while(fread(&reg, sizeof(Usuario),1, p)==1){
        if(reg.id == id){
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -2;///codigo de error de usuario inexistente.
}

Usuario leerUsuario(int pos){
    Usuario reg;
    FILE *p = fopen(FILE_USUARIOS, "rb");
    if (p == NULL){
        reg.id = 0;
        return reg;
    }
    if(pos == -1){
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
    p = fopen(FILE_USUARIOS,"rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }
    title("LISTAR USUARIOS",BLACK,CYAN);
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
            }else{cout<<"Estado: Inactivo"<<endl;}
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
    user = buscarID(idUsuario);
    //cout<<"Ubicacion: "<<user+1<<endl;
    //system("PAUSE");

    if(user>=0){
        p = fopen(FILE_USUARIOS,"rb");
        if(p==NULL)
        {
            msj("Error al abrir el archivo",WHITE,RED,29,TEXT_LEFT);
            getch();
            return;
        }
        fseek(p,sizeof(Usuario)*user,SEEK_SET);
        fread(&reg,sizeof(Usuario),1,p);
        mostrarReg(reg);
        fclose(p);
        system("PAUSE");
    }
    else if(user==-2){
        msj("ID Inexistente",WHITE,RED,29,TEXT_LEFT);
        system("PAUSE");
    }else{
        msj("Error al abrir el archivo",WHITE,RED,29,TEXT_LEFT);
        getch();
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
        cout<<"\nUsuario eliminado"<<endl<<endl;
        }
}

void eliminarUsuario(){

    FILE *p;
    Usuario regAux;
    bool guardo;
    int idUsuario, posicion;
    char opc;

    p = fopen(FILE_USUARIOS,"rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo\n";
        return;
    }

    cout << "Ingrese el ID:\t";
    cin >> idUsuario;
    posicion=buscarID(idUsuario);
    if(posicion<0)
    {
        cout << "\n Eliminacion fallida";
        fclose(p);
        system("pause");
        return;
    }
    cout<<"\nse va a eliminar el usuario con ID nro: "<<idUsuario<<endl;

    cout<<" continuar (S/N):"<<endl;
    cin>>opc;
    switch(opc){
        case 'S':  break;
        case 's':  break;
        case 'N': return; break;
        case 'n': return ; break;
        default: return; break;
    }
    regAux = leerUsuario(posicion);
    regAux.estado=false;

    fseek(p,sizeof(Usuario)*posicion,SEEK_SET);
    guardo = fwrite(&regAux,sizeof(Usuario),1,p);
    if(guardo==1)
    {
        cout << "\nUsuario eliminado con exito";
        fclose(p);
        system("pause");
        return;
    }
    else
    {
        cout << "\nEliminacion fallida";
        fclose(p);
        system("pause");
        return;
    }

}

bool validarNombresApellidos(char *nombres, int tam){

    int cadena = strlen(nombres), contEspacios=0;
    bool valorFinal = true;

    for(int i=0; i <= cadena; i++){
        if(nombres[i]==' '){
            contEspacios++;
        }
        if(isdigit(nombres[i])==true){
            return false;
        }
    }
    if(contEspacios>=2){
        return false;
    }
    return valorFinal;
}
