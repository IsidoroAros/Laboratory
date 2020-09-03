#include <iostream>
#include <cstdio.h>
#include "funcionesTP.h"

using namespace std;


bool validarFecha( int dia, int mes, int anio){

 // Precondici�n: Se han de recibir tres par�metros, todos ellos de tipo entero.
 // Poscondici�n: Se devolver� un 0/false o un 1/true.

 bool fec = 0;

 if( mes >= 1 && mes <= 12 ){

 switch( mes ){

 case 1: case 3: case 5: case 7: case 8: case 10: case 12:
 if( dia >= 1 && dia <= 31 ){
 fec = true;
 }
 break;


 case 4: case 6: case 9: case 11:
 if( dia >= 1 && dia <= 30 ){
 fec = true;
 }
 break;


 case 2:
 //Si el a�o es bisiesto +1 d�a.
 if( (anio%4 == 0)   &&   (anio%100 != 0)   ||   (anio%400 == 0) ){
 if( dia >= 1 && dia <= 29 ){
 fec = true;
 }
 }
 else{
 if( dia >= 1 && dia <= 28 ){
fec = true;
 }
 }
 break;

 }

 }

 return fec;
 }

Usuario cargarUsuario(){

	int dia,mes,anio;
	Usuario registro;

    cout << "Ingrese ID:\t";
    cin >> registro.id;
    /// chequear si el usuario ya existe buscarregistro();
    cout << "Nombre:\t";
    cin.ignore();
    cin.getline(registro.nombres,50,'\n');
    cout << "Apellido:\t";
    cin.ignore();
    cin.getline(registro.apellidos,50,'\n');
	cout << "Ingrese fecha de nacimiento:\t";
	cin >> dia >> mes >> anio;
	while(validarFecha(dia,mes,anio)==0){
        cout << "Fecha invalida, reingrese:\t";
        cin >> dia;
        cin >> mes;
        cin >> anio;
	}
	registro.fecha.dia = dia;
	registro.fecha.mes = mes;
	registro.fecha.anio = anio;

	cout << "Altura:\t";
	cin >> registro.altura;
	cout << "Peso:\t";
	cin >> registro.altura;
	cout << "Perfil de actividad:\t";
	cin >> registro.perfAct;
	cout << "�Tiene apto medico?\t";
	cin >> registro.aptoMedico;
	registro.estado = true;

	return registro;

 }


