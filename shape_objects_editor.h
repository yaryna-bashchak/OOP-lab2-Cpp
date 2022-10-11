#pragma once
#include "editor.h"
#include "shape.h"
#include "ShapeEditor.cpp"
#include <string>

using namespace std;

class ShapeObjectsEditor
{
private:
	int COUNT_OF_OBJECTS = 0;
	const int ARRAY_SIZE = 103;
	//long xstart, ystart, xend, yend;
	string type;
public:
	void StartPointEditor(HWND hWnd) {
		SetWindowText(hWnd, L"����� ����� ������");
		type = "point";
	};
	void StartLineEditor(HWND hWnd) {
		SetWindowText(hWnd, L"����� ����� ���");
		type = "line";
	};
	void StartRectEditor(HWND hWnd) {
		SetWindowText(hWnd, L"����� ����� ������������");
		type = "rect";
	};
	void StartEllipseEditor(HWND hWnd) {
		SetWindowText(hWnd, L"����� ����� �����");
		type = "ellipse";
	};
	void OnLBdown(HWND hWnd, ShapeEditor* pse[]) {
		if (type != "") {
			if (type == "point") {
				//p[COUNT_OF_OBJECTS] = new PointShape;
			}
			else if (type == "line") {
				pse[0] = new LineEditor;
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
			pse[0]->OnLBup(hWnd, p, COUNT_OF_OBJECTS);
			InvalidateRect(hWnd, NULL, TRUE);
			COUNT_OF_OBJECTS++;
		}
	};
	void OnMouseMove(HWND hWnd, ShapeEditor* pse[]) {};
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