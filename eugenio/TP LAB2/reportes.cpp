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
        CopyFile("archivos/Entrenamientos.dat", "archivos/copia/EntrenamientosBkp.dat", TRUE);        CopyFile("archivos/usuarios.dat", "archivos/copia/usuariosBkp.dat", TRUE);
        cout<<"\n\t\t\tse Realizo la copia de seguridad al directorio COPIA: "<<endl;
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
        CopyFile("archivos/Entrenamientos.dat", "archivos/copia/EntrenamientosBkp.dat", TRUE);        CopyFile("archivos/usuarios.dat", "archivos/copia/usuariosBkp.dat", TRUE);
        cout<<"\n\t\t\tse Realizo la restauracion  de  la copia de seguridad al directorio ARCHIVOS: "<<endl;
        system("PAUSE");
      }else{
          menu();
      }

        }
