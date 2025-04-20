#pragma once

#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>
#include <Windows.h>
#include <string>

class Integer {
public:

	//Конструкторы

	//по умолчанию
	Integer();

	//с заполнением всех полей
	Integer(bool sign, unsigned units);

	//конвертация int в объект
	Integer(int number);

	//конвертация double в объект
	explicit Integer(double number);

	//конвертация bool в объект
	explicit Integer(bool number);

	//конвертация string в объект
	explicit Integer(std::string number);


	//Методы для работы с полями

	//задать знак
	void SetSign(bool newSign);

	//задать еденицы
	void SetUnits(unsigned newUnits);

	//получить знак
	bool GetSign()const;

	//получить еденицы
	unsigned GetUnits()const;


	//Методы определения свойств

	//Четность
	bool isEven()const;

	//Не четность
	bool isOdd()const;

	//Положительность
	bool isPositive()const;

	//Отрицательность
	bool isNegative()const;

	//Простота
	bool isPrime()const;

	//Взаимная простота
	static bool isСoprime(const Integer& A, const Integer& B);

	// Наибольший общий делитель
	static Integer NOD(const Integer& A, const Integer& B);

	//Наименьшее общее кратное
	static Integer NOK(const Integer& A, const Integer& B);


	//перегрузки операторов

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