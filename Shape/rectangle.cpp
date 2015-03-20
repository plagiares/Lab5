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

void Rectangle::setHeight(int _height)
{
	if (_height < 0) throw invalid_argument("the height is too short");
	height = _height;
}
void Rectangle::setWidth(int _width)
{
	if (_width < 0) throw invalid_argument("the width is too short");
	width = _width;
}
void Rectangle::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawRectangle(*position,width,height);
	windowAPI->fillRectangle(*position, width, height);
}
