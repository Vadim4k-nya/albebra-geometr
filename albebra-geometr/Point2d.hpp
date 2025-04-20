#pragma once

#ifndef POINT2D_HPP
#define POINT2D_HPP

#include "Real.hpp"

class Point2d {
public:
	Point2d();
	Point2d(Real point1, Real point2);

	void SetPoint1();

	void SetPoint2();

	Real GetPoint1();

	Real GetPoint2();

	friend bool operator==(const Point2d& A, const Point2d& B);

	bool SamenessOfTwoPoints();

	Real SectionLength();

	// виртуальный деструктор

private:
	Real point1_;
	Real point2_;
};

#endif // !POINT2D_HPP
