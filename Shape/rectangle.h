#pragma once
#include "stdafx.h"

namespace ShapeLibrary
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(IWindowAPI & _windowAPI);
		void setPosition(Point _point);
		void setHeight(unsigned int _height);
		void setWidth(unsigned int _width);
	
	private:
		unsigned int height;
		unsigned int width;
	};
}