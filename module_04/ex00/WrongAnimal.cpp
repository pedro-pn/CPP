/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:27:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 10:43:56 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("foo") {
	std::cout << "WrongAnimal default constructor was called!" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor was called!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor was called!" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
	if (&wrongAnimal == this)
		return (*this);
	this->setType(wrongAnimal.getType());
	return (*this);	
}

std::string	WrongAnimal::getType(void) const{
	return (this->type);
}

void	WrongAnimal::setType(std::string const type) {
	this->type = type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Roger Roger!" << std::endl; 
}
