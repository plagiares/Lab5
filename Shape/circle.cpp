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
	windowAPI->fillCircle(*center, radius);
}
void Circle::setCenter(Point _point)
{
	center = &_point;
}
void Circle::setRadius(int _radius)
{
	if (_radius < 0) throw invalid_argument("the radius is too small");
	radius = _radius;
}