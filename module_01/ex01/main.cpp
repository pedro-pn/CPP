/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/28 21:07:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int	main(void) {
	Zombie	*horde;
	int		zombie_num;
	
	zombie_num = 500;
	horde = zombieHorde(zombie_num, "Shekira");
	for (int i = 0; i < zombie_num; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
