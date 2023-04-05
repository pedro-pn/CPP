/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:52:04 by pedro             #+#    #+#             */
/*   Updated: 2023/04/05 19:42:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>

int	main(void){
	// List container test
	std::cout << "\n======LIST TEST=====\n" << std::endl;
	std::list<int>	lst;
	int				b;

	lst.push_back(5);
	lst.push_back(4);
	lst.push_back(7);
	b = easyfind(lst, 5);
	std::cout << b << std::endl;
	try {
		b = easyfind(lst, 50);
	} catch (std::exception &e) {
		std::cout << "Error:\nWhat(): " << e.what() << std::endl;
	}

	// Vector container test
	std::cout << "\n======VECTOR TEST=====\n" << std::endl;

	std::vector<int>	vec;

	vec.push_back(40);
	vec.push_back(41);
	vec.push_back(42);
	vec.push_back(43);
	b = easyfind(vec, 42);
	std::cout << b << std::endl;
	try {
		b = easyfind(vec, 50);
	} catch (std::exception &e) {
		std::cout << "Error:\nWhat(): " << e.what() << std::endl;
	}

	// Deque container test
	std::cout << "\n======DEQUE TEST=====\n" << std::endl;

	std::deque<int>	deq;

	deq.push_back(50);
	deq.push_back(51);
	deq.push_back(52);
	deq.push_back(53);
	deq.push_back(54);
	deq.push_back(55);
	deq.push_back(56);
	b = easyfind(deq, 53);
	std::cout << b << std::endl;
	try {
		b = easyfind(deq, 42);
	} catch (std::exception &e) {
		std::cout << "Error:\nWhat(): " << e.what() << std::endl;
	}

	return (0);
}
