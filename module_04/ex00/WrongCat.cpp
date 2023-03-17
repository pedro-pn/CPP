/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:30:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 09:33:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor was called!" << std::endl;
}

WrongCat::WrongCat(std::string const name) : WrongAnimal() {
	std::cout << "WrongCat named constructor was called!" << std::endl;
	setType(name);
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat default destructor was called!" << std::endl;
}

WrongCat::WrongCat(WrongCat const &wrongCat) : WrongAnimal() {
	std::cout << "WrongCat copy constructor was called!" << std::endl;
	*this = wrongCat;
}

WrongCat&	WrongCat::operator=(WrongCat const &wrongCat) {
	if (this == &wrongCat)
		return (*this);
	*this = wrongCat.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << getType() << ": WOEEEEEEEEEEEEM!" << std::endl;
}
