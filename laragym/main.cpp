z#include <iostream>
using namespace std;
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "usuario.h"
#include "rutinas.h"
#include "menu.h"
const int TOPE_MIN= 13;

Fecha hoy();
void validarEdad(int, int, int );
int main()
{

    int anio, mes,dia;
    bool fechaInvalida=true;
    bool validaEdad=false;
    //int edad;
    cin>> dia;
    cin>> mes;
    cin>> anio;

    validarEdad( dia,  mes, anio);

    while(fechaInvalida==true)
    {
        if(valFecha( dia, mes,  anio)==0)
        {
            cout<<" fecha incorrecta vuelva a ingresar: ";
            cin>> dia;
            cin>> mes;
            cin>> anio;
        }
        else if(valFecha( dia, mes,  anio)==1)
        {
            fechaInvalida=false;
        }
    }

    //menu();
    return 0;
}

void validarEdad(int  dia, int mes, int anio){
    int edad;
    Fecha fecha= hoy();

    if (fecha.mes > mes)
    {
        edad = fecha.anio - anio;
    }
    else if(fecha.mes == mes)
    {

        if (fecha.dia >= dia)
        {
            edad = fecha.anio - anio;
        }
    }
    else
    {
        edad  = (fecha.anio - 1) - anio;
    }

    if(edad>=13 && edad<90)
    {
        cout <<"La edad es correcta: " << endl;

    }
    else
    {
        cout <<"La edad es incorrecta: " << endl;
    }
}

Fecha hoy()
{
    Fecha reg;
    time_t  hoy = time(0);
    tm *time=localtime(&hoy);
    reg.anio=1900+ time->tm_year;
    reg.mes= 1 + time->tm_mon;
    reg.dia= time->tm_mday;
    return reg;
}
