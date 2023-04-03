/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:19:20 by pedro             #+#    #+#             */
/*   Updated: 2023/04/03 17:46:44 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int	main() {
	int a = 2;
	int b = 3;

	::swap<int>( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap<std::string>(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;

	std::cout << std::endl << "====My main===" << std::endl << std::endl;
	std::cout << "<int test> Max value between 50 and 20: " << ::max<int>(50, 20) << std::endl;
	std::cout << "<int test> Min value between 50 and 20: " << ::min<int>(50, 20) << std::endl;

	std::cout << "<int test> Max value between 20 and 20: " << ::max<int>(20, 20) << std::endl;
	std::cout << "<int test> Max value between 20 and 20: " <<  ::min<int>(20, 20) << std::endl;

	std::cout << "<double test> Max value between 20.5 and 20.1: " << ::max<double>(20.5, 20.1) << std::endl;
	std::cout << "<char test> Max value between 'd' and 'a': " << ::min<char>('d', 'a') << std::endl;

	return (0);
}
