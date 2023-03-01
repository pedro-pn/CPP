/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:07:40 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/28 21:05:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void) : name("newbie") {
	std::cout << "newbie was BoRn!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " is dead!" << std::endl;
}

void	Zombie::announce(void) {
	std::string	announcement;

	announcement = "BraiiiiiiinnnzzzZ...";
	std::cout << this->name << ": " << announcement << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}
