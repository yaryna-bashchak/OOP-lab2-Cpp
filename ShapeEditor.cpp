#include "editor.h"
#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "LineShape.cpp"
#include "PointShape.cpp"
#include "RectShape.cpp"
#include "EllipseShape.cpp"

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
private:
	void DrawRect()
	{
		MoveToEx(hdc, xend, yend, NULL);
		LineTo(hdc, xend, 2 * ystart - yend);
		LineTo(hdc, 2 * xstart - xend, 2 * ystart - yend);
		LineTo(hdc, 2 * xstart - xend, yend);
		LineTo(hdc, xend, yend);
	}
public:
	RectEditor(HWND hwnd)
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
		p[COUNT_OF_OBJECTS] = new RectShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
	}

	void OnMouseMove(HWND hWnd)
	{
		SetROP2(hdc, R2_NOTXORPEN);
		DrawRect();
		UpdateXY();
		DrawRect();
	}

	void OnPaint(HWND hWnd, Shape* pcshape[])
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);

		//InvalidateRect(hWnd, NULL, TRUE);
	}
};

class EllipseEditor : public ShapeEditor
{
private:
	void DrawRect()
	{
		MoveToEx(hdc, xend, yend, NULL);
		LineTo(hdc, xend, ystart);
		LineTo(hdc, xstart, ystart);
		LineTo(hdc, xstart, yend);
		LineTo(hdc, xend, yend);
	}
	void DrawEllipse()
	{
		Arc(hdc, xstart, ystart, xend, yend, 0, 0, 0, 0);
	}
public:
	EllipseEditor(HWND hwnd)
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
		p[COUNT_OF_OBJECTS] = new EllipseShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
	}

	void OnMouseMove(HWND hWnd)
	{
		SetROP2(hdc, R2_NOTXORPEN);
		DrawEllipse();
		DrawRect();
		UpdateXY();
		DrawEllipse();
		DrawRect();
	}

	void OnPaint(HWND hWnd, Shape* pcshape[])
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);

		//InvalidateRect(hWnd, NULL, TRUE);
	}
};