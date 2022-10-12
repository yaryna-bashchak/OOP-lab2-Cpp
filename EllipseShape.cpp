/*
Ellipse(hdc,x1,y1,x2,y2); (���� �� �����������)
��� Arc(hdc, x1,y1, x2,y2, 0,0,0,0); (���� ������� ����� ������).
*/

#include "shape.h"

class EllipseShape : public Shape
{
private:
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 255));
public:
	void Show(HDC hdc)
	{
		SelectObject(hdc, hBrush);
		Ellipse(hdc, xs1, ys1, xs2, ys2);
	}
};