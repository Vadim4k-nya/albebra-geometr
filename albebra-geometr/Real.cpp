#include "Real.hpp"

Real::Real() 
	:Real(Integer(), Rational()) {};

Real::Real(Integer intPart, Rational rationalPart) 
	:intPart_(intPart), ratPart_(rationalPart) {};

Real::Real(int number)
{

}

Real::Real(double number)
{
	
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
	if (*this == obj)
	{
		return true;
	}
	return false;
}

bool Real::Negativity()
{
	return false;
}

bool Real::Positivity()
{
	return false;
}

Real operator+(const Real& A, const Real& B)
{
	return Real();
}

Real operator-(const Real& A, const Real& B)
{
	return Real();
}

Real operator*(const Real& A, const Real& B)
{
	return Real();
}

Real operator/(const Real& A, const Real& B)
{
	return Real();
}

Integer Real::operator+()
{
	return Integer();
}

Integer Real::operator-()
{
	return Integer();
}

bool operator==(const Real& A, const Real& B)
{
	return false;
}

bool operator!=(const Real& A, const Real& B)
{
	return false;
}

bool operator<(const Real& A, const Real& B)
{
	return false;
}

bool operator<=(const Real& A, const Real& B)
{
	return false;
}

bool operator>(const Real& A, const Real& B)
{
	return false;
}

bool operator>=(const Real& A, const Real& B)
{
	return false;
}

std::ostream& operator<<(std::ostream& out, const Real obj)
{
	out << obj.intPart_ << "(" << obj.ratPart_ << ")";
	return out;
}
