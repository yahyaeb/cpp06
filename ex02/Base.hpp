/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:21:18 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/08 12:53:29 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base() {}
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);