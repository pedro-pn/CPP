/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:37:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 11:46:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("foo") {
	std::cout << "Animal default constructor was called!" << std::endl;
}

Animal::Animal(std::string const &type) : type(type) {
	std::cout << "Animal typed constructor was called!" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor was called!" << std::endl;
}

Animal::Animal(Animal const &animal) {
	std::cout << "Animal copy constructor was called!" << std::endl;
	*this = animal;
}

Animal&	Animal::operator=(Animal const &animal) {
	if (&animal == this)
		return (*this);
	this->type = animal.getType();
	return (*this);	
}

std::string	Animal::getType(void) const{
	return (this->type);
}

void	Animal::setType(std::string const type) {
	this->type = type;
}

void	Animal::makeSound(void) const {
	std::cout << "What does an Animal say?" << std::endl; 
}
