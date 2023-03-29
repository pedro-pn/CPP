/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:49:01 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 18:08:05 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

void	Test::_useTypes(std::string const &n, std::string const &tittle) {
	std::cout << std::endl;
	std::cout << tittle << " test with literal: " << n << std::endl;
	std::string	isTypesNames[4] = {"is_char", "is_int", "is_float", "is_double"};
	bool	(ScalarConverter::*istypes[4])(std::string const &) = {&Test::_isChar, &Test::_isInt, &Test::_isFloat, &Test::_isDouble};
	for (int i = 0; i < 4; i++) {
		std::cout << isTypesNames[i] << " result: " << (this->*istypes[i])(n) << std::endl;
	}
	std::cout << std::endl;
}

void	Test::testTypes(std::string const &n, std::string const &tittle) {
	Test()._useTypes(n, tittle);
}
