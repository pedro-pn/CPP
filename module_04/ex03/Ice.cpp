/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:15:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 19:16:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void) {}

Ice::Ice(Ice const & rhs) : AMateria("ice") {
	*this = rhs;
}

Ice&	Ice::operator=(Ice const & rhs) {
	return (*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void	Ice::use(int idx, ICharacter& target) {
	
}