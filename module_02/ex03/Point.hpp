/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:32:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/08 18:21:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	public:

		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const &point);
		~Point(void);

		Point& operator=(Point const &point);

		Fixed	getx(void) const;
		Fixed	gety(void) const;

		void	setx(Fixed x);
		void	sety(Fixed y);

	private:

		Fixed	x;
		Fixed	y;
		
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif