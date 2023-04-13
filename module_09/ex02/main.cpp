/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:55:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/13 14:03:16 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	checkArgs(int argc) {
	if (argc > 1)
		return (0);
	std::cerr << "PmergeMe error: insert a positive integer array" << std::endl;
	return (1);
}

int	main(int argc, char *argv[]) {
	if (checkArgs(argc))
		return (1);

	try {
		PmergeMe	sort(argv);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
