#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "rutinas.h"
#include "usuarios.h"
#include "menus.h"
#include "fechas.h"
#include "ui.h"
#include "rlutil.h"
#include "reportes.h"

using namespace rlutil;
using namespace std;
const char *FILE_RUTINAS2 = "archivos/Entrenamientos.dat";

void puntoA(){///LISTA ENTRENAMIENTOS CON DURACION DE TIEMPO POR ENCIMA DEL PROMEDIO

    FILE *pFile;
    Rutina *vecRutina;
    Rutina reg;
    int registros=0, acuRutinas=0;
    float prom;

    ///---
    pFile=fopen(FILE_RUTINAS2,"rb");
    while(fread(&reg,sizeof(Rutina),1,pFile)==1){
        registros++;
        acuRutinas+=reg.tiempo;
    }
    fclose(pFile);
    prom=((float) acuRutinas/registros);

    cout<<"\nPROMEDIO: "<<prom<<endl<<endl;
    ///---
    vecRutina=(Rutina*)malloc(sizeof(Rutina)*registros);
    pFile=fopen(FILE_RUTINAS2,"rb");
    fread(vecRutina,sizeof(Rutina),registros,pFile);
    for(int i=0;i<registros;i++){
        if(vecRutina[i].tiempo>=prom){
            mostrarRutina(vecRutina[i]);
        }
    }
    anykey();
    free(vecRutina);

}

void puntoB(){
///A partir de un ID de usuario que se ingrese por teclado listar Apellido,
///Nombres y cantidad de entrenamientos realizados en el año 2020.

Usuario regAux;
int idUsuario,anio,cantRutinas;

cout<<"Ingresar id a buscar: ";
cin>>idUsuario;
cout<<"Ingresar anio de la busqueda: ";
cin>>anio;

cantRutinas=cantRutinasUsuario(idUsuario,anio);

regAux=leerUsuario(buscarID(idUsuario));
cls();
cout<<regAux.nombres<<" "<<regAux.apellidos<<endl;
cout<<"Cantidad de Rutinas: "<<cantRutinas<<endl;
getch();

}





///---------------------------------------------------U CAN'T TOUCH THIS-----------
void creditos(){

    title("LISTAR PROGRAMADORES",BLACK,CYAN);

           cout<<endl<<endl;
            cout<<"\n\t\t\tELIZABETH CAROLINA AYALA"<<endl;
            cout<<"\n\t\t\tISIDORO AROSTEGUI"<<endl;
            cout<<"\n\t\t\tDAVID QUINTEROS"<<endl;
            cout<<"\n\t\t\tEUGENIO AREVALO"<<endl;
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
    system("PAUSE");

}

void hacerCopia() {
    int opcion;
      title("COPIA DE SEGURIDAD DE ARCHIVOS",BLACK,CYAN);
       gotoxy(1,3);
      cout<<"1. REALIZAR COPIA"<<endl;
      cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
      cin>>opcion;
      if(opcion==1){
        CopyFile("archivos/Entrenamientos.dat", "archivos/Entrenamientos.bkp", TRUE);        CopyFile("archivos/usuarios.dat", "archivos/usuarios.bkp", TRUE);
        cout<<"\n\t\t\tse Realizo la copia de seguridad correctamente"<<endl;
        system("PAUSE");
      }else{
          menu();
      }
}

void  restaurarCopia(){
        int opcion;
      title("RESTAURAR COPIA DE SEGURIDAD DE COPIA A ARCHIVOS",BLACK,RED);
       gotoxy(1,3);
      cout<<"1. RESTAURAR COPIA"<<endl;
      cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
      cin>>opcion;
      if(opcion==1){
        CopyFile( "archivos/Entrenamientos.bkp", "archivos/Entrenamientos.dat", TRUE);        CopyFile("archivos/usuarios.bkp", "archivos/usuarios.dat",  TRUE);
        cout<<"\n\t\t\tse realizo la restauracion  de  la copia de seguridad correctamente"<<endl;
        system("PAUSE");
      }else{
          menu();
      }

        }
