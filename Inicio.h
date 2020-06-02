#pragma once

#include "Juego.h"
#include "ETSIDI.H"

/*
La clase inicio se encargar de coordinar el pang. La enumeracion de Estado permite controlar
a qu� pantalla del programa se quiere ir. 
En primer lugar se imprime por pantalla el men� completo, dejando a eleccion del jugador el modo de juego:
jugador contra jugador o jugador contra m�quina. Adem�s tendr� otras opciones como imrpimir las reglas por pantalla 
o silenciar la m�sica. 
El coordinador de pang esta constantemente controlando el n�mero de fichas de cada jugador para cambiar el modo
de juego inst�ntanemente a FINJ1 o FINJ2 en funci�n del perdedor. En ese instante finaliza la partida. 
*/


class Inicio
{
public:
	Inicio();
	virtual ~Inicio();
	void tecla(unsigned char key);
	void dibuja();
	void Raton(int, int, int, int);
	void RotarOjo();
	void Mueve();

protected:
	Juego Juego;
	enum Estado { INICIO, JUGVSMAQ, JUGVSJUG, FINJ1,FINJ2, REGLAS };
	Estado estado;
	int contador;
};
