#include "Juego.h"

void Juego::Inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;
	paso =PrimPaso;
	turno = TurnoUno;
	contadorPosibilidadesJ1=contadorPosibilidadesJ2 = false;
	ComidaVariasJ1 = ComidaVariasJ2 = false; 
	//inicilaizo las reinas
	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			reinaJ1[j][i].setPosicion(j, i);
			reinaJ2[j][i].setPosicion(j, i);
		}
	}
	for (int i = 0; i < tablero.GetCasillas(); i++)
	{
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			reinaJ1[j][i].SetDesactiva();
			reinaJ1[j][i].SetColor(89, 46, 11);
			reinaJ2[j][i].SetDesactiva();
			reinaJ2[j][i].SetColor(185, 147, 90);
		}
	}

	//primera posicion de las piezas
	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			fichaJ1[j][i].setPosicion(j, i);
			fichaJ1[j][i].SetColor(89, 46, 11);
			fichaJ2[j][i].setPosicion(j, i);
			fichaJ2[j][i].SetColor(185, 147, 90);
		}
	}

	for (int i = 0; i < tablero.GetCasillas(); i++)
	{
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			if (i <= 2 && ((i + j) % 2 == 0))
			{
				fichaJ1[j][i].SetActiva();
			}
			else if (i >= 5 && ((i + j) % 2 == 0))
			{
				fichaJ2[j][i].SetActiva();
			}
		}
	}
}
bool Juego::Compruebareina1() {
	v.i = aux2.i;
	v.j = aux2.j;
	//va para atras izquierda
	for (int i = 0; v.i >= 0;i++) {
		v.i = v.i - 1;
		v.j = v.j - 1;
		if (Ocupada(fichaJ2, v)) {
			if (Ocupada(fichaJ2, v.CasillaInfIzq())==false){ return true; }
		}
		if (Ocupada(fichaJ1, v)) {
			if (Ocupada(fichaJ1, v.CasillaInfIzq()) == false) { return true; ; }
		}
	}
	//va para delante derecha
	v.i = aux2.i;
	v.j = aux2.j;
	for (int i = 0; v.i < tablero.GetCasillas();i++) {
		v.i = v.i + 1;
		v.j = v.j + 1;
		if (Ocupada(fichaJ2, v)) {
			if (Ocupada(fichaJ2, v.CasillaSupDer()) == false) { return true; ; }
		}
		if (Ocupada(fichaJ1, v)) {
			if (Ocupada(fichaJ1, v.CasillaSupDer()) == false) { return true; ; }
		}
	}
	//va para atras derecha
	v.i = aux2.i;
	v.j = aux2.j;
	for (int i = 0; v.i >=0 ;i++) {
		v.i = v.i - 1;
		v.j = v.j + 1;
		if (Ocupada(fichaJ2, v.CasillaSupDer())) {
			if (Ocupada(fichaJ2, v.CasillaInfDer()) == false) { return true; ; }
		}
		if (Ocupada(fichaJ1, v)) {
			if (Ocupada(fichaJ1, v.CasillaInfDer()) == false) { return true; ; }
		}
	}
	v.i = aux2.i;
	v.j = aux2.j;
	//va para delante izquierda
	for (int i = 0; v.i < tablero.GetCasillas();i++) {
		v.i = v.i + 1;
		v.j = v.j - 1;
		if (Ocupada(fichaJ2, v)) {
			if (Ocupada(fichaJ2, v.CasillaSupIzq()) == false) { return true; ; }
		}
		if (Ocupada(fichaJ1, v)) {
			if (Ocupada(fichaJ1, v.CasillaSupIzq()) == false) { return true; ; }
		}
	}
	if (Ocupada(fichaJ2, v) == false) { return false; }
}

bool Juego::Ocupada(Ficha fichas[8][8] , Vector2D v) {

	 return(fichas[v.j][v.i].GetOcupada());
	
};

bool Juego::Ocupada(Vector2D v) {
	return (fichaJ1[v.j][v.i].GetOcupada() || fichaJ2[v.j][v.i].GetOcupada());
	
}
bool Juego::Ocupada(Reina reina[8][8], Vector2D v) {
	return(reina[v.j][v.i].GetOcupada());
};



bool Juego::Existe(Vector2D v) {
	if (v.j < tablero.GetCasillas() && v.j >= 0 && v.i < tablero.GetCasillas() && v.i >= 0) return true;
	else return false;
}

void Juego::Jugadas() {
	if (turno == TurnoUno) {
		std::cout << "Jugador 1" << std::endl;
		std::cout << "linea 50" << std::endl;
		MovimientoJ1();
		
	}
	else if(turno == TurnoDos && tipojuego==juego1) {
		std::cout << "Jugador 2" << std::endl;
		std::cout << "linea 56" << std::endl;
		MovimientoJ2();
	}

	else if (turno == TurnoDos && tipojuego == juego2)
	{
		printf("________________");
	}

	
}

void Juego::MuestraPosibilidades(){
	if (paso == PrimPaso && turno == TurnoUno) {
		MalaComidaJ1();
		std::cout << "linea 64" << std::endl;
	}
	if (paso == PrimPaso && turno == TurnoDos )  {
		MalaComidaJ2();
		std::cout << "linea 67" << std::endl;
	}
}

void Juego::MovimientoJ1() {
	std::cout << "entra en movimiento" << std::endl;
	//primero que se comprueba que la casilla tenga ficha del jugador 

	if (Ocupada(fichaJ1, vector) && paso == PrimPaso)
	{
		if (contadorPosibilidadesJ1==0) {
			std::cout << "Puede escoger la ficha que quiera" <<  std::endl;
			std::cout << "PRIMERA JUGADA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
			std::cout << "Ha seleccionado su ficha, elija su próxima casilla porfavor" << std::endl;

			aux.j = vector.j; //revisar
			aux.i = vector.i;
			paso = SegPaso;
		}
		else {
			std::cout << "Esta obligado a comer, solo puede seleccionar las fichas en rojo" << std::endl;
			if (FichaCorrecta(fichaJ1, vector)) {
				std::cout << "Selecciono la casilla correcta" << std::endl;
					aux.j = vector.j; //revisar
					aux.i = vector.i;
					paso = SegPaso;
			}
			else {
				std::cout << "Esta obligado a comer" << std::endl;
				paso = PrimPaso;
			}
			contadorPosibilidadesJ1 = 0;
			
		}

	}

	//Segundo paso
	else if (paso == SegPaso && vector.j != aux.j && vector.i != aux.i) {
		std::cout << "SEGUNDA JUGADA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
		//Movimimiento simple derecha
		if (Ocupada (vector) == false) {
			std::cout << "hooo" << aux.j<<aux.i<< std::endl;
			std::cout << "hooo" << vector.j << vector.i << std::endl;
			if (aux.j + 1 == vector.j && aux.i + 1 == vector.i) {
				fichaJ1[vector.j][vector.i].SetActiva();
				fichaJ1[aux.j][aux.i].SetDesactiva();
				std::cout << "movimiento derecha" << std::endl;
				MovimientoReina();
				turno = TurnoDos;
				paso = PrimPaso;
				
			}

			//Movimimiento simple izquierda
			else if (aux.j - 1 == vector.j && aux.i + 1 == vector.i) {
				fichaJ1[vector.j][vector.i].SetActiva();
				fichaJ1[aux.j][aux.i].SetDesactiva();
				std::cout << "movimiento izquierda" << std::endl;
				MovimientoReina();
				turno = TurnoDos;
				paso = PrimPaso;
			}

			
			//come fichas der
			if (Ocupada(fichaJ2, aux.CasillaSupDer()) && aux.j + 2 == vector.j && aux.i + 2 == vector.i && Ocupada(vector) == false && Existe(vector)) {
				fichaJ1[vector.j][vector.i].SetActiva();
				fichaJ1[aux.j][aux.i].SetDesactiva();
				fichaJ2[aux.CasillaSupDer().j][aux.CasillaSupDer().i].SetDesactiva();
				MovimientoReina();
				std::cout << "movimiento derecha" << std::endl;
				if (Ocupada(fichaJ2, vector.CasillaSupDer()) && Ocupada(vector.CasillaDobleSupDer()) == false && Existe(vector.CasillaDobleSupDer())) {
					tablero.SeleccionaCasilla(vector.CasillaDobleSupDer(), 200);
					std::cout << "caca" << std::endl;
					ComidaVariasJ1 = true;
					turno = TurnoUno;
				}
				else {
					ComidaVariasJ1 = false;
					turno = TurnoDos;
				}
			}

			//come fichas izq
			else if (Ocupada(fichaJ2, aux.CasillaSupIzq()) && aux.j - 2 == vector.j && aux.i + 2 == vector.i && Ocupada(vector) == false && Existe(vector)) {
				fichaJ1[vector.j][vector.i].SetActiva();
				fichaJ1[aux.j][aux.i].SetDesactiva();
				fichaJ2[aux.CasillaSupIzq().j][aux.CasillaSupIzq().i].SetDesactiva();
				MovimientoReina();
				std::cout << "movimiento izquierda" << std::endl;
				if (Ocupada(fichaJ2, vector.CasillaSupIzq()) && Ocupada(vector.CasillaDobleSupIzq()) == false && Existe(vector.CasillaDobleSupIzq()) ){
					tablero.SeleccionaCasilla(vector.CasillaDobleSupIzq(), 200);
						std::cout << "caca" << std::endl;
						ComidaVariasJ1 = true;
						turno = TurnoUno;
				}
				else {
					ComidaVariasJ1 = false;
					turno = TurnoDos;
				}
			}
				paso = PrimPaso;
		}
		else if (Ocupada(vector)) {
			std::cout << "linea 125" << std::endl;
			paso = PrimPaso;
		}
	}
	
	else if (Ocupada(reinaJ1, vector) && paso == PrimPaso) {
	std::cout << "PRIMERA JUGADA CON REINA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
	std::cout << "Ha seleccionado su ficha, elija su proxima casilla porfavor" << std::endl;
	aux.j = vector.j;
	aux.i = vector.i;
	paso = SegPasoReina;
	std::cout << "el vector " << aux.j << "      " << aux.i << std::endl;
	//Segundo paso
	}
	else if (paso == SegPasoReina && vector.j != aux.j && vector.i != aux.i) {
		std::cout << "SEGUNDA JUGADA CON REINA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
		ReinaMengu(aux);
	}
}
void Juego::ReinaMengu(Vector2D m) {
	aux2.i = m.i;
	aux2.j = m.j;
	//va para atras izquierda
	if (aux.i > vector.i&& aux.j > vector.j) {
		int j = 0;
		for (int i = 0; aux2.i >= vector.i;i++, j++) {
			aux2.i = aux.i - i;
			aux2.j = aux.j - j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ2, aux2.CasillaInfIzq()) == false) {
					reinaJ1[aux2.j - 1][aux2.i - 1].SetActiva();
					fichaJ2[aux2.j][aux2.i].SetDesactiva();
					reinaJ1[aux.j][aux.i].SetDesactiva();
					aux2.i = aux2.i - 1;
					aux2.j = aux2.j - 1;
					if (Compruebareina1() == true) {
						paso = PrimPaso;
						turno = TurnoUno;
						return;
					}
					turno = TurnoDos;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ1[vector.j][vector.i].SetActiva();
				reinaJ1[aux.j][aux.i].SetDesactiva();
			}
		}
		turno = TurnoDos;
		paso = PrimPaso;
	}
	//va para delante derecha
	if (aux.i < vector.i && aux.j < vector.j) {
		int j = 0;
		for (int i = 0; aux2.i <= vector.i;i++, j++) {
			aux2.i = aux.i + i;
			aux2.j = aux.j + j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ2, aux2.CasillaSupDer()) == false) {
					reinaJ1[aux2.j + 1][aux2.i + 1].SetActiva();
					fichaJ2[aux2.j][aux2.i].SetDesactiva();
					reinaJ1[aux.j][aux.i].SetDesactiva();
					aux2.i = aux.i + 1;
					aux2.j = aux.j + 1;
					if (Compruebareina1() == true) {
						paso = PrimPaso;
						turno = TurnoUno;
						return;
					}
					turno = TurnoDos;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ1[vector.j][vector.i].SetActiva();
				reinaJ1[aux.j][aux.i].SetDesactiva();
				turno = TurnoDos;
				paso = PrimPaso;
			}
		}
	}
	//va para atras derecha
	if (aux.i > vector.i&& aux.j < vector.j) {
		int j = 0;
		for (int i = 0; aux2.i > vector.i;i++, j++) {
			aux2.i = aux.i - i;
			aux2.j = aux.j + j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ2, aux2.CasillaInfDer()) == false) {
					reinaJ1[aux2.j + 1][aux2.i - 1].SetActiva();
					fichaJ2[aux2.j][aux2.i].SetDesactiva();
					reinaJ1[aux.j][aux.i].SetDesactiva();
					aux2.i = aux.i - 1;
					aux2.j = aux.j + 1;
					if (Compruebareina1() == true) {
						paso = PrimPaso;
						turno = TurnoUno;
						return;
					}
					turno = TurnoDos;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ1[vector.j][vector.i].SetActiva();
				reinaJ1[aux.j][aux.i].SetDesactiva();
				turno = TurnoDos;
				paso = PrimPaso;

			}
		}
		return;
	}
	//va para delante izquierda
	if (aux.i < vector.i && aux.j > vector.j) {
		int j = 0;
		for (int i = 0; aux2.i < vector.i;i++, j++) {
			aux2.i = aux.i + i;
			aux2.j = aux.j - j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ2, aux2.CasillaSupIzq()) == false) {
					reinaJ1[aux2.j - 1][aux2.i + 1].SetActiva();
					fichaJ2[aux2.j][aux2.i].SetDesactiva();
					reinaJ1[aux.j][aux.i].SetDesactiva();
					aux2.i = aux.i + 1;
					aux2.j = aux.j - 1;
					if (Compruebareina1() == true)
					{
						paso = PrimPaso;
						turno = TurnoUno;
						return;

					}
					turno = TurnoDos;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ1[vector.j][vector.i].SetActiva();
				reinaJ1[aux.j][aux.i].SetDesactiva();
				turno = TurnoDos;
				paso = PrimPaso;
			}
		}
		return;
	}
}
bool Juego::FichaCorrecta(Ficha f[8][8], Vector2D v) {
	if (f[v.j][v.i].marca == true) {
		return true;
		std::cout << "linea 134" << std::endl;
	}
	else {
		return false;
		std::cout << "linea 138" << std::endl;
	}
}

void Juego::MovimientoJ2() {
	std::cout << "entra en movimiento" << std::endl;
	//primero que se comprueba que la casilla tenga ficha del jugador 
	if (Ocupada(fichaJ2, vector) && paso == PrimPaso) {
		if (contadorPosibilidadesJ2 == 0) {
			MalaComidaJ2();
			std::cout << "PRIMERA JUGADA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
			std::cout << "Ha seleccionado su ficha, elija su próxima casilla porfavor" << std::endl;
			aux.j = vector.j; //revisar
			aux.i = vector.i;
			paso = SegPaso;
		}

		else {
			std::cout << "Esta obligado a comer, solo puede seleccionar las fichas en rojo" << std::endl;
			if (FichaCorrecta(fichaJ2, vector)) {
				aux.j = vector.j; //revisar
				aux.i = vector.i;
				paso = SegPaso;
			}
			else paso = PrimPaso;
			contadorPosibilidadesJ2 = 0; 
	}
	}
	//Segunda jugada
	else if (paso == SegPaso && vector.j != aux.j && vector.i != aux.i) {
		std::cout << "SEGUNDA JUGADA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
		//Movimimiento simple derecha
		if (Ocupada(fichaJ1, vector) == false && Ocupada(fichaJ2, vector) == false) {
			if (aux.j + 1 == vector.j && aux.i - 1 == vector.i) {
				fichaJ2[vector.j][vector.i].SetActiva();
				fichaJ2[aux.j][aux.i].SetDesactiva();
				MovimientoReina();
				std::cout << "movimiento derecha" << std::endl;
				turno = TurnoUno;
			}

			//Movimimiento simple izquierda
			else if (aux.j - 1 == vector.j && aux.i - 1 == vector.i) {
				fichaJ2[vector.j][vector.i].SetActiva();
				fichaJ2[aux.j][aux.i].SetDesactiva();
				MovimientoReina();
				std::cout << "movimiento izq" << std::endl;
				turno = TurnoUno;
			}
			//come fichas 
			else if (Ocupada(fichaJ1, aux.CasillaInfDer()) && aux.j + 2 == vector.j && aux.i - 2 == vector.i && Ocupada(vector) == false && Existe(vector)) {
				fichaJ2[vector.j][vector.i].SetActiva();
				fichaJ2[aux.j][aux.i].SetDesactiva();
				fichaJ1[aux.CasillaInfDer().j][aux.CasillaInfDer().i].SetDesactiva();
				MovimientoReina();
				std::cout << "movimiento derecha" << std::endl;

				if (Ocupada(fichaJ1, vector.CasillaInfIzq()) && Ocupada(vector.CasillaDobleInfIzq()) == false && Existe(vector.CasillaDobleInfIzq())) {
					tablero.SeleccionaCasilla(vector.CasillaDobleInfIzq(), 200);
					std::cout << "caca" << std::endl;
					ComidaVariasJ2 = true;
					turno = TurnoDos;
					
				}
				else {
					ComidaVariasJ2 = false;
					turno = TurnoUno;
					
				}


			}

			//come izquierda
			else if (Ocupada(fichaJ1, aux.CasillaInfIzq()) && aux.j - 2 == vector.j && aux.i - 2 == vector.i && Ocupada(vector)==false && Existe(vector)) {
				fichaJ2[vector.j][vector.i].SetActiva();
				fichaJ2[aux.j][aux.i].SetDesactiva();
				fichaJ1[aux.CasillaInfIzq().j][aux.CasillaInfIzq().i].SetDesactiva();
				MovimientoReina();
				std::cout << "movimiento izquierda" << std::endl;
					if ((Ocupada(fichaJ1, vector.CasillaInfIzq()) && Ocupada(vector.CasillaDobleInfIzq()) == false) && Existe(vector.CasillaDobleInfIzq())) {
						tablero.SeleccionaCasilla(vector.CasillaDobleInfIzq(), 200);
						std::cout << "caca" << std::endl;
						ComidaVariasJ2 = true;
						turno = TurnoDos;

					}
					else {
						ComidaVariasJ2 = false;
						turno = TurnoUno;

					}
			}

			
			paso = PrimPaso;
		}
		else if (Ocupada(fichaJ1, vector) || Ocupada(fichaJ2, vector)) {
			paso = PrimPaso;
		}
	}
	else if (Ocupada(reinaJ2, vector) && paso == PrimPaso) {
		std::cout << "PRIMERA JUGADA CON REINA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
		std::cout << "Ha seleccionado su ficha, elija su proxima casilla porfavor" << std::endl;
		aux.j = vector.j;
		aux.i = vector.i;
		paso = SegPasoReina;
		std::cout << "el vector " << aux.j << "      " << aux.i << std::endl;
		//Segundo paso
	}
	else if (paso == SegPasoReina && vector.j != aux.j && vector.i != aux.i) {
		std::cout << "SEGUNDA JUGADA CON REINA: Ha pulsado la columna" << vector.j << "y la fila" << vector.i << std::endl;
		ReinaMengu2(aux);
	}
}
void Juego::ReinaMengu2(Vector2D m) {
	aux2.i = m.i;
	aux2.j = m.j;
	if (aux.i > vector.i&& aux.j > vector.j) {
		int j = 0;
		for (int i = 0; aux2.i >= vector.i;i++, j++) {
			aux2.i = aux.i - i;
			aux2.j = aux.j - j;
			if (Ocupada(fichaJ1, aux2)) {
				if (Ocupada(fichaJ1, aux2.CasillaInfIzq()) == false) {
					reinaJ2[aux2.j - 1][aux2.i - 1].SetActiva();
					fichaJ1[aux2.j][aux2.i].SetDesactiva();
					reinaJ2[aux.j][aux.i].SetDesactiva();
					aux2.i = aux2.i - 1;
					aux2.j = aux2.j - 1;
					if (Compruebareina1() == true) {
						paso = PrimPaso;
						turno = TurnoDos;
						return;
					}
					turno = TurnoUno;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ2[vector.j][vector.i].SetActiva();
				reinaJ2[aux.j][aux.i].SetDesactiva();
			}
		}
		turno = TurnoDos;
		paso = PrimPaso;
	}
	if (aux.i < vector.i && aux.j < vector.j) {
		int j = 0;
		for (int i = 0; aux2.i <= vector.i;i++, j++) {
			aux2.i = aux.i + i;
			aux2.j = aux.j + j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ1, aux2.CasillaSupDer()) == false) {
					reinaJ2[aux2.j + 1][aux2.i + 1].SetActiva();
					fichaJ1[aux2.j][aux2.i].SetDesactiva();
					reinaJ2[aux.j][aux.i].SetDesactiva();
					aux2.i = aux.i + 1;
					aux2.j = aux.j + 1;
					if (Compruebareina1() == true) {
						paso = PrimPaso;
						turno = TurnoDos;
						return;
					}
					turno = TurnoUno;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ2[vector.j][vector.i].SetActiva();
				reinaJ2[aux.j][aux.i].SetDesactiva();
			}
		}
		turno = TurnoUno;
		paso = PrimPaso;
	}
	if (aux.i > vector.i&& aux.j < vector.j) {
		int j = 0;
		for (int i = 0; aux2.i > vector.i;i++, j++) {
			aux2.i = aux.i - i;
			aux2.j = aux.j + j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ2, aux2.CasillaInfDer()) == false) {
					reinaJ2[aux2.j + 1][aux2.i - 1].SetActiva();
					fichaJ1[aux2.j][aux2.i].SetDesactiva();
					reinaJ2[aux.j][aux.i].SetDesactiva();
					aux2.i = aux.i - 1;
					aux2.j = aux.j + 1;
					if (Compruebareina1() == true) {
						paso = PrimPaso;
						turno = TurnoDos;
						return;
					}
					turno = TurnoUno;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ2[vector.j][vector.i].SetActiva();
				reinaJ2[aux.j][aux.i].SetDesactiva();
				turno = TurnoUno;
				paso = PrimPaso;

			}
		}
		return;
	}
	if (aux.i < vector.i && aux.j > vector.j) {
		int j = 0;
		for (int i = 0; aux2.i < vector.i;i++, j++) {
			aux2.i = aux.i + i;
			aux2.j = aux.j - j;
			if (Ocupada(fichaJ2, aux2)) {
				if (Ocupada(fichaJ2, aux2.CasillaSupIzq()) == false) {
					reinaJ2[aux2.j - 1][aux2.i + 1].SetActiva();
					fichaJ1[aux2.j][aux2.i].SetDesactiva();
					reinaJ2[aux.j][aux.i].SetDesactiva();
					aux2.i = aux.i + 1;
					aux2.j = aux.j - 1;
					if (Compruebareina1() == true)
					{
						paso = PrimPaso;
						turno = TurnoDos;
						return;
					}
					turno = TurnoUno;
					paso = PrimPaso;
					return;
				}
				else {
					paso = PrimPaso;
				}
			}
			else if (vector.i == aux2.i && vector.j == aux2.j) {
				reinaJ2[vector.j][vector.i].SetActiva();
				reinaJ2[aux.j][aux.i].SetDesactiva();
				turno = TurnoUno;
				paso = PrimPaso;
			}
		}
		return;
	}
}

void Juego::MovimientoReina() {
	if (vector.i == 7 && turno == TurnoUno && paso == SegPaso) {
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			std::cout << "Consigue reina" << std::endl;
			if (fichaJ1[vector.j][vector.i].GetPosicionX() == reinaJ1[j][7].GetPosicionX()) {
				reinaJ1[vector.j][7].SetActiva();
				fichaJ1[vector.j][7].SetDesactiva();
				turno = TurnoDos;
			}

		}
	}
	if (vector.i == 0 && turno == TurnoDos && paso == SegPaso) {
		for (int j = 0; j < tablero.GetCasillas(); j++)
		{
			std::cout << "Consigue reina" << std::endl;
			if (fichaJ2[vector.j][vector.i].GetPosicionX() == reinaJ2[j][0].GetPosicionX()) {
				reinaJ2[vector.j][0].SetActiva();
				fichaJ2[vector.j][0].SetDesactiva();
				turno = TurnoUno;
			}


		}
	}
}


void Juego::MalaComidaJ1() {
	Vector2D v, vDer, vIzq, vDobleDer, vDobleIzq;
	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			v.j = j;
			v.i = i;
			vDer = v.CasillaSupDer();
			vIzq = v.CasillaSupIzq();
			vDobleDer = v.CasillaDobleSupDer();
			vDobleIzq = v.CasillaDobleSupIzq();
			if (Ocupada(fichaJ1, v)) {
				std::cout << "uno" << v.j << v.i << std::endl;
				if (Ocupada(fichaJ2, vDer) && Ocupada(vDobleDer) == false && Existe(vDobleDer)) {
					//llama a elimina 
					std::cout << "casilla eliminada:" << v.j << v.i << std::endl;
					//fichaJ1[v.j][v.i].SetDesactiva();
					tablero.SeleccionaCasilla(v, 200);
					fichaJ1[v.j][v.i].marca = true;
					contadorPosibilidadesJ1++;
				}
				if (Ocupada(fichaJ2, vIzq) && Ocupada(vDobleIzq) == false && Existe(vDobleIzq)) {
					//llama a elimina 
					std::cout << "casilla eliminada:" << v.j << v.i << std::endl;
					//fichaJ1[v.j][v.i].SetDesactiva();
					tablero.SeleccionaCasilla(v, 200);
					fichaJ1[v.j][v.i].marca = true;
					contadorPosibilidadesJ1++;
				}
			}
		}
	}
}

void Juego::MalaComidaJ2() {
	Vector2D v, vDer, vIzq, vDobleDer, vDobleIzq;
	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			v.j = j;
			v.i = i;
			vDer = v.CasillaInfDer();
			vIzq = v.CasillaInfIzq();
			vDobleDer = v.CasillaDobleInfDer();
			vDobleIzq = v.CasillaDobleInfIzq();
			if (Ocupada(fichaJ2, v)) {
				if (Ocupada(fichaJ1, vDer) && Ocupada(vDobleDer) == false && Existe(vDobleDer)) {
					//llama a elimina 
					std::cout << "casilla eliminada:" << v.j << v.i << std::endl;
					//fichaJ2[v.j][v.i].SetDesactiva();
					tablero.SeleccionaCasilla(v, 200);
					fichaJ2[v.j][v.i].marca = true;
					contadorPosibilidadesJ2++;

				}
				if (Ocupada(fichaJ1, vIzq) && Ocupada(vDobleIzq) == false && Existe(vDobleIzq)) {
					//llama a elimina 
					std::cout << "casilla eliminada:" << v.j << v.i << std::endl;
					//fichaJ2[v.j][v.i].SetDesactiva();
					tablero.SeleccionaCasilla(v, 200);
					fichaJ2[v.j][v.i].marca = true;
					contadorPosibilidadesJ2++;
				}
			}

		}
	}
}

void Juego::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Juego::Dibuja()
{

	
	
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Textura.png").id);
	//dibujo del plano donde está la foto
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-30, -10, -1);
	glTexCoord2d(1, 1); glVertex3f(30, -10, -1); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
	glTexCoord2d(1, 0); glVertex3f(30, 35, -1);
	glTexCoord2d(0, 0); glVertex3f(-30, 35, -1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo

	tablero.Dibuja();


	for (int i = 0; i < tablero.GetCasillas(); i++) {
		for (int j = 0; j < tablero.GetCasillas(); j++) {
			if (fichaJ1[j][i].ocupada == true) fichaJ1[j][i].Dibuja();
			if (fichaJ2[j][i].ocupada == true) fichaJ2[j][i].Dibuja();
			if (reinaJ1[j][i].ocupada == true) reinaJ1[j][i].Dibuja();
			if (reinaJ2[j][i].ocupada == true) reinaJ2[j][i].Dibuja();
		}
	}
}

void Juego::Mueve()
{

	float d = sqrt((pow(y_ojo, 2)) + pow(x_ojo, 2));
	double theta = atan2(y_ojo,x_ojo);
	theta += 0.1f;
	//con el angulo aumentado un diferencial cambio los valores de los puntos de vista x y z 
	x_ojo = d * cos(theta);
	y_ojo = d * sin(theta);
}

void Juego::Para()
{	x_ojo = 4;
	y_ojo = 4;

}



void Juego::Tecla(unsigned char key)
{
	if (key=='a') printf("hola %d espacio %d fin", vector.j, vector.i);

}


void Juego::Raton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (x >= 152 && x < 207)  {;
			vector.j = 0;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		};
		if (x >= 207 && x < 263) {

			vector.j = 1;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 263 && x < 318)  {
	
			vector.j = 2;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 318 && x < 373)  {

			vector.j = 3;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383)vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163)vector.i = 7;
		}
		if (x >= 373 && x < 428) {
			vector.j = 4;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 428 && x < 483)  {

			vector.j = 5;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 483 && x < 538)  {

			vector.j = 6;
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		if (x >= 538 && x < 593)  {
			vector.j = 7; 
			if (y >= 493 && y < 547) vector.i = 0;
			if (y >= 438 && y < 493) vector.i = 1;
			if (y >= 383 && y < 438) vector.i = 2;
			if (y >= 328 && y < 383) vector.i = 3;
			if (y >= 273 && y < 328) vector.i = 4;
			if (y >= 218 && y < 273) vector.i = 5;
			if (y >= 163 && y < 218) vector.i = 6;
			if (y >= 108 && y < 163) vector.i = 7;
		}
		tablero.DesSeleccionaCasilla(vector);
		tablero.SeleccionaCasilla(vector, 0);
		Jugadas();
		
		MuestraPosibilidades();
	}

}
