/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:11:31 by pedro             #+#    #+#             */
/*   Updated: 2023/03/30 10:39:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer(void) {
	std::cout << "Serializer constructor was called!" << std::endl;
}

Serializer::~Serializer(void) {
	std::cout << "Serializer destructor was called!" << std::endl;
}

Serializer::Serializer(Serializer const &rhs) {
	std::cout << "Serializer copy constructor was called!" << std::endl;
	*this = rhs;
}

Serializer&	Serializer::operator=(Serializer const &rhs) {
	std::cout << "Serializer assigment operator was called!" << std::endl;
	(void)rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
