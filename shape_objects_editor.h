#pragma once
#include "editor.h"
#include "shape.h"
#include "LineShape.cpp"
#include "ShapeEditor.cpp"


class ShapeObjectsEditor
{
private:
	int COUNT_OF_OBJECTS = 0;
	const int ARRAY_SIZE = 103;
	long xstart, ystart, xend, yend;
public:
	void StartPointEditor() {};
	void StartLineEditor(HWND hWnd, Shape* p[]) {
		
	};
	void StartRectEditor() {};
	void StartEllipseEditor() {};
	void OnLBdown(HWND hWnd) {
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xstart = xend = pt.x;
		ystart = yend = pt.y;

	};
	void OnLBup(HWND hWnd, Shape* p[]) {
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;

		p[COUNT_OF_OBJECTS] = new LineShape;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		InvalidateRect(hWnd, NULL, TRUE);
		COUNT_OF_OBJECTS++;
	};
	void OnMouseMove(HWND) {};
	void OnPaint(HWND hWnd, Shape* p[]) {
		//pse->OnPaint(hwnd, p);
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < ARRAY_SIZE; i++)
			if (p[i])
				p[i]->Show(hdc);
		EndPaint(hWnd, &ps);
		
	};
};