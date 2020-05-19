#pragma once
#include "math.h"
#include "glut.h"
class Ficha
{
private:
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	


public:
	Ficha();
	void Dibuja();
	void setPosicion(float ix, float iy);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetActiva();
	void SetDesactiva();
	bool GetOcupada() { return ocupada; };
	int GetPosicionX();
	bool ocupada;
	bool marca;

};

