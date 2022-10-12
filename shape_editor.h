#pragma once
#include "editor.h"

class ShapeEditor : public Editor //- базовий клас, який забезпечуватиме поліморфізм
{
protected:
    long xstart = 0, ystart = 0, xend = 0, yend = 0;
	HWND hWnd;
	HDC hdc;
	HPEN hPen, hPenOld;
	void UpdateXY()
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;
	}
public:
	ShapeEditor(HWND hwnd);
	void OnLBdown(HWND hWnd);
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND hWnd, Shape* pcshape[], int COUNT_OF_OBJECTS);
};
