#include "ScalarConverter.hpp"
#include "ConversionUtils.hpp"
#include "PrintUtils.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal))
	{
		printFromChar(literal[0]);
	}
	else if (isInt(literal))
	{
		std::stringstream ss(literal);
		int num;
		ss >> num;
		printFromInt(num);
	}
	else if (isFloat(literal))
	{
		float f;
		if (literal == "nanf")
			f = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff")
			f = std::numeric_limits<float>::infinity();
		else if (literal == "-inff")
			f = -std::numeric_limits<float>::infinity();
		else
		{
			std::stringstream ss(literal.substr(0, literal.length() - 1));
			ss >> f;
		}
		printFromFloat(f);
	}
	else if (isDouble(literal))
	{
		double d;
		if (literal == "nan")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			d = std::numeric_limits<double>::infinity();
		else if (literal == "-inf")
			d = -std::numeric_limits<double>::infinity();
		else
		{
			std::stringstream ss(literal);
			ss >> d;
		}
		printFromDouble(d);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}
