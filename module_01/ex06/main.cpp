/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:23:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/02 21:08:43 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

static int	get_start_level(std::string input) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			index;

	for (index = 0; index < 4; index++) {
		if (levels[index] == input)
			return (index) ;
	}
	return (-1);
}

void	harl_filter(Harl harl, int index)
{
	for (int i = index; i < 4; i++) {
		switch (i) {
			case (0):
				harl.complain("DEBUG");
				break ;
			case (1):
				harl.complain("INFO");
				break ;
			case (2):
				harl.complain("WARNING");
				break ;
			case (3):
				harl.complain("ERROR");
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return ;
		}
		std::cout << std::endl;
	}
}

int	main(int argc, char *argv[]) {
	Harl		harl;
	int			index;

	if (argc != 2){
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	index = get_start_level(argv[1]);
	harl_filter(harl, index);
	return (0);
}
