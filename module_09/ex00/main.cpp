/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:19:09 by pedro             #+#    #+#             */
/*   Updated: 2023/04/11 12:10:05 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	checkArgs(int argc) {
	if (argc < 2) {
		std::cerr << "btc error: missing input file." << std::endl;
		return (1);
	}
	if (argc > 2) {
		std::cerr << "btc error: insert only one input file." << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (checkArgs(argc))
		return (1);
	
	try {
		BitcoinExchange	btc("data.csv");
		btc.processInput(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
