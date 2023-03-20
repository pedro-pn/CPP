/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:51:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 18:51:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::~Cure(void) {}

Cure::Cure(Cure const & rhs) : AMateria("cure") {
	*this = rhs;
}

Cure&	Cure::operator=(Cure const & rhs) {
	return (*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}
