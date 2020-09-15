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

int contarRegistro();
void vectorIdsUsuarios();
void leerVector(int *vec, int cantidadRegistros);

int main(){

	menu();
    ///vectorIdsUsuarios();

return 0;
}

int contarRegistro(){

    FILE *p;
    int posiciones=0;
    Usuario reg;

    p = fopen("usuarios.dat", "rb");
        if(p==NULL){
            cout << "Error de archivo";
            return - 1 ;
        }
    while(fread(&reg,sizeof (Usuario),1,p)==1){
        posiciones++;
    }
      // cout<< posiciones;
    fclose(p);
   return posiciones;
}

void vectorIdsUsuarios(){

    FILE *p;
    Usuario registro;
    int fila_pos, cant_reg, i=0;
    int *idsUsuarios;

   cant_reg = contarRegistro();

    p = fopen("usuarios.dat", "rb");
        if(p==NULL){
            cout << "Error de archivo";
            return;
        }

    idsUsuarios =(int*) malloc(cant_reg*sizeof(int));
        if(idsUsuarios==NULL){
            cout << "No hay memoria disponible\n";
            return;
        }
        while(fread(&registro,sizeof (Usuario),1,p)==1){
            idsUsuarios[i] = registro.id;
            i++;

        }
        fclose(p);
        leerVector(idsUsuarios, cant_reg);
        free (idsUsuarios);
}

void leerVector(int *vec, int cantidadRegistros){

    for(int i=0;i<cantidadRegistros;i++){
        cout << "user: " << i+1 << " id: " << vec[i] << endl;
    }
    return;
}

