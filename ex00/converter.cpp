/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:12:58 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/08 11:11:32 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &)
{
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

static bool isChar(const std::string&literal)
{
	if (literal.empty())
		return false;
	if(literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		return true;
	}
	if (literal.length() == 3 && !std::isdigit(literal[1])
		&& literal[0] == '\'' && literal[2] == '\'' && std::isprint(literal[1]))
	{
		return true;
	}
	if (literal.length() == 3 && literal[0] == '"' && !std::isdigit(literal[1]) 
		&& literal[2] == '"' && std::isprint(literal[1]))
	{
		return true;
	}
	return false;
};

static bool isInt(const std::string &literal)
{
	if (literal.empty())
		return false;

	char *endptr;
	errno = 0;
	long val = strtol(literal.c_str(), &endptr, 10);

	if (*endptr != '\0' || endptr == literal.c_str())
	{
		return false;	
	}

	if (errno == ERANGE || val > MAX_INT || val < MIN_INT)
		return false;

	return true;
}

static bool isSpecialFloat(const std::string &literal)
{
	return literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff";
}

static bool isFloat(const std::string& literal)
{
	if (isSpecialFloat(literal))
		return true;

	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return false;

	std::string core = literal.substr(0, literal.length() - 1);
	if (core.empty())
		return false;
	char *endptr;
	errno = 0;
	std::strtof(core.c_str(), &endptr);  
	if (*endptr != '\0' || endptr == core.c_str())
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

static	bool isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf");
}

static bool isDouble(const std::string& literal)
{
	if (isPseudoLiteral(literal))
		return true;
	if (literal.empty())
		return false;
	char *endptr;
	errno = 0;
	std::strtod(literal.c_str(), &endptr);
	if (*endptr != '\0' || endptr == literal.c_str())
		return false;
	if (errno == ERANGE)
		return false;
	return true;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal)) 
	{
		printf("char: '%c'\n", literal[0]);
		printf("int: %d\n", static_cast<int>(literal[0]));
		printf("float: %.1ff\n", static_cast<float>(literal[0]));
		printf("double: %.1f\n", static_cast<double>(literal[0]));	
	}
	else if (isInt(literal))
	{
		int intValue = std::atoi(literal.c_str());
		if (std::isprint(intValue))
			printf("char: '%c'\n", static_cast<char>(intValue));
		else
			printf("char: Non displayable\n");
		printf("int: %d\n", intValue);
		printf("float: %.1ff\n", static_cast<float>(intValue));
		printf("double: %.1f\n", static_cast<double>(intValue));
	}
	else if (isFloat(literal))
	{
		char *endptr;
		float floatValue = std::strtof(literal.c_str(), &endptr);  
		if (std::isprint(static_cast<int>(floatValue)))
			printf("char: '%c'\n", static_cast<char>(floatValue));
		else
			printf("char: Non displayable\n");
		if (floatValue > MAX_INT || floatValue < MIN_INT || std::isnan(floatValue))
			printf("int: impossible\n");
		else
			printf("int: %d\n", static_cast<int>(floatValue));
		printf("float: %.1ff\n", floatValue);
		printf("double: %.1f\n", static_cast<double>(floatValue));
	}
	else if (isDouble(literal))
	{
		char *endptr;
		double doubleValue = std::strtod(literal.c_str(), &endptr);
		if (std::isprint(static_cast<int>(doubleValue)))
			printf("char: '%c'\n", static_cast<char>(doubleValue));
		else
			printf("char: Non displayable\n");
		if (doubleValue > MAX_INT || doubleValue < MAX_INT || std::isnan(doubleValue))
			printf("int: impossible\n");
		else
			printf("int: %d\n", static_cast<int>(doubleValue));
		if (doubleValue > MAX_FLOAT || doubleValue < -MAX_FLOAT)
			printf("float: impossible\n");
		else
			printf("float: %.1ff\n", static_cast<float>(doubleValue));
		printf("double: %.1f\n", doubleValue);
	}
	else
	{
		printf("char: impossible\n");
		printf("int: impossible\n");
		printf("float: impossible\n");
		printf("double: impossible\n");
	}
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./converter <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}