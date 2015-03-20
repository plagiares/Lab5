#include "stdafx.h"

#include <stdexcept>

using namespace ShapeLibrary;


Point::Point( double _x, double _y ) :
	x(_x), 
	y(_y)
{	
	if (x < 0 || y < 0) throw invalid_argument("localisations can't be negative");
}

bool Point::operator == (const Point & point) const
{
	if (x == point.x && y == point.y)
	return true;

	return false;
}

bool Point::operator != (const Point & point) const
{
	if (x != point.x || y != point.y)
		return true;
	return false;
}
