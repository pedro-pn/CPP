/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:15:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 10:43:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor was called!" << std::endl;
}

Dog::Dog(std::string const name) : Animal() {
	std::cout << "Dog named constructor was called!" << std::endl;
	setType(name);
}

Dog::~Dog(void) {
	std::cout << "Dog default destructor was called!" << std::endl;
}

Dog::Dog(Dog const &dog) : Animal() {
	std::cout << "Dog copy constructor was called!" << std::endl;
	*this = dog;
}

Dog&	Dog::operator=(Dog const &dog) {
	if (this == &dog)
		return (*this);
	this->setType(dog.getType());
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << getType() << ": WOOF WOOF!" << std::endl;
}
