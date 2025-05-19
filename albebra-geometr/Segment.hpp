#pragma once

#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Point2d.hpp"

class Segment 
{
public:
	Segment();
	Segment(Point2d point1, Point2d point2);

	Real Length—omparison(const Segment& segmnt2);

	bool SamenessOfSegments(const Segment& segment2);

	bool IntersectionOfSegments(const Segment& segment2);

	Real Length()const;

private:
	Point2d point1_;
	Point2d point2_;
};

#endif // !SEGMENT_HPP
