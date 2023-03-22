/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/22 15:42:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Gerald"), grade(150) {
	std::cout << "Bureaucrat default constructor was called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : name(name), grade(grade) {
	std::cout << "Bureaucrat constructor was called!" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor was called!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : name(name) {
	*this = rhs;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this == &rhs)
		return (*this);
	this->grade = rhs.grade;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const {
	return (this->name);
}

int	const			Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void				Bureaucrat::incrementGrade(int const increment) {
	this->grade -= increment;
}
void				Bureaucrat::decrementGrade(int const decrement) {
	this->grade += decrement;
}

std::ostream&	operator<<(std::ostream &o, Bureaucrat const &rhs) {
	o << rhs.getGrade();
	return (o);
}