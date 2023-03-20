/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:37:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 11:48:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : type("foo") {
	std::cout << "Animal default constructor was called!" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor was called!" << std::endl;
}

AAnimal::AAnimal(AAnimal const &animal) {
	std::cout << "Animal copy constructor was called!" << std::endl;
	*this = animal;
}

AAnimal&	AAnimal::operator=(AAnimal const &animal) {
	if (&animal == this)
		return (*this);
	this->setType(animal.getType());
	return (*this);	
}

std::string	AAnimal::getType(void) const{
	return (this->type);
}

void	AAnimal::setType(std::string const type) {
	this->type = type;
}

void	AAnimal::makeSound(void) const {
	std::cout << "What does an Animal say?" << std::endl; 
}
