#include "ConversionUtils.hpp"

bool isChar(const std::string& str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

bool isInt(const std::string& str)
{
	if (str.empty() || (str.length() == 1 && (str[0] == '-' || str[0] == '+')))
		return false;
	
	size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	
	for (size_t i = start; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	
	std::stringstream ss(str);
	long value;
	if (!(ss >> value))
		return false;
	
	return (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
}

bool isFloat(const std::string& str)
{
	if (str.empty() || str[str.length() - 1] != 'f')
		return false;
	
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	
	std::string withoutF = str.substr(0, str.length() - 1);
	if (withoutF.empty())
		return false;
	
	int dotCount = 0;
	int digitCount = 0;
	size_t start = (withoutF[0] == '-' || withoutF[0] == '+') ? 1 : 0;
	
	if (start == withoutF.length())
		return false;
	
	for (size_t i = start; i < withoutF.length(); i++)
	{
		if (withoutF[i] == '.')
			dotCount++;
		else if (std::isdigit(str[i]))
			digitCount++;
		else
			return false;
	}
	return (dotCount <= 1 && digitCount > 0);
}

bool isDouble(const std::string& str)
{
	if (str.empty())
		return false;
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	
	if (str[str.length() - 1] == 'f')
		return false;
	
	int dotCount = 0;
	int digitCount = 0;
	size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	
	if (start == str.length())
		return false;
	
	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
			dotCount++;
		else if (std::isdigit(str[i]))
			digitCount++;
		else
			return false;
	}
	return (dotCount <= 1 && digitCount > 0);
}
