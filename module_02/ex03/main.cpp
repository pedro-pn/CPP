/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:52:09 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/08 18:47:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {

	// Point in the middle
	bool is_inside = bsp(Point(1, 1), Point(3, 1), Point(2, 3), Point(2, 2));
	std::cout << "is_inside: " << is_inside << std::endl;

	// Point in the edge
	is_inside = bsp(Point(1, 1), Point(3, 1), Point(2, 3), Point(2.5f, 2));
	std::cout << "is_inside: " << is_inside << std::endl;

	// point in the vertice
	is_inside = bsp(Point(1, 1), Point(3, 1), Point(2, 3), Point(3, 1));
	std::cout << "is_inside: " << is_inside << std::endl;

	// point outside
	is_inside = bsp(Point(1, 1), Point(3, 1), Point(2, 3), Point(5, 90.3f));
	std::cout << "is_inside: " << is_inside << std::endl;

	return (0);
}
