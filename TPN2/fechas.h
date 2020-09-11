#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

///------------------- STRUCTS -------------------

struct Fecha{

	int dia;
	int mes;
    int anio;

};

///------------------- FUNCIONES -------------------

Fecha hoy();
bool validarEdad(int  dia, int mes, int anio);
bool validarFecha( int dia, int mes, int anio); /// Función que valida una fecha



#endif // FECHAS_H_INCLUDED
