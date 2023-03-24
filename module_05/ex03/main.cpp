/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:18 by pedro             #+#    #+#             */
/*   Updated: 2023/03/24 17:48:19 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
	
	// ==================EX01======================
	std::cout << "===== EX01=====" << std::endl << std::endl;
	try {
		Bureaucrat bu = Bureaucrat("Robert", 200);
		std::cout << bu << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Couldn't create bureaucrat" << std::endl;
	}
	try {
		Bureaucrat bu = Bureaucrat("Robert", -50);
		  std::cout << bu << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Couldn't create bureaucrat" << std::endl;
	}
	try {
		Bureaucrat bu = Bureaucrat("Robert", 23);
		  std::cout << bu << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Couldn't create bureaucrat" << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Couldn't create bureaucrat" << std::endl;
	}

	Bureaucrat buLow = Bureaucrat("Nino", 150);
	Bureaucrat buHigh = Bureaucrat("Faísca", 1);

	try {
	 buLow.decrementGrade(1);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Cannot decrement grade" << std::endl;
	}
	try {
		buHigh.incrementGrade(1);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Cannot increment grade" << std::endl;
	}

	try {
	 buLow.incrementGrade(1);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Cannot decrement grade" << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Cannot increment grade" << std::endl;
	}

	try{
		buHigh.decrementGrade(1);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "Cannot increment grade" << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "Cannot decrement grade" << std::endl;
	}
	
	std::cout << buHigh << std::endl;
	std::cout << buLow << std::endl;
	
	std::cout << std::endl << "=======END OF EX01======" << std::endl;
	
	// ====================EX02 TESTS===================
	std::cout << std::endl << "===== EX02 =====" << std::endl << std::endl;
	
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
	
	std::cout << std::endl << "==========END OF EX02========" << std::endl << std::endl;
	// ===============EX03=================
	
	std::cout << "==========EX03========" << std::endl << std::endl;
	Intern intern;
	AForm	*form1;
	AForm	*form2;
	AForm	*form3;
	
	form1 = intern.makeForm("shrubbery creation", "shekira");
	form2 = intern.makeForm("robotomy request", "shekira2");
	form3 = intern.makeForm("presidential pardon", "shekira3");
	
	// Criar função intermediaria createForm em intern que faz um try-catch para makeForm. Printa mensagem de erro e retorna NULL;
	AForm *form4 = intern.makeForm("noexiste", "malaca");
	if (form4 != NULL)
		buHigh.signForm(*form4);
	
	buHigh.signForm(*form1);
	buHigh.signForm(*form2);
	buHigh.signForm(*form3);
	
	buHigh.executeForm(*form1);
	buHigh.executeForm(*form2);
	buHigh.executeForm(*form3);
	
	std::cout << std::endl << "==========END OF EX03========" << std::endl << std::endl;
	
	delete shubery;
	delete robotomy;
	delete pardon;
	delete form1;
	delete form2;
	delete form3;
	
	return (0);
}
