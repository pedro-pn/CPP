/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:06:16 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/17 13:37:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain default constructor was called!" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor was called!" << std::endl;
}

Brain::Brain(Brain const &brain) {
	*this = brain;
}

Brain&	Brain::operator=(Brain const &brain) {
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdeas(int const index) const {
	return (this->ideas[index]);
}

void	Brain::setIdeas(std::string *ideas) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas[i];
	}
}