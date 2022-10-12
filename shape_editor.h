#pragma once
#include "editor.h"

class ShapeEditor : public Editor //- ������� ����, ���� ��������������� ����������
{
private:
	
protected:
    long xstart = 0, ystart = 0, xend = 0, yend = 0;
	//������ �����, �� ���������� ��������� Windows-�������
public:
	//ShapeEditor(Shape*);
	virtual void OnLBdown(HWND hWnd) = 0;
	virtual void OnLBup(HWND, Shape* p[], int) = 0;
	virtual void OnMouseMove(HWND) = 0;
	virtual void OnPaint(HWND, Shape* pcshape[]) = 0;
};
