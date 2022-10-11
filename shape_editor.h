#pragma once
#include "editor.h"
#include "shape.h"

class ShapeEditor : public Editor //- базовий клас, який забезпечуватиме поліморфізм
{
private:
	
protected:
    long xstart, ystart, xend, yend;
	//корисні члени, які враховують специфіку Windows-програм
public:
	//ShapeEditor(Shape*);
	virtual void OnLBdown(HWND hWnd) = 0;
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	virtual void OnPaint(HWND, Shape* pcshape[]) = 0;
};
