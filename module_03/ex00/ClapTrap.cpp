/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:44:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 10:13:02 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : Name(name) {
	std::cout << "ClapTrap constructor was called!" << std::endl;
	this->Hit = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor was called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap) {
	*this = claptrap;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &claptrap) {
	if (this == &claptrap)
		return (*this);
	this->AttackDamage = claptrap.getAttackDamage();
	this->EnergyPoints = claptrap.getEnergyPoints();
	this->Hit = claptrap.getHit();
	this->Name = claptrap.getName();
	return (*this);
}

std::string	ClapTrap::getName(void) const {
	return (this->Name);
}
int			ClapTrap::getHit(void) const {
	return (this->Hit);
}

int			ClapTrap::getEnergyPoints(void) const {
	return (this->EnergyPoints);
}

int			ClapTrap::getAttackDamage(void) const {
	return (this->AttackDamage);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->Hit == 0){
		std::cout << this->Name << " is dead!" << std::endl;
		return ;
	}
	if (this->EnergyPoints == 0) {
		std::cout << this->Name << " doesn't have enough Energy Points!" << std::endl;
		return ;
	}
	this->EnergyPoints--;;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() <<  " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->Hit == 0)
		return ;
	std::cout << this->Name << " takes " << amount << " points of damage!" << std::endl;
	this->Hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->EnergyPoints == 0) {
		std::cout << this->Name << " doesn't have enough Energy Points!" << std::endl;
		return ;
	}
	if (this->Hit <= 0) {
		std::cout << this->Name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->Name << " repaired " << amount << " Hit points!" << std::endl;
	this->Hit += amount;
	this->EnergyPoints -= 1;
}
