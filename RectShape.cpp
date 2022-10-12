/*
Rectangle(hdc,x1,y1,x2,y2); (����������� �� �����������)
��� ������� ����� (���� ������� ����� ������).
*/

#include "shape.h"

class RectShape : public Shape
{
private:
	HPEN hPen = CreatePen(PS_SOLID, 3, 0);
public:
	void Show(HDC hdc) {
		SelectObject(hdc, hPen);
		MoveToEx(hdc, xs2, ys2, NULL);
		LineTo(hdc, xs2, 2 * ys1 - ys2);
		LineTo(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2);
		LineTo(hdc, 2 * xs1 - xs2, ys2);
		LineTo(hdc, xs2, ys2);
	}
};

/*
HBRUSH hBrush,hBrushOld;

hBrush = (HBRUSH)CreateSolidBrush(RGB(255,255,0)); //����������� ������
hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ -> � hdc

Ellipse(hdc,x1,y1,x2,y2); //��� Rectangle

SelectObject(hdc, hBrushOld); //������������ ������-����������
DeleteObject(hBrush); //��������� ���������
*/