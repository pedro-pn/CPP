/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:52:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/08 18:46:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	calculateArea(Point const a, Point const b, Point const c) {
	Fixed area;

	area = Fixed(0.5f) * ((a.getx() * (b.gety() - c.gety()))
			+ (b.getx() * (c.gety() - a.gety()))
			+ (c.getx() * (a.gety() - b.gety())));
	area = Fixed::abs(area);
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area = calculateArea(a, b, c);
	Fixed	area_pab = calculateArea(point, a, b);
	Fixed	area_pac = calculateArea(point, a, c);
	Fixed	area_pbc = calculateArea(point, b, c);
	Fixed	totalpArea = area_pab + area_pac + area_pbc;

	if (area_pab == Fixed(0) || area_pac == Fixed(0) || area_pbc == Fixed(0))
		return (false);
	if (totalpArea != area)
		return (false);
	return (true);
}
