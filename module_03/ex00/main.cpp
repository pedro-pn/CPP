/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:29:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 10:20:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	robot_1("Brookisfild");
	ClapTrap	robot_2("Xerox");
	ClapTrap	robot_3;

	robot_3.attack(robot_1.getName());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.attack(robot_2.getName());
	robot_2.takeDamage(robot_1.getAttackDamage());
	robot_1.beRepaired(4);
	std::cout << "Bookisfild Hit: " << robot_1.getHit() << std::endl;

	robot_2.attack(robot_1.getName());
	robot_1.takeDamage(robot_2.getAttackDamage());
	robot_1.attack(robot_1.getName());
	robot_1.takeDamage(robot_2.getAttackDamage());

	return (0);
}