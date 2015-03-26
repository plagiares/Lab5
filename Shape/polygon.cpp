#include "stdafx.h"
#include <algorithm>

using namespace ShapeLibrary;

Polygon::Polygon(IWindowAPI& _windowAPI)
{
	windowAPI = &_windowAPI;
}

void Polygon::draw()
{
	windowAPI->setDrawingColor(lineColor);
	if (point.size() < 3) throw runtime_error("Not enough points have been added");
	for (int i = 0; i < point.size(); i++)
	{
		if ((i + 1) < point.size())
		{
			windowAPI->drawLine(point[i], point[i + 1]);
		}
		else
		{
			windowAPI->drawLine(point[i], point[0]);
		}
	}
}

void Polygon::add(Point _point)
{
	if (isOnLine(_point)) throw runtime_error("Un point ne peut pas être sur une ligne déjà existante");
	if (isCrossingLine(_point)) throw runtime_error("Une ligne ne peut pas en traverser une autre");
	point.push_back(_point);
}

bool Polygon::isOnLine(const Point &_point)
{
	if (point.size() >= 2)
	{
		double x1 = point[point.size() - 2].x, x2 = point[point.size() - 1].x, x3 = _point.x;
		double y1 = point[point.size() - 2].y, y2 = point[point.size() - 1].y, y3 = _point.y;

		double penteDerniereLigne = (y2 - y1) / (x2 - x1);
		double penteNouveauPoint = (y3 - y2) / (x3 - x2);

		double origineDerniereLigne = y1 - (penteDerniereLigne * x1);
		double origineNouveauPoint = y3 - (penteNouveauPoint * x3);

		return (penteDerniereLigne + origineDerniereLigne == penteNouveauPoint + origineNouveauPoint);
	}
	return false;
}

bool Polygon::isCrossingLine(const Point &_point)
{
	if (point.size() >= 3)
	{
		double x1, x2, x3, x4 = _point.x;
		double y1, y2, y3, y4 = _point.y;

		for (int i = 0; i < point.size() - 2; i += 3)
		{
			x1 = point[i].x;
			y1 = point[i].y;
			x2 = point[i + 1].x;
			y2 = point[i + 1].y;
			x3 = point[i + 2].x;
			y3 = point[i + 2].y;

			double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
			if (d == 0) return false;

			double x = ((x1*y2 - y1*x2) * (x3 - x4) - (x1 - x2) * (x3*y4 - y3*x4)) / d;
			double y = ((x1*y2 - y1*x2) * (y3 - y4) - (y1 - y2) * (x3*y4 - y3*x4)) / d;

			if (x < min(x1, x2) || x > max(x1, x2) || x < min(x3, x4) || x > max(x3, x4)) return false;
			if (y < min(y1, y2) || y > max(y1, y2) || y < min(y3, y4) || y > max(y3, y4)) return false;

			if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x4 && y3 == y4) || (x4 == x1 && y4 == y1)) return false;
		}
		return true;
	}
	return false;
}