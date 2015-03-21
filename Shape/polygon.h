#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Polygon : public Shape
	{
	public:
		Polygon(IWindowAPI &_windowAPI);
		void draw();
		void add(Point _point);
		bool isAlreadyInLine(const Point _point);
		bool isCrossingLine(const Point _point);
	private:
		vector<int> xAxisTable;
		vector<int> yAxisTable;
	};
}
