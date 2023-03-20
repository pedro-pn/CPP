/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:04:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/20 11:26:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : AAnimal() {
	std::cout << "Cat default constructor was called!" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string const name) : AAnimal() {
	std::cout << "Cat named constructor was called!" << std::endl;
	setType(name);
	this->brain = new Brain();
}

Cat::~Cat(void) {
	std::cout << "Cat default destructor was called!" << std::endl;
	delete this->brain;
}

Cat::Cat(Cat const &cat) : AAnimal() {
	std::cout << "Cat copy constructor was called!" << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat&	Cat::operator=(Cat const &cat) {
	if (this == &cat)
		return (*this);
	this->setType(cat.getType());
	*this->brain = *cat.brain;
	return (*this);
}

std::string	Cat::getBrainIdea(int const index) const {
	return (this->brain->getIdeas(index));
}

void		Cat::setBrainIdea(std::string const idea, int const index) {
	this->brain->setIdeas(idea, index);
}


void	Cat::makeSound(void) const {
	std::cout << getType() << ": MEOOOOOOOOOOOOOOOOOWWW!" << std::endl;
}
