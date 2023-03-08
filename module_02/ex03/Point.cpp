/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:31 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/08 17:50:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) {

}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y) {

}

Point::Point(Point const &point) {
	*this = point;
}

Point::~Point(void) {

}

Point&	Point::operator=(Point const &point) {
	setx(point.getx());
	sety(point.gety());
	return (*this);
}

Fixed	Point::getx(void) const {
	return (this->x);
}

Fixed	Point::gety(void) const {
	return (this->y);
}

void	Point::setx(Fixed x) {
	this->x = x;
}

void	Point::sety(Fixed y) {
	this->y = y;
}
