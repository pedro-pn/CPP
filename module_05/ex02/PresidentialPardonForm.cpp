/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:23:20 by pedro             #+#    #+#             */
/*   Updated: 2023/03/23 20:12:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("none") {
	std::cout << "PresidentialPardonForm default constructor was called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor was called!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm default destructor was called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "PresidentialPardonForm copy constructor was called!" << std::endl;
	*this = rhs;
}

void	PresidentialPardonForm::beExecuted(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}
