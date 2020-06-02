#pragma once
#include "math.h"
#include "glut.h"
class Ficha
{
private:
	float x;
	float y;
	bool marca;
	bool next;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:
	Ficha();
	void Dibuja();

	//set
	void setPosicion(float ix, float iy);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetActiva();
	void SetDesactiva();
	void SetOcupada(bool o) { ocupada = o; }
	void SetMarca(bool o) { marca = o; }
	void SetNext(bool o) { next = o; }

	//get
	bool GetOcupada() { return ocupada; };
	bool GetMarca() { return marca; };
	bool GetNext() { return next; };
	int GetPosicionX();

	bool ocupada;


};

