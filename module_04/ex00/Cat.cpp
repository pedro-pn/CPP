/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:04:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 11:49:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor was called!" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat default destructor was called!" << std::endl;
}

Cat::Cat(Cat const &cat) : Animal() {
	std::cout << "Cat copy constructor was called!" << std::endl;
	*this = cat;
}

Cat&	Cat::operator=(Cat const &cat) {
	if (this == &cat)
		return (*this);
	this->setType(cat.getType());
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << getType() << ": MEOOOOOOOOOOOOOOOOOWWW!" << std::endl;
}
