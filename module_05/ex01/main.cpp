/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:18 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 12:07:16 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	
	Form	nuclearBomb("manhattan_project", 1, 1);
	Form	freePassport("passport", 20, 20);

	std::cout << nuclearBomb << std::endl;
	buHigh.signForm(nuclearBomb);
	std::cout << freePassport << std::endl;
	buLow.signForm(freePassport);
	std::cout << freePassport << std::endl;
	buHigh.signForm(freePassport);
	std::cout << freePassport << std::endl;

	return (0);
}
