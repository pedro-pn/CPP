/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:29:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 18:58:09 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	robot_1("Brookisfild");
	ClapTrap	robot_2("Xerox");

	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.attackTarget(robot_2);
	robot_1.beRepaired(4);
	std::cout << "Bookisfild Hit: " << robot_1.getHit() << std::endl;

	robot_2.attackTarget(robot_1);

	robot_1.attackTarget(robot_1);

	return (0);
}