#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include "funcionesTP.h"
#include "menus.h"
#include "fechas.h"
using namespace std;

Usuario cargarUsuario(){

    int dia,mes,anio, retornoId;
    Usuario registro;
    char apto, perf, nombre[50], apellido[50];

    cout << "Ingrese ID:\t";
    cin >> registro.id;
    while(buscarID(registro.id)!=-2 || (registro.id<0 || registro.id>9999)){
        cout << "ID erroneo, ingrese otro ID:\t";
        cin >> registro.id;
    } /// validacion id

    cin.ignore();
    cout << "Nombre:\t";
    cin.getline(nombre,50,'\n');
        while(validarNombresApellidos(nombre,50)==false){
                cout << "Nombre incorrecto, vuelva a ingresar:\t";
                cin.getline(nombre,50,'\n');
        } /// validacion nombre
    cout << "Apellido:\t";
    cin.getline(apellido,50,'\n');

        while(validarNombresApellidos(apellido,50)==false){
                cout << "Apellido incorrecto, vuelva a ingresar:\t";
                cin.getline(apellido,50,'\n');
        } /// validacion apellido

    cout << "Ingrese fecha de nacimiento:\t";
    cin >> dia >> mes >> anio;

    while(validarEdad(dia,mes,anio)==false){

        cout << "Fecha invalida, reingrese:\t";
        cin >> dia;
        cin >> mes;
        cin >> anio;

    } /// validacion fecha
    registro.fecha.dia = dia;
    registro.fecha.mes = mes;
    registro.fecha.anio = anio;

    cout << "Altura:\t";
    cin >> registro.altura;
    cout << "Peso:\t";
    cin >> registro.peso;
    cout << "Perfil de actividad:\t";
    cin >> perf;
        while(!(perf == 'A' || perf == 'a'
                || perf == 'B' || perf == 'b'
                || perf == 'C' || perf == 'c') ){
                fflush(stdin);
            cout << "INCORRECTO, perfil de actividad:\t";
            cin >>perf;
        }
        registro.perfAct=perf;
    cout << "¿Tiene apto medico?\t";
    cin >> apto;
        while(apto != 'S' || apto != 's' || apto != 'N' || apto != 'n'){
                fflush(stdin);
            cout << "INCORRECTO, ¿Tiene apto medico?\t";
            cin >> apto;
        }
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
    regAux = leerUsuario(posicion);
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

    p = fopen("usuarios.dat","rb");

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
    FILE *p = fopen("usuarios.dat", "rb");
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
        p = fopen("usuarios.dat","rb");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo\n";
            return;
        }
        fseek(p,sizeof(Usuario)*user,SEEK_SET);
        fread(&reg,sizeof(Usuario),1,p);
        mostrarReg(reg);
        fclose(p);
        system("PAUSE");
    }
    else if(user==-2){
        cout<<"ID inexistente\n";
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
        cout<<"\nUsuario eliminado"<<endl<<endl;
        }
}

void eliminarUsuario(){

    FILE *p;
    Usuario regAux;
    bool guardo;
    int idUsuario, posicion;
    char opc;

    p = fopen("usuarios.dat","rb+");
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
