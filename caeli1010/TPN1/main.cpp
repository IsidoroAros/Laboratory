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
void ValidarVariable(char *numero,int);

int main(){

	/*CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows); *//// para chequear el alto y ancho de consola
	menu();
   /* char numero [10];
     cout<<" Nombre  :"  ;
    cin.getline(numero,10);
	ValidarVariable(numero,10);*/
return 0;
}


void ValidarVariable(char numero [], int tam){
    int no_vacio = 0 , contador = 0;
    no_vacio = strlen (numero);
    while (no_vacio == 0){
      cout<<"Campo vacio, ingrese un nombre  :"  ;
        cin.getline(numero, tam);
         no_vacio = strlen (numero);
         }
    { if (no_vacio != 0)cout<<"Campo completo ";
}
}
