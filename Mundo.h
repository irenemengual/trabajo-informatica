#include "Tablero.h"
class Mundo
{	
	Tablero tablero;
	float x_ojo;
	float y_ojo;
	float z_ojo;
public: 
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();

};
