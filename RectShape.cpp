/*
Rectangle(hdc,x1,y1,x2,y2); (прямокутник із заповненням)
або чотирма лініями (якщо потрібен тільки контур).
*/

#include "shape.h"

class RectShape : public Shape
{
private:

public:
	//Show
};

/*
HBRUSH hBrush,hBrushOld;

hBrush = (HBRUSH)CreateSolidBrush(RGB(255,255,0)); //створюється пензль
hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //пензль -> у hdc

Ellipse(hdc,x1,y1,x2,y2); //або Rectangle

SelectObject(hdc, hBrushOld); //відновлюється пензль-попередник
DeleteObject(hBrush); //створений знищується
*/