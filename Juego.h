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
	enum Turnos { TurnoUno, TurnoDos };
	Turnos turno;
	enum TipoJuego{juego1, juego2};
	TipoJuego tipojuego;

	int contadorPosibilidadesJ1;
	int contadorPosibilidadesJ2;
	bool ComidaVariasJ1;
	bool ComidaVariasJ2;

public: 	
	void Tecla(unsigned char key);
	void Raton(int button, int state, int x, int y);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Para();
	void Dibuja();
	bool Ocupada(Ficha fichas[8][8], Vector2D v); //comprueba si esta ocupada lleva bool
	bool Ocupada(Vector2D v);
	bool Ocupada(Reina reina[8][8], Vector2D v);
	void Jugadas(); //va controlando los turnos
	void MuestraPosibilidades();
	bool FichaCorrecta(Ficha f[8][8] , Vector2D v);
	void MovimientoJ1();
	void MovimientoJ2();
	void MovimientoReina();
	void MalaComidaJ1();
	void MalaComidaJ2();
	bool Existe(Vector2D v);
	bool Compruebareina1();
	void ReinaMengu(Vector2D m);
	void ReinaMengu2(Vector2D m);

	TipoJuego getJuego2() { return juego2; };
	TipoJuego getJuego1() { return juego1; };

};

