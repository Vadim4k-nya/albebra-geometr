#pragma once

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include "Integer.hpp"

class Rational {
public:

	//������������

	Rational();
	Rational(Integer numerator, Integer denominator);
	explicit Rational(int numerator, int denominator);
	explicit Rational(double number);
	explicit Rational(std::string number);

	//������� ��������� ��������

	void SetNumerator(Integer& newNumerator);

	void SetDeniminator(Integer& newDeniminator);

	Integer GetNumerator()const;

	Integer GetDenominator()const;

	//������� �������� ���������

	//������������ �����
	bool IsProper()const;

	bool IsNotProper()const;

	//��������������� �����
	bool IsPositive()const;

	bool IsNegative()const;

	//�������� �� 2 ����� ����� � ��� �� �������� � ���������
	bool IsTheSameObj(Rational& obj)const;

	// ������ ��� ��������� ��������

	//�������� �����
	Rational Reverse();

	//��������� �����
	Rational Simplifying();

	//����� ����� �����
	Integer IntParts();

	//����� ������� �����
	Rational FractPart();

	// ������ ��� ����������� �����

	//����������� ��������� �����
	void ModSimplifying();

	//����������� ��������������� �����
	void ModReverse();

	// ���������

	friend Rational operator+(const Rational& A, const Rational& B);

	friend Rational operator-(const Rational& A, const Rational& B);

	friend Rational operator*(const Rational& A, const Rational& B);

	friend Rational operator/(const Rational& A, const Rational& B);

	//������������� ������ ���������� ���� ����� ������� (���� ��������)

	Integer operator+();

	Integer operator-();

	friend bool operator==(const Rational& A, const Rational& B);

	friend bool operator!=(const Rational& A, const Rational& B);

	friend bool operator<(const Rational& A, const Rational& B);

	friend bool operator<=(const Rational& A, const Rational& B);

	friend bool operator>(const Rational& A, const Rational& B);

	friend bool operator>=(const Rational& A, const Rational& B);

	friend std::ostream& operator<<(std::ostream& out, const Rational obj);

private:
	Integer numerator_;
	Integer denominator_;
};

#endif // !RATIONAL_HPP
