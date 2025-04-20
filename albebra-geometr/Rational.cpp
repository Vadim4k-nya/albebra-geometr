#include "Rational.hpp"

Rational::Rational() 
	:Rational(0u, 0u) {};

Rational::Rational(Integer numerator, Integer denominator) 
	:numerator_(numerator), denominator_(denominator) {ModSimplifying();};

Rational::Rational(int numerator, int denominator)
{
	this->numerator_ = numerator;
	this->denominator_ = denominator;
}

Rational::Rational(double number)
{
	int intPart = static_cast<int>(number);
	number -= intPart;
	this->numerator_ = (intPart * 100) + (number * 100);
	this->denominator_ = 100;
	ModSimplifying();
}

Rational::Rational(std::string number) 
	:Rational(std::stod(number)) {};

void Rational::SetNumerator(Integer& newNumerator)
{
	this->numerator_ = newNumerator;
}

void Rational::SetDeniminator(Integer& newDeniminator)
{
	this->denominator_ = newDeniminator;
}

Integer Rational::GetNumerator() const
{
	return numerator_;
}

Integer Rational::GetDenominator() const
{
	return denominator_;
}

bool Rational::IsProper() const
{
	if (numerator_.GetUnits() < denominator_.GetUnits())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::IsNotProper() const
{
	return !IsProper();
}

bool Rational::IsPositive() const
{
	if (numerator_.GetSign() == denominator_.GetSign())
	{
		return true;
	}
	return false;
}

bool Rational::IsNegative() const
{
	return !IsPositive();
}

bool Rational::IsTheSameObj(Rational& obj)const
{
	if (this == &obj)
	{
		return true;
	}
	return false;
}

Rational Rational::Reverse()
{
	Rational reverse = { denominator_, numerator_ };
	return reverse;
}

Rational Rational::Simplifying()
{
	Rational simp = { numerator_, denominator_ };
	simp.ModSimplifying();
	return simp;
}

Integer Rational::IntParts()
{
	return numerator_ / denominator_;
}

Rational Rational::FractPart()
{
	return { numerator_ % denominator_, denominator_ };
}

void Rational::ModSimplifying()
{
	Integer nod = Integer::NOD(numerator_, denominator_);
	numerator_ = numerator_ / nod;
	denominator_ = denominator_ / nod;
}

void Rational::ModReverse()
{
	std::swap(numerator_, denominator_);
}

Rational operator+(const Rational& A, const Rational& B)
{
	Rational result;
	result.numerator_ = A.numerator_ * B.denominator_ + B.numerator_ * A.denominator_;
	result.denominator_ = A.denominator_ * B.numerator_;
	return result;
}

Rational operator-(const Rational& A, const Rational& B)
{
	Rational result;
	result.numerator_ = A.numerator_ * B.denominator_ - B.numerator_ * A.denominator_;
	result.denominator_ = A.denominator_ * B.numerator_;
	return result;
}

Rational operator*(const Rational& A, const Rational& B)
{
	Rational result;
	result.numerator_ = A.numerator_ * B.numerator_;
	result.denominator_ = A.denominator_ * B.denominator_;
	return result;
}

Rational operator/(const Rational& A, const Rational& B)
{
	Rational result;
	result.numerator_ = A.numerator_ * B.denominator_;
	result.denominator_ = A.denominator_ * B.numerator_;
	return result;
}

Integer Rational::operator+()
{
	return Integer();
}

Integer Rational::operator-()
{
	return Integer();
}

bool operator==(const Rational& A, const Rational& B)
{
	if (A.numerator_ == B.numerator_ && A.denominator_ == B.denominator_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Rational& A, const Rational& B)
{
	return !(A == B);
}

bool operator<(const Rational& A, const Rational& B)
{
	if (A.denominator_ == B.denominator_)
	{
		return A.numerator_ < B.numerator_;
	}
	else if (A.numerator_ == B.numerator_)
	{
		return !(A.denominator_ < B.denominator_);
	}
	else
	{
		Integer NOK = Integer::NOK(A.denominator_, B.denominator_);
		return (A.numerator_ * NOK) < (B.numerator_ * NOK);
	}
}

bool operator<=(const Rational& A, const Rational& B)
{
	if (A < B && A == B)
	{
		return true;
	}
	return false;
}

bool operator>(const Rational& A, const Rational& B)
{
	if (A.denominator_ == B.denominator_)
	{
		return A.numerator_ > B.numerator_;
	}
	else if (A.numerator_ == B.numerator_)
	{
		return !(A.denominator_ > B.denominator_);
	}
	else
	{
		Integer NOK = Integer::NOK(A.denominator_, B.denominator_);
		return (A.numerator_ * NOK) > (B.numerator_ * NOK);
	}
}

bool operator>=(const Rational& A, const Rational& B)
{
	if (A > B && A == B)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Rational obj) {
	out << obj.numerator_ << " /" << obj.denominator_;
	return out;
}
