#pragma once
#include "stdafx.h"

#include <vector>

using namespace std;

namespace ShapeLibrary
{

	class Shape
	{
	public:
		void add(Point _point);
		void draw();
		Point getPoint(unsigned int _index);
	protected:
		IWindowAPI * windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
		
	};
}
