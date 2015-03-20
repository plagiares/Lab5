#include "stdafx.h"

using namespace ShapeLibrary;



void Shape::add(Point _point)
{
	point.push_back(_point);
}

void Shape::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawLine(getPoint(0), getPoint(1));
	windowAPI->drawLine(getPoint(1), getPoint(2));
}
Point Shape::getPoint(unsigned int _index)
{
	return point.at(_index);
}

