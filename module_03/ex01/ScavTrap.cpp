/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:13:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 10:33:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->Hit = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap default constructor was called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->Hit = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap named constructor was called!" << std::endl;
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

void	ScavTrap::attack(const std::string &target) {
	if (this->Hit == 0){
		std::cout << this->Name << " is dead!" << std::endl;
		return ;
	}
	if (this->EnergyPoints == 0) {
		std::cout << this->Name << " doesn't have enough Energy Points!" << std::endl;
		return ;
	}
	this->EnergyPoints--;;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() <<  " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << this->Name << " is in Gate Keeper mode!" << std::endl;
}
