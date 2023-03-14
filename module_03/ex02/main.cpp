/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:24:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 16:56:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
	FragTrap	frag_1("Gertrudes");
	FragTrap	frag_2("Xerolaine");
	FragTrap	frag_3;

	frag_3.highFiveGuys();

	frag_1.attack(frag_2.getName());
	frag_2.takeDamage(frag_1.getAttackDamage());
	frag_1.attack(frag_2.getName());
	frag_2.takeDamage(frag_1.getAttackDamage());
	std::cout << "Xerolaine hit points: " << frag_2.getHit() << std::endl;
	frag_2.beRepaired(5);
	std::cout << "Xerolaine hit points: " << frag_2.getHit() << std::endl;
	frag_2.highFiveGuys();

	return (0);
}
