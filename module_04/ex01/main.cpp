/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 13:38:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void) {
	Animal *animals[6];

	for (int i = 0; i < 3; i++) {
		animals[i] = new Cat();
	}
	for (int i = 3; i < 6; i++) {
		animals[i] = new Dog();
	}
	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}

	std::cout << std::endl << "==== End of subject tests ====" << std::endl;
	Animal	*dog = new Dog("romeu");
	Animal	*cat = new Cat("Romeu");
	//fazer getter and setter do brain em Dog e Cat

	
}
