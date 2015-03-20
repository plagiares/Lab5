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

void Shape::setFillColor(Color _color)
{
	fillColor = _color;
}
void Shape::setLineColor(Color _color){
	lineColor = _color;
}
Color Shape::getFillColor(){
	return fillColor;
}
Color Shape::getLineColor(){
	return lineColor;
}
