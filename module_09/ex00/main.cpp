/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:19:09 by pedro             #+#    #+#             */
/*   Updated: 2023/04/10 22:15:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	main(void)
{
	BitcoinExchange	btc("data.csv");
	
	try {
		btc.processInput("teste.txt");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}