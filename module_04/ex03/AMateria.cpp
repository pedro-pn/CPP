/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:55:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 19:32:17 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) {

}

AMateria::~AMateria(void) {

}

AMateria::AMateria(std::string const & type) : type(type) {

}

AMateria::AMateria(AMateria const & rhs) {
	*this = rhs;
}

AMateria&	AMateria::operator=(AMateria const & rhs) {
	if (this == &rhs)
		return (*this);
	return (*this);
}

std::string const & AMateria::getType(void) const {
	return (this->type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() \
	<< " *" << std::endl; 
}
