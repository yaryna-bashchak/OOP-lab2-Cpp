/*
Rectangle(hdc,x1,y1,x2,y2); (����������� �� �����������)
��� ������� ����� (���� ������� ����� ������).
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

hBrush = (HBRUSH)CreateSolidBrush(RGB(255,255,0)); //����������� ������
hBrushOld = (HBRUSH)SelectObject(hdc, hBrush); //������ -> � hdc

Ellipse(hdc,x1,y1,x2,y2); //��� Rectangle

SelectObject(hdc, hBrushOld); //������������ ������-����������
DeleteObject(hBrush); //��������� ���������
*/