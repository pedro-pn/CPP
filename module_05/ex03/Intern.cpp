/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:45:44 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 12:11:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {
	if (DEBUG)
		std::cout << "Intern constructor was called!" << std::endl;	
}

Intern::~Intern(void) {
	if (DEBUG)
		std::cout << "Intern destructor was called!" << std::endl;	
}

Intern::Intern(Intern const &rhs) {
	if (DEBUG)
		std::cout << "Intern copy constructor was called!" << std::endl;
	*this = rhs;
}

Intern&	Intern::operator=(Intern const &rhs) {
	if (DEBUG)
		std::cout << "Intern assigment operator was called!" << std::endl;	
	if (this == &rhs)
		return (*this);
	return (*this);
}

AForm	*Intern::makeForm(std::string const &form, std::string const &target) {
	try {
		return (this->createForm(form, target));
	}	catch (std::exception &e) {
		std::cout << "Intern couldn't create " << form << " because " << e.what() << std::endl;
		return (NULL);
	}
}

AForm	*Intern::createForm(std::string const &form, std::string const &target) {
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*formsMakers[3])(std::string const &) = {
		&Intern::_makeShruberryCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialParonForm};
	for (int index = 0; index < 3; index++) {
		if (form == forms[index]){
			std::cout << "Intern creates " << form << std::endl;
			return ((this->*formsMakers[index])(target));
		}
	}
	throw (AForm::FormNotExistException());
}

AForm	*Intern::_makeShruberryCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}
AForm	*Intern::_makeRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
}
AForm	*Intern::_makePresidentialParonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
}
