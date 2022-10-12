#pragma once
#include "editor.h"
#include "shape.h"
#include "ShapeEditor.cpp"
#include <string>

using namespace std;

class ShapeObjectsEditor
{
private:
	int* pCOUNT_OF_OBJECTS;
	int ARRAY_SIZE;
	//long xstart, ystart, xend, yend;
	string type;
public:
	ShapeObjectsEditor(int size, int* p) {
		ARRAY_SIZE = size;
		pCOUNT_OF_OBJECTS = p;
	};
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
	void OnLBdown(HWND hWnd, ShapeEditor* pse[]) {
		if (type != "") {
			if (type == "point") {
				//p[COUNT_OF_OBJECTS] = new PointShape;
			}
			else if (type == "line") {
				pse[0] = new LineEditor(hWnd);
			}
			else if (type == "rect") {
				//p[COUNT_OF_OBJECTS] = new RectShape;
			}
			else if (type == "ellipse") {
				//p[COUNT_OF_OBJECTS] = new EllipseShape;
			}
			pse[0]->OnLBdown(hWnd);
		}
	};
	void OnLBup(HWND hWnd, Shape* p[], ShapeEditor* pse[]) {
		if (type != "") {
			pse[0]->OnLBup(hWnd, p, *pCOUNT_OF_OBJECTS);
			delete pse[0];
			pse[0] = NULL;
			InvalidateRect(hWnd, NULL, TRUE);
			(*pCOUNT_OF_OBJECTS)++;
		}
	};
	void OnMouseMove(HWND hWnd, ShapeEditor* pse[]) {
		if (pse[0])
			pse[0]->OnMouseMove(hWnd);
	};
	void OnPaint(HWND hWnd, Shape* p[]) {
		//pse->OnPaint(hwnd, p);
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < *pCOUNT_OF_OBJECTS; i++)
			p[i]->Show(hdc);
		EndPaint(hWnd, &ps);
		
	};
};