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
		void setFillColor(Color _color);
		void setLineColor(Color _color);
		Color getFillColor();
		Color getLineColor();
	protected:
		IWindowAPI * windowAPI;
		vector<Point> point;
		Color lineColor;
		Color fillColor;
	};
}
