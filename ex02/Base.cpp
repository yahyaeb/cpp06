/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:21:11 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/09 18:59:55 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	int random_num = std::rand() % 3;

	if(random_num == 0)
		return new A;
	if(random_num == 1)
		return new B;
	return new C;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...){}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...){}
		try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...){}
}

int main() {

	std::srand(static_cast<unsigned int>(time(0)));
	// Generate random object
	Base* ptr = generate();

	// Test identify(Base*)
	std::cout << "identify(Base*): ";
	identify(ptr);

	// Test identify(Base&)
	std::cout << "identify(Base&): ";
	identify(*ptr);

	// Clean up memory
	delete ptr;

	return 0;
}