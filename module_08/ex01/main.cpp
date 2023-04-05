/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:48:45 by pedro             #+#    #+#             */
/*   Updated: 2023/04/05 19:13:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>

int	main(void) {
	
	// test basic functions
	std::cout << "\n=====BASIC=====\n" << std::endl;
	
	Span	test(5);
	
	test.addNumber(6);
	test.addNumber(3);
	test.addNumber(17);
	test.addNumber(9);
	test.addNumber(11);
	
	try {
		test.addNumber(10);
	} catch (std::exception &e) {
		std::cerr << "Could not fill test: " << e.what() << std::endl;
	}
	std::cout << test.longestSpan() << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	
	// test addMany and exception cases
	std::cout << "\n====ADDMANY AND EXCEPTIONS====\n" << std::endl;
	
	int	array[] = {6, 3, 17, 9, 11};
	Span	test_2(6);
	
	test_2.addNumber(42);
	try {
		std::cout << test_2.longestSpan() << std::endl;
		std::cout << test_2.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Couldn't get longest/shorted span: " << e.what() << std::endl;
	}
	test_2.addMany(array, array+5);
	
	std::cout << test_2.longestSpan() << std::endl;
	std::cout << test_2.shortestSpan() << std::endl;
	std::cout << test_2.longestSpan() << std::endl;
	std::cout << test_2.shortestSpan() << std::endl;
	
	try {
		test_2.addMany(array, array+5);
	} catch (std::exception &e) {
		std::cerr << "Couldn't add more elements to teste_2: " << e.what() << std::endl;
	}
	
	// test operator
	std::cout << "\n=====OPERATORS TESTS====\n" << std::endl;
	Span	test_3(6);
	test_3.addMany(array, array+5);
	Span	c(test_3);

	std::cout << "test_3 longest span: " << test_3.longestSpan() << std::endl;
	std::cout << "test_3 shortest span: " << test_3.shortestSpan() << std::endl;
	std::cout << "c longest span: " << c.longestSpan() << std::endl;
	std::cout << "c shortest span: " << c.shortestSpan() << std::endl;
	c.addNumber(20);
	std::cout << "c longest span: " << c.longestSpan() << std::endl;
	std::cout << "c shortest span: " << c.shortestSpan() << std::endl;
	std::cout << "test_3 longest span: " << test_3.longestSpan() << std::endl;
	std::cout << "test shortest span: " << test.shortestSpan() << std::endl;
	
	Span	d(2);
	
	try {
		d = test_3;
	} catch (std::exception &e) {
		std::cerr << "Couldn't assign test_3 to d: " << e.what() << std::endl;
	}
	
	Span	f(7);
	
	f = c;
	std::cout << "f longest span: " << f.longestSpan() << std::endl;
	std::cout << "f shortest span: " << f.shortestSpan() << std::endl;
	
	// 50000 test
	std::cout << "\n=====50 000 TEST====\n" << std::endl;
	int big[50000];
	
	srand(time(NULL));
	for (int i = 0; i < 50000; i++)
	{
		big[i] = rand() % RAND_MAX;
	}
	
	Span	bigSpan(50000);
	
	bigSpan.addMany(big, big + 50000);
	
	std::cout << "bigSpan longest span: " << bigSpan.longestSpan() << std::endl;
	std::cout << "bigSpan shortest span: " << bigSpan.shortestSpan() << std::endl;
	
	return (0);
}
