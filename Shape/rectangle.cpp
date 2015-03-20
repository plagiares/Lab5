#include "stdafx.h"

using namespace ShapeLibrary;

Rectangle::Rectangle(IWindowAPI & _windowAPI)
{
	windowAPI = &_windowAPI;
}
void Rectangle::setPosition(Point _point)
{
	position = &_point;
}

void Rectangle::setHeight(unsigned int _height)
{
	height = _height;
}
void Rectangle::setWidth(unsigned int _width)
{
	width = _width;
}
void Rectangle::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawRectangle(*position,width,height);
	windowAPI->fillRectangle(*position, width, height);
}
