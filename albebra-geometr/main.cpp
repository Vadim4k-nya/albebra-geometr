#include "main.hpp"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "����� Integer: " << '\n';

	Integer num1 = 8;
	
	std::cout << num1 << '\n';

	std::cout << num1 << " ������? : " << num1.isEven() << '\n';
	std::cout << num1 << " �� ������? : " << num1.isOdd() << '\n';
	std::cout << num1 << " �������������? : " << num1.isPositive() << '\n';
	std::cout << num1 << " �������������? : " << num1.isNegative() << '\n';
	std::cout << num1 << " �������? : " << num1.isPrime() << '\n';

	Integer num2 = 3;

	std::cout << num1 << " � " << num2 << " ������� �������? : " << Integer::is�oprime(num1, num2) << '\n';
	std::cout << "���������� ����� �������� " << num1 << " � " << num2 << "? : " << Integer::NOD(num1, num2) << '\n';
	std::cout << "���������� ����� ������� " << num1 << " � " << num2 << "? : " << Integer::NOK(num1, num2) << "\n\n";


	std::cout << "num1 = " << num1 
		<< "\nnum2 = " << num2 << "\n\n";
	std::cout << "num1 + num2 = " << num1 + num2 << '\n';
	std::cout << "num1 - num2 = " << num1 - num2 << '\n';
	std::cout << "num1 * num2 = " << num1 * num2 << '\n';
	std::cout << "num1 % num2 = " << num1 % num2 << '\n';
	std::cout << "num1 / num2 = " << num1 / num2 << "\n\n";

	++num1;
	std::cout << "++num1: " << num1 << "\n";
	num1++;
	std::cout << "num1++: " << num1 << "\n";
	--num1;
	std::cout << "--num1: " << num1 << "\n";
	num1--;
	std::cout << "num1--: " << num1 << "\n\n";

	return 0;
}
