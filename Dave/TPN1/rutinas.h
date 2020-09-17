#ifndef RUTINAS_H_INCLUDED
#define RUTINAS_H_INCLUDED

#include "fechas.h"
 #include "funcionesTP.h"
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
void listarRutinas();
#endif // RUTINAS_H_INCLUDED
