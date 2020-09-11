#ifndef RUTINAS_H_INCLUDED
#define RUTINAS_H_INCLUDED

#include "fechas.h"

struct Rutina{
    int id;
    int idUsuario;
    Fecha fechaRutina;
    int  actividad;
    float calorias;
    int tiempo;
};
//Autonum incrementa();
 void nuevaRutina();
 Rutina cargarRutina();
 int crearId();

#endif // RUTINAS_H_INCLUDED
