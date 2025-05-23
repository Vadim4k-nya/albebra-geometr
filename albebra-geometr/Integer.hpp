#pragma once

#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include <Windows.h>
#include <string>

class Integer {
public:

	//������������

	//�� ���������
	Integer();

	//� ����������� ���� �����
	Integer(bool sign, unsigned units);

	//����������� int � ������
	Integer(int number);

	//����������� double � ������
	explicit Integer(double number);

	//����������� bool � ������
	explicit Integer(bool number);

	//����������� string � ������
	explicit Integer(std::string number);


	//������ ��� ������ � ������

	//������ ����
	void SetSign(bool newSign);

	//������ �������
	void SetUnits(unsigned newUnits);

	//�������� ����
	bool GetSign()const;

	//�������� �������
	unsigned GetUnits()const;


	//������ ����������� �������

	//��������
	bool IsEven()const;

	//�� ��������
	bool IsOdd()const;

	//���������������
	bool IsPositive()const;

	//���������������
	bool IsNegative()const;

	//��������
	bool IsPrime()const;

	//�������� ��������
	static bool Is�oprime(const Integer& A, const Integer& B);

	bool IsTheSameObj(Integer& obj)const;

	// ���������� ����� ��������
	static Integer NOD(const Integer& A, const Integer& B);

	//���������� ����� �������
	static Integer NOK(const Integer& A, const Integer& B);


	//���������� ����������

	friend Integer operator+(const Integer& A, const Integer& B);

	friend Integer operator-(const Integer& A, const Integer& B);

	friend Integer operator*(const Integer& A, const Integer& B);

	friend Integer operator/(const Integer& A, const Integer& B);

	friend Integer operator%(const Integer& A, const Integer& B);


	Integer operator+=(Integer A);

	Integer operator-=(Integer A);

	Integer operator*=(Integer A);

	Integer operator/=(Integer A);


	Integer operator++();

	Integer operator++(int);

	Integer operator--();

	Integer operator--(int);

	Integer operator+();

	Integer operator-();


	bool operator!();

	friend bool operator==(const Integer& A, const Integer& B);

	friend bool operator!=(const Integer& A, const Integer& B);

	friend bool operator<(const Integer& A, const Integer& B);

	friend bool operator<=(const Integer& A, const Integer& B);

	friend bool operator>(const Integer& A, const Integer& B);

	friend bool operator>=(const Integer& A, const Integer& B);


	friend std::ostream& operator<<(std::ostream& out, const Integer obj);

private:
	bool sign_;
	unsigned units_;
};

#endif // !INTEGER_HPP