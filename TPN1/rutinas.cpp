#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include "funcionesTP.h"
#include "menus.h"
#include "fechas.h"
#include "rutinas.h"
using namespace std;
void nuevaRutina(){

    FILE *p;
    bool chequeo;
    Rutina registro;

    registro = cargarRutina(); /// recibo los datos de la funcion
    p = fopen("datos/rutinas.dat","ab");
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
    int dia,mes,anio, retornoId;
    Rutina registro;

    registro.id= crearId();
    cout<<" id creado con el Nro :"<<registro.id<<endl<<endl;
    registro.idUsuario=7945;
    registro.fechaRutina.dia=10;
    registro.fechaRutina.mes=03;
    registro.fechaRutina.anio=2020;
    registro.actividad=1;
    registro.calorias=125;
    registro.tiempo=40;

    return registro;
}
int crearId()
{
    int bytes, cant;
    FILE *p = fopen("datos/rutinas.dat", "rb");
    if (p == NULL)
    {
        return 1000;///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Rutina);
    return cant+1000;

}
