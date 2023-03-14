/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:24:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 16:50:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	ScavTrap	scav_1("Gertrudes");
	ScavTrap	scav_2("Xerolaine");
	ScavTrap	scav_3;

	scav_3.attack(scav_1.getName());
	scav_1.takeDamage(scav_3.getAttackDamage());
	scav_1.attack(scav_2.getName());
	scav_2.takeDamage(scav_1.getAttackDamage());
	scav_1.attack(scav_2.getName());
	scav_2.takeDamage(scav_1.getAttackDamage());

	std::cout << "Xerolaine hit points: " << scav_2.getHit() << std::endl;
	scav_2.beRepaired(5);
	std::cout << "Xerolaine hit points: " << scav_2.getHit() << std::endl;
	scav_2.guardGate();

	return (0);
}
