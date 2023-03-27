/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:04:37 by pedro             #+#    #+#             */
/*   Updated: 2023/03/27 12:37:35 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) : _name("none"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
	if (DEBUG)
		std::cout << "AForm default constructor was called!" << std::endl;
}

AForm::AForm(std::string const &name, int const gradeToSign, int const gradeToExecute) : 
		_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (DEBUG)
		std::cout << "Form constructor was called!" << std::endl;
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &rhs) :
	_name(rhs._name), _signed(rhs._signed), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){
	if (DEBUG)
		std::cout << "AForm copy constructor was called" << std::endl;
	*this = rhs;

}
AForm::~AForm(void) {
	if (DEBUG)
		std::cout << "AForm destructor was called!" << std::endl;
}

AForm&	AForm::operator=(AForm const &rhs) {
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

std::string const&	AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSigned(void) const {
	return (this->_signed);
}

int	AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	this->beExecuted();
}

// exceptions

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low!");
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high!");
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return ("form is not signed!");
}

const char	*AForm::FormNotExistException::what() const throw() {
	return ("form does not exist");
}


// ostream overload
std::ostream&	operator<<(std::ostream &o, AForm const &rhs) {
	o << "Name: " << rhs.getName() << std::endl;
	o << "Signed: " << rhs.getSigned() << std::endl;
	o << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	o << "Grade to execute:  " << rhs.getGradeToExecute();
	return (o);
}
