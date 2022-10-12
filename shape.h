#pragma once
#include "framework.h"

class Shape
{
protected:
	long xs1 = 0, ys1 = 0, xs2 = 0, ys2 = 0;
	//Shape* pcshape[];
public:
	//Shape(Shape* p[]);
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC) = 0;
};