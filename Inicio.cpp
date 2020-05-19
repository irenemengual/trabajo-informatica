#include "Inicio.h"


Inicio::Inicio()
{
	estado = INICIO;
	contador = 0; 
}

Inicio::~Inicio()
{
}

void Inicio::tecla(unsigned char key)
{
	if (key == 'c') ETSIDI::stopMusica();
	//if (key == 'c') ETSIDI::stopMusica();
	if (estado == INICIO)
	{
		if (key == '1')
		{
			Juego.Inicializa();
			Juego.getJuego1();
		}
		if (key == '2')
		{
			Juego.Inicializa();
			estado = JUEGO;
			Juego.getJuego2();
		}
		if (key == 'r' || key == 'R')
		{
			estado = REGLAS;
		}
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}
	Juego.Tecla(key);

}

void Inicio::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menufinal2.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		/*ETSIDI::setTextColor(0.64f, 0.16f, 0.16f); //r g b //no se por que no se dibuja marrón, amarillo :/
		ETSIDI::setFont("fuentes/Brush.otf", 45);
		ETSIDI::printxy("Juego de las Damas", -10, 14);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pulsa S (Start)", -12, 20);
		ETSIDI::printxy("Pulsa E (Exit)", -12, 22);
		ETSIDI::printxy("Pulsa R (Reglas)", -12, 24);//const char* txt ,int x,int y,int z=0
		ETSIDI::setFont("Orange Juice.otf", 20);
		ETSIDI::setTextColor(0.7f, 0.1f, 0.1f); //r g b
		ETSIDI::printxy("IRENE MENGUAL MAHAVE", -1, 7);
		ETSIDI::printxy("IRENE MARTIN MAESTRO", -1, 6);
		ETSIDI::printxy("ALVARO MERODIO PARDO", -1, 5);
		ETSIDI::printxy("DAVID PATRIZI GARCIA", -1, 4);
		ETSIDI::printxy("IGNACIO MAYORAL SANCHEZ", -1, 3);*/
	}
	else if (estado == JUEGO)
	{
		Juego.Dibuja();
		
	}
	else if (estado == REGLAS) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reglas.png").id);
		//dibujo del plano donde está la foto
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-15, -3.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(15, -3.5, -0.1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-15, 20, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}

void Inicio::Raton(int button, int state, int x, int y)
{
	Juego.Raton(button, state, x, y);
}

void Inicio::Mueve() {
	if (contador < 100 && estado == JUEGO) {
		Juego.Mueve();
		contador++;
	}
	else Juego.Para();
}