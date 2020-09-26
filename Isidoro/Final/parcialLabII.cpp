#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "rutinas.h"
#include "usuarios.h"
#include "menus.h"
#include "fechas.h"
#include "ui.h"
#include "rlutil.h"
#include "modeloParcial.h"
#include "configuracion.h"
#include "parcialLabII.h"

using namespace rlutil;
using namespace std;


void entrenamientoMasCalorias(){
///1) A partir de un IDUsuario que se ingresa por teclado, listar el entrenamiento de mayor cantidad de calorías y la fecha en que las registró.
///Si hay dos registro con misma cantidad, mostrar el primero de ellos.

    Rutina registro;
    FILE *p;
    Rutina *vecEntrenamientos;
    int idAux,cantRegis;
    int guardo;
    float maxCalorias=0;
    Fecha fechaAux;

    title("Entrenamiento con máximas calorías quemadas");
    gotoxy(1,3);cout <<"Ingrese ID Usuario:\t";
    cin >> idAux;

            while(buscarID(idAux) == -2){
                msj("ID inexistente",WHITE,RED,29,TEXT_LEFT);
                cls();
                title("NUEVA RUTINA");
                gotoxy(1,3);cout << "Ingrese otro ID:\t";
                fflush(stdin);
                cin >> idAux;
            }

		p=fopen("archivos/Entrenamientos.dat","rb");
			if(p==NULL){
				cout << "Error al abrir el archivo \n";
				return;
			}

			cantRegis = contarRutinas();
			vecEntrenamientos = (Rutina *) malloc(cantRegis*sizeof(Rutina));
				        if(vecEntrenamientos==NULL){
                msj("No hay espacio en memoria",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
			}
			guardo = fread(vecEntrenamientos,sizeof(Rutina),cantRegis,p);
            if(guardo!=cantRegis){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(p);
                return;
            }

            fclose(p);

				for(int i=0;i<cantRegis;i++){
					if(vecEntrenamientos[i].idUsuario == idAux && vecEntrenamientos[i].calorias > maxCalorias){
						maxCalorias = vecEntrenamientos[i].calorias;
						fechaAux = vecEntrenamientos[i].fechaRutina;
					}
				}

                free(vecEntrenamientos);

				cout << "Para el usuario:\t" << idAux << endl;
                cout << "Las maximas calorias quemadas fueron:\t" << maxCalorias << endl;
                cout << "En el dia:\t" << fechaAux.dia << "/" << fechaAux.mes << "/" << fechaAux.anio << endl;

                getch();
                return;
}

char perfilUsuario(int idBusca){

	FILE *u;
	char perfilActAux;
	Usuario regAux;

			u=fopen("archivos/Usuarios.dat","rb");
			if(u==NULL){
				cout << "Error al abrir el archivo usuarios \n";
				fclose(u);
				return 'X';
			}

			while(fread(&regAux,sizeof(Usuario),1,u)==1){
                if(regAux.id == idBusca){
					perfilActAux = regAux.perfAct;
					fclose(u);
					return perfilActAux;
                }
			}
			cout << "No hubo coincidencias\n\n";
			fclose(u);
			return 'X';

}

void PuntoB(){

	FILE *p;
	const int actividades = 5;
	int vecRutina[actividades], guardo,cantRegis;
	Rutina *vecEntrenamientos;
	const int filas=5, columnas=3;
    int matAct[filas][columnas]={0}, idAux, actAux;
    char caracterAux;

		p=fopen("archivos/Entrenamientos.dat","rb");
			if(p==NULL){
				cout << "Error al abrir el archivo entrenamientos \n";
				return;
			}

			cantRegis = contarRutinas();
			vecEntrenamientos = (Rutina*) malloc(cantRegis*sizeof(Rutina));
				        if(vecEntrenamientos==NULL){
                msj("No hay espacio en memoria rutinas",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
					}

			guardo = fread(vecEntrenamientos,sizeof(Rutina),cantRegis,p);
            if(guardo!=cantRegis){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(p);
                return;
            }

            for(int i=0;i<=cantRegis;i++){

				idAux = vecEntrenamientos[i].idUsuario;
                actAux = vecEntrenamientos[i].actividad;
                caracterAux = perfilUsuario(idAux);

                //cout << "Caracter auxiliar N:\t" << i+1 << "\t\t" << caracterAux << endl;

                switch(caracterAux){
					case 'A':
                        matAct[actAux-1][0]++;
					break;
					case 'B':
                        matAct[actAux-1][1]++;
					break;
					case 'C':
                        matAct[actAux-1][2]++;
					break;

                }

            }
			 cout << "\t\tA\t\tB\t\tC\t\t" << endl;
             cout << endl;
            for(int x=0;x<filas;x++){
				cout << x+1 << "\t\t";
				for(int z=0;z<columnas;z++){
					cout << matAct[x][z] <<"\t\t";
						}
					cout << endl;
				}
					system("pause");
					cout << endl;
				free(vecEntrenamientos);
				return;
}

/*void actividadPorPerfil(){

        FILE *p, *u;
        const int filas=5, columnas=3;
        int matAct[filas][columnas]={0};
        Rutina regAux, *vecEntrenamientos;
        Usuario *vecUsuarios;
		int idAux,cantRegis, cantRegisUser;
		int guardo, guardoUser;

			p=fopen("archivos/Entrenamientos.dat","rb");
			if(p==NULL){
				cout << "Error al abrir el archivo entrenamientos \n";
				return;
			}
			u=fopen("archivos/Usuarios.dat","rb");
			if(u==NULL){
				cout << "Error al abrir el archivo usuarios \n";
				return;
			}
			/// Crear vector rutinas
			cantRegis = contarRutinas();
			vecEntrenamientos = (Rutina *) malloc(cantRegis*sizeof(Rutina));
				        if(vecEntrenamientos==NULL){
                msj("No hay espacio en memoria rutinas",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
			}
			guardo = fread(vecEntrenamientos,sizeof(Rutina),cantRegis,p);
            if(guardo!=cantRegis){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(p);
                return;
            }
            /// Crear vector usuarios
            cantRegisUser = contarRegistro();
			vecUsuarios = (Usuario *) malloc(cantRegisUser*sizeof(Usuario));
				        if(vecUsuarios==NULL){
                msj("No hay espacio en memoria usuarios",WHITE,RED,29,TEXT_LEFT);
                cls();
                return;
			}
			guardoUser = fread(vecUsuarios,sizeof(Usuario),cantRegisUser,u);
            if(guardoUser!=cantRegisUser){
                msj("Error al guardar registros",WHITE,RED,29,TEXT_LEFT);
                cls();
                fclose(u);
                return;
            }

            fclose(p);
            fclose(u);


				for(int i=0;i<cantRegis;i++){
				 for(int j=0;j<filas;j++){
                    cout << "Vector entrenamiento en\t" << i+1 << "\t"<< vecEntrenamientos[i].actividad;
					cout << endl;
					cout << "Vector usuarios en\t" << j+1<< "\t" << vecUsuarios[j].perfAct;
					cout << endl;
					cout << endl;

                   switch(vecEntrenamientos[i].actividad){
					case 1:
						for(int j=0;j<cantRegisUser;j++){
							if(vecUsuarios[j].perfAct=='A'){
								matAct[vecEntrenamientos[j].actividad][0]++;
							}else if(vecUsuarios[j].perfAct=='B'){
								matAct[vecEntrenamientos[j].actividad][1]++;
							}else if(vecUsuarios[j].perfAct=='C'){
								matAct[vecEntrenamientos[j].actividad][2]++;
							}
						}
					break;
                    case 2:
						for(int j=0;j<cantRegisUser;j++){
							if(vecUsuarios[j].perfAct=='A'){
								matAct[vecEntrenamientos[j].actividad][0]++;
							}else if(vecUsuarios[j].perfAct=='B'){
								matAct[vecEntrenamientos[j].actividad][1]++;
							}else if(vecUsuarios[j].perfAct=='C'){
								matAct[vecEntrenamientos[j].actividad][2]++;
							}
						}
					break;
					case 3:
						for(int j=0;j<cantRegisUser;j++){
							if(vecUsuarios[j].perfAct=='A'){
								matAct[vecEntrenamientos[j].actividad][0]++;
							}else if(vecUsuarios[j].perfAct=='B'){
								matAct[vecEntrenamientos[j].actividad][1]++;
							}else if(vecUsuarios[j].perfAct=='C'){
								matAct[vecEntrenamientos[j].actividad][2]++;
							}
						}
					break;
					case 4:
						for(int j=0;j<cantRegisUser;j++){
							if(vecUsuarios[j].perfAct=='A'){
								matAct[vecEntrenamientos[j].actividad][0]++;
							}else if(vecUsuarios[j].perfAct=='B'){
								matAct[vecEntrenamientos[j].actividad][1]++;
							}else if(vecUsuarios[j].perfAct=='C'){
								matAct[vecEntrenamientos[j].actividad][2]++;
							}
						}
					break;
					case 5:
						for(int j=0;j<cantRegisUser;j++){
							if(vecUsuarios[j].perfAct=='A'){
								matAct[vecEntrenamientos[j].actividad][0]++;
							}else if(vecUsuarios[j].perfAct=='B'){
								matAct[vecEntrenamientos[j].actividad][1]++;
							}else if(vecUsuarios[j].perfAct=='C'){
								matAct[vecEntrenamientos[j].actividad][2]++;
							}
						}
					break;
                    }
				 }
            }

             cout << "\t\tA\t\tB\t\tC\t\t" << endl;
             cout << endl;
            for(int x=0;x<filas;x++){
				cout << x+1 << "\t\t";
				for(int z=0;z<columnas;z++){
					cout << matAct[x][z] <<"\t\t";
						}
					cout << endl;
                    }
					cout << endl;

                free(vecEntrenamientos);
                free(vecUsuarios);

                getch();
                return;
}*/

