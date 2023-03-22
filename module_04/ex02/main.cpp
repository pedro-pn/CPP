/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/22 11:35:10 by ppaulo-d         ###   ########.fr       */
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

	Dog	dog = Dog();
	dog.setBrainIdea("Jelly", 0);
	dog.setBrainIdea("Jelly1", 1);
	dog.setBrainIdea("Jelly2", 2);
	dog.setBrainIdea("Jelly3", 3);
	Dog dog_2 = Dog(dog);
	Dog dog_3 = Dog();
	Dog	dog_4;
	dog_3 = dog;
	dog_4 = dog;

	std::cout << "dog_3 first idea: " << dog_3.getBrainIdea(0) << std::endl;
	std::cout << "dog_4 first idea: " << dog_4.getBrainIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << "dog before the change: " << dog.getBrainIdea(0) << std::endl;
	dog.setBrainIdea("Pasta", 0);
	std::cout << "dog after the change: " << dog.getBrainIdea(0) << std::endl;
	std::cout << "dog_2: " << dog_2.getBrainIdea(0) << std::endl;
	std::cout << "Teste" << std::endl;
}
