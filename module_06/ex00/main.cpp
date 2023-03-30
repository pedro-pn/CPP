/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:09:07 by pedro             #+#    #+#             */
/*   Updated: 2023/03/29 20:01:39 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: enter a char/int/float or double literal!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
