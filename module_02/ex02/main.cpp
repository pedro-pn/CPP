/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:52:09 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/08 17:01:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	Fixed	a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "----- end of subdject main ------" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	Fixed c(50);
	Fixed d(5.5f);

	Fixed e = c + d;
	std::cout << e << std::endl;

	e = c - d;
	std::cout << e << std::endl;

	e = c * d;
	std::cout << e << std::endl;

	e = c / d;
	std::cout << e << std::endl;

	return 0;
}
