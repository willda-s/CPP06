#include "PrintUtils.hpp"

static void printIntFrom(double v)
{
	if (v < -2147483648.0 || v >= 2147483648.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(v) << std::endl;
}

static void printDecimal(double v, const char* suffix, int maxDigits)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(maxDigits) << v;
	std::string out = oss.str();

	size_t dot = out.find('.');
	if (dot != std::string::npos)
	{
		size_t last = out.find_last_not_of('0');
		if (last == dot)
			last = dot + 1;
		out = out.substr(0, last + 1);
	}
	std::cout << out << suffix << std::endl;
}

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
	std::cout << "float: ";  printDecimal(static_cast<float>(c), "f", 6);
	std::cout << "double: "; printDecimal(static_cast<double>(c), "", 10);
}

void printFromInt(int num)
{
	if (num >= 0 && num <= 127)
		printChar(static_cast<char>(num));
	else
		std::cout << "char: impossible" << std::endl;
	
	std::cout << "int: " << num << std::endl;
	std::cout << "float: ";  printDecimal(static_cast<float>(num), "f", 6);
	std::cout << "double: "; printDecimal(static_cast<double>(num), "", 10);
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
		printIntFrom(static_cast<double>(f));
	}
	
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		printDecimal(static_cast<float>(f), "f", 6);
	
	std::cout << "double: ";
	if (std::isnan(f))
		std::cout << "nan" << std::endl;
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
		printDecimal(static_cast<double>(f), "", 6);
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
		printIntFrom(d);
	}
	
	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inff" : "-inff") << std::endl;
	else
		printDecimal(static_cast<float>(d), "f", 6);
	
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		printDecimal(static_cast<double>(d), "", 10);
}
