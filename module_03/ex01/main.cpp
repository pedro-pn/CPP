/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:24:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 19:46:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	ScavTrap	scav_1("Gertrudes");
	ScavTrap	scav_2("Xerolaine");

	scav_1.attackTarget(scav_2);
	scav_1.attackTarget(scav_2);
	std::cout << "Xerolaine hit points: " << scav_2.getHit() << std::endl;
	scav_2.beRepaired(5);
	std::cout << "Xerolaine hit points: " << scav_2.getHit() << std::endl;
	scav_2.guardGate();

	return (0);
}
