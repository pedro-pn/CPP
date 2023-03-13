/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:24:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 20:10:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
	FragTrap	scav_1("Gertrudes");
	FragTrap	scav_2("Xerolaine");

	scav_1.attackTarget(scav_2);
	scav_1.attackTarget(scav_2);
	std::cout << "Xerolaine hit points: " << scav_2.getHit() << std::endl;
	scav_2.beRepaired(5);
	std::cout << "Xerolaine hit points: " << scav_2.getHit() << std::endl;
	scav_2.highFiveGuys();

	return (0);
}
