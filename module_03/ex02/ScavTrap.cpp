/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:13:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 19:32:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->Hit = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap constructor was called!" << std::endl;
} 

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor was called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavtrap) : ClapTrap(scavtrap) {
	std::cout << "ScavTrap copy constructor was called!" << std::endl;
	*this = scavtrap;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &scavtrap) {
	if (this == &scavtrap)
		return (*this);
	this->AttackDamage = scavtrap.getAttackDamage();
	this->EnergyPoints = scavtrap.getEnergyPoints();
	this->Hit = scavtrap.getHit();
	this->Name = scavtrap.getName();
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << this->Name << " is in Gate Keeper mode!" << std::endl;
}
