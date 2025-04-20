#pragma once

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include "Integer.hpp"

class Rational {
public:

	//Конструкторы

	Rational();
	Rational(Integer numerator, Integer denominator);
	explicit Rational(int numerator, int denominator);
	explicit Rational(double number);
	explicit Rational(std::string number);

	//Способы обработки объектов

	void SetNumerator(Integer& newNumerator);

	void SetDeniminator(Integer& newDeniminator);

	Integer GetNumerator()const;

	Integer GetDenominator()const;

	//Способы проверки состояния

	//Правильность дроби
	bool IsProper()const;

	bool IsNotProper()const;

	//Положительность дроби
	bool IsPositive()const;

	bool IsNegative()const;

	//Являются ли 2 числа одним и тем же объектом в программе
	bool IsTheSameObj(Rational& obj)const;

	// Методы для получения значений

	//Обратная дробь
	Rational Reverse();

	//Упрощение дроби
	Rational Simplifying();

	//Найти целую часть
	Integer IntParts();

	//Найти дробную часть
	Rational FractPart();

	// Методы для модификации дроби

	//Модификатор упрощения дроби
	void ModSimplifying();

	//Медификатор переворачивания дроби
	void ModReverse();

	// Операторы

	friend Rational operator+(const Rational& A, const Rational& B);

	friend Rational operator-(const Rational& A, const Rational& B);

	friend Rational operator*(const Rational& A, const Rational& B);

	friend Rational operator/(const Rational& A, const Rational& B);

	//Присваивающие версии операторов надо будет сделать (если возможно)

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
