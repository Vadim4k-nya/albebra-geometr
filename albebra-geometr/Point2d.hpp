#pragma once

#ifndef POINT2D_HPP
#define POINT2D_HPP

#include "Real.hpp"

class Point2d {
public:
	Point2d();
	Point2d(Real x, Real y);

	void SetPointX(Real X);

	void SetPointY(Real Y);

	Real GetPointX()const;

	Real GetPointY()const;

	friend bool operator==(const Point2d& A, const Point2d& B);

	bool SamenessOfTwoPoints(const Point2d& obj);

	static Real SectionLength(const Point2d& point1, const Point2d& point2);

	// виртуальный деструктор

private:
	Real x_;
	Real y_;
};

#endif // !POINT2D_HPP
