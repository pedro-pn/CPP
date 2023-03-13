/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:04:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 20:09:58 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	std::cout << "FragTrap constructor was called!" << std::endl;
	this->Hit = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor was called!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragtrap) : ClapTrap(fragtrap) {
	*this = fragtrap;
}

FragTrap&	FragTrap::operator=(FragTrap const &fragtrap) {
	if (this == &fragtrap)
		return (*this);
	this->AttackDamage = fragtrap.getAttackDamage();
	this->EnergyPoints = fragtrap.getEnergyPoints();
	this->Hit = fragtrap.getHit();
	this->Name = fragtrap.getName();
	return (*this);
}

void	FragTrap::highFiveGuys(void) {
	std::cout << this->Name << ": requests a High Five!" << std::endl;
}
