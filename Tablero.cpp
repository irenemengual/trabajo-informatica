#include "Tablero.h"

Tablero::Tablero() {
    numCasillas = 8;
}

void Tablero::Cuadrado(float x, float y, float rad)
{
    rad = rad / 2;
    glBegin(GL_QUADS);
    glVertex2i(x + rad, y + rad);
    glVertex2i(x + rad, y - rad);
    glVertex2i(x - rad, y - rad);
    glVertex2i(x - rad, y + rad);
    glEnd();
}

void Tablero::Dibuja(){
 
        for (int i = 0; i <= numCasillas ; i++)
        {
            if ((i % 2) == 0) //casillas Y par
            {
                for (int j = 0; j <= numCasillas; j++)
                {
                    if (((j) % 2) == 0)//rellenan las casillas X par
                    {
                        Cuadrado(j, i, 1);
                    }
                }
            }
            else //casillas Y impar
            {
                for (int j = 0; j <=numCasillas; j++)
                {
                    if (((j) % 2) != 0)//rellenan las casillas X impar
                    {
                        Cuadrado(j, i, 1);
                    }
                }
            }
        }
}
