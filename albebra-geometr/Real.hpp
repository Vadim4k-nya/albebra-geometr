#pragma once

#ifndef REAL_HPP
#define REAL_HPP

#include "Rational.hpp"
#include <cmath>

class Real {
public:
	Real();
	Real(Integer intPart, Rational ratPart);
	Real(int number);
	Real(double number);
	Real(std::string number);

	void SetIntPart(Integer& newIntPart);

	void SetRationalPart(Rational& newRatPart);

	Integer GetIntPart();

	Rational GetRationalPart();

	bool IsDecimal();

	bool IsTheSameObj(const Real& obj);

	bool IsNegative();

	bool IsPositive();

	friend Real operator+(const Real& A, const Real& B);

	friend Real operator-(const Real& A, const Real& B);

	friend Real operator*(const Real& A, const Real& B);

	friend Real operator/(const Real& A, const Real& B);

	//������������� ������ ���������� ���� ����� ������� (���� ��������)

	Real operator+();

	Real operator-();

	friend bool operator==(const Real& A, const Real& B);

	friend bool operator!=(const Real& A, const Real& B);

	friend bool operator<(const Real& A, const Real& B);

	friend bool operator<=(const Real& A, const Real& B);

	friend bool operator>(const Real& A, const Real& B);

	friend bool operator>=(const Real& A, const Real& B);

	friend std::ostream& operator<<(std::ostream& out, const Real obj);

private:
	Integer intPart_;
	Rational ratPart_;
};

#endif // !REAL_HPP
