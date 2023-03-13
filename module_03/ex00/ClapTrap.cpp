/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:44:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 18:35:10 by ppaulo-d         ###   ########.fr       */
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
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() <<  " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->Hit == 0)
		return ;
	this->Hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->EnergyPoints == 0) {
		std::cout << this->Name << " doesn't have enough Energy Points!" << std::endl;
		return ;
	}
	this->Hit += amount;
	this->EnergyPoints -= 1;

}

void	ClapTrap::attackTarget(ClapTrap& target) {
	if (this == &target){
		std::cout << this->Name << " cannot attack itself!" << std::endl;
	}
	if (this->Hit == 0)
		return ;
	if (this->EnergyPoints == 0) {
		std::cout << this->Name << " doesn't have enough Energy Points!" << std::endl;
		return ;
	}
	this->attack(target.getName());
	target.takeDamage(this->getAttackDamage());
}
