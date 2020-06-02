#pragma once

#include "Juego.h"
#include "ETSIDI.H"

/*
La clase inicio se encargar de coordinar el pang. La enumeracion de Estado permite controlar
a qué pantalla del programa se quiere ir. 
En primer lugar se imprime por pantalla el menú completo, dejando a eleccion del jugador el modo de juego:
jugador contra jugador o jugador contra máquina. Además tendrá otras opciones como imrpimir las reglas por pantalla 
o silenciar la música. 
El coordinador de pang esta constantemente controlando el número de fichas de cada jugador para cambiar el modo
de juego instántanemente a FINJ1 o FINJ2 en función del perdedor. En ese instante finaliza la partida. 
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
