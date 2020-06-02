#pragma once
#include "Tablero.h"
#include "Casilla.h"
#include "Vector2D.h"
#include "ETSIDI.H"
#include "Reina.h"
#include <math.h>
#include <stdio.h>
#include "glut.h"
#include <iostream>


class Juego
{	
	Tablero tablero;
	Ficha fichaJ1[8][8];
	Ficha fichaJ2[8][8];
	Reina reinaJ1[8][8];
	Reina reinaJ2[8][8];
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Vector2D vector;
	Vector2D aux; 
	Vector2D aux2;
	Vector2D v;
	enum Pasos { PrimPaso, SegPaso, SegPasoReina};
	Pasos paso;
	enum Turnos { TurnoUno, TurnoDos, TurnoPC, TurnoTres };
	Turnos turno;

	enum Movimientos { NADA, AD, AI, DD, DI };
	Movimientos movimiento;

	int contadorPosibilidadesJ1;
	int contadorPosibilidadesJ2;
	bool ComidaVariasJ1;
	bool ComidaVariasJ2;
	int tipo; //tipo de juego (1/2)
	int contadorJ1;
	int contadorJ2;

public: 	
	void Tecla(unsigned char key);
	void Raton(int button, int state, int x, int y);
	void Inicializa(int t); //adquiere una variable de juego al inicializarse
	
	void RotarOjo();
	void Para();
	void Dibuja();
	bool Ocupada(Ficha fichas[8][8], Vector2D v); //comprueba si esta ocupada lleva bool
	bool Ocupada(Vector2D v);
	bool Ocupada(Reina reina[8][8], Vector2D v);
	void Jugadas(); //va controlando los turnos
	void MuestraPosibilidades();
	bool FichaCorrecta(Ficha f[8][8] , Vector2D v);
	bool FichaNextCorrecta(Ficha f[8][8], Vector2D v);
	void MovimientoJ1();
	void MovimientoJ2();
	void MovimientoPC();
	void MovimientoReina();
	void MalaComidaJ1();
	void MalaComidaJ2();
	bool Existe(Vector2D v);

	bool CompruebaPC();

	bool Compruebareina();
	void MovimientoR1(Vector2D m);
	void MovimientoR2(Vector2D m);
	void DesactivaPosibilidadesJ2();
	void DesactivaPosibilidadesJ1();


	//void contador(int numFichas);
	int contador(Ficha jugad[8][8], Reina jugad_[8][8]);
	int GetContadorJ1() { return contadorJ1; };
	int GetContadorJ2() { return contadorJ2; };

	

};

