/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:04:37 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 12:37:23 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("none"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
	std::cout << "Form default constructor was called!" << std::endl;
}

Form::Form(std::string const &name, int const gradeToSign, int const gradeToExecute) : 
		_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor was called!" << std::endl;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &rhs) :
	_name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){
	std::cout << "Form copy constructor was called" << std::endl;
	*this = rhs;

}
Form::~Form(void) {
	std::cout << "Form destructor was called!" << std::endl;
}

Form&   Form::operator=(Form const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

std::string const&  Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSigned(void) const {
	return (this->_signed);
}

int	Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
}

// exceptions

const char	*Form::GradeTooLowException::what() const throw() {
	return ("grade is too low!");
}

const char	*Form::GradeTooHighException::what() const throw() {
	return ("grade is too high!");
}

// ostream overload
std::ostream&	operator<<(std::ostream &o, Form const &rhs) {
	o << "Name: " << rhs.getName() << std::endl;
	o << "Signed: " << rhs.getSigned() << std::endl;
	o << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	o << "Grade to execute:  " << rhs.getGradeToExecute();
	return (o);
}
