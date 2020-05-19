#pragma once

#include "Juego.h"
#include "ETSIDI.H"

class Inicio
{
public:
	Inicio();
	virtual ~Inicio();
	void tecla(unsigned char key);
	void dibuja();
	void Raton(int, int, int, int);
	void Mueve();

protected:
	Juego Juego;
	enum Estado { INICIO, JUEGO, FIN, REGLAS };
	Estado estado;
	int contador;
};
