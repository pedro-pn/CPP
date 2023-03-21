/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:55:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 12:02:17 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) {
	std::cout << "AMateria constructor was called!" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor was called!" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "AMateria types constructor was called!" << std::endl;
}

AMateria::AMateria(AMateria const & rhs) {
	std::cout << "AMateria copy constructor was called!" << std::endl;
	*this = rhs;
}

AMateria&	AMateria::operator=(AMateria const & rhs) {
	std::cout << "AMateria assigment operator was called!" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

std::string const & AMateria::getType(void) const {
	return (this->type);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
	return ;
}
