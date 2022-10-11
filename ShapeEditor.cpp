#include "editor.h"
#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
/*
void ShapeEditor::OnLBdown(HWND hWnd)
{
	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = yend = pt.y;
}


void ShapeEditor::OnMouseMove(HWND hWnd)
{
	POINT pt;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd); //�������� �������� ���� ��� ���������
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	//��������� ������(xstart, ystart, xend, yend);
	//��������� �� "��������" ���� ������������ ������������ �������
	
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //���������� ������� ����� �������
	yend = pt.y;

	//��������� �� "��������" ���� ��� ��������� ������������ �������
	//��������� ������(xstart, ystart, xend, yend);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //��������� �������� ����
}

void ShapeEditor::OnLBup(HWND hWnd)
{
	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
}

void ShapeEditor::OnPaint(HWND hWnd, Shape *pcshape[])
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < 103; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);

	//InvalidateRect(hWnd, NULL, TRUE);
}
*/

class PointEditor : public ShapeEditor
{
	
};

class LineEditor : public ShapeEditor
{
	
};

class RectEditor : public ShapeEditor
{
	
};

class EllipseEditor : public ShapeEditor
{
	
};