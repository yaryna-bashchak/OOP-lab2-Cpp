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
	string type;
public:
	ShapeObjectsEditor(int size, int* p);
	void StartPointEditor(HWND hWnd);
	void StartLineEditor(HWND hWnd);
	void StartRectEditor(HWND hWnd);
	void StartEllipseEditor(HWND hWnd);
	void OnLBdown(HWND hWnd, ShapeEditor* pse[]);
	void OnLBup(HWND hWnd, Shape* p[], ShapeEditor* pse[]);
	void OnMouseMove(HWND hWnd, ShapeEditor* pse[]);
	void OnPaint(HWND hWnd, Shape* p[]);
};