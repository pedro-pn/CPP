/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:45:12 by pedro             #+#    #+#             */
/*   Updated: 2023/03/24 17:22:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("none") {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm default constructor was called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm constructor was called!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm default destructor was called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm("ShrubberyCreationForm", 145, 137) {
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor was called!" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::beExecuted(void) const {
	std::ofstream	output;
	std::string		fileName = this->_target + "_shrubbery";
	
	output.open(fileName.c_str());
	if (output.fail()) {
		std::cout << "Couldn't open " << fileName << std::endl;
		return ; 
	}
	output << TREE;
	output.close();
}
