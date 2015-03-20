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
	throw logic_error("Not Implmented yet");
	return true;
}

bool Point::operator != (const Point & point) const
{
	throw logic_error("Not Implmented yet");
	return false; 
}
