/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:35:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/07 00:02:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::bits = 8;

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : value(n) {
	std::cout << "Int constructor called" << std::endl;
	this->value = n << this->bits;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->value = (int) roundf(n * (1 << this->bits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed&	Fixed::operator = (Fixed const &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float) this->value / ((float) (1 << this->bits)));
}

int	Fixed::toInt(void) const {
	return ((int) this->value / ((int) (1 << this->bits)));
}

std::ostream & operator<<(std::ostream& o, Fixed const & fixed) {
	o << fixed.toFloat();

	return (o);
}
