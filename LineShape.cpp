//SelectObject(hdc, GetStockObject(WHITE_PEN))
/*
MoveToEx(hdc,x1,y1,NULL);
LineTo(hdc,x2,y2);
*/

#include "shape.h"

class LineShape : public Shape
{
private:
	HPEN hPen = CreatePen(PS_SOLID, 3, 0);
public:
	void Show(HDC hdc) { 
		SelectObject(hdc, hPen);
		MoveToEx(hdc, xs1, ys1, NULL);
		LineTo(hdc, xs2, ys2);
	}
};