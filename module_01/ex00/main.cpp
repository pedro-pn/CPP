/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/13 10:19:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void) {
	Zombie	*carlos_eduardo;
	
	carlos_eduardo  = newZombie("Carlos Eduardo");
	carlos_eduardo->announce();
	randomChump("Carimbo");
	
	std::cout << "Carlos Eduardo is still alive!" << std::endl;
	delete carlos_eduardo;
	return (0);
}
