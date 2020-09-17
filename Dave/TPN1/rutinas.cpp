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
void nuevaRutina()
{

    FILE *p;
    bool chequeo;
    Rutina registro;

    registro = cargarRutina(); /// recibo los datos de la funcion
    p = fopen("archivos/rutinas.dat","ab");
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return;
    }
    chequeo = fwrite(&registro, sizeof(Rutina),1,p);
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
Rutina cargarRutina()
{
    Rutina registro;
    Usuario regUsuario;

    registro.id= crearId();
    cout<<" id creado con el Nro :"<<registro.id<<endl<<endl;
    cout <<"Ingrese ID Usuario : " ;
    cin >> registro.idUsuario;
    while(buscarID(registro.idUsuario) == -2){
             msj("ID inexistente",WHITE,RED,29,TEXT_LEFT);

        cls();
        title("NUEVA RUTINA");
        gotoxy(1,2);cout << "Ingrese otro ID:\t";
        fflush(stdin);
        cin >> registro.idUsuario;
    }

     regUsuario=leerUsuario(buscarID(registro.idUsuario));
     if (regUsuario.estado == true) {
         registro.fechaRutina.dia = 10;
         registro.fechaRutina.mes = 03;
         registro.fechaRutina.anio = 2020;
         registro.actividad = 1;
         registro.calorias = 125;
         registro.tiempo = 40;

         return registro;
       
    }else{                      
          msj("Usuario de baja", WHITE, RED, 29, TEXT_LEFT);
          return;
         }
}

int crearId()
{
    int bytes, cant;
    FILE *p = fopen("archivos/rutinas.dat", "rb");
    if (p == NULL)
    {
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
    p = fopen("archivos/rutinas.dat","rb+");
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

