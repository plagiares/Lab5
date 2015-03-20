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
		virtual void draw() = 0;
		Point getPoint(unsigned int _index);
	protected:
		IWindowAPI * windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
		
	};
}
