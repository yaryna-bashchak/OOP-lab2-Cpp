#pragma once
#include "framework.h"
#include "shape.h"

class Editor
{
public: //а, можливо, ще потрібен віртуальний деструктор?
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	virtual void OnPaint(HWND, Shape* pcshape[]) = 0;
};