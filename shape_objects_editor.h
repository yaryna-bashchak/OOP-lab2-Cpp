#pragma once
#include "editor.h"
#include "shape.h"
#include "LineShape.cpp"
#include "ShapeEditor.cpp"
#include <string>

using namespace std;

class ShapeObjectsEditor
{
private:
	int COUNT_OF_OBJECTS = 0;
	const int ARRAY_SIZE = 103;
	long xstart, ystart, xend, yend;
	string type;
public:
	void StartPointEditor(HWND hWnd) {
		SetWindowText(hWnd, L"Режим вводу крапок");
		type = "point";
	};
	void StartLineEditor(HWND hWnd) {
		SetWindowText(hWnd, L"Режим вводу ліній");
		type = "line";
	};
	void StartRectEditor(HWND hWnd) {
		SetWindowText(hWnd, L"Режим вводу прямокутників");
		type = "rect";
	};
	void StartEllipseEditor(HWND hWnd) {
		SetWindowText(hWnd, L"Режим вводу еліпсів");
		type = "ellipse";
	};
	void OnLBdown(HWND hWnd) {
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xstart = xend = pt.x;
		ystart = yend = pt.y;

	};
	void OnLBup(HWND hWnd, Shape* p[]) {
		if (type != "") {
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;

		if (type == "point") {
			//p[COUNT_OF_OBJECTS] = new PointShape;
		}
		else if (type == "line") {
			p[COUNT_OF_OBJECTS] = new LineShape;
		}
		else if (type == "rect") {
			//p[COUNT_OF_OBJECTS] = new RectShape;
		}
		else if (type == "ellipse") {
			//p[COUNT_OF_OBJECTS] = new EllipseShape;
		}

		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		InvalidateRect(hWnd, NULL, TRUE);
		COUNT_OF_OBJECTS++;
		}
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