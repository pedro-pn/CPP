/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:51:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 12:13:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure constructor was called!" << std::endl;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor was called!" << std::endl;
}

Cure::Cure(Cure const & rhs) : AMateria("cure") {
	std::cout << "Cure copy constructor was called!" << std::endl;
	*this = rhs;
}

Cure&	Cure::operator=(Cure const & rhs) {
	std::cout << "Cure assgiment operator was called!" << std::endl;
	(void)rhs;
	return (*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
