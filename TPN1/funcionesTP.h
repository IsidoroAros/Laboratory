#ifndef FUNCIONESTP_H_INCLUDED
#define FUNCIONESTP_H_INCLUDED


///------------------- STRUCTS -------------------

struct Fecha{

	int dia;
	int mes;
    int anio;

};

struct Usuario{

    int id;
    char nombres[50];
    char apellidos[50];
    Fecha fecha;
    float altura;
    float peso;
    char perfAct;
    bool aptoMedico;
    bool estado;

};

///------------------- FUNCIONES -------------------

bool validarFecha( int dia, int mes, int anio); // Función que valida una fecha:
Usuario cargarUsuario();
void guardarUsuario();
void modificarUsuario();
int buscarID();
Usuario leer_usuario(int pos);
void listarUsuariosActivos();

#endif // FUNCIONESTP_H_INCLUDED
