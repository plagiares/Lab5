#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Circle : public Shape
	{
	public:
		Circle(IWindowAPI & _windowAPI);
		void setCenter(const Point _point);
		void setRadius(const int _radius);
		void draw();
	private:
		Point * center;
		int radius;
	};
}
