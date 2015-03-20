#include "stdafx.h"

using namespace ShapeLibrary;

ClosedPolyline::ClosedPolyline(IWindowAPI &_windowAPI)
{
	windowAPI = &_windowAPI;
}
void ClosedPolyline::draw()
{
	windowAPI->setDrawingColor(lineColor);
	if (point.size() < 3) throw runtime_error("Not enough points have been added");
	windowAPI->drawLine(getPoint(0), getPoint(1));
	windowAPI->drawLine(getPoint(1), getPoint(2));
	windowAPI->drawLine(getPoint(2), getPoint(0));
}