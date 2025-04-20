#include "Integer.hpp"

Integer::Integer()
	:Integer(false, 0u) {}

Integer::Integer(bool sign, unsigned units)
	:sign_(sign), units_(units) {}

Integer::Integer(int number)
{
	if (number < 0)
	{
		sign_ = true;
		units_ = abs(number);
	}
	else {
		sign_ = false;
		units_ = static_cast<unsigned>(number);
	}
}

Integer::Integer(double number)
	:Integer(static_cast<int>(number)) {}

Integer::Integer(bool number)
	:Integer(static_cast<int>(number)) {}

Integer::Integer(std::string number)
	:Integer(std::stoi(number)) {}

void Integer::SetSign(bool newSign)
{
	this->sign_ = newSign;
}

void Integer::SetUnits(unsigned newUnits)
{
	this->units_ = newUnits;
}

bool Integer::GetSign() const
{
	return sign_;
}

unsigned Integer::GetUnits() const
{
	return units_;
}

bool Integer::IsEven() const
{
	return !(units_ % 2);
}

bool Integer::IsOdd() const
{
	return units_ % 2;
}

bool Integer::IsPositive() const
{
	return !sign_;
}

bool Integer::IsNegative() const
{
	return sign_;
}

bool Integer::IsPrime() const
{
	for (int i = 2; i <= sqrt(units_); i++) {
		if (units_ % i == 0) {
			return false;
		}
	}
	return true;
}

bool Integer::IsÑoprime(const Integer& A, const Integer& B)
{
	if (NOD(A, B) == 1)
	{
		return true;
	}
	return false;
}

bool Integer::IsTheSameObj(Integer& obj) const
{
	if (this == &obj)
	{
		return true;
	}
	return false;
}

Integer Integer::NOD(const Integer& A, const Integer& B)
{
	Integer result;
	if (A % B == 0)
	{
		if (B < 0)
		{
			return {!B.sign_, B.units_};
		}
		return { B.sign_, B.units_ };
	}
		
	if (B % A == 0)
	{
		if (A < 0)
		{
			return { !A.sign_, A.units_ };
		}
		return { A.sign_, A.units_ };
	}
	if (A > B)
	{
		result = NOD(A % B, B);
		return { false, result.units_ };
	}
	result = NOD(A, B % A);
	return { false, result.units_ };
}

Integer Integer::NOK(const Integer& A, const Integer& B)
{
	Integer result;
	result = (A * B) / NOD(A, B);
	return { false, result.units_ };
}

Integer operator+(const Integer& A, const Integer& B)
{
	Integer result;
	if (A.sign_ == B.sign_) {
		result.sign_ = A.sign_;
		result.units_ = A.units_ + B.units_;
	}
	else
	{
		if (A.units_ > B.units_)
		{
			result.sign_ = A.sign_;
			result.units_ = A.units_ - B.units_;
		}
		else if (A.units_ < B.units_) {
			result.sign_ = B.sign_;
			result.units_ = B.units_ - A.units_;
		}
		else {
			result.sign_ = false;
			result.units_ = true;
		}
	}
	return result;
}

Integer operator-(const Integer& A, const Integer& B)
{
	Integer tmp = B;
	tmp.sign_ = !tmp.sign_;
	return A + tmp;
}

Integer operator*(const Integer& A, const Integer& B)
{
	Integer result;
	for (int i = 0; i < B.GetUnits(); i++)
	{
		result.units_ += A.units_;
	}
	if (A.sign_ == B.sign_)
	{
		result.sign_ = false;
	}
	else
	{
		result.sign_ = true;
	}
	return result;
}

Integer operator/(const Integer& A, const Integer& B)
{
	if (B.units_ == 0)
	{
		std::cout << "!!ÍÅ ÄÅËÈ ÍÀ 0, ÍÅÓ×!!";
		return 0;
	}
	Integer result;
	result = {false, A.units_ / B.units_ };
	if (A.sign_ == B.sign_)
	{
		result.sign_ = false;
	}
	else
	{
		result.sign_ = true;
	}
	return result;
}

Integer operator%(const Integer& A, const Integer& B)
{
	Integer result = {false, A.units_ % B.units_ };
	if (A.sign_ || B.sign_ && result.units_ != 0)
	{
		result.sign_ = true;
	}
	return result;
}

Integer Integer::operator+=(Integer A)
{
	Integer result(*this);
	*this = *this + A;
	return result;
}

Integer Integer::operator-=(Integer A)
{
	Integer result(*this);
	*this = *this - A;
	return result;
}

Integer Integer::operator*=(Integer A)
{
	Integer result(*this);
	*this = *this * A;
	return result;
}

Integer Integer::operator/=(Integer A)
{
	Integer result(*this);
	*this = *this / A;
	return result;
}

Integer Integer::operator++()
{
	Integer result(*this);
	*this = sign_ ? *this - 1 : *this + 1;
	return result;
}

Integer Integer::operator++(int)
{	
	Integer result(*this);
	*this = sign_ ? *this - 1 : *this + 1;
	return result;
}

Integer Integer::operator--()
{
	Integer result(*this);
	*this = sign_ ? *this + 1 : *this - 1;
	return result;
}

Integer Integer::operator--(int)
{
	Integer result(*this);
	*this = sign_ ? *this + 1 : *this - 1;
	return result;
}

Integer Integer::operator+()
{
	return { sign_, units_ };
}

Integer Integer::operator-()
{
	return { !sign_, units_ };
}

bool Integer::operator!()
{
	return !sign_;
}

bool operator==(const Integer& A, const Integer& B)
{
	if (A.sign_ == B.sign_ && A.units_ == B.units_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Integer& A, const Integer& B)
{
	return !(A == B);
}

bool operator<(const Integer& A, const Integer& B)
{
	if (B.sign_ < A.sign_)
	{
		return false;
	}
	else if (B.sign_ && A.sign_) {
		if (B.units_ < A.units_) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (!B.sign_ && !A.sign_) {
		if (B.units_ > A.units_) {
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool operator<=(const Integer& A, const Integer& B)
{
	if (A == B || A < B)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(const Integer& A, const Integer& B)
{
	if (B.sign_ > A.sign_)
	{
		return false;
	}
	else if (B.sign_ && A.sign_) {
		if (B.units_ > A.units_) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (!B.sign_ && !A.sign_) {
		if (B.units_ < A.units_) {
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return true;
	}
}

bool operator>=(const Integer& A, const Integer& B)
{
	if (A == B || A > B)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const Integer obj)
{
	out << (obj.sign_ ? '-' : ' ') << obj.units_;
	return out;
}
