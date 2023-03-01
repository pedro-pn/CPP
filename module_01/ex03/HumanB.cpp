/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:53:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/01 10:47:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {

}

HumanB::~HumanB(void) {

}

void	HumanB::attack(void) {
	if (this->weapon == NULL){
		std::cout << this->name << " has no weapon to attack!" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
