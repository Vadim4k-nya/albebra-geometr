#include "Point2d.hpp"

Point2d::Point2d()
	:x_(0), y_(0)
{}

Point2d::Point2d(Real x, Real y)
	:x_(x), y_(y)
{}

void Point2d::SetPointX(Real X)
{
	this->x_ = X;
}

void Point2d::SetPointY(Real Y)
{
	this->y_ = Y;
}

Real Point2d::GetPointX()const
{
	return this->x_;
}

Real Point2d::GetPointY()const
{
	return this->y_;
}

bool Point2d::SamenessOfTwoPoints(const Point2d& obj)
{
	if (this == &obj)
	{
		return true;
	}
	return false;
}

Real Point2d::SectionLength(const Point2d& point1, const Point2d& point2)
{
	// хз пока
}

bool operator==(const Point2d& A, const Point2d& B)
{
	if (A.x_ == B.x_ && A.y_ == B.y_)
	{
		return true;
	}
	return false;
}
