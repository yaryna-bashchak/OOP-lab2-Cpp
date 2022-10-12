#include "editor.h"
#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "LineShape.cpp"
#include "PointShape.cpp"

class PointEditor : public ShapeEditor
{
public:
	PointEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}
	void OnLBdown(HWND hWnd) {}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateXY();
		p[COUNT_OF_OBJECTS] = new PointShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
	}

	void OnMouseMove(HWND hWnd) {};

	void OnPaint(HWND hWnd, Shape* pcshape[])
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);

		//InvalidateRect(hWnd, NULL, TRUE);
	}
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