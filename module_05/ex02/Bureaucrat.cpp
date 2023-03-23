/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:57:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/23 20:08:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Gerald"), _grade(150) {
	std::cout << "Bureaucrat default constructor was called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor was called!" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor was called!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : _name(rhs._name) {
	*this = rhs;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_grade = rhs._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int const increment) {
	if (this->_grade - increment < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= increment;
}
void	Bureaucrat::decrementGrade(int const decrement) {
	if (this->_grade + decrement > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += decrement;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	} catch (AForm::GradeTooLowException &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
	} catch (AForm::FormNotSignedException &e) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " executed " << form.getName() << std::endl;
}

// exceptions

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Ops, grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Ops, grade is too Low!");
}

// ostream overload

std::ostream&	operator<<(std::ostream &o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}
