#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Usuario{
    int id;
    char apellido[50];
    char nombre[50];
    char genero;
    Fecha fechaNac;
    bool estado;
};

Usuario cargarUsuario();
bool guardarUsuario(Usuario);
int buscarUsuario(int);
void  mostrarUsuario(Usuario, bool);
void  listarUsuario(bool);
int  cantidadUsuarios();
Usuario leer_usuario(int pos);

#endif // USUARIO_H_INCLUDED
