/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:12:58 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/07 10:24:30 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"
#include  <cstdio>


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

    size_t i = 0;

    // Handle optional sign
    if (literal[i] == '+' || literal[i] == '-')
        ++i;

    // String cannot be just a sign
    if (i == literal.length())
        return false;

    // All remaining chars must be digits
    for (; i < literal.length(); ++i)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
	if(literal.length() > 11)
		return false;
	// try {
    //     // Use stoll to handle overflows cleanly
    //     long long val = std::stoll(literal);
    //     if (val < MIN_INT || val > MAX_INT)
    //         return false;
    // } catch (...) {
    //     return false; // Conversion failed (overflow, invalid)
    // }

		return false;
    return true;
}


// static bool isFloat(const std::string&)
// {
// }

// static bool isDouble(const std::string&)
// {
	
// }

// static bool isPseudoLiteral(const std::string&)
// {
	
// }
int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./converter <literal>" << std::endl;
		return 1;
	}
	bool results = isChar(argv[1]);
	bool results2 = isInt(argv[1]);
	printf("isInt: %d\n", results2);
	printf("isChar: %d\n", results);
	return 0;
}