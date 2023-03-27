/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:14:06 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 19:29:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("none") {
	if (DEBUG)
		std::cout << "RobotomyRequestForm default constructor was called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	if (DEBUG)
		std::cout << "RobotomyRequestForm constructor was called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	if (DEBUG)
		std::cout << "RobotomyRequestForm default destructor was called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm("RobotomyRequestForm", 72, 45) {
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy constructor was called!" << std::endl;
	*this = rhs;
}

void	RobotomyRequestForm::beExecuted(void) const {
	std::cout << "BZZZZZZZZZZZZZZZZZzzzzzzzzzzZZZZZZZZZZZZZ plec!" << std::endl;
	std::srand(time(0));
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "OOPS, it looks like "<<this->_target << " is not here anymore!" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}
