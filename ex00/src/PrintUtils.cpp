#include "PrintUtils.hpp"

static void printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printFromChar(char c)
{
	printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void printFromInt(int num)
{
	if (num >= 0 && num <= 127)
		printChar(static_cast<char>(num));
	else
		std::cout << "char: impossible" << std::endl;
	
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void printFromFloat(float f)
{
	if (std::isnan(f) || std::isinf(f))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (f >= 0 && f <= 127)
			printChar(static_cast<char>(f));
		else
			std::cout << "char: impossible" << std::endl;
		
		if (f > (float)2147483647 || f < (float)-2147483648)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	
	std::cout << "double: ";
	if (std::isnan(f))
		std::cout << "nan" << std::endl;
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void printFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (d >= 0 && d <= 127)
			printChar(static_cast<char>(d));
		else
			std::cout << "char: impossible" << std::endl;
		
		if (d > 2147483647 || d < -2147483648)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	
	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}
