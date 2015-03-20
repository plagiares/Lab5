#include "stdafx.h"

using namespace ShapeLibrary;

OpenPolyline::OpenPolyline(IWindowAPI & _windowAPI)
{
	windowAPI = &_windowAPI;
}
void OpenPolyline::draw()
{
	windowAPI->setDrawingColor(lineColor);
	if (point.size() < 2) throw runtime_error("Not enough points have been added");
	windowAPI->drawLine(getPoint(0), getPoint(1));
	windowAPI->drawLine(getPoint(1), getPoint(2));
}