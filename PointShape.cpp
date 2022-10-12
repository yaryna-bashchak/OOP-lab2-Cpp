//SetPixel(hdc,x,y,колір);

#include "shape.h"

class PointShape : public Shape
{
private:
	HPEN hPen = CreatePen(PS_SOLID, 6, 0);
public:
	void Show(HDC hdc) {
		SelectObject(hdc, hPen);
		MoveToEx(hdc, xs2, ys2, NULL);
		LineTo(hdc, xs2, ys2);
	}
};