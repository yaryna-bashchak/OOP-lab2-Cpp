#include "editor.h"
#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "LineShape.cpp"
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
	hdc = GetDC(hWnd); //отримуємо контекст вікна для малювання
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	//Стирається відрізок(xstart, ystart, xend, yend);
	//Малюються лінії "гумового" сліду попереднього розташування курсору
	
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x; //координати поточної точки курсору
	yend = pt.y;

	//Малюються лінії "гумового" сліду для поточного розташування курсору
	//Малюється відрізок(xstart, ystart, xend, yend);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc); //закриваємо контекст вікна
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
private:
	void DrawLine()
	{
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, yend);
	}
public:
	LineEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}
	void OnLBdown(HWND hWnd)
	{
		UpdateXY();
		xstart = xend;
		ystart = yend;
	}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateXY();
		p[COUNT_OF_OBJECTS] = new LineShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
	}

	void OnMouseMove(HWND hWnd)
	{
		SetROP2(hdc, R2_NOTXORPEN);

		DrawLine();
		UpdateXY();
		DrawLine();
	}

	void OnPaint(HWND hWnd, Shape* pcshape[])
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);

		//InvalidateRect(hWnd, NULL, TRUE);
	}
};

class RectEditor : public ShapeEditor
{
	
};

class EllipseEditor : public ShapeEditor
{
	
};