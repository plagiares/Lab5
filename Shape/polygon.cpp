#include "stdafx.h"



using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI &_windowAPI)
{
	windowAPI = &_windowAPI;
}
void Polygon::draw()
{
	
}
void Polygon::add(Point _point)
{
	if (isAlreadyInLine(_point)) throw runtime_error("the point is already in a line");
	point.push_back(_point);
	xAxisTable.push_back(_point.x);
	yAxisTable.push_back(_point.y);
}
bool Polygon::isAlreadyInLine(Point _point)
{
	if (point.size() < 2) return false;
	//http://www.softwareandfinance.com/Visual_CPP/VCPP_Check_Point_Lies_line_Segment.html

	float slope, intercept;
	float x1 = point.at(0).x, y1 = point.at(0).y, x2 = point.at(1).x, y2 = point.at(1).y;
	float px = _point.x, py = _point.y;
	float left, top, right, bottom; // Bounding Box For Line Segment
	float dx, dy;

	dx = x2 - x1;
	dy = y2 - y1;

	slope = dy / dx;
	// y = mx + c
	// intercept c = y - mx
	intercept = y1 - slope * x1; // which is same as y2 - slope * x2

	// For Bounding Box
	if (x1 < x2)
	{
		left = x1;
		right = x2;
	}
	else
	{
		left = x2;
		right = x1;
	}
	if (y1 < y2)
	{
		top = y1;
		bottom = y2;
	}
	else
	{
		top = y1;
		bottom = y2;
	}

	if (slope * px + intercept > (py - 0.01) &&
		slope * px + intercept < (py + 0.01))
	{
		if (px >= left && px <= right &&
			py >= top && py <= bottom)
		{
			return true;
		}
		else
			return false;

	}
	return false;

}
bool Polygon::isCrossingLine(const Point _point)
{
	if (point.size() < 3) return false;

	return false;
}