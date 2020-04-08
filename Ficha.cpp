#include "Ficha.h"
void Ficha::Dibuja() {
	 glBegin(GL_POLYGON);
	 glColor3ub(255, 0, 0);
	glVertex2f(0., 0.);
for (int count = 0; count <= 360; count++)
glVertex2f(0 + sin((float)count) * 0.5, 0 + cos((float)count) * 0.5);
glEnd();
};