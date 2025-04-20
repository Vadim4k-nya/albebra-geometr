#include "Real.hpp"

Real::Real() 
	:Real(Integer(), Rational()) {};

Real::Real(Integer intPart, Rational rationalPart) 
	:intPart_(intPart), ratPart_(rationalPart) {};

Real::Real(int number)
{
	this->intPart_ = number;
	this->ratPart_ = Rational();
}

Real::Real(double number)
{
	this->intPart_ = number;
	int intPart = number;
	number -= intPart;
	this->ratPart_ = Rational(number);
}

Real::Real(std::string number) 
	:Real(std::stod(number)) {};

void Real::SetIntPart(Integer& newIntPart)
{
	this->intPart_ = newIntPart;
}

void Real::SetRationalPart(Rational& newRatPart)
{
	this->ratPart_ = newRatPart;
}

Integer Real::GetIntPart()
{
	return intPart_;
}

Rational Real::GetRationalPart()
{
	return ratPart_;
}

bool Real::IsDecimal()
{
	if (ratPart_.GetDenominator() % 10 == 0)
	{
		return true;
	}
	return false;
}

bool Real::IsTheSameObj(const Real& obj)
{
	if (this == &obj)
	{
		return true;
	}
	return false;
}

bool Real::IsNegative()
{
	if ((intPart_.IsNegative() && ratPart_.IsNegative()) || (intPart_.IsPositive() && ratPart_.IsPositive()))
	{
		return false;
	}
	return true;
}

bool Real::IsPositive()
{
	return IsNegative();
}

Real operator+(const Real& A, const Real& B)
{
	Real result;
	result.intPart_ = A.intPart_ + B.intPart_;
	result.ratPart_ = A.ratPart_ + B.ratPart_;
	return result;
}

Real operator-(const Real& A, const Real& B)
{
	Real result;
	result.intPart_ = A.intPart_ - B.intPart_;
	result.ratPart_ = A.ratPart_ - B.ratPart_;
	return result;
}

Real operator*(const Real& A, const Real& B)
{
	Real result;
	result.intPart_ = A.intPart_ * B.intPart_;
	result.ratPart_ = A.ratPart_ * B.ratPart_;
	return result;
}

Real operator/(const Real& A, const Real& B)
{
	Real result;
	result.intPart_ = A.intPart_ / B.intPart_;
	result.ratPart_ = A.ratPart_ / B.ratPart_;
	return result;
}

Real Real::operator+()
{
	return Real();
}

Real Real::operator-()
{
	return Real();
}

bool operator==(const Real& A, const Real& B)
{
	if ((A.intPart_ == B.intPart_) && (A.ratPart_ == B.ratPart_))
	{
		return true;
	}
	return false;
}

bool operator!=(const Real& A, const Real& B)
{
	return !(A == B);
}

bool operator<(const Real& A, const Real& B)
{
	if (A.intPart_ < B.intPart_)
	{
		return true;
	}
	else if (A.ratPart_ < B.ratPart_)
	{
		return true;
	}
	return false;
}

bool operator<=(const Real& A, const Real& B)
{
	if (A.intPart_ <= B.intPart_)
	{
		return true;
	}
	else if (A.ratPart_ <= B.ratPart_)
	{
		return true;
	}
	return false;
}

bool operator>(const Real& A, const Real& B)
{
	if (A.intPart_ > B.intPart_)
	{
		return true;
	}
	else if (A.ratPart_ > B.ratPart_)
	{
		return true;
	}
	return false;
}

bool operator>=(const Real& A, const Real& B)
{
	if (A.intPart_ >= B.intPart_)
	{
		return true;
	}
	else if (A.ratPart_ >= B.ratPart_)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Real obj)
{
	out << obj.intPart_ << "(" << obj.ratPart_ << ")";
	return out;
}
