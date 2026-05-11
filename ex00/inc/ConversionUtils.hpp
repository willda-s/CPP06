#ifndef CONVERSIONUTILS_HPP
# define CONVERSIONUTILS_HPP

#include <string>
#include <cctype>
#include <sstream>
#include <limits>

bool isChar(const std::string& str);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

#endif
