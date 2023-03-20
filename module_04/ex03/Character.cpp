/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:09:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 20:02:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : ICharacter() {
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
}

Character::Character(std::string const & name) : ICharacter(), name(name) {
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
}

Character::~Character(void) {}

Character::Character(Character const &rhs) : ICharacter(){
	*this = rhs;
}

Character&	Character::operator=(Character const &rhs) {
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != NULL)
			delete this->slots[i];
		this->slots[i] = rhs.slots[i]->clone();
	}
	this->name = rhs.getName();
	return (*this);
}

void	Character::use(int idx, ICharacter& target) {
	if (this->slots[idx] == NULL)
		return ;
	this->slots[idx]->use(target);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == NULL) {
			this->slots[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx) {
	this->slots[idx] == NULL;
}

std::string const &	Character::getName(void) const {
	return (this->name);
}
