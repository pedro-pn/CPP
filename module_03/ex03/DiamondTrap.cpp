/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:31:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 17:45:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor was called!" << std::endl;
	this->Name = "Newbie";
	ClapTrap::Name = this->Name + "_clap_name";
	this->Hit = FragTrap::Hit;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name) {
	std::cout << "DiamondTrap named constructor was called!" << std::endl;
	this->Hit = FragTrap::Hit;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor was called!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamondtrap) :  ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap) {
	std::cout << "DiamondTrap copy constructor was called!" << std::endl;
	*this = diamondtrap;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &diamondtrap) {
	if (this == &diamondtrap)
		return (*this);
	this->AttackDamage = diamondtrap.getAttackDamage();
	this->EnergyPoints = diamondtrap.getEnergyPoints();
	this->Hit = diamondtrap.getHit();
	this->Name = diamondtrap.getName();
	ClapTrap::Name = diamondtrap.getName() + "_clap_name";
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "My DiamondTrap name is: " << this->Name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::Name << std::endl;;
}
