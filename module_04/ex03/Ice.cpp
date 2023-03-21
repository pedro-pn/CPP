/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:15:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 12:13:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice constructor was called!" << std::endl;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor was called!" << std::endl;
}

Ice::Ice(Ice const & rhs) : AMateria("ice") {
	std::cout << "Ice copy constructor was called!" << std::endl;
	*this = rhs;
}

Ice&	Ice::operator=(Ice const & rhs) {
	std::cout << "Ice assigment operator was called!" << std::endl;
	(void)rhs;
	return (*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() \
	<< " *" << std::endl; 
}
