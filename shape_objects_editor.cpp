#include "framework.h"
#include "shape_objects_editor.h"
#include "editor.h"
#include "shape.h"

ShapeObjectsEditor::ShapeObjectsEditor(int size, int* p) {
	ARRAY_SIZE = size;
	pCOUNT_OF_OBJECTS = p;
};

void ShapeObjectsEditor::StartPointEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу крапок");
	type = "point";
};
void ShapeObjectsEditor::StartLineEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу ліній");
	type = "line";
};
void ShapeObjectsEditor::StartRectEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу прямокутників");
	type = "rect";
};
void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу еліпсів");
	type = "ellipse";
};
void ShapeObjectsEditor::OnLBdown(HWND hWnd, ShapeEditor* pse[]) {
	if (type != "") {
		if (type == "point") {
			pse[0] = new PointEditor(hWnd);
		}
		else if (type == "line") {
			pse[0] = new LineEditor(hWnd);
		}
		else if (type == "rect") {
			pse[0] = new RectEditor(hWnd);
		}
		else if (type == "ellipse") {
			pse[0] = new EllipseEditor(hWnd);
		}
		pse[0]->OnLBdown(hWnd);
	}
};
void ShapeObjectsEditor::OnLBup(HWND hWnd, Shape* p[], ShapeEditor* pse[]) {
	if (type != "") {
		pse[0]->OnLBup(hWnd, p, *pCOUNT_OF_OBJECTS);
		delete pse[0];
		pse[0] = NULL;
		InvalidateRect(hWnd, NULL, TRUE);
		(*pCOUNT_OF_OBJECTS)++;
	}
};
void ShapeObjectsEditor::OnMouseMove(HWND hWnd, ShapeEditor* pse[]) {
	if (pse[0])
		pse[0]->OnMouseMove(hWnd);
};
void ShapeObjectsEditor::OnPaint(HWND hWnd, Shape* p[]) {
	//pse->OnPaint(hwnd, p);
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < *pCOUNT_OF_OBJECTS; i++)
		p[i]->Show(hdc);
	EndPaint(hWnd, &ps);

};