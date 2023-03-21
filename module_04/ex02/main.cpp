/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/21 12:00:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void) {
	AAnimal *animals[6];
	// AAnimal teste = AAnimal();

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
	Dog	dog = Dog();
	Cat	cat = Cat();
	cat.setBrainIdea("Jelly", 0);
	cat.setBrainIdea("Jelly1", 1);
	cat.setBrainIdea("Jelly2", 2);
	cat.setBrainIdea("Jelly3", 3);
	Cat	cat_2 = Cat(cat);
	
	std::cout << std::endl;
	std::cout << "cat before the change: " << cat.getBrainIdea(0) << std::endl;
	cat.setBrainIdea("Pasta", 0);
	std::cout << "cat after the change: " << cat.getBrainIdea(0) << std::endl;
	std::cout << "cat_2: " << cat_2.getBrainIdea(0) << std::endl;
	std::cout << std::endl;


	
}
