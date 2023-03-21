/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:46:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 11:34:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#define my_delete(x) {delete x; x = NULL;}

MateriaSource::MateriaSource(void) : IMateriaSource(){
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		my_delete(this->slots[i]);
	}
}

MateriaSource::MateriaSource(MateriaSource const & rhs) : IMateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
	*this = rhs;
}

MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs) {
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++) {
		my_delete(this->slots[i]);
		this->slots[i] = rhs.slots[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *mat) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == NULL) {
			this->slots[i] = mat;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != NULL) {
			if (this->slots[i]->getType() == type)
				return (this->slots[i]->clone());
		}
	}
	return (NULL);
}