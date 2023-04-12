/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:55:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/12 16:40:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char *argv[]) {
	(void)argc;
	try {
		PmergeMe	sort(argv);
		for (std::vector<int>::iterator it = sort._vector.begin(); it != sort._vector.end(); ++it) {
			std::cout << *it << std::endl;
		}
		// for (std::list<int>::iterator it = sort._list.begin(); it != sort._list.end(); ++it) {
		// 	std::cout << *it << std::endl;
		// }
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}