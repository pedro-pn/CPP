/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:24:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 19:24:29 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	DiamondTrap	dia_1("Gertrudes");
	DiamondTrap	dia_2("Xerolaine");

	dia_1.attack(dia_2.getName());
	dia_2.takeDamage(dia_1.getAttackDamage());
	dia_2.whoAmI();

	dia_1.highFiveGuys();
	dia_1.beRepaired(40);
	dia_1.guardGate();

	return (0);
}
