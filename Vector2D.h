#pragma once

class Vector2D
{
public: //atributos
	int i;
	int j;
public: //métodos
	 Vector2D(int xv = 0, int yv = 0);
	virtual ~Vector2D();
	Vector2D restador();
	Vector2D sumador();
	Vector2D CasillaSupDer();
	Vector2D CasillaSupIzq();
	Vector2D CasillaDobleSupDer();
	Vector2D CasillaDobleSupIzq();
	Vector2D CasillaInfDer();
	Vector2D CasillaInfIzq();
	Vector2D CasillaDobleInfDer();
	Vector2D CasillaDobleInfIzq();

};