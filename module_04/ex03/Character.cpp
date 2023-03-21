/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:09:32 by ppaulo-d          #+#    #+#          	   */
/*   Updated: 2023/03/21 11:06:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#define my_delete(x) {delete x; x = NULL;}

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

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != NULL)
			my_delete(this->slots[i]);
	}
}

Character::Character(Character const &rhs) : ICharacter() {
	for (int i = 0; i < 4; i++) {
		this->slots[i] = NULL;
	}
	*this = rhs;
}

Character&	Character::operator=(Character const &rhs) {
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != NULL)
			my_delete(this->slots[i]);
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
	if (idx < 0 || idx > 3)
		return ;
	this->slots[idx] = NULL;
}

std::string const &	Character::getName(void) const {
	return (this->name);
}
