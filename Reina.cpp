#include "Reina.h"

Reina::Reina() {
	x = y = 0;
	rojo = verde = azul = 1;
	ocupada = false;
	marca = false;

}

void Reina::Dibuja() {
	//cilindro
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(x, y, 0);
	gluCylinder(quadratic, 0.4f, 0.4f, 0.3f, 32, 32);
	glTranslatef(-x, -y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	//tapa del cilindro
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
	glVertex3f(x, y, 0.3f);
	for (int count = 0; count <= 360; count++)
		glVertex3f(x + sin((float)count) * 0.401, +y + cos((float)count) * 0.401, 0.3f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(240,200,166);
	glVertex3f(x, y, 0.315f);
	for (int count = 0; count <= 360; count++)
		glVertex3f(x + sin((float)count) * 0.15, +y + cos((float)count) * 0.15, 0.3f);
	glEnd();
	glEnable(GL_LIGHTING);



};
int Reina::GetPosicionX() {
	return  x;
}
void Reina::setPosicion(float ix, float iy) {
	x = ix;
	y = iy;
}

void Reina::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Reina::SetActiva() {
	ocupada = true;
};
void Reina::SetDesactiva() {
	ocupada = false;
}
