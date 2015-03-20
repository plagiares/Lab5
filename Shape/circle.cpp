#include "stdafx.h"

using namespace ShapeLibrary;

Circle::Circle(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}
void Circle::draw()
{
	windowAPI->setDrawingColor(lineColor);
	windowAPI->drawCircle(*center, radius);
}
void Circle::setCenter(Point _point)
{
	center = &_point;
}
void Circle::setRadius(int _radius)
{
	radius = _radius;
}