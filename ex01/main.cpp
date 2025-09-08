/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:10:26 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/08 12:15:37 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->value = 42;
	
	std::cout << "Original pointer:   " << data << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "Serialized uintptr: " << raw << std::endl;
	// std::cout << "Serialized uintptr (hex): 0x" << std::hex << raw << std::dec << std::endl;

	Data *serialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << serialized << std::endl;
	std::cout << "Value: " << serialized->value << std::endl;

	delete data;
	return 0;
}
