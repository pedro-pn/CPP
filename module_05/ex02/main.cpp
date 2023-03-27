/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:18 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 12:08:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	try {
		Bureaucrat bu = Bureaucrat("Robert", 200);
		std::cout << bu << std::endl;
	} catch (std::exception &e) {
		std::cout << "Couldn't create bureaucrat: " << e.what() << std::endl;
	}
	try {
		Bureaucrat bu = Bureaucrat("Robert", -50);
		std::cout << bu << std::endl;
	} catch (std::exception &e) {
		std::cout << "Couldn't create bureaucrat: " << e.what() << std::endl;
	}
	try {
		Bureaucrat bu = Bureaucrat("Robert", 23);
		std::cout << bu << std::endl;
	} catch (std::exception &e) {
		std::cout << "Couldn't create bureaucrat: " << e.what() << std::endl;
	}

	Bureaucrat buLow = Bureaucrat("Nino", 150);
	Bureaucrat buHigh = Bureaucrat("Faísca", 1);

	try {
	 buLow.decrementGrade(1);
	} catch (std::exception &e) {
		std::cout << "Cannot increment/decrement grade: " << e.what() << std::endl;
	}
	try{
		buHigh.incrementGrade(1);
	} catch (std::exception &e) {
		std::cout << "Cannot increment/decrement grade: " << e.what() << std::endl;
	}

	try {
	 buLow.incrementGrade(1);
	} catch (std::exception &e) {
		std::cout << "Cannot increment/decrement grade: " << e.what() << std::endl;
	}

	try{
		buHigh.decrementGrade(1);
	} catch (std::exception &e) {
		std::cout << "Cannot increment/decrement grade: " << e.what() << std::endl;
	}
	
	std::cout << buHigh << std::endl;
	std::cout << buLow << std::endl;
	
	std::cout << std::endl << "=====END OF EX00====" << std::endl << std::endl;
	
	std::cout << std::endl << "===== EX02 =====" << std::endl;
	
	AForm	*shubery = new ShrubberyCreationForm("home");
	AForm	*robotomy = new RobotomyRequestForm("furuleibe");
	AForm	*pardon = new PresidentialPardonForm("xuleibe");
	
	
	std::cout << *pardon << std::endl;
	buHigh.signForm(*pardon);
	std::cout << *shubery << std::endl;
	buLow.signForm(*shubery);
	std::cout << *shubery << std::endl;
	buHigh.signForm(*shubery);
	std::cout << *shubery << std::endl;
	
	buHigh.executeForm(*robotomy);
	buHigh.signForm(*robotomy);
	
	buLow.executeForm(*shubery);
	buLow.executeForm(*robotomy);
	buLow.executeForm(*pardon);
	
	buHigh.executeForm(*shubery);
	buHigh.executeForm(*robotomy);
	buHigh.executeForm(*pardon);

	delete shubery;
	delete robotomy;
	delete pardon;
	
	return (0);
}
