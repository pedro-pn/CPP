/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/28 23:09:25 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int	main(void) {
	Zombie	*horde;
	int		zombie_num;
	
	zombie_num = 10;
	horde = zombieHorde(zombie_num, "Shekira");
	for (int i = 0; i < zombie_num; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
