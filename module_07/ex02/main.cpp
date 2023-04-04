/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:50:20 by pedro             #+#    #+#             */
/*   Updated: 2023/04/03 22:34:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main(void) {
	
	// Test with array of int
	std::cout << "\n===Array of ints test===\n" << std::endl;
	Array<int> a(5);
	
	std::cout << a.size() << std::endl;
	a[0] = 40;
	a[1] = 41;
	a[2] = 42;
	a[3] = 43;
	a[4] = 44;
	std::cout << "a array: ";
	a.print();
	std::cout << a[4] << std::endl;
	
	// test of copy operator
	std::cout << "\n===Copy operator test===\n" << std::endl;
	Array<int> b(a);
	std::cout << "b array: ";
	b.print();
	std::cout << b[4] << std::endl;
	std::cout << b.size() << std::endl;
	
	b[0] = 99;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
	
	Array<int> c(5);
	c = a;
	
	std::cout << c[4] << std::endl;
	std::cout << c.size() << std::endl;
	
	c[0] = 99;
	std::cout << a[0] << std::endl;
	std::cout << c[0] << std::endl;
	
	Array<int> d;
	
	try {
		d = a;
	} catch (std::exception &e)
	{
		std::cout << "Could not assign a to d: " << e.what() << std::endl;
	}
	
	// char array tests
	std::cout << "\n ==== Array of char tests=====\n" << std::endl;
	
	Array<char>	charArray(6);
	
	charArray[0] = 'b';
	charArray[1] = 'a';
	charArray[2] = 'n';
	charArray[3] = 'a';
	charArray[4] = 'n';
	charArray[5] = 'a';
	
	charArray.print();

	return (0);
}
