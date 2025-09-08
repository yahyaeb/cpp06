/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:16:59 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/08 12:12:24 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called." << std::endl;
} // or delete it

Serializer::Serializer(const Serializer &)
{
	std::cout << "Copy constructor called." << std::endl;
}

Serializer& Serializer::operator=(const Serializer &)
{
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Default destructor called." << std::endl;
};
