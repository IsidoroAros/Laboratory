#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
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

const char *FILE_RUTINAS = "archivos/rutinas.dat";


void guardarRutina(){

    FILE *p;
    bool chequeo;
    Rutina registro;

    registro = cargarRutina(); /// recibo los datos de la funcion
    p = fopen(FILE_RUTINAS,"ab");
    if(p==NULL){
        cout << "Error al abrir el archivo \n";
        return;
    }
    chequeo = fwrite(&registro, sizeof(Rutina),1,p);
    if(chequeo==1){
        cout << "El registro se guardo correctamente \n\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
    else{
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        system("cls");
        return;
    }
}
Rutina cargarRutina(){

    Rutina registro;
    Usuario regUsuario;
    int dia, mes,anio;

    registro.id = crearId();
    title("NUEVA RUTINA");
    cout <<"Ingrese ID Usuario : " ;
    cin >> registro.idUsuario;
    while(buscarID(registro.idUsuario) == -2){
        msj("ID inexistente",WHITE,RED,29,TEXT_LEFT);
        cls();
        title("NUEVA RUTINA");
        gotoxy(1,3);cout << "Ingrese otro ID:\t";
        fflush(stdin);
        cin >> registro.idUsuario;
    } /// registra que exista el usuario, sino retorna -2

     regUsuario=leerUsuario(buscarID(registro.idUsuario));

     while(regUsuario.estado==false){
        cls();
        msj("ID dado de baja",WHITE,RED,29,TEXT_LEFT);
        gotoxy(1,3);cout << "Ingrese otro ID:\t";
        cin >> registro.idUsuario;
        regUsuario=leerUsuario(buscarID(registro.idUsuario));
     }

     cout << "Ingrese fecha de la rutina:\t";
     cin >> dia >> mes >> anio;
     while(validarEdad(dia, mes, anio)==false){
         msj("Fecha invalida",WHITE,RED,29,TEXT_LEFT);
         cls();
         title("NUEVA RUTINA");
         fflush(stdin);
         gotoxy(1,3);cout << "Reingrese fecha\t";
         cin >> dia >> mes >> anio;
     } /// falta comparación de fecha del dia de hoy

        registro.fechaRutina.dia = dia;
        registro.fechaRutina.mes = mes;
        registro.fechaRutina.anio = anio;

        cout << "Ingrese actividad:\t";
        cin >> registro.actividad;

        while(registro.actividad < 0 || registro.actividad > 5){

         msj("Actividad fuera de rango",WHITE,RED,29,TEXT_LEFT);
         cls();
         title("NUEVA RUTINA");
         fflush(stdin);
         gotoxy(1,3);cout << "Reingrese actividad:\t";
         cin >> registro.actividad;
        }/// validacion del rango de la actividad
                if(regUsuario.aptoMedico == 0 || regUsuario.aptoMedico == false){
                    while(registro.actividad == 4 || registro.actividad == 5){
                     msj("No posee apto medico",WHITE,RED,29,TEXT_LEFT);
                     cls();
                     title("NUEVA RUTINA");
                     fflush(stdin);
                     gotoxy(1,3);cout << "Reingrese actividad:\t";
                     cin >> registro.actividad;
                    }
                }/// validacion actividad / apto medico

        cout << "Calorias quemadas:\t";
        cin >> registro.calorias;

            while(registro.calorias < 0){
                     msj("Calorias negativas",WHITE,RED,29,TEXT_LEFT);
                     cls();
                     title("NUEVA RUTINA");
                     fflush(stdin);
                     gotoxy(1,3);cout << "Reingrese calorias:\t";
                     cin >> registro.calorias;
            }

        cout << "Tiempo:\t";
        cin >> registro.tiempo;

            while(registro.tiempo < 0){
                     msj("Tiempo invalido",WHITE,RED,29,TEXT_LEFT);
                     cls();
                     title("NUEVA RUTINA");
                     fflush(stdin);
                     gotoxy(1,3);cout << "Reingrese tiempo:\t";
                     cin >> registro.tiempo;
            }

         return registro;

}

int crearId(){
    int bytes, cant;
    FILE *p = fopen(FILE_RUTINAS, "rb");
    if (p == NULL){
        return 1;///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Rutina);
    return cant+1;

}
void listarRutinas(){

    FILE *p;
    Rutina reg;
    p = fopen(FILE_RUTINAS,"rb+");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }
    title("LISTAR RUTINAS",BLACK,CYAN);
    while(fread(&reg,sizeof(Rutina),1,p)==1)
    {
            cout<<"\n\nID: "<<reg.id<<endl;
            cout<<"ID de Usuario : "<<reg.idUsuario<<endl;
            cout<<"Fecha :"<<reg.fechaRutina.dia<<" / " <<reg.fechaRutina.mes<<" / "<<reg.fechaRutina.anio<<endl;
            cout<<"Actividad : "<<reg.actividad<<endl;
            cout<<"Calorias : "<<reg.calorias<<endl;
            cout<<"Tiempo : "<<reg.tiempo<<endl;

    }
    fclose(p);
    getch();

}

int buscarIDRutina(int id){

    int contador=0;
    Rutina reg;
    FILE *p;

    p = fopen(FILE_RUTINAS,"rb");

    if(p==NULL){
        return -1;///codigo de error de que no halló el archivo.
    }

    while(fread(&reg, sizeof(Rutina),1, p)==1){
        if(reg.id == id){
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -2;///codigo de error de rutina inexistente.

}

void mostrarRutina(Rutina reg){

            cout<<"\n\nID: "<<reg.id<<endl;
            cout<<"ID de Usuario : "<<reg.idUsuario<<endl;
            cout<<"Fecha :"<<reg.fechaRutina.dia<<" / " <<reg.fechaRutina.mes<<" / "<<reg.fechaRutina.anio<<endl;
            cout<<"Actividad : "<<reg.actividad<<endl;
            cout<<"Calorias : "<<reg.calorias<<endl;
            cout<<"Tiempo : "<<reg.tiempo<<endl;

}

void listarRutinaXId(){
    int pos;
    FILE *p;
    int idRutina;
    Rutina reg;

    cout << "Ingrese el ID:\t";
    cin >> idRutina;
    pos = buscarIDRutina(idRutina);


    if(pos>=0){
        p = fopen(FILE_RUTINAS,"rb");
        if(p==NULL){
            msj("Error al abrir el archivo",WHITE,RED,29,TEXT_LEFT);
            getch();
            return;
        }
        fseek(p,sizeof(Rutina)*pos,SEEK_SET);
        fread(&reg,sizeof(Rutina),1,p);
        mostrarRutina(reg);
        fclose(p);
        system("PAUSE");

    }else if(pos==-2){
        msj("ID Inexistente",WHITE,RED,29,TEXT_LEFT);
        system("PAUSE");
    }else{
        msj("Error al abrir el archivo",WHITE,RED,29,TEXT_LEFT);
        getch();
        }
}

