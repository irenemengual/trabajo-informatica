#include "Vector2D.h"
#include "math.h"
#include "glut.h"

Vector2D::Vector2D(int xv, int yv)
{
	i = xv;
	j = yv;
}
Vector2D::~Vector2D()
{

}

Vector2D Vector2D::restador() {
	Vector2D v;
	v.j = j - 1;
	v.i = i - 1;
	return v;
	
}
Vector2D Vector2D::sumador() {
	Vector2D v;
	v.j = j + 1;
	v.i = i + 1;
	return v; 

}

Vector2D Vector2D::CasillaSupDer() {
	Vector2D v;
	v.j = j + 1;
	v.i = i + 1;
	return v;
}

Vector2D Vector2D::CasillaDobleSupDer() {
	Vector2D v;
	v.j = j + 2;
	v.i = i + 2;
	return v;
}
Vector2D Vector2D::CasillaSupIzq() {
	Vector2D v;
	v.j = j - 1;
	v.i = i +1;
	return v;
}

Vector2D Vector2D::CasillaDobleSupIzq() {
	Vector2D v;
	v.j = j - 2;
	v.i = i + 2;
	return v;
}


Vector2D Vector2D::CasillaInfIzq() {
	Vector2D v;
	v.j = j - 1;
	v.i = i - 1;
	return v;
}

Vector2D Vector2D::CasillaDobleInfIzq() {
	Vector2D v;
	v.j = j - 2;
	v.i = i - 2;
	return v;
}

Vector2D Vector2D::CasillaInfDer() {
	Vector2D v;
	v.j = j + 1;
	v.i = i - 1;
	return v;
}

Vector2D Vector2D::CasillaDobleInfDer() {
	Vector2D v;
	v.j = j +2;
	v.i = i - 2;
	return v;
}