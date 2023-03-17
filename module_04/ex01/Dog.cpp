/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:15:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 13:27:49 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor was called!" << std::endl;
	this->brain = new Brain();
	
}

Dog::Dog(std::string const name) : Animal() {
	std::cout << "Dog named constructor was called!" << std::endl;
	setType(name);
	this->brain = new Brain();
}

Dog::~Dog(void) {
	std::cout << "Dog default destructor was called!" << std::endl;
	delete this->brain;
}

Dog::Dog(Dog const &dog) : Animal() {
	std::cout << "Dog copy constructor was called!" << std::endl;
	*this = dog;
}

Dog&	Dog::operator=(Dog const &dog) {
	if (this == &dog)
		return (*this);
	this->setType(dog.getType());
	*this->brain = *dog.brain;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << getType() << ": WOOF WOOF!" << std::endl;
}
