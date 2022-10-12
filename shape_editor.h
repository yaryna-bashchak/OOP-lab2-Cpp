#pragma once
#include "editor.h"

class ShapeEditor : public Editor //- базовий клас, який забезпечуватиме поліморфізм
{
private:
	
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
	ShapeEditor(HWND hwnd) {
		hWnd = hwnd;
		hdc = GetDC(hWnd);
		hPen = CreatePen(PS_DOT, 1, 0);
		hPenOld = (HPEN)SelectObject(hdc, hPen);
	};
	virtual void OnLBdown(HWND hWnd) = 0;
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnPaint(HWND hWnd, Shape* pcshape[], int COUNT_OF_OBJECTS)
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < COUNT_OF_OBJECTS; i++)
			pcshape[i]->Show(hdc);
		EndPaint(hWnd, &ps);
	}
};
