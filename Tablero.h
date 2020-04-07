#pragma once
#include "glut.h"

class Tablero
{
private:
    float numCasillas;
public:
    Tablero();
    void Cuadrado(float x, float y, float rad);
    void Dibuja();
};

