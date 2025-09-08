/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:16:53 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/08 12:09:50 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <string.h>


struct Data
{
	int	value;
};

class Serializer {
private:
	Serializer(); // or delete it
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}
	static Data* deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data*>(raw);
	}
};
