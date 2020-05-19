#pragma once
#include <ETSIDI.h>
#include "glut.h"
class Casilla
{
private:
	float lado;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Casilla();
	void Dibuja();
	void setPosicion(float ix, float iy);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void Ilumina(unsigned char m);
};

