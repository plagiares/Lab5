#include "stdafx.h"

using namespace ShapeLibrary;



void Shape::add(Point _point)
{
	point.push_back(_point);
}


Point Shape::getPoint(unsigned int _index)
{
	return point.at(_index);
}

