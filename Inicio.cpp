#include "Inicio.h"

Inicio::Inicio()
{
	//La variable estado se inicializa a INICIO de juego
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
			estado = JUGVSMAQ;
			Juego.Inicializa(estado);
		}
		if (key == '2')
		{
			estado = JUGVSJUG;
			Juego.Inicializa(estado);
		}
		if (key == 'r' || key == 'R')
		{
			estado = REGLAS;
		}
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}
	if (estado == REGLAS)
	{
		if (key == '1')
		{
			estado = JUGVSMAQ;
			Juego.Inicializa(estado);
		}
		if (key == '2')
		{
			estado = JUGVSJUG;
			Juego.Inicializa(estado);
		}
		if (key == 'e' || key == 'E')
		{
			exit(0);
		}
	}
	if (estado == FINJ1 || estado == FINJ2)
	{
		if (key == 'e' || key == 'E') {
			exit(0);
		}
	}	
	
	Juego.Tecla(key);

}

void Inicio::dibuja()
{
	//si el juego esta en modo INICIO se imprime por pantalla un menu
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

	}

	//si el juego esta en modo "activo", es decir, en JUGVSMAQ o JUGVSMAQ se dibuja en la pantalla el espacio
	else if  (estado == JUGVSMAQ || estado == JUGVSJUG)
	{
		Juego.Dibuja();
	}
	
	//si el juego esta en REGLAS se facilitan por pantalla las reglas del juego
	else if (estado == REGLAS) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
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

	//si el juego esta en FINJ1 o FINJ2 significa que uno de los jugadores ha perdido, se imprime por pantalla y finaliza el juego
	else if (estado == FINJ1)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu3.png").id);
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

		ETSIDI::setTextColor(150, 75, 0); //r g b
		ETSIDI::setFont("fuentes/Calibri.ttf", 60);
		ETSIDI::printxy("Victoria J1! ", -7, 14);
		ETSIDI::setTextColor(150, 75, 0); //r g b
		ETSIDI::setFont("fuentes/Calibri.ttf", 30);
		ETSIDI::printxy("Presione E para salir", -7, 10);

	}
	else if (estado == FINJ2)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/menu3.png").id);
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

		ETSIDI::setTextColor(150, 75, 0); //r g b
		ETSIDI::setFont("fuentes/Calibri.ttf", 60);
		ETSIDI::printxy("Victoria J2! ", -7, 14);
		ETSIDI::setTextColor(150, 75, 0); //r g b
		ETSIDI::setFont("fuentes/Calibri.ttf", 30);
		ETSIDI::printxy("Presione E para salir", -7, 10);
	}


}

void Inicio::Raton(int button, int state, int x, int y)
{
	Juego.Raton(button, state, x, y);
}

void Inicio::RotarOjo()
{
	if (contador < 100 && (estado == JUGVSMAQ || estado == JUGVSJUG)) {
		Juego.RotarOjo();
		contador++;
	}
	else Juego.Para();
}

void Inicio::Mueve()
{
	if (estado == JUGVSMAQ || estado == JUGVSJUG)
	{
		if ( Juego.GetContadorJ1() == 0)
		{
			estado = FINJ2;
		}
		if (Juego.GetContadorJ2() == 0)
		{
			estado = FINJ1;
		}
	}
}

