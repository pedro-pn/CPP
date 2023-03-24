/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:45:44 by pedro             #+#    #+#             */
/*   Updated: 2023/03/24 09:48:08 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {
	std::cout << "Intern constructor was called!" << std::endl;	
}

Intern::~Intern(void) {
	std::cout << "Intern destructor was called!" << std::endl;	
}

Intern::Intern(Intern const &rhs) {
	std::cout << "Intern copy constructor was called!" << std::endl;
	*this = rhs;
}

Intern&	Intern::operator=(Intern const &rhs) {
	std::cout << "Intern assigment operator was called!" << std::endl;	
	if (this == &rhs)
		return (*this);
	return (*this);
}

AForm	*Intern::makeForm(std::string const &form, std::string const &target) const {
	try {
		return (this->createForm(form, target));
	}	catch (AForm::FormNotExistException &e) {
		std::cout << "Intern couldn't create " << form << " because " << e.what() << std::endl;
		return (NULL);
	}
}

AForm	*Intern::createForm(std::string const &form, std::string const &target) const {
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	index;
	for (index = 0; index < 3; index++) {
		if (form == forms[index])
			break ;
	}
	switch (index) {
		case (0):
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		case (1):
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
		case (2):
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Stupid Intern doesn't know " << form << std::endl;
			throw AForm::FormNotExistException();
	}
}


