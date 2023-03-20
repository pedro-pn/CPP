/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:46:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 19:52:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}

}

MateriaSource::~MateriaSource(void) {

}

MateriaSource::MateriaSource(MateriaSource const & rhs) {
	*this = rhs;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs) {
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++) {
		delete this->slots[i];
		this->slots[i] = rhs.slots[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *mat) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == NULL) {
			this->slots[i] == mat->clone();
			break ;
		}
	}
}